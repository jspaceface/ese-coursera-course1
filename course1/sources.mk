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

SRC_DIR = src

# Add your Source files to this variable
ifeq ($(PLATFORM),HOST)
	SOURCES = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/memory.c \
		$(SRC_DIR)/stats.c \
		$(SRC_DIR)/course1.c \
		$(SRC_DIR)/data.c
else
	SOURCES = \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/memory.c \
		$(SRC_DIR)/stats.c \
		$(SRC_DIR)/course1.c \
		$(SRC_DIR)/data.c \
		$(SRC_DIR)/interrupts_msp432p401r_gcc.c \
		$(SRC_DIR)/startup_msp432p401r_gcc.c \
		$(SRC_DIR)/system_msp432p401r.c 
endif

# Add your include paths to this variable
INCLUDES = \
	-I./include/CMSIS/ \
	-I./include/common/ \
	-I./include/msp432
