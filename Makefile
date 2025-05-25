#   arboreta-nexus
#   Copyright (C) 2025  Mirko Lindroth
#
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License version 2.0
#   as published by the Free Software Foundation.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License version 2.0 for more details.

# Directory settings
makefile_path    := $(abspath $(firstword $(MAKEFILE_LIST)))
makefile_dir     := $(patsubst %/,%,$(dir $(makefile_path)))
src_dir          := $(makefile_dir)/src
test_dir         := $(makefile_dir)/tests

# Output app binary
exe := arbex

# App sources
src := $(shell find $(src_dir) -type f -name "*.c" -o -name "*.h")
includes := $(sort $(dir $(wildcard $(src_dir)/*/)))
objects := $(patsubst %.c, %.o, $(filter %.c,$(src)))

# Test sources
test_src := $(shell find $(test_dir) -type f -name "*.c" -o -name "*.h")
test_includes := $(sort $(dir $(wildcard $(test_dir)/*/)))
test_objects := $(patsubst %.c, %.o, $(filter %.c,$(test_src)))

CC := gcc

# Recipe settings
SHELL         := bash
.DEFAULT_GOAL := help

.PHONY: help
#: Prints available phony targets
help:
	@for makefile in $(MAKEFILE_LIST); do \
		echo -e "\n$$makefile targets:"; \
		echo -e "-------------------------------"; \
		grep -B1 -E "^[a-zA-Z0-9_-]+:([^\=]|$$)" $$makefile \
			| sed '/^[#||-]/! s/[^:]*$$//' \
			| uniq \
			| grep -v -- -- \
			| sed 'N;s/\n/###/' \
			| sed -n 's/^#: \(.*\)###\(.*\):.*/\2###\1/p' \
			| column -ts '###' \
			| sort; \
	done

.PHONY: test
#: Run tests
test: run_test
	./$<

run_test: $(test_objects) $(objects)
	# Rename main function to arbex
	objcopy --redefine-sym main=arbex $(src_dir)/main.o
	# Rename the test function to main
	objcopy --redefine-sym test=main $(test_dir)/test_lib.o
	# Compile binary 'test'
	gcc $^ -o $@

.PHONY: comp
#: Compile application
comp: $(exe)
# Generate executable artefinery
$(exe): $(objects)
	# In case test was ran previously
	objcopy --redefine-sym arbex=main $(src_dir)/main.o
	gcc $^ -o $@

.PHONY: clean
#: Clean all output files
clean: mostlyclean
	rm -rf $(exe)
	rm -rf run_test

.PHONY: mostlyclean
#: Clean object files and logs
mostlyclean:
	rm -rf $(objects)
	rm -rf $(test_objects)
	rm -rf *.log

$(objects): $(src)

$(test_objects): $(test_src)
