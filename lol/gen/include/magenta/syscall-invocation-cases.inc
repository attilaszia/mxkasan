// Copyright 2017 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //magenta/system/host/sysgen.
// The license governing this file can be found in the LICENSE file.

    case 0: {
        CHECK_SYSCALL_PC(time_get);
        ret = static_cast<uint64_t>(sys_time_get(
                static_cast<uint32_t>(arg1)));
        break;
    }
    case 1: {
        CHECK_SYSCALL_PC(nanosleep);
        ret = static_cast<uint64_t>(sys_nanosleep(
                static_cast<mx_time_t>(arg1)));
        break;
    }
    case 2: {
        CHECK_SYSCALL_PC(handle_close);
        ret = static_cast<uint64_t>(sys_handle_close(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 3: {
        CHECK_SYSCALL_PC(handle_duplicate);
        ret = static_cast<uint64_t>(sys_handle_duplicate(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_rights_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 4: {
        CHECK_SYSCALL_PC(handle_replace);
        ret = static_cast<uint64_t>(sys_handle_replace(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_rights_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 5: {
        CHECK_SYSCALL_PC(object_wait_one);
        ret = static_cast<uint64_t>(sys_object_wait_one(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_signals_t>(arg2),
                static_cast<mx_time_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_signals_t*>(arg4))));
        break;
    }
    case 6: {
        CHECK_SYSCALL_PC(object_wait_many);
        ret = static_cast<uint64_t>(sys_object_wait_many(
                make_user_ptr(reinterpret_cast<mx_wait_item_t*>(arg1)),
                static_cast<uint32_t>(arg2),
                static_cast<mx_time_t>(arg3)));
        break;
    }
    case 7: {
        CHECK_SYSCALL_PC(object_wait_async);
        ret = static_cast<uint64_t>(sys_object_wait_async(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uint64_t>(arg3),
                static_cast<mx_signals_t>(arg4),
                static_cast<uint32_t>(arg5)));
        break;
    }
    case 8: {
        CHECK_SYSCALL_PC(object_signal);
        ret = static_cast<uint64_t>(sys_object_signal(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 9: {
        CHECK_SYSCALL_PC(object_signal_peer);
        ret = static_cast<uint64_t>(sys_object_signal_peer(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 10: {
        CHECK_SYSCALL_PC(object_get_property);
        ret = static_cast<uint64_t>(sys_object_get_property(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<size_t>(arg4)));
        break;
    }
    case 11: {
        CHECK_SYSCALL_PC(object_set_property);
        ret = static_cast<uint64_t>(sys_object_set_property(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<size_t>(arg4)));
        break;
    }
    case 12: {
        CHECK_SYSCALL_PC(object_set_cookie);
        ret = static_cast<uint64_t>(sys_object_set_cookie(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uint64_t>(arg3)));
        break;
    }
    case 13: {
        CHECK_SYSCALL_PC(object_get_cookie);
        ret = static_cast<uint64_t>(sys_object_get_cookie(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                make_user_ptr(reinterpret_cast<uint64_t*>(arg3))));
        break;
    }
    case 14: {
        CHECK_SYSCALL_PC(object_get_info);
        ret = static_cast<uint64_t>(sys_object_get_info(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5)),
                make_user_ptr(reinterpret_cast<size_t*>(arg6))));
        break;
    }
    case 15: {
        CHECK_SYSCALL_PC(object_get_child);
        ret = static_cast<uint64_t>(sys_object_get_child(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint64_t>(arg2),
                static_cast<mx_rights_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4))));
        break;
    }
    case 16: {
        CHECK_SYSCALL_PC(channel_create);
        ret = static_cast<uint64_t>(sys_channel_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 17: {
        CHECK_SYSCALL_PC(channel_read);
        ret = static_cast<uint64_t>(sys_channel_read(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4)),
                static_cast<uint32_t>(arg5),
                static_cast<uint32_t>(arg6),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg7)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg8))));
        break;
    }
    case 18: {
        CHECK_SYSCALL_PC(channel_write);
        ret = static_cast<uint64_t>(sys_channel_write(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<const mx_handle_t*>(arg5)),
                static_cast<uint32_t>(arg6)));
        break;
    }
    case 19: {
        CHECK_SYSCALL_PC(channel_call_noretry);
        ret = static_cast<uint64_t>(sys_channel_call_noretry(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<mx_time_t>(arg3),
                make_user_ptr(reinterpret_cast<const mx_channel_call_args_t*>(arg4)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg5)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg6)),
                make_user_ptr(reinterpret_cast<mx_status_t*>(arg7))));
        break;
    }
    case 20: {
        CHECK_SYSCALL_PC(channel_call_finish);
        ret = static_cast<uint64_t>(sys_channel_call_finish(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_time_t>(arg2),
                make_user_ptr(reinterpret_cast<const mx_channel_call_args_t*>(arg3)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg4)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg5)),
                make_user_ptr(reinterpret_cast<mx_status_t*>(arg6))));
        break;
    }
    case 21: {
        CHECK_SYSCALL_PC(socket_create);
        ret = static_cast<uint64_t>(sys_socket_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 22: {
        CHECK_SYSCALL_PC(socket_write);
        ret = static_cast<uint64_t>(sys_socket_write(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 23: {
        CHECK_SYSCALL_PC(socket_read);
        ret = static_cast<uint64_t>(sys_socket_read(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 24: {
        CHECK_SYSCALL_PC(thread_exit);
        sys_thread_exit(); // __noreturn__
    }
    case 25: {
        CHECK_SYSCALL_PC(thread_create);
        ret = static_cast<uint64_t>(sys_thread_create(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const char*>(arg2)),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg5))));
        break;
    }
    case 26: {
        CHECK_SYSCALL_PC(thread_start);
        ret = static_cast<uint64_t>(sys_thread_start(
                static_cast<mx_handle_t>(arg1),
                static_cast<uintptr_t>(arg2),
                static_cast<uintptr_t>(arg3),
                static_cast<uintptr_t>(arg4),
                static_cast<uintptr_t>(arg5)));
        break;
    }
    case 27: {
        CHECK_SYSCALL_PC(thread_read_state);
        ret = static_cast<uint64_t>(sys_thread_read_state(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg5))));
        break;
    }
    case 28: {
        CHECK_SYSCALL_PC(thread_write_state);
        ret = static_cast<uint64_t>(sys_thread_write_state(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 29: {
        CHECK_SYSCALL_PC(process_exit);
        sys_process_exit(
                static_cast<int>(arg1)); // __noreturn__
    }
    case 30: {
        CHECK_SYSCALL_PC(process_create);
        ret = static_cast<uint64_t>(sys_process_create(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const char*>(arg2)),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg5)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg6))));
        break;
    }
    case 31: {
        CHECK_SYSCALL_PC(process_start);
        ret = static_cast<uint64_t>(sys_process_start(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uintptr_t>(arg3),
                static_cast<uintptr_t>(arg4),
                static_cast<mx_handle_t>(arg5),
                static_cast<uintptr_t>(arg6)));
        break;
    }
    case 32: {
        CHECK_SYSCALL_PC(process_read_memory);
        ret = static_cast<uint64_t>(sys_process_read_memory(
                static_cast<mx_handle_t>(arg1),
                static_cast<uintptr_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 33: {
        CHECK_SYSCALL_PC(process_write_memory);
        ret = static_cast<uint64_t>(sys_process_write_memory(
                static_cast<mx_handle_t>(arg1),
                static_cast<uintptr_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 34: {
        CHECK_SYSCALL_PC(job_create);
        ret = static_cast<uint64_t>(sys_job_create(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 35: {
        CHECK_SYSCALL_PC(job_set_policy);
        ret = static_cast<uint64_t>(sys_job_set_policy(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<const void*>(arg4)),
                static_cast<uint32_t>(arg5)));
        break;
    }
    case 36: {
        CHECK_SYSCALL_PC(task_bind_exception_port);
        ret = static_cast<uint64_t>(sys_task_bind_exception_port(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uint64_t>(arg3),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 37: {
        CHECK_SYSCALL_PC(task_suspend);
        ret = static_cast<uint64_t>(sys_task_suspend(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 38: {
        CHECK_SYSCALL_PC(task_resume);
        ret = static_cast<uint64_t>(sys_task_resume(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2)));
        break;
    }
    case 39: {
        CHECK_SYSCALL_PC(task_kill);
        ret = static_cast<uint64_t>(sys_task_kill(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 40: {
        CHECK_SYSCALL_PC(event_create);
        ret = static_cast<uint64_t>(sys_event_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2))));
        break;
    }
    case 41: {
        CHECK_SYSCALL_PC(eventpair_create);
        ret = static_cast<uint64_t>(sys_eventpair_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 42: {
        CHECK_SYSCALL_PC(futex_wait);
        ret = static_cast<uint64_t>(sys_futex_wait(
                make_user_ptr(reinterpret_cast<mx_futex_t*>(arg1)),
                static_cast<int>(arg2),
                static_cast<mx_time_t>(arg3)));
        break;
    }
    case 43: {
        CHECK_SYSCALL_PC(futex_wake);
        ret = static_cast<uint64_t>(sys_futex_wake(
                make_user_ptr(reinterpret_cast<const mx_futex_t*>(arg1)),
                static_cast<uint32_t>(arg2)));
        break;
    }
    case 44: {
        CHECK_SYSCALL_PC(futex_requeue);
        ret = static_cast<uint64_t>(sys_futex_requeue(
                make_user_ptr(reinterpret_cast<mx_futex_t*>(arg1)),
                static_cast<uint32_t>(arg2),
                static_cast<int>(arg3),
                make_user_ptr(reinterpret_cast<mx_futex_t*>(arg4)),
                static_cast<uint32_t>(arg5)));
        break;
    }
    case 45: {
        CHECK_SYSCALL_PC(waitset_create);
        ret = static_cast<uint64_t>(sys_waitset_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2))));
        break;
    }
    case 46: {
        CHECK_SYSCALL_PC(waitset_add);
        ret = static_cast<uint64_t>(sys_waitset_add(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint64_t>(arg2),
                static_cast<mx_handle_t>(arg3),
                static_cast<mx_signals_t>(arg4)));
        break;
    }
    case 47: {
        CHECK_SYSCALL_PC(waitset_remove);
        ret = static_cast<uint64_t>(sys_waitset_remove(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint64_t>(arg2)));
        break;
    }
    case 48: {
        CHECK_SYSCALL_PC(waitset_wait);
        ret = static_cast<uint64_t>(sys_waitset_wait(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_time_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_waitset_result_t*>(arg3)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg4))));
        break;
    }
    case 49: {
        CHECK_SYSCALL_PC(port_create);
        ret = static_cast<uint64_t>(sys_port_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2))));
        break;
    }
    case 50: {
        CHECK_SYSCALL_PC(port_queue);
        ret = static_cast<uint64_t>(sys_port_queue(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const void*>(arg2)),
                static_cast<size_t>(arg3)));
        break;
    }
    case 51: {
        CHECK_SYSCALL_PC(port_wait);
        ret = static_cast<uint64_t>(sys_port_wait(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_time_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<size_t>(arg4)));
        break;
    }
    case 52: {
        CHECK_SYSCALL_PC(port_cancel);
        ret = static_cast<uint64_t>(sys_port_cancel(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uint64_t>(arg3)));
        break;
    }
    case 53: {
        CHECK_SYSCALL_PC(timer_create);
        ret = static_cast<uint64_t>(sys_timer_create(
                static_cast<uint32_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 54: {
        CHECK_SYSCALL_PC(timer_start);
        ret = static_cast<uint64_t>(sys_timer_start(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_time_t>(arg2),
                static_cast<mx_duration_t>(arg3),
                static_cast<mx_duration_t>(arg4)));
        break;
    }
    case 55: {
        CHECK_SYSCALL_PC(timer_cancel);
        ret = static_cast<uint64_t>(sys_timer_cancel(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 56: {
        CHECK_SYSCALL_PC(vmo_create);
        ret = static_cast<uint64_t>(sys_vmo_create(
                static_cast<uint64_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 57: {
        CHECK_SYSCALL_PC(vmo_read);
        ret = static_cast<uint64_t>(sys_vmo_read(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<void*>(arg2)),
                static_cast<uint64_t>(arg3),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 58: {
        CHECK_SYSCALL_PC(vmo_write);
        ret = static_cast<uint64_t>(sys_vmo_write(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const void*>(arg2)),
                static_cast<uint64_t>(arg3),
                static_cast<size_t>(arg4),
                make_user_ptr(reinterpret_cast<size_t*>(arg5))));
        break;
    }
    case 59: {
        CHECK_SYSCALL_PC(vmo_get_size);
        ret = static_cast<uint64_t>(sys_vmo_get_size(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<uint64_t*>(arg2))));
        break;
    }
    case 60: {
        CHECK_SYSCALL_PC(vmo_set_size);
        ret = static_cast<uint64_t>(sys_vmo_set_size(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint64_t>(arg2)));
        break;
    }
    case 61: {
        CHECK_SYSCALL_PC(vmo_op_range);
        ret = static_cast<uint64_t>(sys_vmo_op_range(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint64_t>(arg3),
                static_cast<uint64_t>(arg4),
                make_user_ptr(reinterpret_cast<void*>(arg5)),
                static_cast<size_t>(arg6)));
        break;
    }
    case 62: {
        CHECK_SYSCALL_PC(vmo_clone);
        ret = static_cast<uint64_t>(sys_vmo_clone(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint64_t>(arg3),
                static_cast<uint64_t>(arg4),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg5))));
        break;
    }
    case 63: {
        CHECK_SYSCALL_PC(vmo_set_cache_policy);
        ret = static_cast<uint64_t>(sys_vmo_set_cache_policy(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2)));
        break;
    }
    case 64: {
        CHECK_SYSCALL_PC(vmar_allocate);
        ret = static_cast<uint64_t>(sys_vmar_allocate(
                static_cast<mx_handle_t>(arg1),
                static_cast<size_t>(arg2),
                static_cast<size_t>(arg3),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg5)),
                make_user_ptr(reinterpret_cast<uintptr_t*>(arg6))));
        break;
    }
    case 65: {
        CHECK_SYSCALL_PC(vmar_destroy);
        ret = static_cast<uint64_t>(sys_vmar_destroy(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 66: {
        CHECK_SYSCALL_PC(vmar_map);
        ret = static_cast<uint64_t>(sys_vmar_map(
                static_cast<mx_handle_t>(arg1),
                static_cast<size_t>(arg2),
                static_cast<mx_handle_t>(arg3),
                static_cast<uint64_t>(arg4),
                static_cast<size_t>(arg5),
                static_cast<uint32_t>(arg6),
                make_user_ptr(reinterpret_cast<uintptr_t*>(arg7))));
        break;
    }
    case 67: {
        CHECK_SYSCALL_PC(vmar_unmap);
        ret = static_cast<uint64_t>(sys_vmar_unmap(
                static_cast<mx_handle_t>(arg1),
                static_cast<uintptr_t>(arg2),
                static_cast<size_t>(arg3)));
        break;
    }
    case 68: {
        CHECK_SYSCALL_PC(vmar_protect);
        ret = static_cast<uint64_t>(sys_vmar_protect(
                static_cast<mx_handle_t>(arg1),
                static_cast<uintptr_t>(arg2),
                static_cast<size_t>(arg3),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 69: {
        CHECK_SYSCALL_PC(cprng_draw);
        ret = static_cast<uint64_t>(sys_cprng_draw(
                make_user_ptr(reinterpret_cast<void*>(arg1)),
                static_cast<size_t>(arg2),
                make_user_ptr(reinterpret_cast<size_t*>(arg3))));
        break;
    }
    case 70: {
        CHECK_SYSCALL_PC(cprng_add_entropy);
        ret = static_cast<uint64_t>(sys_cprng_add_entropy(
                make_user_ptr(reinterpret_cast<const void*>(arg1)),
                static_cast<size_t>(arg2)));
        break;
    }
    case 71: {
        CHECK_SYSCALL_PC(fifo_create);
        ret = static_cast<uint64_t>(sys_fifo_create(
                static_cast<uint32_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4)),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg5))));
        break;
    }
    case 72: {
        CHECK_SYSCALL_PC(fifo_read);
        ret = static_cast<uint64_t>(sys_fifo_read(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<void*>(arg2)),
                static_cast<size_t>(arg3),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg4))));
        break;
    }
    case 73: {
        CHECK_SYSCALL_PC(fifo_write);
        ret = static_cast<uint64_t>(sys_fifo_write(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const void*>(arg2)),
                static_cast<size_t>(arg3),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg4))));
        break;
    }
    case 74: {
        CHECK_SYSCALL_PC(log_create);
        ret = static_cast<uint64_t>(sys_log_create(
                static_cast<uint32_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2))));
        break;
    }
    case 75: {
        CHECK_SYSCALL_PC(log_write);
        ret = static_cast<uint64_t>(sys_log_write(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 76: {
        CHECK_SYSCALL_PC(log_read);
        ret = static_cast<uint64_t>(sys_log_read(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<void*>(arg3)),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 77: {
        CHECK_SYSCALL_PC(ktrace_read);
        ret = static_cast<uint64_t>(sys_ktrace_read(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<void*>(arg2)),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg5))));
        break;
    }
    case 78: {
        CHECK_SYSCALL_PC(ktrace_control);
        ret = static_cast<uint64_t>(sys_ktrace_control(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<void*>(arg4))));
        break;
    }
    case 79: {
        CHECK_SYSCALL_PC(ktrace_write);
        ret = static_cast<uint64_t>(sys_ktrace_write(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4)));
        break;
    }
    case 80: {
        CHECK_SYSCALL_PC(mtrace_control);
        ret = static_cast<uint64_t>(sys_mtrace_control(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                reinterpret_cast<void*>(arg5),
                static_cast<uint32_t>(arg6)));
        break;
    }
    case 81: {
        CHECK_SYSCALL_PC(debug_transfer_handle);
        ret = static_cast<uint64_t>(sys_debug_transfer_handle(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2)));
        break;
    }
    case 82: {
        CHECK_SYSCALL_PC(debug_read);
        ret = static_cast<uint64_t>(sys_debug_read(
                static_cast<mx_handle_t>(arg1),
                reinterpret_cast<void*>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 83: {
        CHECK_SYSCALL_PC(debug_write);
        ret = static_cast<uint64_t>(sys_debug_write(
                reinterpret_cast<const void*>(arg1),
                static_cast<uint32_t>(arg2)));
        break;
    }
    case 84: {
        CHECK_SYSCALL_PC(debug_send_command);
        ret = static_cast<uint64_t>(sys_debug_send_command(
                static_cast<mx_handle_t>(arg1),
                reinterpret_cast<const void*>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 85: {
        CHECK_SYSCALL_PC(interrupt_create);
        ret = static_cast<uint64_t>(sys_interrupt_create(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 86: {
        CHECK_SYSCALL_PC(interrupt_complete);
        ret = static_cast<uint64_t>(sys_interrupt_complete(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 87: {
        CHECK_SYSCALL_PC(interrupt_wait);
        ret = static_cast<uint64_t>(sys_interrupt_wait(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 88: {
        CHECK_SYSCALL_PC(interrupt_signal);
        ret = static_cast<uint64_t>(sys_interrupt_signal(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 89: {
        CHECK_SYSCALL_PC(mmap_device_io);
        ret = static_cast<uint64_t>(sys_mmap_device_io(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 90: {
        CHECK_SYSCALL_PC(mmap_device_memory);
        ret = static_cast<uint64_t>(sys_mmap_device_memory(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_paddr_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<mx_cache_policy_t>(arg4),
                make_user_ptr(reinterpret_cast<uintptr_t*>(arg5))));
        break;
    }
    case 91: {
        CHECK_SYSCALL_PC(io_mapping_get_info);
        ret = static_cast<uint64_t>(sys_io_mapping_get_info(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<uintptr_t*>(arg2)),
                make_user_ptr(reinterpret_cast<uint64_t*>(arg3))));
        break;
    }
    case 92: {
        CHECK_SYSCALL_PC(vmo_create_contiguous);
        ret = static_cast<uint64_t>(sys_vmo_create_contiguous(
                static_cast<mx_handle_t>(arg1),
                static_cast<size_t>(arg2),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4))));
        break;
    }
    case 93: {
        CHECK_SYSCALL_PC(bootloader_fb_get_info);
        ret = static_cast<uint64_t>(sys_bootloader_fb_get_info(
                make_user_ptr(reinterpret_cast<uint32_t*>(arg1)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg2)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg3)),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg4))));
        break;
    }
    case 94: {
        CHECK_SYSCALL_PC(set_framebuffer);
        ret = static_cast<uint64_t>(sys_set_framebuffer(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<void*>(arg2)),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                static_cast<uint32_t>(arg5),
                static_cast<uint32_t>(arg6),
                static_cast<uint32_t>(arg7)));
        break;
    }
    case 95: {
        CHECK_SYSCALL_PC(set_framebuffer_vmo);
        ret = static_cast<uint64_t>(sys_set_framebuffer_vmo(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                static_cast<uint32_t>(arg5),
                static_cast<uint32_t>(arg6),
                static_cast<uint32_t>(arg7)));
        break;
    }
    case 96: {
        CHECK_SYSCALL_PC(clock_adjust);
        ret = static_cast<uint64_t>(sys_clock_adjust(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<int64_t>(arg3)));
        break;
    }
    case 97: {
        CHECK_SYSCALL_PC(pci_get_nth_device);
        ret = static_cast<uint64_t>(sys_pci_get_nth_device(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_pcie_device_info_t*>(arg3))));
        break;
    }
    case 98: {
        CHECK_SYSCALL_PC(pci_claim_device);
        ret = static_cast<uint64_t>(sys_pci_claim_device(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 99: {
        CHECK_SYSCALL_PC(pci_enable_bus_master);
        ret = static_cast<uint64_t>(sys_pci_enable_bus_master(
                static_cast<mx_handle_t>(arg1),
                static_cast<bool>(arg2)));
        break;
    }
    case 100: {
        CHECK_SYSCALL_PC(pci_enable_pio);
        ret = static_cast<uint64_t>(sys_pci_enable_pio(
                static_cast<mx_handle_t>(arg1),
                static_cast<bool>(arg2)));
        break;
    }
    case 101: {
        CHECK_SYSCALL_PC(pci_reset_device);
        ret = static_cast<uint64_t>(sys_pci_reset_device(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 102: {
        CHECK_SYSCALL_PC(pci_get_bar);
        ret = static_cast<uint64_t>(sys_pci_get_bar(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_pci_resource_t*>(arg3))));
        break;
    }
    case 103: {
        CHECK_SYSCALL_PC(pci_get_config);
        ret = static_cast<uint64_t>(sys_pci_get_config(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_pci_resource_t*>(arg2))));
        break;
    }
    case 104: {
        CHECK_SYSCALL_PC(pci_io_write);
        ret = static_cast<uint64_t>(sys_pci_io_write(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                static_cast<uint32_t>(arg5)));
        break;
    }
    case 105: {
        CHECK_SYSCALL_PC(pci_io_read);
        ret = static_cast<uint64_t>(sys_pci_io_read(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg5))));
        break;
    }
    case 106: {
        CHECK_SYSCALL_PC(pci_map_interrupt);
        ret = static_cast<uint64_t>(sys_pci_map_interrupt(
                static_cast<mx_handle_t>(arg1),
                static_cast<int32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 107: {
        CHECK_SYSCALL_PC(pci_query_irq_mode_caps);
        ret = static_cast<uint64_t>(sys_pci_query_irq_mode_caps(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<uint32_t*>(arg3))));
        break;
    }
    case 108: {
        CHECK_SYSCALL_PC(pci_set_irq_mode);
        ret = static_cast<uint64_t>(sys_pci_set_irq_mode(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 109: {
        CHECK_SYSCALL_PC(pci_init);
        ret = static_cast<uint64_t>(sys_pci_init(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const mx_pci_init_arg_t*>(arg2)),
                static_cast<uint32_t>(arg3)));
        break;
    }
    case 110: {
        CHECK_SYSCALL_PC(pci_add_subtract_io_range);
        ret = static_cast<uint64_t>(sys_pci_add_subtract_io_range(
                static_cast<mx_handle_t>(arg1),
                static_cast<bool>(arg2),
                static_cast<uint64_t>(arg3),
                static_cast<uint64_t>(arg4),
                static_cast<bool>(arg5)));
        break;
    }
    case 111: {
        CHECK_SYSCALL_PC(acpi_uefi_rsdp);
        ret = static_cast<uint64_t>(sys_acpi_uefi_rsdp(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 112: {
        CHECK_SYSCALL_PC(acpi_cache_flush);
        ret = static_cast<uint64_t>(sys_acpi_cache_flush(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 113: {
        CHECK_SYSCALL_PC(resource_create);
        ret = static_cast<uint64_t>(sys_resource_create(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<const mx_rrec_t*>(arg2)),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4))));
        break;
    }
    case 114: {
        CHECK_SYSCALL_PC(resource_destroy);
        ret = static_cast<uint64_t>(sys_resource_destroy(
                static_cast<mx_handle_t>(arg1)));
        break;
    }
    case 115: {
        CHECK_SYSCALL_PC(resource_get_handle);
        ret = static_cast<uint64_t>(sys_resource_get_handle(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg4))));
        break;
    }
    case 116: {
        CHECK_SYSCALL_PC(resource_do_action);
        ret = static_cast<uint64_t>(sys_resource_do_action(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                static_cast<uint32_t>(arg3),
                static_cast<uint32_t>(arg4),
                static_cast<uint32_t>(arg5)));
        break;
    }
    case 117: {
        CHECK_SYSCALL_PC(resource_connect);
        ret = static_cast<uint64_t>(sys_resource_connect(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2)));
        break;
    }
    case 118: {
        CHECK_SYSCALL_PC(resource_accept);
        ret = static_cast<uint64_t>(sys_resource_accept(
                static_cast<mx_handle_t>(arg1),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg2))));
        break;
    }
    case 119: {
        CHECK_SYSCALL_PC(hypervisor_create);
        ret = static_cast<uint64_t>(sys_hypervisor_create(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<mx_handle_t*>(arg3))));
        break;
    }
    case 120: {
        CHECK_SYSCALL_PC(hypervisor_op);
        ret = static_cast<uint64_t>(sys_hypervisor_op(
                static_cast<mx_handle_t>(arg1),
                static_cast<uint32_t>(arg2),
                make_user_ptr(reinterpret_cast<const void*>(arg3)),
                static_cast<uint32_t>(arg4),
                make_user_ptr(reinterpret_cast<void*>(arg5)),
                static_cast<uint32_t>(arg6)));
        break;
    }
    case 121: {
        CHECK_SYSCALL_PC(system_mexec);
        ret = static_cast<uint64_t>(sys_system_mexec(
                static_cast<mx_handle_t>(arg1),
                static_cast<mx_handle_t>(arg2)));
        break;
    }
    case 122: {
        CHECK_SYSCALL_PC(syscall_test_0);
        ret = static_cast<uint64_t>(sys_syscall_test_0());
        break;
    }
    case 123: {
        CHECK_SYSCALL_PC(syscall_test_1);
        ret = static_cast<uint64_t>(sys_syscall_test_1(
                static_cast<int>(arg1)));
        break;
    }
    case 124: {
        CHECK_SYSCALL_PC(syscall_test_2);
        ret = static_cast<uint64_t>(sys_syscall_test_2(
                static_cast<int>(arg1),
                static_cast<int>(arg2)));
        break;
    }
    case 125: {
        CHECK_SYSCALL_PC(syscall_test_3);
        ret = static_cast<uint64_t>(sys_syscall_test_3(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3)));
        break;
    }
    case 126: {
        CHECK_SYSCALL_PC(syscall_test_4);
        ret = static_cast<uint64_t>(sys_syscall_test_4(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3),
                static_cast<int>(arg4)));
        break;
    }
    case 127: {
        CHECK_SYSCALL_PC(syscall_test_5);
        ret = static_cast<uint64_t>(sys_syscall_test_5(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3),
                static_cast<int>(arg4),
                static_cast<int>(arg5)));
        break;
    }
    case 128: {
        CHECK_SYSCALL_PC(syscall_test_6);
        ret = static_cast<uint64_t>(sys_syscall_test_6(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3),
                static_cast<int>(arg4),
                static_cast<int>(arg5),
                static_cast<int>(arg6)));
        break;
    }
    case 129: {
        CHECK_SYSCALL_PC(syscall_test_7);
        ret = static_cast<uint64_t>(sys_syscall_test_7(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3),
                static_cast<int>(arg4),
                static_cast<int>(arg5),
                static_cast<int>(arg6),
                static_cast<int>(arg7)));
        break;
    }
    case 130: {
        CHECK_SYSCALL_PC(syscall_test_8);
        ret = static_cast<uint64_t>(sys_syscall_test_8(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3),
                static_cast<int>(arg4),
                static_cast<int>(arg5),
                static_cast<int>(arg6),
                static_cast<int>(arg7),
                static_cast<int>(arg8)));
        break;
    }
    case 131: {
        CHECK_SYSCALL_PC(syscall_test_wrapper);
        ret = static_cast<uint64_t>(sys_syscall_test_wrapper(
                static_cast<int>(arg1),
                static_cast<int>(arg2),
                static_cast<int>(arg3)));
        break;
    }

