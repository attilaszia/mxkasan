// Copyright 2017 The Fuchsia Authors. All rights reserved.
// This is a GENERATED file, see //magenta/system/host/sysgen.
// The license governing this file can be found in the LICENSE file.

mx_time_t sys_time_get(
uint32_t clock_id);

mx_status_t sys_nanosleep(
mx_time_t deadline);

mx_status_t sys_handle_close(
mx_handle_t handle);

mx_status_t sys_handle_duplicate(
mx_handle_t handle,
    mx_rights_t rights,
    user_ptr<mx_handle_t> out);

mx_status_t sys_handle_replace(
mx_handle_t handle,
    mx_rights_t rights,
    user_ptr<mx_handle_t> out);

mx_status_t sys_object_wait_one(
mx_handle_t handle,
    mx_signals_t waitfor,
    mx_time_t deadline,
    user_ptr<mx_signals_t> observed);

mx_status_t sys_object_wait_many(
user_ptr<mx_wait_item_t> items,
    uint32_t count,
    mx_time_t deadline);

mx_status_t sys_object_wait_async(
mx_handle_t handle,
    mx_handle_t port_handle,
    uint64_t key,
    mx_signals_t signals,
    uint32_t options);

mx_status_t sys_object_signal(
mx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask);

mx_status_t sys_object_signal_peer(
mx_handle_t handle,
    uint32_t clear_mask,
    uint32_t set_mask);

mx_status_t sys_object_get_property(
mx_handle_t handle,
    uint32_t property,
    user_ptr<void> value,
    size_t size);

mx_status_t sys_object_set_property(
mx_handle_t handle,
    uint32_t property,
    user_ptr<const void> value,
    size_t size);

mx_status_t sys_object_set_cookie(
mx_handle_t handle,
    mx_handle_t scope,
    uint64_t cookie);

mx_status_t sys_object_get_cookie(
mx_handle_t handle,
    mx_handle_t scope,
    user_ptr<uint64_t> cookie);

mx_status_t sys_object_get_info(
mx_handle_t handle,
    uint32_t topic,
    user_ptr<void> buffer,
    size_t buffer_size,
    user_ptr<size_t> actual_count,
    user_ptr<size_t> avail_count);

mx_status_t sys_object_get_child(
mx_handle_t handle,
    uint64_t koid,
    mx_rights_t rights,
    user_ptr<mx_handle_t> out);

mx_status_t sys_channel_create(
uint32_t options,
    user_ptr<mx_handle_t> out0,
    user_ptr<mx_handle_t> out1);

mx_status_t sys_channel_read(
mx_handle_t handle,
    uint32_t options,
    user_ptr<void> bytes,
    user_ptr<mx_handle_t> handles,
    uint32_t num_bytes,
    uint32_t num_handles,
    user_ptr<uint32_t> actual_bytes,
    user_ptr<uint32_t> actual_handles);

mx_status_t sys_channel_write(
mx_handle_t handle,
    uint32_t options,
    user_ptr<const void> bytes,
    uint32_t num_bytes,
    user_ptr<const mx_handle_t> handles,
    uint32_t num_handles);

mx_status_t sys_channel_call_noretry(
mx_handle_t handle,
    uint32_t options,
    mx_time_t deadline,
    user_ptr<const mx_channel_call_args_t> args,
    user_ptr<uint32_t> actual_bytes,
    user_ptr<uint32_t> actual_handles,
    user_ptr<mx_status_t> read_status);

mx_status_t sys_channel_call_finish(
mx_handle_t handle,
    mx_time_t deadline,
    user_ptr<const mx_channel_call_args_t> args,
    user_ptr<uint32_t> actual_bytes,
    user_ptr<uint32_t> actual_handles,
    user_ptr<mx_status_t> read_status);

mx_status_t sys_socket_create(
uint32_t options,
    user_ptr<mx_handle_t> out0,
    user_ptr<mx_handle_t> out1);

mx_status_t sys_socket_write(
mx_handle_t handle,
    uint32_t options,
    user_ptr<const void> buffer,
    size_t size,
    user_ptr<size_t> actual);

mx_status_t sys_socket_read(
mx_handle_t handle,
    uint32_t options,
    user_ptr<void> buffer,
    size_t size,
    user_ptr<size_t> actual);

void sys_thread_exit(
) __attribute__((__noreturn__));

mx_status_t sys_thread_create(
mx_handle_t process,
    user_ptr<const char> name,
    uint32_t name_len,
    uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_thread_start(
mx_handle_t handle,
    uintptr_t thread_entry,
    uintptr_t stack,
    uintptr_t arg1,
    uintptr_t arg2);

mx_status_t sys_thread_read_state(
mx_handle_t handle,
    uint32_t kind,
    user_ptr<void> buffer,
    uint32_t len,
    user_ptr<uint32_t> actual);

mx_status_t sys_thread_write_state(
mx_handle_t handle,
    uint32_t kind,
    user_ptr<const void> buffer,
    uint32_t buffer_len);

void sys_process_exit(
int retcode) __attribute__((__noreturn__));

mx_status_t sys_process_create(
mx_handle_t job,
    user_ptr<const char> name,
    uint32_t name_len,
    uint32_t options,
    user_ptr<mx_handle_t> proc_handle,
    user_ptr<mx_handle_t> vmar_handle);

mx_status_t sys_process_start(
mx_handle_t process_handle,
    mx_handle_t thread_handle,
    uintptr_t entry,
    uintptr_t stack,
    mx_handle_t arg_handle,
    uintptr_t arg2);

mx_status_t sys_process_read_memory(
mx_handle_t proc,
    uintptr_t vaddr,
    user_ptr<void> buffer,
    size_t len,
    user_ptr<size_t> actual);

mx_status_t sys_process_write_memory(
mx_handle_t proc,
    uintptr_t vaddr,
    user_ptr<const void> buffer,
    size_t len,
    user_ptr<size_t> actual);

mx_status_t sys_job_create(
mx_handle_t parent_job,
    uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_job_set_policy(
mx_handle_t job,
    uint32_t options,
    uint32_t topic,
    user_ptr<const void> policy,
    uint32_t count);

mx_status_t sys_task_bind_exception_port(
mx_handle_t object,
    mx_handle_t eport,
    uint64_t key,
    uint32_t options);

mx_status_t sys_task_suspend(
mx_handle_t task_handle);

mx_status_t sys_task_resume(
mx_handle_t task_handle,
    uint32_t options);

mx_status_t sys_task_kill(
mx_handle_t task_handle);

mx_status_t sys_event_create(
uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_eventpair_create(
uint32_t options,
    user_ptr<mx_handle_t> out0,
    user_ptr<mx_handle_t> out1);

mx_status_t sys_futex_wait(
user_ptr<mx_futex_t> value_ptr,
    int current_value,
    mx_time_t deadline);

mx_status_t sys_futex_wake(
user_ptr<const mx_futex_t> value_ptr,
    uint32_t count);

mx_status_t sys_futex_requeue(
user_ptr<mx_futex_t> wake_ptr,
    uint32_t wake_count,
    int current_value,
    user_ptr<mx_futex_t> requeue_ptr,
    uint32_t requeue_count);

mx_status_t sys_waitset_create(
uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_waitset_add(
mx_handle_t waitset_handle,
    uint64_t cookie,
    mx_handle_t handle,
    mx_signals_t signals);

mx_status_t sys_waitset_remove(
mx_handle_t waitset_handle,
    uint64_t cookie);

mx_status_t sys_waitset_wait(
mx_handle_t waitset_handle,
    mx_time_t deadline,
    user_ptr<mx_waitset_result_t> results,
    user_ptr<uint32_t> count);

mx_status_t sys_port_create(
uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_port_queue(
mx_handle_t handle,
    user_ptr<const void> packet,
    size_t size);

mx_status_t sys_port_wait(
mx_handle_t handle,
    mx_time_t deadline,
    user_ptr<void> packet,
    size_t size);

mx_status_t sys_port_cancel(
mx_handle_t handle,
    mx_handle_t source,
    uint64_t key);

mx_status_t sys_timer_create(
uint32_t options,
    uint32_t clock_id,
    user_ptr<mx_handle_t> out);

mx_status_t sys_timer_start(
mx_handle_t handle,
    mx_time_t deadline,
    mx_duration_t period,
    mx_duration_t slack);

mx_status_t sys_timer_cancel(
mx_handle_t handle);

mx_status_t sys_vmo_create(
uint64_t size,
    uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_vmo_read(
mx_handle_t handle,
    user_ptr<void> data,
    uint64_t offset,
    size_t len,
    user_ptr<size_t> actual);

mx_status_t sys_vmo_write(
mx_handle_t handle,
    user_ptr<const void> data,
    uint64_t offset,
    size_t len,
    user_ptr<size_t> actual);

mx_status_t sys_vmo_get_size(
mx_handle_t handle,
    user_ptr<uint64_t> size);

mx_status_t sys_vmo_set_size(
mx_handle_t handle,
    uint64_t size);

mx_status_t sys_vmo_op_range(
mx_handle_t handle,
    uint32_t op,
    uint64_t offset,
    uint64_t size,
    user_ptr<void> buffer,
    size_t buffer_size);

mx_status_t sys_vmo_clone(
mx_handle_t handle,
    uint32_t options,
    uint64_t offset,
    uint64_t size,
    user_ptr<mx_handle_t> out);

mx_status_t sys_vmo_set_cache_policy(
mx_handle_t handle,
    uint32_t cache_policy);

mx_status_t sys_vmar_allocate(
mx_handle_t parent_vmar_handle,
    size_t offset,
    size_t size,
    uint32_t map_flags,
    user_ptr<mx_handle_t> child_vmar,
    user_ptr<uintptr_t> child_addr);

mx_status_t sys_vmar_destroy(
mx_handle_t vmar_handle);

mx_status_t sys_vmar_map(
mx_handle_t vmar_handle,
    size_t vmar_offset,
    mx_handle_t vmo_handle,
    uint64_t vmo_offset,
    size_t len,
    uint32_t map_flags,
    user_ptr<uintptr_t> mapped_addr);

mx_status_t sys_vmar_unmap(
mx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len);

mx_status_t sys_vmar_protect(
mx_handle_t vmar_handle,
    uintptr_t addr,
    size_t len,
    uint32_t prot_flags);

mx_status_t sys_cprng_draw(
user_ptr<void> buffer,
    size_t len,
    user_ptr<size_t> actual);

mx_status_t sys_cprng_add_entropy(
user_ptr<const void> buffer,
    size_t len);

mx_status_t sys_fifo_create(
uint32_t elem_count,
    uint32_t elem_size,
    uint32_t options,
    user_ptr<mx_handle_t> out0,
    user_ptr<mx_handle_t> out1);

mx_status_t sys_fifo_read(
mx_handle_t handle,
    user_ptr<void> data,
    size_t len,
    user_ptr<uint32_t> num_written);

mx_status_t sys_fifo_write(
mx_handle_t handle,
    user_ptr<const void> data,
    size_t len,
    user_ptr<uint32_t> num_written);

mx_status_t sys_log_create(
uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_log_write(
mx_handle_t handle,
    uint32_t len,
    user_ptr<const void> buffer,
    uint32_t options);

mx_status_t sys_log_read(
mx_handle_t handle,
    uint32_t len,
    user_ptr<void> buffer,
    uint32_t options);

mx_status_t sys_ktrace_read(
mx_handle_t handle,
    user_ptr<void> data,
    uint32_t offset,
    uint32_t len,
    user_ptr<uint32_t> actual);

mx_status_t sys_ktrace_control(
mx_handle_t handle,
    uint32_t action,
    uint32_t options,
    user_ptr<void> ptr);

mx_status_t sys_ktrace_write(
mx_handle_t handle,
    uint32_t id,
    uint32_t arg0,
    uint32_t arg1);

mx_status_t sys_mtrace_control(
mx_handle_t handle,
    uint32_t kind,
    uint32_t action,
    uint32_t options,
    void* ptr,
    uint32_t size);

mx_handle_t sys_debug_transfer_handle(
mx_handle_t proc,
    mx_handle_t handle);

mx_status_t sys_debug_read(
mx_handle_t handle,
    void* buffer,
    uint32_t length);

mx_status_t sys_debug_write(
const void* buffer,
    uint32_t length);

mx_status_t sys_debug_send_command(
mx_handle_t resource_handle,
    const void* buffer,
    uint32_t length);

mx_handle_t sys_interrupt_create(
mx_handle_t handle,
    uint32_t vector,
    uint32_t options);

mx_status_t sys_interrupt_complete(
mx_handle_t handle);

mx_status_t sys_interrupt_wait(
mx_handle_t handle);

mx_status_t sys_interrupt_signal(
mx_handle_t handle);

mx_status_t sys_mmap_device_io(
mx_handle_t handle,
    uint32_t io_addr,
    uint32_t len);

mx_status_t sys_mmap_device_memory(
mx_handle_t handle,
    mx_paddr_t paddr,
    uint32_t len,
    mx_cache_policy_t cache_policy,
    user_ptr<uintptr_t> out_vaddr);

mx_status_t sys_io_mapping_get_info(
mx_handle_t handle,
    user_ptr<uintptr_t> out_vaddr,
    user_ptr<uint64_t> out_size);

mx_status_t sys_vmo_create_contiguous(
mx_handle_t rsrc_handle,
    size_t size,
    uint32_t alignment_log2,
    user_ptr<mx_handle_t> out);

mx_status_t sys_bootloader_fb_get_info(
user_ptr<uint32_t> format,
    user_ptr<uint32_t> width,
    user_ptr<uint32_t> height,
    user_ptr<uint32_t> stride);

mx_status_t sys_set_framebuffer(
mx_handle_t handle,
    user_ptr<void> vaddr,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride);

mx_status_t sys_set_framebuffer_vmo(
mx_handle_t handle,
    mx_handle_t vmo,
    uint32_t len,
    uint32_t format,
    uint32_t width,
    uint32_t height,
    uint32_t stride);

mx_status_t sys_clock_adjust(
mx_handle_t handle,
    uint32_t clock_id,
    int64_t offset);

mx_handle_t sys_pci_get_nth_device(
mx_handle_t handle,
    uint32_t index,
    user_ptr<mx_pcie_device_info_t> out_info);

mx_status_t sys_pci_claim_device(
mx_handle_t handle);

mx_status_t sys_pci_enable_bus_master(
mx_handle_t handle,
    bool enable);

mx_status_t sys_pci_enable_pio(
mx_handle_t handle,
    bool enable);

mx_status_t sys_pci_reset_device(
mx_handle_t handle);

mx_status_t sys_pci_get_bar(
mx_handle_t handle,
    uint32_t bar_num,
    user_ptr<mx_pci_resource_t> out_bar);

mx_status_t sys_pci_get_config(
mx_handle_t handle,
    user_ptr<mx_pci_resource_t> out_config);

mx_status_t sys_pci_io_write(
mx_handle_t handle,
    uint32_t bar_num,
    uint32_t offset,
    uint32_t len,
    uint32_t value);

mx_status_t sys_pci_io_read(
mx_handle_t handle,
    uint32_t bar_num,
    uint32_t offset,
    uint32_t len,
    user_ptr<uint32_t> out_value);

mx_status_t sys_pci_map_interrupt(
mx_handle_t handle,
    int32_t which_irq,
    user_ptr<mx_handle_t> out_handle);

mx_status_t sys_pci_query_irq_mode_caps(
mx_handle_t handle,
    uint32_t mode,
    user_ptr<uint32_t> out_max_irqs);

mx_status_t sys_pci_set_irq_mode(
mx_handle_t handle,
    uint32_t mode,
    uint32_t requested_irq_count);

mx_status_t sys_pci_init(
mx_handle_t handle,
    user_ptr<const mx_pci_init_arg_t> init_buf,
    uint32_t len);

mx_status_t sys_pci_add_subtract_io_range(
mx_handle_t handle,
    bool mmio,
    uint64_t base,
    uint64_t len,
    bool add);

uint64_t sys_acpi_uefi_rsdp(
mx_handle_t handle);

mx_status_t sys_acpi_cache_flush(
mx_handle_t handle);

mx_status_t sys_resource_create(
mx_handle_t parent_handle,
    user_ptr<const mx_rrec_t> records,
    uint32_t count,
    user_ptr<mx_handle_t> resource_out);

mx_status_t sys_resource_destroy(
mx_handle_t handle);

mx_status_t sys_resource_get_handle(
mx_handle_t handle,
    uint32_t index,
    uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_resource_do_action(
mx_handle_t handle,
    uint32_t index,
    uint32_t action,
    uint32_t arg0,
    uint32_t arg1);

mx_status_t sys_resource_connect(
mx_handle_t handle,
    mx_handle_t channel);

mx_status_t sys_resource_accept(
mx_handle_t handle,
    user_ptr<mx_handle_t> channel);

mx_status_t sys_hypervisor_create(
mx_handle_t handle,
    uint32_t options,
    user_ptr<mx_handle_t> out);

mx_status_t sys_hypervisor_op(
mx_handle_t handle,
    uint32_t opcode,
    user_ptr<const void> args,
    uint32_t args_len,
    user_ptr<void> result,
    uint32_t result_len);

mx_status_t sys_system_mexec(
mx_handle_t kernel,
    mx_handle_t bootimage);

mx_status_t sys_syscall_test_0(
);

mx_status_t sys_syscall_test_1(
int a);

mx_status_t sys_syscall_test_2(
int a,
    int b);

mx_status_t sys_syscall_test_3(
int a,
    int b,
    int c);

mx_status_t sys_syscall_test_4(
int a,
    int b,
    int c,
    int d);

mx_status_t sys_syscall_test_5(
int a,
    int b,
    int c,
    int d,
    int e);

mx_status_t sys_syscall_test_6(
int a,
    int b,
    int c,
    int d,
    int e,
    int f);

mx_status_t sys_syscall_test_7(
int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g);

mx_status_t sys_syscall_test_8(
int a,
    int b,
    int c,
    int d,
    int e,
    int f,
    int g,
    int h);

mx_status_t sys_syscall_test_wrapper(
int a,
    int b,
    int c);


