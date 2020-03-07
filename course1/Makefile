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
# TODO resume: trying to get output to ROOT_BUILD_DIR...

MKDIR_P = mkdir -p

CFLAGS_COMMON = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) -DCOURSE1 -DVERBOSE
LDFLAGS_COMMON = -Wl,-Map=$(TARGET).map

ROOT_BUILD_DIR = build
OBJ_BUILD_DIR = $(ROOT_BUILD_DIR)/obj
ASM_BUILD_DIR = $(ROOT_BUILD_DIR)/asm
PREPROC_BUILD_DIR = $(ROOT_BUILD_DIR)/i
OUTPUT_DIRS = $(ROOT_BUILD_DIR) $(OBJ_BUILD_DIR) $(ASM_BUILD_DIR) $(PREPROC_BUILD_DIR)

TARGET = $(ROOT_BUILD_DIR)/c1m2

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

OBJS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_BUILD_DIR)/%.o)
ASMS = $(SOURCES:$(SRC_DIR)/%.c=$(ASM_BUILD_DIR)/%.asm)
PREPROCS = $(SOURCES:$(SRC_DIR)/%.c=$(PREPROC_BUILD_DIR)/%.i)

.PHONY: dirs
dirs: $(OUTPUT_DIRS)

.PHONY: compile-all
compile-all: dirs $(OBJS)

.PHONY: build-all
build-all: dirs $(TARGET).out

.PHONY: clean
clean:
	rm -rf $(ROOT_BUILD_DIR)

$(OUTPUT_DIRS): 
	$(MKDIR_P) $(OUTPUT_DIRS)

$(PREPROCS) : $(PREPROC_BUILD_DIR)/%.i : $(SRC_DIR)/%.c
	$(CC) $(INCLUDES) -E -c $< $(CFLAGS) -o $@ 

$(ASMS) : $(ASM_BUILD_DIR)/%.asm : $(SRC_DIR)/%.c
	$(CC) $(INCLUDES) -S -c $< $(CFLAGS) -o $@ 

$(OBJS) : $(OBJ_BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@ 

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
