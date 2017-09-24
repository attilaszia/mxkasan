# Copyright 2017 Attila Szasz
#
# Use of this source code is governed by a MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS += \
	$(LOCAL_DIR)/mxkasan.cpp \
	$(LOCAL_DIR)/report.cpp \

MODULE_DEPS := \
    kernel/lib/mxtl \

include make/module.mk