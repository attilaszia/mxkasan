// Copyright 2017 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //magenta/system/host/sysgen.
// The license governing this file can be found in the LICENSE file.

mx_status_t _mx_nanosleep(mx_time_t deadline) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_nanosleep(deadline);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_nanosleep);

mx_status_t _mx_object_wait_one(mx_handle_t handle, mx_signals_t waitfor, mx_time_t deadline, mx_signals_t* observed) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_object_wait_one(handle, waitfor, deadline, observed);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_object_wait_one);

mx_status_t _mx_object_wait_many(mx_wait_item_t* items, uint32_t count, mx_time_t deadline) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_object_wait_many(items, count, deadline);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_object_wait_many);

mx_status_t _mx_futex_wait(mx_futex_t* value_ptr, int current_value, mx_time_t deadline) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_futex_wait(value_ptr, current_value, deadline);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_futex_wait);

mx_status_t _mx_waitset_wait(mx_handle_t waitset_handle, mx_time_t deadline, mx_waitset_result_t* results, uint32_t* count) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_waitset_wait(waitset_handle, deadline, results, count);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_waitset_wait);

mx_status_t _mx_port_wait(mx_handle_t handle, mx_time_t deadline, void* packet, size_t size) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_port_wait(handle, deadline, packet, size);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_port_wait);

mx_status_t _mx_interrupt_wait(mx_handle_t handle) {
    mx_status_t ret;
    do {
        ret = SYSCALL_mx_interrupt_wait(handle);
    } while (unlikely(ret == MX_ERR_INTERRUPTED_RETRY));
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_interrupt_wait);

mx_status_t _mx_syscall_test_wrapper(int a, int b, int c) {
    mx_status_t ret;
    if (a < 0 || b < 0 || c < 0) return MX_ERR_INVALID_ARGS;
        ret = SYSCALL_mx_syscall_test_wrapper(a, b, c);
    if (ret > 50) return MX_ERR_OUT_OF_RANGE;
    return ret;
}

VDSO_INTERFACE_FUNCTION(mx_syscall_test_wrapper);


