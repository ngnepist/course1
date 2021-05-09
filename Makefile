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
# Simple make file to support two build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      <FILE>.i - Builds a <FILE>.i preprocessed file
#      <FILE>.asm - Dumps <FILE>.asm assembly file
#      <FILE>.d - Builds <FILE>.d dependency file
#      compile-all - Compiles all source files in project
#      build - Builds all object files in project (links as well)
#      clean - Removes all generated files
#
# Platform Overrides:
#      HOST - Default platform
#      MSP342 - Target cross-compiled platform
#
# Author: vtotient
# Date:   April 29, 2021
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# General flags for both platforms.
G_FLAGS = -std=c99 \
	  -g \
	  -O0 \
	  -Wall \
	  -Werror

# Architectures Specific Flags for MSP432.
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
EXTRA = -mthumb \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16


TARGET = c1m2

ifeq ($(PLATFORM), MSP432)
	# Compiler Flags & Defines
        CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        CFLAGS = $(G_FLAGS) \
				-mcpu=$(CPU) \
				-march=$(ARCH) \
				--specs=$(SPECS) \
				$(EXTRA)
        CPPFLAGS = -DMSP432 $(INCLUDES)
        LDFLAGS = -Wl,-Map=$(TARGET).map \
		  			-L ../ $(LINKER_FILE)
        OBJDUMP = arm-none-eabi-objdump
        SIZE = arm-none-eabi-size 

else
	# Compiler Flags & Defines
	CC = gcc
	LD = ld
	CFLAGS = $(G_FLAGS)
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(TARGET).map
	OBJDUMP = objdump
	SIZE = size
endif

# Building Object file (file.o)
# Building Dependency file (file.d)
# Building Assembly file (file.asm)
# Building Preprocessed file (file.i)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
ASMS = $(SRCS:.c=.asm)
PREP = $(SRCS:.c=.i)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

%.i: %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.d: %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: Clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PREP) $(TARGET).out $(TARGET).map