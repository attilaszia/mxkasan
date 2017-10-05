# Copyright 2017 Attila Szasz
#
# Use of this source code is governed by a MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS += \
	$(LOCAL_DIR)/test_mxkasan.cpp \

MODULE_DEPS := \
    kernel/lib/mxtl \

MODULE_COMPILEFLAGS += -fsanitize=kernel-address $(DISABLESTACKASAN) 

include make/module.mk
