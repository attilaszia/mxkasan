// Copyright 2017 Attila Szasz
//
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <lib/mxkasan.h>


void mxkasan_test(void) {
    uint8_t* testptr = (uint8_t*) 0xffffde0000000000 ;

    testptr += 0xdead;
    printf("writing MXKASAN shadow memory at %#" PRIxPTR "\n", (unsigned long)testptr);
    *testptr = 0xaa;
    printf("reading back value at %#" PRIxPTR ": %x\n", (unsigned long)testptr, *testptr);
}

/*
 * Poisons the shadow memory for 'size' bytes starting from 'addr'.
 * Memory addresses should be aligned to KASAN_SHADOW_SCALE_SIZE.
 */
static void mxkasan_poison_shadow(const void *address, size_t size, u8 value) {
    void *shadow_start, *shadow_end;

    shadow_start = mxkasan_mem_to_shadow(address);
    shadow_end = mxkasan_mem_to_shadow(address + size);

    memset(shadow_start, value, shadow_end - shadow_start);
}

void mxkasan_unpoison_shadow(const void *address, size_t size)
{
	mxkasan_poison_shadow(address, size, 0);

	if (size & MXKASAN_SHADOW_MASK) {
		u8 *shadow = (u8 *)mxkasan_mem_to_shadow(address + size);
		*shadow = size & MXKASAN_SHADOW_MASK;
	}
}


/*
 * All functions below always inlined so compiler could
 * perform better optimizations in each of __asan_loadX/__assn_storeX
 * depending on memory access size X.
 */

static inline bool memory_is_poisoned_1(unsigned long addr)
{
	s8 shadow_value = *(s8 *)mxkasan_mem_to_shadow((void *)addr);

	if (unlikely(shadow_value)) {
		s8 last_accessible_byte = addr & MXKASAN_SHADOW_MASK;
		return unlikely(last_accessible_byte >= shadow_value);
	}

	return false;
}

static inline bool memory_is_poisoned_2(unsigned long addr)
{
	u16 *shadow_addr = (u16 *)mxkasan_mem_to_shadow((void *)addr);

	if (unlikely(*shadow_addr)) {
		if (memory_is_poisoned_1(addr + 1))
			return true;

		if (likely(((addr + 1) & MXKASAN_SHADOW_MASK) != 0))
			return false;

		return unlikely(*(u8 *)shadow_addr);
	}

	return false;
}

static inline bool memory_is_poisoned_4(unsigned long addr)
{
	u16 *shadow_addr = (u16 *)mxkasan_mem_to_shadow((void *)addr);

	if (unlikely(*shadow_addr)) {
		if (memory_is_poisoned_1(addr + 3))
			return true;

		if (likely(((addr + 3) & MXKASAN_SHADOW_MASK) >= 3))
			return false;

		return unlikely(*(u8 *)shadow_addr);
	}

	return false;
}

static inline bool memory_is_poisoned_8(unsigned long addr)
{
	u16 *shadow_addr = (u16 *)mxkasan_mem_to_shadow((void *)addr);

	if (unlikely(*shadow_addr)) {
		if (memory_is_poisoned_1(addr + 7))
			return true;

		if (likely(((addr + 7) & MXKASAN_SHADOW_MASK) >= 7))
			return false;

		return unlikely(*(u8 *)shadow_addr);
	}

	return false;
}

static inline bool memory_is_poisoned_16(unsigned long addr)
{
	u32 *shadow_addr = (u32 *)mxkasan_mem_to_shadow((void *)addr);

	if (unlikely(*shadow_addr)) {
		u16 shadow_first_bytes = *(u16 *)shadow_addr;
		s8 last_byte = (addr + 15) & MXKASAN_SHADOW_MASK;

		if (unlikely(shadow_first_bytes))
			return true;

		if (likely(!last_byte))
			return false;

		return memory_is_poisoned_1(addr + 15);
	}

	return false;
}


static inline unsigned long bytes_is_zero(const u8 *start,
					size_t size)
{
	while (size) {
		if (unlikely(*start))
			return (unsigned long)start;
		start++;
		size--;
	}

	return 0;
}

static inline unsigned long memory_is_zero(const void *start,
						const void *end)
{
	unsigned int words;
	unsigned long ret;
	unsigned int prefix = (unsigned long)start % 8;

	if (end - start <= 16)
		return bytes_is_zero(start, end - start);

	if (prefix) {
		prefix = 8 - prefix;
		ret = bytes_is_zero(start, prefix);
		if (unlikely(ret))
			return ret;
		start += prefix;
	}

	words = (end - start) / 8;
	while (words) {
		if (unlikely(*(u64 *)start))
			return bytes_is_zero(start, 8);
		start += 8;
		words--;
	}

	return bytes_is_zero(start, (end - start) % 8);
}

static inline bool memory_is_poisoned_n(unsigned long addr,
						size_t size)
{
	unsigned long ret;

	ret = memory_is_zero(mxkasan_mem_to_shadow((void *)addr),
			mxkasan_mem_to_shadow((void *)addr + size - 1) + 1);

	if (unlikely(ret)) {
		unsigned long last_byte = addr + size - 1;
		s8 *last_shadow = (s8 *)mxkasan_mem_to_shadow((void *)last_byte);

		if (unlikely(ret != (unsigned long)last_shadow ||
			((last_byte & MXKASAN_SHADOW_MASK) >= (u8)*last_shadow)))
			return true;
	}
	return false;
}

static inline bool memory_is_poisoned(unsigned long addr, size_t size)
{
	if (__builtin_constant_p(size)) {
		switch (size) {
		case 1:
			return memory_is_poisoned_1(addr);
		case 2:
			return memory_is_poisoned_2(addr);
		case 4:
			return memory_is_poisoned_4(addr);
		case 8:
			return memory_is_poisoned_8(addr);
		case 16:
			return memory_is_poisoned_16(addr);
		default:
		//TODO static assertion here
		    ;
		}
	}

	return memory_is_poisoned_n(addr, size);
}

static inline void check_memory_region(unsigned long addr,
						size_t size, bool write)
{
	struct mxkasan_access_info info;

	if (unlikely(size == 0))
		return;

	if (unlikely((void *)addr <
		mxkasan_shadow_to_mem((void *)MXKASAN_SHADOW_START))) {
		info.access_addr = (void *)addr;
		info.access_size = size;
		info.is_write = write;
		info.ip = _RET_IP_;
		mxkasan_report_user_access(&info);
		return;
	}

	if (likely(!memory_is_poisoned(addr, size)))
		return;

	mxkasan_report(addr, size, write, _RET_IP_);
}

#define DEFINE_ASAN_LOAD_STORE(size)				\
	void __asan_load##size(unsigned long addr)		\
	{							\
		check_memory_region(addr, size, false);		\
	}							\
		\
	__alias(__asan_load##size)				\
	void __asan_load##size##_noabort(unsigned long);	\
	void __asan_store##size(unsigned long addr)		\
	{							\
		check_memory_region(addr, size, true);		\
	}							\
	__alias(__asan_store##size)				\
	void __asan_store##size##_noabort(unsigned long);	\

DEFINE_ASAN_LOAD_STORE(1);
DEFINE_ASAN_LOAD_STORE(2);
DEFINE_ASAN_LOAD_STORE(4);
DEFINE_ASAN_LOAD_STORE(8);
DEFINE_ASAN_LOAD_STORE(16);

void __asan_loadN(unsigned long addr, size_t size)
{
	check_memory_region(addr, size, false);
}

__alias(__asan_loadN)
void __asan_loadN_noabort(unsigned long, size_t);


void __asan_storeN(unsigned long addr, size_t size)
{
	check_memory_region(addr, size, true);
}

__alias(__asan_storeN)
void __asan_storeN_noabort(unsigned long, size_t);

/* to shut up compiler complaints */
void __asan_handle_no_return(void) {}

