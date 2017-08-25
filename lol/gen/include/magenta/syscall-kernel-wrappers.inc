// Copyright 2017 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //magenta/system/host/sysgen.
// The license governing this file can be found in the LICENSE file.

extern "C" {
#if ARCH_X86_64
x86_64_syscall_result wrapper_time_get(uint32_t clock_id, uint64_t ip) {
    return do_syscall(MX_SYS_time_get, ip, &VDso::ValidSyscallPC::time_get, [&]() {
        return static_cast<uint64_t>(sys_time_get(clock_id));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_nanosleep(mx_time_t deadline, uint64_t ip) {
    return do_syscall(MX_SYS_nanosleep, ip, &VDso::ValidSyscallPC::nanosleep, [&]() {
        return static_cast<uint64_t>(sys_nanosleep(deadline));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_handle_close(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_handle_close, ip, &VDso::ValidSyscallPC::handle_close, [&]() {
        return static_cast<uint64_t>(sys_handle_close(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_handle_duplicate(mx_handle_t handle, mx_rights_t rights, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_handle_duplicate, ip, &VDso::ValidSyscallPC::handle_duplicate, [&]() {
        return static_cast<uint64_t>(sys_handle_duplicate(handle, rights, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_handle_replace(mx_handle_t handle, mx_rights_t rights, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_handle_replace, ip, &VDso::ValidSyscallPC::handle_replace, [&]() {
        return static_cast<uint64_t>(sys_handle_replace(handle, rights, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_wait_one(mx_handle_t handle, mx_signals_t waitfor, mx_time_t deadline, mx_signals_t* observed, uint64_t ip) {
    return do_syscall(MX_SYS_object_wait_one, ip, &VDso::ValidSyscallPC::object_wait_one, [&]() {
        return static_cast<uint64_t>(sys_object_wait_one(handle, waitfor, deadline, make_user_ptr(observed)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_wait_many(mx_wait_item_t* items, uint32_t count, mx_time_t deadline, uint64_t ip) {
    return do_syscall(MX_SYS_object_wait_many, ip, &VDso::ValidSyscallPC::object_wait_many, [&]() {
        return static_cast<uint64_t>(sys_object_wait_many(make_user_ptr(items), count, deadline));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_wait_async(mx_handle_t handle, mx_handle_t port_handle, uint64_t key, mx_signals_t signals, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_object_wait_async, ip, &VDso::ValidSyscallPC::object_wait_async, [&]() {
        return static_cast<uint64_t>(sys_object_wait_async(handle, port_handle, key, signals, options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_signal(mx_handle_t handle, uint32_t clear_mask, uint32_t set_mask, uint64_t ip) {
    return do_syscall(MX_SYS_object_signal, ip, &VDso::ValidSyscallPC::object_signal, [&]() {
        return static_cast<uint64_t>(sys_object_signal(handle, clear_mask, set_mask));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_signal_peer(mx_handle_t handle, uint32_t clear_mask, uint32_t set_mask, uint64_t ip) {
    return do_syscall(MX_SYS_object_signal_peer, ip, &VDso::ValidSyscallPC::object_signal_peer, [&]() {
        return static_cast<uint64_t>(sys_object_signal_peer(handle, clear_mask, set_mask));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_get_property(mx_handle_t handle, uint32_t property, void* value, size_t size, uint64_t ip) {
    return do_syscall(MX_SYS_object_get_property, ip, &VDso::ValidSyscallPC::object_get_property, [&]() {
        return static_cast<uint64_t>(sys_object_get_property(handle, property, make_user_ptr(value), size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_set_property(mx_handle_t handle, uint32_t property, const void* value, size_t size, uint64_t ip) {
    return do_syscall(MX_SYS_object_set_property, ip, &VDso::ValidSyscallPC::object_set_property, [&]() {
        return static_cast<uint64_t>(sys_object_set_property(handle, property, make_user_ptr(value), size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_set_cookie(mx_handle_t handle, mx_handle_t scope, uint64_t cookie, uint64_t ip) {
    return do_syscall(MX_SYS_object_set_cookie, ip, &VDso::ValidSyscallPC::object_set_cookie, [&]() {
        return static_cast<uint64_t>(sys_object_set_cookie(handle, scope, cookie));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_get_cookie(mx_handle_t handle, mx_handle_t scope, uint64_t* cookie, uint64_t ip) {
    return do_syscall(MX_SYS_object_get_cookie, ip, &VDso::ValidSyscallPC::object_get_cookie, [&]() {
        return static_cast<uint64_t>(sys_object_get_cookie(handle, scope, make_user_ptr(cookie)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_get_info(mx_handle_t handle, uint32_t topic, void* buffer, size_t buffer_size, size_t* actual_count, size_t* avail_count, uint64_t ip) {
    return do_syscall(MX_SYS_object_get_info, ip, &VDso::ValidSyscallPC::object_get_info, [&]() {
        return static_cast<uint64_t>(sys_object_get_info(handle, topic, make_user_ptr(buffer), buffer_size, make_user_ptr(actual_count), make_user_ptr(avail_count)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_object_get_child(mx_handle_t handle, uint64_t koid, mx_rights_t rights, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_object_get_child, ip, &VDso::ValidSyscallPC::object_get_child, [&]() {
        return static_cast<uint64_t>(sys_object_get_child(handle, koid, rights, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_channel_create(uint32_t options, mx_handle_t* out0, mx_handle_t* out1, uint64_t ip) {
    return do_syscall(MX_SYS_channel_create, ip, &VDso::ValidSyscallPC::channel_create, [&]() {
        return static_cast<uint64_t>(sys_channel_create(options, make_user_ptr(out0), make_user_ptr(out1)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_channel_read(mx_handle_t handle, uint32_t options, void* bytes, mx_handle_t* handles, uint32_t num_bytes, uint32_t num_handles, uint32_t* actual_bytes, uint32_t* actual_handles, uint64_t ip) {
    return do_syscall(MX_SYS_channel_read, ip, &VDso::ValidSyscallPC::channel_read, [&]() {
        return static_cast<uint64_t>(sys_channel_read(handle, options, make_user_ptr(bytes), make_user_ptr(handles), num_bytes, num_handles, make_user_ptr(actual_bytes), make_user_ptr(actual_handles)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_channel_write(mx_handle_t handle, uint32_t options, const void* bytes, uint32_t num_bytes, const mx_handle_t* handles, uint32_t num_handles, uint64_t ip) {
    return do_syscall(MX_SYS_channel_write, ip, &VDso::ValidSyscallPC::channel_write, [&]() {
        return static_cast<uint64_t>(sys_channel_write(handle, options, make_user_ptr(bytes), num_bytes, make_user_ptr(handles), num_handles));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_channel_call_noretry(mx_handle_t handle, uint32_t options, mx_time_t deadline, const mx_channel_call_args_t* args, uint32_t* actual_bytes, uint32_t* actual_handles, mx_status_t* read_status, uint64_t ip) {
    return do_syscall(MX_SYS_channel_call_noretry, ip, &VDso::ValidSyscallPC::channel_call_noretry, [&]() {
        return static_cast<uint64_t>(sys_channel_call_noretry(handle, options, deadline, make_user_ptr(args), make_user_ptr(actual_bytes), make_user_ptr(actual_handles), make_user_ptr(read_status)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_channel_call_finish(mx_handle_t handle, mx_time_t deadline, const mx_channel_call_args_t* args, uint32_t* actual_bytes, uint32_t* actual_handles, mx_status_t* read_status, uint64_t ip) {
    return do_syscall(MX_SYS_channel_call_finish, ip, &VDso::ValidSyscallPC::channel_call_finish, [&]() {
        return static_cast<uint64_t>(sys_channel_call_finish(handle, deadline, make_user_ptr(args), make_user_ptr(actual_bytes), make_user_ptr(actual_handles), make_user_ptr(read_status)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_socket_create(uint32_t options, mx_handle_t* out0, mx_handle_t* out1, uint64_t ip) {
    return do_syscall(MX_SYS_socket_create, ip, &VDso::ValidSyscallPC::socket_create, [&]() {
        return static_cast<uint64_t>(sys_socket_create(options, make_user_ptr(out0), make_user_ptr(out1)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_socket_write(mx_handle_t handle, uint32_t options, const void* buffer, size_t size, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_socket_write, ip, &VDso::ValidSyscallPC::socket_write, [&]() {
        return static_cast<uint64_t>(sys_socket_write(handle, options, make_user_ptr(buffer), size, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_socket_read(mx_handle_t handle, uint32_t options, void* buffer, size_t size, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_socket_read, ip, &VDso::ValidSyscallPC::socket_read, [&]() {
        return static_cast<uint64_t>(sys_socket_read(handle, options, make_user_ptr(buffer), size, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_thread_exit(uint64_t ip) {
    return do_syscall(MX_SYS_thread_exit, ip, &VDso::ValidSyscallPC::thread_exit, [&]() {
        sys_thread_exit(); // __noreturn__
        /* NOTREACHED */
        return MX_ERR_BAD_STATE;
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_thread_create(mx_handle_t process, const char* name, uint32_t name_len, uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_thread_create, ip, &VDso::ValidSyscallPC::thread_create, [&]() {
        return static_cast<uint64_t>(sys_thread_create(process, make_user_ptr(name), name_len, options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_thread_start(mx_handle_t handle, uintptr_t thread_entry, uintptr_t stack, uintptr_t arg1, uintptr_t arg2, uint64_t ip) {
    return do_syscall(MX_SYS_thread_start, ip, &VDso::ValidSyscallPC::thread_start, [&]() {
        return static_cast<uint64_t>(sys_thread_start(handle, thread_entry, stack, arg1, arg2));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_thread_read_state(mx_handle_t handle, uint32_t kind, void* buffer, uint32_t len, uint32_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_thread_read_state, ip, &VDso::ValidSyscallPC::thread_read_state, [&]() {
        return static_cast<uint64_t>(sys_thread_read_state(handle, kind, make_user_ptr(buffer), len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_thread_write_state(mx_handle_t handle, uint32_t kind, const void* buffer, uint32_t buffer_len, uint64_t ip) {
    return do_syscall(MX_SYS_thread_write_state, ip, &VDso::ValidSyscallPC::thread_write_state, [&]() {
        return static_cast<uint64_t>(sys_thread_write_state(handle, kind, make_user_ptr(buffer), buffer_len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_process_exit(int retcode, uint64_t ip) {
    return do_syscall(MX_SYS_process_exit, ip, &VDso::ValidSyscallPC::process_exit, [&]() {
        sys_process_exit(retcode); // __noreturn__
        /* NOTREACHED */
        return MX_ERR_BAD_STATE;
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_process_create(mx_handle_t job, const char* name, uint32_t name_len, uint32_t options, mx_handle_t* proc_handle, mx_handle_t* vmar_handle, uint64_t ip) {
    return do_syscall(MX_SYS_process_create, ip, &VDso::ValidSyscallPC::process_create, [&]() {
        return static_cast<uint64_t>(sys_process_create(job, make_user_ptr(name), name_len, options, make_user_ptr(proc_handle), make_user_ptr(vmar_handle)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_process_start(mx_handle_t process_handle, mx_handle_t thread_handle, uintptr_t entry, uintptr_t stack, mx_handle_t arg_handle, uintptr_t arg2, uint64_t ip) {
    return do_syscall(MX_SYS_process_start, ip, &VDso::ValidSyscallPC::process_start, [&]() {
        return static_cast<uint64_t>(sys_process_start(process_handle, thread_handle, entry, stack, arg_handle, arg2));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_process_read_memory(mx_handle_t proc, uintptr_t vaddr, void* buffer, size_t len, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_process_read_memory, ip, &VDso::ValidSyscallPC::process_read_memory, [&]() {
        return static_cast<uint64_t>(sys_process_read_memory(proc, vaddr, make_user_ptr(buffer), len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_process_write_memory(mx_handle_t proc, uintptr_t vaddr, const void* buffer, size_t len, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_process_write_memory, ip, &VDso::ValidSyscallPC::process_write_memory, [&]() {
        return static_cast<uint64_t>(sys_process_write_memory(proc, vaddr, make_user_ptr(buffer), len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_job_create(mx_handle_t parent_job, uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_job_create, ip, &VDso::ValidSyscallPC::job_create, [&]() {
        return static_cast<uint64_t>(sys_job_create(parent_job, options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_job_set_policy(mx_handle_t job, uint32_t options, uint32_t topic, const void* policy, uint32_t count, uint64_t ip) {
    return do_syscall(MX_SYS_job_set_policy, ip, &VDso::ValidSyscallPC::job_set_policy, [&]() {
        return static_cast<uint64_t>(sys_job_set_policy(job, options, topic, make_user_ptr(policy), count));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_task_bind_exception_port(mx_handle_t object, mx_handle_t eport, uint64_t key, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_task_bind_exception_port, ip, &VDso::ValidSyscallPC::task_bind_exception_port, [&]() {
        return static_cast<uint64_t>(sys_task_bind_exception_port(object, eport, key, options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_task_suspend(mx_handle_t task_handle, uint64_t ip) {
    return do_syscall(MX_SYS_task_suspend, ip, &VDso::ValidSyscallPC::task_suspend, [&]() {
        return static_cast<uint64_t>(sys_task_suspend(task_handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_task_resume(mx_handle_t task_handle, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_task_resume, ip, &VDso::ValidSyscallPC::task_resume, [&]() {
        return static_cast<uint64_t>(sys_task_resume(task_handle, options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_task_kill(mx_handle_t task_handle, uint64_t ip) {
    return do_syscall(MX_SYS_task_kill, ip, &VDso::ValidSyscallPC::task_kill, [&]() {
        return static_cast<uint64_t>(sys_task_kill(task_handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_event_create(uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_event_create, ip, &VDso::ValidSyscallPC::event_create, [&]() {
        return static_cast<uint64_t>(sys_event_create(options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_eventpair_create(uint32_t options, mx_handle_t* out0, mx_handle_t* out1, uint64_t ip) {
    return do_syscall(MX_SYS_eventpair_create, ip, &VDso::ValidSyscallPC::eventpair_create, [&]() {
        return static_cast<uint64_t>(sys_eventpair_create(options, make_user_ptr(out0), make_user_ptr(out1)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_futex_wait(mx_futex_t* value_ptr, int current_value, mx_time_t deadline, uint64_t ip) {
    return do_syscall(MX_SYS_futex_wait, ip, &VDso::ValidSyscallPC::futex_wait, [&]() {
        return static_cast<uint64_t>(sys_futex_wait(make_user_ptr(value_ptr), current_value, deadline));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_futex_wake(const mx_futex_t* value_ptr, uint32_t count, uint64_t ip) {
    return do_syscall(MX_SYS_futex_wake, ip, &VDso::ValidSyscallPC::futex_wake, [&]() {
        return static_cast<uint64_t>(sys_futex_wake(make_user_ptr(value_ptr), count));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_futex_requeue(mx_futex_t* wake_ptr, uint32_t wake_count, int current_value, mx_futex_t* requeue_ptr, uint32_t requeue_count, uint64_t ip) {
    return do_syscall(MX_SYS_futex_requeue, ip, &VDso::ValidSyscallPC::futex_requeue, [&]() {
        return static_cast<uint64_t>(sys_futex_requeue(make_user_ptr(wake_ptr), wake_count, current_value, make_user_ptr(requeue_ptr), requeue_count));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_waitset_create(uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_waitset_create, ip, &VDso::ValidSyscallPC::waitset_create, [&]() {
        return static_cast<uint64_t>(sys_waitset_create(options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_waitset_add(mx_handle_t waitset_handle, uint64_t cookie, mx_handle_t handle, mx_signals_t signals, uint64_t ip) {
    return do_syscall(MX_SYS_waitset_add, ip, &VDso::ValidSyscallPC::waitset_add, [&]() {
        return static_cast<uint64_t>(sys_waitset_add(waitset_handle, cookie, handle, signals));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_waitset_remove(mx_handle_t waitset_handle, uint64_t cookie, uint64_t ip) {
    return do_syscall(MX_SYS_waitset_remove, ip, &VDso::ValidSyscallPC::waitset_remove, [&]() {
        return static_cast<uint64_t>(sys_waitset_remove(waitset_handle, cookie));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_waitset_wait(mx_handle_t waitset_handle, mx_time_t deadline, mx_waitset_result_t* results, uint32_t* count, uint64_t ip) {
    return do_syscall(MX_SYS_waitset_wait, ip, &VDso::ValidSyscallPC::waitset_wait, [&]() {
        return static_cast<uint64_t>(sys_waitset_wait(waitset_handle, deadline, make_user_ptr(results), make_user_ptr(count)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_port_create(uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_port_create, ip, &VDso::ValidSyscallPC::port_create, [&]() {
        return static_cast<uint64_t>(sys_port_create(options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_port_queue(mx_handle_t handle, const void* packet, size_t size, uint64_t ip) {
    return do_syscall(MX_SYS_port_queue, ip, &VDso::ValidSyscallPC::port_queue, [&]() {
        return static_cast<uint64_t>(sys_port_queue(handle, make_user_ptr(packet), size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_port_wait(mx_handle_t handle, mx_time_t deadline, void* packet, size_t size, uint64_t ip) {
    return do_syscall(MX_SYS_port_wait, ip, &VDso::ValidSyscallPC::port_wait, [&]() {
        return static_cast<uint64_t>(sys_port_wait(handle, deadline, make_user_ptr(packet), size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_port_cancel(mx_handle_t handle, mx_handle_t source, uint64_t key, uint64_t ip) {
    return do_syscall(MX_SYS_port_cancel, ip, &VDso::ValidSyscallPC::port_cancel, [&]() {
        return static_cast<uint64_t>(sys_port_cancel(handle, source, key));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_timer_create(uint32_t options, uint32_t clock_id, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_timer_create, ip, &VDso::ValidSyscallPC::timer_create, [&]() {
        return static_cast<uint64_t>(sys_timer_create(options, clock_id, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_timer_start(mx_handle_t handle, mx_time_t deadline, mx_duration_t period, mx_duration_t slack, uint64_t ip) {
    return do_syscall(MX_SYS_timer_start, ip, &VDso::ValidSyscallPC::timer_start, [&]() {
        return static_cast<uint64_t>(sys_timer_start(handle, deadline, period, slack));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_timer_cancel(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_timer_cancel, ip, &VDso::ValidSyscallPC::timer_cancel, [&]() {
        return static_cast<uint64_t>(sys_timer_cancel(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_create(uint64_t size, uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_create, ip, &VDso::ValidSyscallPC::vmo_create, [&]() {
        return static_cast<uint64_t>(sys_vmo_create(size, options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_read(mx_handle_t handle, void* data, uint64_t offset, size_t len, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_read, ip, &VDso::ValidSyscallPC::vmo_read, [&]() {
        return static_cast<uint64_t>(sys_vmo_read(handle, make_user_ptr(data), offset, len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_write(mx_handle_t handle, const void* data, uint64_t offset, size_t len, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_write, ip, &VDso::ValidSyscallPC::vmo_write, [&]() {
        return static_cast<uint64_t>(sys_vmo_write(handle, make_user_ptr(data), offset, len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_get_size(mx_handle_t handle, uint64_t* size, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_get_size, ip, &VDso::ValidSyscallPC::vmo_get_size, [&]() {
        return static_cast<uint64_t>(sys_vmo_get_size(handle, make_user_ptr(size)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_set_size(mx_handle_t handle, uint64_t size, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_set_size, ip, &VDso::ValidSyscallPC::vmo_set_size, [&]() {
        return static_cast<uint64_t>(sys_vmo_set_size(handle, size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_op_range(mx_handle_t handle, uint32_t op, uint64_t offset, uint64_t size, void* buffer, size_t buffer_size, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_op_range, ip, &VDso::ValidSyscallPC::vmo_op_range, [&]() {
        return static_cast<uint64_t>(sys_vmo_op_range(handle, op, offset, size, make_user_ptr(buffer), buffer_size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_clone(mx_handle_t handle, uint32_t options, uint64_t offset, uint64_t size, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_clone, ip, &VDso::ValidSyscallPC::vmo_clone, [&]() {
        return static_cast<uint64_t>(sys_vmo_clone(handle, options, offset, size, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_set_cache_policy(mx_handle_t handle, uint32_t cache_policy, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_set_cache_policy, ip, &VDso::ValidSyscallPC::vmo_set_cache_policy, [&]() {
        return static_cast<uint64_t>(sys_vmo_set_cache_policy(handle, cache_policy));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmar_allocate(mx_handle_t parent_vmar_handle, size_t offset, size_t size, uint32_t map_flags, mx_handle_t* child_vmar, uintptr_t* child_addr, uint64_t ip) {
    return do_syscall(MX_SYS_vmar_allocate, ip, &VDso::ValidSyscallPC::vmar_allocate, [&]() {
        return static_cast<uint64_t>(sys_vmar_allocate(parent_vmar_handle, offset, size, map_flags, make_user_ptr(child_vmar), make_user_ptr(child_addr)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmar_destroy(mx_handle_t vmar_handle, uint64_t ip) {
    return do_syscall(MX_SYS_vmar_destroy, ip, &VDso::ValidSyscallPC::vmar_destroy, [&]() {
        return static_cast<uint64_t>(sys_vmar_destroy(vmar_handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmar_map(mx_handle_t vmar_handle, size_t vmar_offset, mx_handle_t vmo_handle, uint64_t vmo_offset, size_t len, uint32_t map_flags, uintptr_t* mapped_addr, uint64_t ip) {
    return do_syscall(MX_SYS_vmar_map, ip, &VDso::ValidSyscallPC::vmar_map, [&]() {
        return static_cast<uint64_t>(sys_vmar_map(vmar_handle, vmar_offset, vmo_handle, vmo_offset, len, map_flags, make_user_ptr(mapped_addr)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmar_unmap(mx_handle_t vmar_handle, uintptr_t addr, size_t len, uint64_t ip) {
    return do_syscall(MX_SYS_vmar_unmap, ip, &VDso::ValidSyscallPC::vmar_unmap, [&]() {
        return static_cast<uint64_t>(sys_vmar_unmap(vmar_handle, addr, len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmar_protect(mx_handle_t vmar_handle, uintptr_t addr, size_t len, uint32_t prot_flags, uint64_t ip) {
    return do_syscall(MX_SYS_vmar_protect, ip, &VDso::ValidSyscallPC::vmar_protect, [&]() {
        return static_cast<uint64_t>(sys_vmar_protect(vmar_handle, addr, len, prot_flags));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_cprng_draw(void* buffer, size_t len, size_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_cprng_draw, ip, &VDso::ValidSyscallPC::cprng_draw, [&]() {
        return static_cast<uint64_t>(sys_cprng_draw(make_user_ptr(buffer), len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_cprng_add_entropy(const void* buffer, size_t len, uint64_t ip) {
    return do_syscall(MX_SYS_cprng_add_entropy, ip, &VDso::ValidSyscallPC::cprng_add_entropy, [&]() {
        return static_cast<uint64_t>(sys_cprng_add_entropy(make_user_ptr(buffer), len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_fifo_create(uint32_t elem_count, uint32_t elem_size, uint32_t options, mx_handle_t* out0, mx_handle_t* out1, uint64_t ip) {
    return do_syscall(MX_SYS_fifo_create, ip, &VDso::ValidSyscallPC::fifo_create, [&]() {
        return static_cast<uint64_t>(sys_fifo_create(elem_count, elem_size, options, make_user_ptr(out0), make_user_ptr(out1)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_fifo_read(mx_handle_t handle, void* data, size_t len, uint32_t* num_written, uint64_t ip) {
    return do_syscall(MX_SYS_fifo_read, ip, &VDso::ValidSyscallPC::fifo_read, [&]() {
        return static_cast<uint64_t>(sys_fifo_read(handle, make_user_ptr(data), len, make_user_ptr(num_written)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_fifo_write(mx_handle_t handle, const void* data, size_t len, uint32_t* num_written, uint64_t ip) {
    return do_syscall(MX_SYS_fifo_write, ip, &VDso::ValidSyscallPC::fifo_write, [&]() {
        return static_cast<uint64_t>(sys_fifo_write(handle, make_user_ptr(data), len, make_user_ptr(num_written)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_log_create(uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_log_create, ip, &VDso::ValidSyscallPC::log_create, [&]() {
        return static_cast<uint64_t>(sys_log_create(options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_log_write(mx_handle_t handle, uint32_t len, const void* buffer, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_log_write, ip, &VDso::ValidSyscallPC::log_write, [&]() {
        return static_cast<uint64_t>(sys_log_write(handle, len, make_user_ptr(buffer), options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_log_read(mx_handle_t handle, uint32_t len, void* buffer, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_log_read, ip, &VDso::ValidSyscallPC::log_read, [&]() {
        return static_cast<uint64_t>(sys_log_read(handle, len, make_user_ptr(buffer), options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_ktrace_read(mx_handle_t handle, void* data, uint32_t offset, uint32_t len, uint32_t* actual, uint64_t ip) {
    return do_syscall(MX_SYS_ktrace_read, ip, &VDso::ValidSyscallPC::ktrace_read, [&]() {
        return static_cast<uint64_t>(sys_ktrace_read(handle, make_user_ptr(data), offset, len, make_user_ptr(actual)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_ktrace_control(mx_handle_t handle, uint32_t action, uint32_t options, void* ptr, uint64_t ip) {
    return do_syscall(MX_SYS_ktrace_control, ip, &VDso::ValidSyscallPC::ktrace_control, [&]() {
        return static_cast<uint64_t>(sys_ktrace_control(handle, action, options, make_user_ptr(ptr)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_ktrace_write(mx_handle_t handle, uint32_t id, uint32_t arg0, uint32_t arg1, uint64_t ip) {
    return do_syscall(MX_SYS_ktrace_write, ip, &VDso::ValidSyscallPC::ktrace_write, [&]() {
        return static_cast<uint64_t>(sys_ktrace_write(handle, id, arg0, arg1));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_mtrace_control(mx_handle_t handle, uint32_t kind, uint32_t action, uint32_t options, void* ptr, uint32_t size, uint64_t ip) {
    return do_syscall(MX_SYS_mtrace_control, ip, &VDso::ValidSyscallPC::mtrace_control, [&]() {
        return static_cast<uint64_t>(sys_mtrace_control(handle, kind, action, options, ptr, size));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_debug_transfer_handle(mx_handle_t proc, mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_debug_transfer_handle, ip, &VDso::ValidSyscallPC::debug_transfer_handle, [&]() {
        return static_cast<uint64_t>(sys_debug_transfer_handle(proc, handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_debug_read(mx_handle_t handle, void* buffer, uint32_t length, uint64_t ip) {
    return do_syscall(MX_SYS_debug_read, ip, &VDso::ValidSyscallPC::debug_read, [&]() {
        return static_cast<uint64_t>(sys_debug_read(handle, buffer, length));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_debug_write(const void* buffer, uint32_t length, uint64_t ip) {
    return do_syscall(MX_SYS_debug_write, ip, &VDso::ValidSyscallPC::debug_write, [&]() {
        return static_cast<uint64_t>(sys_debug_write(buffer, length));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_debug_send_command(mx_handle_t resource_handle, const void* buffer, uint32_t length, uint64_t ip) {
    return do_syscall(MX_SYS_debug_send_command, ip, &VDso::ValidSyscallPC::debug_send_command, [&]() {
        return static_cast<uint64_t>(sys_debug_send_command(resource_handle, buffer, length));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_interrupt_create(mx_handle_t handle, uint32_t vector, uint32_t options, uint64_t ip) {
    return do_syscall(MX_SYS_interrupt_create, ip, &VDso::ValidSyscallPC::interrupt_create, [&]() {
        return static_cast<uint64_t>(sys_interrupt_create(handle, vector, options));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_interrupt_complete(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_interrupt_complete, ip, &VDso::ValidSyscallPC::interrupt_complete, [&]() {
        return static_cast<uint64_t>(sys_interrupt_complete(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_interrupt_wait(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_interrupt_wait, ip, &VDso::ValidSyscallPC::interrupt_wait, [&]() {
        return static_cast<uint64_t>(sys_interrupt_wait(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_interrupt_signal(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_interrupt_signal, ip, &VDso::ValidSyscallPC::interrupt_signal, [&]() {
        return static_cast<uint64_t>(sys_interrupt_signal(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_mmap_device_io(mx_handle_t handle, uint32_t io_addr, uint32_t len, uint64_t ip) {
    return do_syscall(MX_SYS_mmap_device_io, ip, &VDso::ValidSyscallPC::mmap_device_io, [&]() {
        return static_cast<uint64_t>(sys_mmap_device_io(handle, io_addr, len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_mmap_device_memory(mx_handle_t handle, mx_paddr_t paddr, uint32_t len, mx_cache_policy_t cache_policy, uintptr_t* out_vaddr, uint64_t ip) {
    return do_syscall(MX_SYS_mmap_device_memory, ip, &VDso::ValidSyscallPC::mmap_device_memory, [&]() {
        return static_cast<uint64_t>(sys_mmap_device_memory(handle, paddr, len, cache_policy, make_user_ptr(out_vaddr)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_io_mapping_get_info(mx_handle_t handle, uintptr_t* out_vaddr, uint64_t* out_size, uint64_t ip) {
    return do_syscall(MX_SYS_io_mapping_get_info, ip, &VDso::ValidSyscallPC::io_mapping_get_info, [&]() {
        return static_cast<uint64_t>(sys_io_mapping_get_info(handle, make_user_ptr(out_vaddr), make_user_ptr(out_size)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_vmo_create_contiguous(mx_handle_t rsrc_handle, size_t size, uint32_t alignment_log2, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_vmo_create_contiguous, ip, &VDso::ValidSyscallPC::vmo_create_contiguous, [&]() {
        return static_cast<uint64_t>(sys_vmo_create_contiguous(rsrc_handle, size, alignment_log2, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_bootloader_fb_get_info(uint32_t* format, uint32_t* width, uint32_t* height, uint32_t* stride, uint64_t ip) {
    return do_syscall(MX_SYS_bootloader_fb_get_info, ip, &VDso::ValidSyscallPC::bootloader_fb_get_info, [&]() {
        return static_cast<uint64_t>(sys_bootloader_fb_get_info(make_user_ptr(format), make_user_ptr(width), make_user_ptr(height), make_user_ptr(stride)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_set_framebuffer(mx_handle_t handle, void* vaddr, uint32_t len, uint32_t format, uint32_t width, uint32_t height, uint32_t stride, uint64_t ip) {
    return do_syscall(MX_SYS_set_framebuffer, ip, &VDso::ValidSyscallPC::set_framebuffer, [&]() {
        return static_cast<uint64_t>(sys_set_framebuffer(handle, make_user_ptr(vaddr), len, format, width, height, stride));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_set_framebuffer_vmo(mx_handle_t handle, mx_handle_t vmo, uint32_t len, uint32_t format, uint32_t width, uint32_t height, uint32_t stride, uint64_t ip) {
    return do_syscall(MX_SYS_set_framebuffer_vmo, ip, &VDso::ValidSyscallPC::set_framebuffer_vmo, [&]() {
        return static_cast<uint64_t>(sys_set_framebuffer_vmo(handle, vmo, len, format, width, height, stride));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_clock_adjust(mx_handle_t handle, uint32_t clock_id, int64_t offset, uint64_t ip) {
    return do_syscall(MX_SYS_clock_adjust, ip, &VDso::ValidSyscallPC::clock_adjust, [&]() {
        return static_cast<uint64_t>(sys_clock_adjust(handle, clock_id, offset));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_get_nth_device(mx_handle_t handle, uint32_t index, mx_pcie_device_info_t* out_info, uint64_t ip) {
    return do_syscall(MX_SYS_pci_get_nth_device, ip, &VDso::ValidSyscallPC::pci_get_nth_device, [&]() {
        return static_cast<uint64_t>(sys_pci_get_nth_device(handle, index, make_user_ptr(out_info)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_claim_device(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_pci_claim_device, ip, &VDso::ValidSyscallPC::pci_claim_device, [&]() {
        return static_cast<uint64_t>(sys_pci_claim_device(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_enable_bus_master(mx_handle_t handle, bool enable, uint64_t ip) {
    return do_syscall(MX_SYS_pci_enable_bus_master, ip, &VDso::ValidSyscallPC::pci_enable_bus_master, [&]() {
        return static_cast<uint64_t>(sys_pci_enable_bus_master(handle, enable));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_enable_pio(mx_handle_t handle, bool enable, uint64_t ip) {
    return do_syscall(MX_SYS_pci_enable_pio, ip, &VDso::ValidSyscallPC::pci_enable_pio, [&]() {
        return static_cast<uint64_t>(sys_pci_enable_pio(handle, enable));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_reset_device(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_pci_reset_device, ip, &VDso::ValidSyscallPC::pci_reset_device, [&]() {
        return static_cast<uint64_t>(sys_pci_reset_device(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_get_bar(mx_handle_t handle, uint32_t bar_num, mx_pci_resource_t* out_bar, uint64_t ip) {
    return do_syscall(MX_SYS_pci_get_bar, ip, &VDso::ValidSyscallPC::pci_get_bar, [&]() {
        return static_cast<uint64_t>(sys_pci_get_bar(handle, bar_num, make_user_ptr(out_bar)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_get_config(mx_handle_t handle, mx_pci_resource_t* out_config, uint64_t ip) {
    return do_syscall(MX_SYS_pci_get_config, ip, &VDso::ValidSyscallPC::pci_get_config, [&]() {
        return static_cast<uint64_t>(sys_pci_get_config(handle, make_user_ptr(out_config)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_io_write(mx_handle_t handle, uint32_t bar_num, uint32_t offset, uint32_t len, uint32_t value, uint64_t ip) {
    return do_syscall(MX_SYS_pci_io_write, ip, &VDso::ValidSyscallPC::pci_io_write, [&]() {
        return static_cast<uint64_t>(sys_pci_io_write(handle, bar_num, offset, len, value));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_io_read(mx_handle_t handle, uint32_t bar_num, uint32_t offset, uint32_t len, uint32_t* out_value, uint64_t ip) {
    return do_syscall(MX_SYS_pci_io_read, ip, &VDso::ValidSyscallPC::pci_io_read, [&]() {
        return static_cast<uint64_t>(sys_pci_io_read(handle, bar_num, offset, len, make_user_ptr(out_value)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_map_interrupt(mx_handle_t handle, int32_t which_irq, mx_handle_t* out_handle, uint64_t ip) {
    return do_syscall(MX_SYS_pci_map_interrupt, ip, &VDso::ValidSyscallPC::pci_map_interrupt, [&]() {
        return static_cast<uint64_t>(sys_pci_map_interrupt(handle, which_irq, make_user_ptr(out_handle)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_query_irq_mode_caps(mx_handle_t handle, uint32_t mode, uint32_t* out_max_irqs, uint64_t ip) {
    return do_syscall(MX_SYS_pci_query_irq_mode_caps, ip, &VDso::ValidSyscallPC::pci_query_irq_mode_caps, [&]() {
        return static_cast<uint64_t>(sys_pci_query_irq_mode_caps(handle, mode, make_user_ptr(out_max_irqs)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_set_irq_mode(mx_handle_t handle, uint32_t mode, uint32_t requested_irq_count, uint64_t ip) {
    return do_syscall(MX_SYS_pci_set_irq_mode, ip, &VDso::ValidSyscallPC::pci_set_irq_mode, [&]() {
        return static_cast<uint64_t>(sys_pci_set_irq_mode(handle, mode, requested_irq_count));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_init(mx_handle_t handle, const mx_pci_init_arg_t* init_buf, uint32_t len, uint64_t ip) {
    return do_syscall(MX_SYS_pci_init, ip, &VDso::ValidSyscallPC::pci_init, [&]() {
        return static_cast<uint64_t>(sys_pci_init(handle, make_user_ptr(init_buf), len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_pci_add_subtract_io_range(mx_handle_t handle, bool mmio, uint64_t base, uint64_t len, bool add, uint64_t ip) {
    return do_syscall(MX_SYS_pci_add_subtract_io_range, ip, &VDso::ValidSyscallPC::pci_add_subtract_io_range, [&]() {
        return static_cast<uint64_t>(sys_pci_add_subtract_io_range(handle, mmio, base, len, add));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_acpi_uefi_rsdp(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_acpi_uefi_rsdp, ip, &VDso::ValidSyscallPC::acpi_uefi_rsdp, [&]() {
        return static_cast<uint64_t>(sys_acpi_uefi_rsdp(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_acpi_cache_flush(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_acpi_cache_flush, ip, &VDso::ValidSyscallPC::acpi_cache_flush, [&]() {
        return static_cast<uint64_t>(sys_acpi_cache_flush(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_create(mx_handle_t parent_handle, const mx_rrec_t* records, uint32_t count, mx_handle_t* resource_out, uint64_t ip) {
    return do_syscall(MX_SYS_resource_create, ip, &VDso::ValidSyscallPC::resource_create, [&]() {
        return static_cast<uint64_t>(sys_resource_create(parent_handle, make_user_ptr(records), count, make_user_ptr(resource_out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_destroy(mx_handle_t handle, uint64_t ip) {
    return do_syscall(MX_SYS_resource_destroy, ip, &VDso::ValidSyscallPC::resource_destroy, [&]() {
        return static_cast<uint64_t>(sys_resource_destroy(handle));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_get_handle(mx_handle_t handle, uint32_t index, uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_resource_get_handle, ip, &VDso::ValidSyscallPC::resource_get_handle, [&]() {
        return static_cast<uint64_t>(sys_resource_get_handle(handle, index, options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_do_action(mx_handle_t handle, uint32_t index, uint32_t action, uint32_t arg0, uint32_t arg1, uint64_t ip) {
    return do_syscall(MX_SYS_resource_do_action, ip, &VDso::ValidSyscallPC::resource_do_action, [&]() {
        return static_cast<uint64_t>(sys_resource_do_action(handle, index, action, arg0, arg1));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_connect(mx_handle_t handle, mx_handle_t channel, uint64_t ip) {
    return do_syscall(MX_SYS_resource_connect, ip, &VDso::ValidSyscallPC::resource_connect, [&]() {
        return static_cast<uint64_t>(sys_resource_connect(handle, channel));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_resource_accept(mx_handle_t handle, mx_handle_t* channel, uint64_t ip) {
    return do_syscall(MX_SYS_resource_accept, ip, &VDso::ValidSyscallPC::resource_accept, [&]() {
        return static_cast<uint64_t>(sys_resource_accept(handle, make_user_ptr(channel)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_hypervisor_create(mx_handle_t handle, uint32_t options, mx_handle_t* out, uint64_t ip) {
    return do_syscall(MX_SYS_hypervisor_create, ip, &VDso::ValidSyscallPC::hypervisor_create, [&]() {
        return static_cast<uint64_t>(sys_hypervisor_create(handle, options, make_user_ptr(out)));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_hypervisor_op(mx_handle_t handle, uint32_t opcode, const void* args, uint32_t args_len, void* result, uint32_t result_len, uint64_t ip) {
    return do_syscall(MX_SYS_hypervisor_op, ip, &VDso::ValidSyscallPC::hypervisor_op, [&]() {
        return static_cast<uint64_t>(sys_hypervisor_op(handle, opcode, make_user_ptr(args), args_len, make_user_ptr(result), result_len));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_system_mexec(mx_handle_t kernel, mx_handle_t bootimage, uint64_t ip) {
    return do_syscall(MX_SYS_system_mexec, ip, &VDso::ValidSyscallPC::system_mexec, [&]() {
        return static_cast<uint64_t>(sys_system_mexec(kernel, bootimage));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_0(uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_0, ip, &VDso::ValidSyscallPC::syscall_test_0, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_0());
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_1(int a, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_1, ip, &VDso::ValidSyscallPC::syscall_test_1, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_1(a));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_2(int a, int b, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_2, ip, &VDso::ValidSyscallPC::syscall_test_2, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_2(a, b));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_3(int a, int b, int c, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_3, ip, &VDso::ValidSyscallPC::syscall_test_3, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_3(a, b, c));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_4(int a, int b, int c, int d, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_4, ip, &VDso::ValidSyscallPC::syscall_test_4, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_4(a, b, c, d));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_5(int a, int b, int c, int d, int e, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_5, ip, &VDso::ValidSyscallPC::syscall_test_5, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_5(a, b, c, d, e));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_6(int a, int b, int c, int d, int e, int f, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_6, ip, &VDso::ValidSyscallPC::syscall_test_6, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_6(a, b, c, d, e, f));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_7(int a, int b, int c, int d, int e, int f, int g, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_7, ip, &VDso::ValidSyscallPC::syscall_test_7, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_7(a, b, c, d, e, f, g));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_8(int a, int b, int c, int d, int e, int f, int g, int h, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_8, ip, &VDso::ValidSyscallPC::syscall_test_8, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_8(a, b, c, d, e, f, g, h));
    });
}
#endif
#if ARCH_X86_64
x86_64_syscall_result wrapper_syscall_test_wrapper(int a, int b, int c, uint64_t ip) {
    return do_syscall(MX_SYS_syscall_test_wrapper, ip, &VDso::ValidSyscallPC::syscall_test_wrapper, [&]() {
        return static_cast<uint64_t>(sys_syscall_test_wrapper(a, b, c));
    });
}
#endif
}
