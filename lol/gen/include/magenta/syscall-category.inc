// Copyright 2017 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //magenta/system/host/sysgen.
// The license governing this file can be found in the LICENSE file.


#define HAVE_SYSCALL_CATEGORY_blocking 1
SYSCALL_CATEGORY_BEGIN(blocking)
    SYSCALL_IN_CATEGORY(nanosleep)
    SYSCALL_IN_CATEGORY(object_wait_one)
    SYSCALL_IN_CATEGORY(object_wait_many)
    SYSCALL_IN_CATEGORY(futex_wait)
    SYSCALL_IN_CATEGORY(waitset_wait)
    SYSCALL_IN_CATEGORY(port_wait)
    SYSCALL_IN_CATEGORY(interrupt_wait)
SYSCALL_CATEGORY_END(blocking)

#define HAVE_SYSCALL_CATEGORY_const 1
SYSCALL_CATEGORY_BEGIN(const)
    SYSCALL_IN_CATEGORY(ticks_per_second)
    SYSCALL_IN_CATEGORY(system_get_num_cpus)
SYSCALL_CATEGORY_END(const)

#define HAVE_SYSCALL_CATEGORY_deprecated 1
SYSCALL_CATEGORY_BEGIN(deprecated)
    SYSCALL_IN_CATEGORY(waitset_create)
    SYSCALL_IN_CATEGORY(waitset_add)
    SYSCALL_IN_CATEGORY(waitset_remove)
    SYSCALL_IN_CATEGORY(waitset_wait)
SYSCALL_CATEGORY_END(deprecated)

#define HAVE_SYSCALL_CATEGORY_no_wrap 1
SYSCALL_CATEGORY_BEGIN(no_wrap)
    SYSCALL_IN_CATEGORY(mtrace_control)
    SYSCALL_IN_CATEGORY(debug_read)
    SYSCALL_IN_CATEGORY(debug_write)
    SYSCALL_IN_CATEGORY(debug_send_command)
SYSCALL_CATEGORY_END(no_wrap)

#define HAVE_SYSCALL_CATEGORY_noreturn 1
SYSCALL_CATEGORY_BEGIN(noreturn)
    SYSCALL_IN_CATEGORY(thread_exit)
    SYSCALL_IN_CATEGORY(process_exit)
    SYSCALL_IN_CATEGORY(futex_wake_handle_close_thread_exit)
SYSCALL_CATEGORY_END(noreturn)

#define HAVE_SYSCALL_CATEGORY_test_category1 1
SYSCALL_CATEGORY_BEGIN(test_category1)
    SYSCALL_IN_CATEGORY(syscall_test_1)
    SYSCALL_IN_CATEGORY(syscall_test_2)
SYSCALL_CATEGORY_END(test_category1)

#define HAVE_SYSCALL_CATEGORY_test_category2 1
SYSCALL_CATEGORY_BEGIN(test_category2)
    SYSCALL_IN_CATEGORY(syscall_test_3)
SYSCALL_CATEGORY_END(test_category2)

#define HAVE_SYSCALL_CATEGORY_vdsocall 1
SYSCALL_CATEGORY_BEGIN(vdsocall)
    SYSCALL_IN_CATEGORY(ticks_get)
    SYSCALL_IN_CATEGORY(ticks_per_second)
    SYSCALL_IN_CATEGORY(deadline_after)
    SYSCALL_IN_CATEGORY(system_get_num_cpus)
    SYSCALL_IN_CATEGORY(system_get_version)
    SYSCALL_IN_CATEGORY(system_get_physmem)
    SYSCALL_IN_CATEGORY(cache_flush)
    SYSCALL_IN_CATEGORY(channel_call)
    SYSCALL_IN_CATEGORY(vmar_unmap_handle_close_thread_exit)
    SYSCALL_IN_CATEGORY(futex_wake_handle_close_thread_exit)
SYSCALL_CATEGORY_END(vdsocall)
