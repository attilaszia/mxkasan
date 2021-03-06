// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <magenta/device/ioctl-wrapper.h>
#include <magenta/device/ioctl.h>
#include <magenta/types.h>

#define MAX_FS_NAME_LEN 32

#define IOCTL_VFS_MOUNT_FS \
    IOCTL(IOCTL_KIND_SET_HANDLE, IOCTL_FAMILY_VFS, 0)
// Unmount the filesystem which 'fd' belongs to.
#define IOCTL_VFS_UNMOUNT_FS \
    IOCTL(IOCTL_KIND_DEFAULT, IOCTL_FAMILY_VFS, 1)
// If a filesystem is mounted on the node represented by 'fd', unmount it.
#define IOCTL_VFS_UNMOUNT_NODE \
    IOCTL(IOCTL_KIND_GET_HANDLE, IOCTL_FAMILY_VFS, 2)
// Add a bootfs vmo to the system fs.
#define IOCTL_VFS_MOUNT_BOOTFS_VMO \
    IOCTL(IOCTL_KIND_SET_HANDLE, IOCTL_FAMILY_VFS, 3)
// Determine which filesystem the vnode belongs to.
#define IOCTL_VFS_QUERY_FS \
    IOCTL(IOCTL_KIND_DEFAULT, IOCTL_FAMILY_VFS, 4)
#define IOCTL_VFS_GET_TOKEN \
    IOCTL(IOCTL_KIND_GET_HANDLE, IOCTL_FAMILY_VFS, 5)
#define IOCTL_VFS_MOUNT_MKDIR_FS \
    IOCTL(IOCTL_KIND_SET_HANDLE, IOCTL_FAMILY_VFS, 6)
// Watch a directory for changes
//   in: none
//   out: handle to channel to get notified on.
//        Notification messages are as for V2 but only
//        ever have a single event per message.
#define IOCTL_VFS_WATCH_DIR \
    IOCTL(IOCTL_KIND_GET_HANDLE, IOCTL_FAMILY_VFS, 7)

// Watch a directory for changes
// in: vfs_watch_dir_t
//
// Watch event messages are sent via the provided channel and take the form:
// { uint8_t event; uint8_t namelen; uint8_t name[namelen]; }
// Multiple events may arrive in one message, one after another.
// Names do not include a terminating null.
//
// TODO: Once fully deployed, remove IOCTL_VFS_WATCH_DIR
#define IOCTL_VFS_WATCH_DIR_V2 \
    IOCTL(IOCTL_KIND_SET_HANDLE, IOCTL_FAMILY_VFS, 8)

typedef struct {
    mx_handle_t channel; // Channel to which watch events will be sent
    uint32_t mask;       // Bitmask of desired events (1 << WATCH_EVT_*)
    uint32_t options;    // Options.  Must be zero.
} vfs_watch_dir_t;

// Indicates that the directory being watched has been deleted.
// namelen will be 0
#define VFS_WATCH_EVT_DELETED 0

// Indication of a file that has been added (created or moved
// in) to the directory
#define VFS_WATCH_EVT_ADDED 1

// Indication of a file that has been removed (deleted or moved
// out) from the directory
#define VFS_WATCH_EVT_REMOVED 2

// Indication of file already in directory when watch started
#define VFS_WATCH_EVT_EXISTING 3

// Indication that no more EXISTING events will be sent (client
// has been informed of all pre-existing files in this directory)
// namelen will be 0
#define VFS_WATCH_EVT_IDLE 4

typedef struct {
    uint8_t event;
    uint8_t len;
    char name[];
} vfs_watch_msg_t;

// clang-format off

#define VFS_WATCH_MASK_DELETED  (1u << VFS_WATCH_EVT_DELETED)
#define VFS_WATCH_MASK_ADDED    (1u << VFS_WATCH_EVT_ADDED)
#define VFS_WATCH_MASK_REMOVED  (1u << VFS_WATCH_EVT_REMOVED)
#define VFS_WATCH_MASK_EXISTING (1u << VFS_WATCH_EVT_EXISTING)
#define VFS_WATCH_MASK_IDLE     (1u << VFS_WATCH_EVT_IDLE)
#define VFS_WATCH_MASK_ALL      (0x1Fu)

// clang-format on

#define VFS_WATCH_NAME_MAX 255
#define VFS_WATCH_MSG_MAX 8192

// ssize_t ioctl_vfs_mount_fs(int fd, mx_handle_t* in);
IOCTL_WRAPPER_IN(ioctl_vfs_mount_fs, IOCTL_VFS_MOUNT_FS, mx_handle_t);

// ssize_t ioctl_vfs_unmount_fs(int fd);
IOCTL_WRAPPER(ioctl_vfs_unmount_fs, IOCTL_VFS_UNMOUNT_FS);

// ssize_t ioctl_vfs_unmount_node(int fd, mx_handle_t* out);
IOCTL_WRAPPER_OUT(ioctl_vfs_unmount_node, IOCTL_VFS_UNMOUNT_NODE, mx_handle_t);

// ssize_t ioctl_vfs_mount_bootfs_vmo(int fd, mx_handle_t* in);
IOCTL_WRAPPER_IN(ioctl_vfs_mount_bootfs_vmo, IOCTL_VFS_MOUNT_BOOTFS_VMO, mx_handle_t);

typedef struct vfs_query_info {
    // these are the total/used # of data bytes, not # of entire disk bytes
    uint64_t total_bytes;
    uint64_t used_bytes;
    uint64_t total_nodes;
    uint64_t used_nodes;
    char name[MAX_FS_NAME_LEN];
} vfs_query_info_t;

// ssize_t ioctl_vfs_query_fs(int fd, vfs_query_info_t* out, size_t out_len);
IOCTL_WRAPPER_VAROUT(ioctl_vfs_query_fs, IOCTL_VFS_QUERY_FS, vfs_query_info_t);

// ssize_t ioctl_vfs_get_token(int fd, mx_handle_t* out);
IOCTL_WRAPPER_OUT(ioctl_vfs_get_token, IOCTL_VFS_GET_TOKEN, mx_handle_t);

// ssize_t ioctl_vfs_watch_dir(int fd, mx_handle_t* out);
IOCTL_WRAPPER_OUT(ioctl_vfs_watch_dir, IOCTL_VFS_WATCH_DIR, mx_handle_t);

// ssize_t ioctl_vfs_watch_dir_v2(int fd, vfs_watch_dir_t* in;
IOCTL_WRAPPER_IN(ioctl_vfs_watch_dir_v2, IOCTL_VFS_WATCH_DIR_V2, vfs_watch_dir_t);

#define MOUNT_MKDIR_FLAG_REPLACE 1

typedef struct mount_mkdir_config {
    mx_handle_t fs_root;
    uint32_t flags;
    char name[]; // Null-terminator required
} mount_mkdir_config_t;

// ssize_t ioctl_vfs_mount_mkdir_fs(int fd, mount_mkdir_config_t* in, size_t in_len);
IOCTL_WRAPPER_VARIN(ioctl_vfs_mount_mkdir_fs, IOCTL_VFS_MOUNT_MKDIR_FS, mount_mkdir_config_t);
