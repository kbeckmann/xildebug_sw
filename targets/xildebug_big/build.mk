PLATFORM := stm32l4xx

TARGET_SRCS += \
	targets/$(TARGET)/target.c \

FEAT_POWER_PROFILER	:= 1
FEAT_DUT_SWITCH		:= 1
