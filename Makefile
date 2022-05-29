# ! VERSION - 1.0

# Target declaration
.phony = all clean slean_shell_cmd clean_shell_sh tests

# Declarations
EXECUTABLE_NAME ?= roobushin

# Determine if file has root access
ROOT = $(shell whoami) # Lates versions will implment use cases for this

# Lets suppose we are working with a Windows operating system "by default"
OS_NAME ?= WINDOWS
SHELL_NAME ?= cmd

# Start OS_NAME and SHELL_NAME tests [thanks to: https://gist.github.com/sighingnow/deee806603ec9274fd47
ifeq ($(OS), Windows_NT)
	OS_NAME = WINDOWS
	ifndef SHELL_NAME
		SHELL_NAME = cmd
	endif
else
	UNAMEOS = $(shell uname -s)
	ifeq ($(UNAMEOS), Linux)
		OS_NAME = LINUX
	endif
	ifeq ($(UNAMEOS), FreeBSD)
		OS_NAME = BSD
	endif
	ifeq ($(UNAMEOS), OpenBSD)
		OS_NAME = BSD
	endif
	ifeq ($(UNAMEOS), NetBSD)
		OS_NAME = BSD
	endif
	ifeq ($(UNAMEOS), DragonFly)
		OS_NAME = BSD
	endif
	ifeq ($(UNAMEOS), Darwin)
		OS_NAME = OSX
	endif
	ifndef SHELL_NAME
		SHELL_NAME = sh
	endif
endif

# Define python command [aka:PYCMD]
PYCMD = python3
ifeq ($(OS_NAME), WINDOWS)
	PYCMD = python
endif

# Define 'C' compiler [aka: CC]
CC = gcc
ifeq ($(OS_NAME), OSX)
# Default compiler for OSX systems
	CC = clang
	GLFW_OSX = -x objective-c
endif
ifeq ($(OS_NAME), BSD)
# Default compiler for BSD systems
	CC = clang
endif

SRC_PATH = ../src
SRC_FILES = $(SRC_PATH)/*.c
INCLUDE_PATH = ../src
INCLUDE_FILES = $(INCLUDE_PATH)/*.h
BUILD_PATH = out
CFLAGS = -std=c99 -O3 -I$(INCLUDE_FILES) -g3 -ggdb
OBJS = $(BUILD_PATH)/*.o
all:
	cd $(BUILD_PATH)/ && $(CC) -c $(SRC_FILES) $(CFLAGS) && cd .. && $(CC) $(OBJS) -o $(EXECUTABLE_NAME) $(CFLAGS)
# Clean everything
clean: clean_shell_$(SHELL_NAME)
clean_shell_sh:
	rm -fv $(BUILD_PATH)/*.o roobushin
clean_shell_cmd:
	rm -f $(BUILD_PATH)/*.o roobushin
ct: cleart_shell_$(SHELL_NAME)
cleart_shell_sh:
	rm -fv tests/*.prc
cleart_shell_cmd:
	rm -f tests/*.prc
licence: licence_$(SHELL_NAME)
licence_sh:
	cat LICENCE_CONTENT.txt
licence_cmd:
	cat LICENCE_CONTENT.txt
# Unsure if cat is on all windows platforms (will be checked in makefile version 1.1+)
# Unsure if rm is on all windows platforms (will be checked in makefile version 1.1+)