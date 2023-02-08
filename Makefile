SYSTEM_PATH ?= $(shell pwd)/System

CSRCS += $(SYSTEM_PATH)/delay.c

CFLAGS += "-I$(SYSTEM_PATH)"
