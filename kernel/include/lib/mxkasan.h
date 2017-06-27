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

// TODO: do this properly
#define BITS_PER_LONG 64

#define _RET_IP_		(unsigned long)__builtin_return_address(0)

struct mxkasan_access_info {
	const void *access_addr;
	const void *first_bad_addr;
	size_t access_size;
	bool is_write;
	unsigned long ip;
};


void mxkasan_report_error(struct mxkasan_access_info *info);
void mxkasan_report_user_access(struct mxkasan_access_info *info);
void mxkasan_report(unsigned long addr, size_t size,
		bool is_write, unsigned long ip);

void mxkasan_test(void);
void mxkasan_unpoison_shadow(const void *address, size_t size);
static void mxkasan_poison_shadow(const void *address, size_t size, u8 value);

static inline uint8_t* mxkasan_mem_to_shadow(const uint8_t* addr)
{
	return (uint8_t*)((unsigned long)addr >> MXKASAN_SHADOW_SCALE_SHIFT)
		+ MXKASAN_SHADOW_OFFSET;
}

static inline const void *mxkasan_shadow_to_mem(const void *shadow_addr)
{
	return (void *)(((unsigned long)shadow_addr - MXKASAN_SHADOW_OFFSET)
		<< MXKASAN_SHADOW_SCALE_SHIFT);
}

/* Enable reporting bugs after kasan_disable_current() */
static inline void mxkasan_enable_current(void)
{
	thread_t* current = get_current_thread();
	current->kasan_depth++;
}

/* Disable reporting bugs for current task */
static inline void mxkasan_disable_current(void)
{
	thread_t* current = get_current_thread();
	current->kasan_depth--;
}