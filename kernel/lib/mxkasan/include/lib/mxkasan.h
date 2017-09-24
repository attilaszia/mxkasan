// Copyright 2017 Attila Szasz
//
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <inttypes.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <kernel/thread.h>


#define MXKASAN_SHADOW_SCALE_SHIFT 3
#define MXKASAN_SHADOW_OFFSET 0xffffde0000000000
#define MXKASAN_SHADOW_START  0xffff000000000000
#define MXKASAN_SHADOW_SIZE 0x100000000000
#define MXKASAN_SHADOW_SCALE_SIZE (1UL << MXKASAN_SHADOW_SCALE_SHIFT)
#define MXKASAN_SHADOW_MASK       (MXKASAN_SHADOW_SCALE_SIZE - 1)

#define MXKASAN_FREE_PAGE         0xFF  /* page was freed */
#define MXKASAN_SHADOW_GAP        0xF9  /* address belongs to shadow memory */
#define MXKASAN_REDZONE   	      0xFC  /* full page redzone */
#define MXKASAN_MALLOC_FREE       0xFB  /* object was freed */

// TODO: do this properly
#define BITS_PER_LONG 64

#define __alias(symbol)	__attribute__((weak, alias(#symbol)))

#define _RET_IP_		(unsigned long)__builtin_return_address(0)

struct mxkasan_access_info {
	const uint8_t *access_addr;
	const uint8_t *first_bad_addr;
	size_t access_size;
	bool is_write;
	unsigned long ip;
};

__BEGIN_CDECLS

extern bool mxkasan_initialized;
extern void* mxkasan_init_heap_ptr;
extern size_t mxkasan_init_heap_size;

void mxkasan_report_error(struct mxkasan_access_info *info);
void mxkasan_report_user_access(struct mxkasan_access_info *info);
void mxkasan_report(unsigned long addr, size_t size,
		bool is_write, unsigned long ip);

void mxkasan_init(void);
void mxkasan_poison_shadow(const uint8_t *address, size_t size, u8 value);
void mxkasan_unpoison_shadow(const uint8_t *address, size_t size);

void mxkasan_alloc_pages(const uint8_t* addr, size_t pages);
void mxkasan_free_pages(const uint8_t* addr, size_t pages);

void __asan_loadN(unsigned long addr, size_t size);
void __asan_load1(unsigned long addr);
void __asan_load2(unsigned long addr);	
void __asan_load4(unsigned long addr);	
void __asan_load8(unsigned long addr);	
void __asan_load16(unsigned long addr);	

void __asan_storeN(unsigned long addr, size_t size);
void __asan_store1(unsigned long addr);
void __asan_store2(unsigned long addr);
void __asan_store4(unsigned long addr);
void __asan_store8(unsigned long addr);
void __asan_store16(unsigned long addr);

void __asan_handle_no_return(void);

#define DEFINE_ASAN_REPORT_LOAD_DEC(size)                     \
void __asan_report_load##size##_noabort(unsigned long addr); \

#define DEFINE_ASAN_REPORT_STORE_DEC(size)                     \
void __asan_report_store##size##_noabort(unsigned long addr); \

DEFINE_ASAN_REPORT_LOAD_DEC(1);
DEFINE_ASAN_REPORT_LOAD_DEC(2);
DEFINE_ASAN_REPORT_LOAD_DEC(4);
DEFINE_ASAN_REPORT_LOAD_DEC(8);
DEFINE_ASAN_REPORT_LOAD_DEC(16);
DEFINE_ASAN_REPORT_STORE_DEC(1);
DEFINE_ASAN_REPORT_STORE_DEC(2);
DEFINE_ASAN_REPORT_STORE_DEC(4);
DEFINE_ASAN_REPORT_STORE_DEC(8);
DEFINE_ASAN_REPORT_STORE_DEC(16);

void __asan_report_load_n_noabort(unsigned long addr, size_t size);
void __asan_report_store_n_noabort(unsigned long addr, size_t size);

__END_CDECLS

inline bool is_shadow_addr(vaddr_t va) {
	if ((MXKASAN_SHADOW_OFFSET <= va) && 
	   (va <= (MXKASAN_SHADOW_OFFSET +MXKASAN_SHADOW_SIZE))) {
	       return true;
	   }
	else 
	   return false;
}

static inline uint8_t* mxkasan_mem_to_shadow(const uint8_t* addr)
{
	unsigned long address = (unsigned long)addr << 16;
	address = (unsigned long)address >> 16;
	return (uint8_t*)((unsigned long)address >> MXKASAN_SHADOW_SCALE_SHIFT)
		+ MXKASAN_SHADOW_OFFSET;
}

static inline const void *mxkasan_shadow_to_mem(const void *shadow_addr)
{
	unsigned long address = ((unsigned long)shadow_addr - MXKASAN_SHADOW_OFFSET)
		<< MXKASAN_SHADOW_SCALE_SHIFT;
	address = address + MXKASAN_SHADOW_START;
	return (void*) address;
}

/* Enable reporting bugs after kasan_disable_current() */
static inline void mxkasan_enable_current(void)
{
	thread_t* current = get_current_thread();
	current->mxkasan_depth++;
}

/* Disable reporting bugs for current task */
static inline void mxkasan_disable_current(void)
{
	thread_t* current = get_current_thread();
	current->mxkasan_depth--;
}

static inline bool mxkasan_enabled(void)
{
	thread_t* current = get_current_thread();
	return !current->mxkasan_depth;
}

