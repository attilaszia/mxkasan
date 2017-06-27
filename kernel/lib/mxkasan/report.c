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

#define __round_mask(x, y) ((__typeof__(x))((y)-1))
#define round_up(x, y) ((((x)-1) | __round_mask(x, y))+1)
#define round_down(x, y) ((x) & ~__round_mask(x, y))

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


static void print_error_description(struct mxkasan_access_info *info)
{
	const char *bug_type = "unknown crash";
	u8 shadow_val;

	info->first_bad_addr = find_first_bad_addr(info->access_addr,
						info->access_size);

	shadow_val = *(u8 *)mxkasan_mem_to_shadow(info->first_bad_addr);

	switch (shadow_val) {
	case 0 ... MXKASAN_SHADOW_SCALE_SIZE - 1:
		bug_type = "out of bounds access";
		break;
	}

	printf("BUG: MXKASan: %s in %pS at addr %p\n",
		bug_type, (void *)info->ip,
		info->access_addr);

	thread_t* current = get_current_thread();
	printf("%s of size %zu by task %s/%d\n",
		info->is_write ? "Write" : "Read",
		info->access_size, current->name, (int)current->user_pid);
}

static void dump_stack (void) {
	printf("TODO: stack dump\n");
}


static void print_address_description(struct mxkasan_access_info *info)
{
	dump_stack();
}

static bool row_is_guilty(const void *row, const void *guilty)
{
	return (row <= guilty) && (guilty < row + SHADOW_BYTES_PER_ROW);
}

static int shadow_pointer_offset(const void *row, const void *shadow)
{
	/* The length of ">ff00ff00ff00ff00: " is
	 *    3 + (BITS_PER_LONG/8)*2 chars.
	 */
	return 3 + (BITS_PER_LONG/8)*2 + (shadow - row)*2 +
		(shadow - row) / SHADOW_BYTES_PER_BLOCK + 1;
}

static void print_shadow_for_address(const void *addr)
{
	int i;
	const void *shadow = mxkasan_mem_to_shadow(addr);
	const void *shadow_row;

	shadow_row = (void *)round_down((unsigned long)shadow,
					SHADOW_BYTES_PER_ROW)
		- SHADOW_ROWS_AROUND_ADDR * SHADOW_BYTES_PER_ROW;

	printf("Memory state around the buggy address:\n");

	for (i = -SHADOW_ROWS_AROUND_ADDR; i <= SHADOW_ROWS_AROUND_ADDR; i++) {
		const void *kaddr = mxkasan_shadow_to_mem(shadow_row);
		char buffer[4 + (BITS_PER_LONG/8)*2];

		snprintf(buffer, sizeof(buffer),
			(i == 0) ? ">%p: " : " %p: ", kaddr);

		mxkasan_disable_current();

        // TODO: make this prettier
		hexdump(shadow_row, SHADOW_BYTES_PER_ROW);

		mxkasan_enable_current();

		if (row_is_guilty(shadow_row, shadow))
			printf("%*c\n",
				shadow_pointer_offset(shadow_row, shadow),
				'^');

		shadow_row += SHADOW_BYTES_PER_ROW;
	}
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
		info->access_size, current->name, (int)current->user_pid);

	dump_stack();
	printf("================================="
		"=================================\n");

	spin_unlock_irqrestore(&report_lock, state);
}



void mxkasan_report(unsigned long addr, size_t size,
		bool is_write, unsigned long ip)
{
	struct mxkasan_access_info info;

	if (likely(!mxkasan_enabled()))
		return;

	info.access_addr = (void *)addr;
	info.access_size = size;
	info.is_write = is_write;
	info.ip = ip;
	mxkasan_report_error(&info);
}


#define DEFINE_ASAN_REPORT_LOAD(size)                     \
void __asan_report_load##size##_noabort(unsigned long addr) \
{                                                         \
	mxkasan_report(addr, size, false, _RET_IP_);	  \
}                                                         \

#define DEFINE_ASAN_REPORT_STORE(size)                     \
void __asan_report_store##size##_noabort(unsigned long addr) \
{                                                          \
	mxkasan_report(addr, size, true, _RET_IP_);	   \
}                                                          \

DEFINE_ASAN_REPORT_LOAD(1);
DEFINE_ASAN_REPORT_LOAD(2);
DEFINE_ASAN_REPORT_LOAD(4);
DEFINE_ASAN_REPORT_LOAD(8);
DEFINE_ASAN_REPORT_LOAD(16);
DEFINE_ASAN_REPORT_STORE(1);
DEFINE_ASAN_REPORT_STORE(2);
DEFINE_ASAN_REPORT_STORE(4);
DEFINE_ASAN_REPORT_STORE(8);
DEFINE_ASAN_REPORT_STORE(16);

void __asan_report_load_n_noabort(unsigned long addr, size_t size)
{
	mxkasan_report(addr, size, false, _RET_IP_);
}

void __asan_report_store_n_noabort(unsigned long addr, size_t size)
{
	mxkasan_report(addr, size, true, _RET_IP_);
}
