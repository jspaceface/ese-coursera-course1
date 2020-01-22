#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2
CFLAGS_COMMON = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
LDFLAGS_COMMON = -Wl,-Map=$(TARGET).map

# Default compiler Flags and Defines
# CPPFLAGS = -D$(PLATFORM)

ifeq ($(PLATFORM),HOST)
	CC = gcc
	LD = ld
	LDFLAGS = $(LDFLAGS_COMMON)
	CFLAGS = $(CFLAGS_COMMON)
else
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = $(LDFLAGS_COMMON) -Wl,-T $(LINKER_FILE)
	CFLAGS = $(CFLAGS_COMMON) \
		-mcpu=cortex-m4 \
		-mthumb \
		-march=armv7e-m \
		-mfloat-abi=hard \
		-mfpu=fpv4-sp-d16 \
		--specs=nosys.specs
	LINKER_FILE = /home/jacob/workspace/ese-coursera-course1/assessments/m2/msp432p401r.lds
endif

OBJS = $(SOURCES:.c=.o)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(SOURCES:.c=.i) $(SOURCES:.c=.asm)

%.i : %.c
	$(CC) $(INCLUDES) -E -c $< $(CFLAGS) -o $@ 

%.asm : %.c
	$(CC) $(INCLUDES) -S -c $< $(CFLAGS) -o $@ 

%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@ 

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
