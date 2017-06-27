// Copyright 2017 Attila Szasz
//
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#include <lib/mxkasan.h>
#include <stdio.h>
#include <inttypes.h>
#include <kernel/spinlock.h>
#include <kernel/thread.h>

static spin_lock_t report_lock;

/* Shadow layout customization. */
#define SHADOW_BYTES_PER_BLOCK 1
#define SHADOW_BLOCKS_PER_ROW 16
#define SHADOW_BYTES_PER_ROW (SHADOW_BLOCKS_PER_ROW * SHADOW_BYTES_PER_BLOCK)
#define SHADOW_ROWS_AROUND_ADDR 2

static const void *find_first_bad_addr(const void *addr, size_t size)
{
	u8 shadow_val = *(u8 *)mxkasan_mem_to_shadow(addr);
	const void *first_bad_addr = addr;

	while (!shadow_val && first_bad_addr < addr + size) {
		first_bad_addr += MXKASAN_SHADOW_SCALE_SIZE;
		shadow_val = *(u8 *)mxkasan_mem_to_shadow(first_bad_addr);
	}
	return first_bad_addr;
}

void mxkasan_report_error(struct mxkasan_access_info *info)
{

    spin_lock_saved_state_t state;
    spin_lock_irqsave(&report_lock, state);

	printf("================================="
		"=================================\n");
	print_error_description(info);
	print_address_description(info);
	print_shadow_for_address(info->first_bad_addr);
	printf("================================="
		"=================================\n");

	spin_unlock_irqrestore(&report_lock, state);
}

void mxkasan_report_user_access(struct mxkasan_access_info *info)
{
    spin_lock_saved_state_t state;
    spin_lock_irqsave(&report_lock, state);
	printf("================================="
	      "=================================\n");
	printf("BUG: MXKASan: user-memory-access on address %p\n",
		info->access_addr);

	thread_t* current = get_current_thread();
	printf("%s of size %zu by task %s/%d\n",
		info->is_write ? "Write" : "Read",
		info->access_size, current->name, current->user_pid);

	dump_stack();
	printf("================================="
		"=================================\n");

	spin_unlock_irqrestore(&report_lock, state);
    
}
