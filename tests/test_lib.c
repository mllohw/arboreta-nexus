/**
 *   arboreta-nexus
 *   Copyright (C) 2025  Mirko Lindroth
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2.0
 *   as published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License version 2.0 for more details.
 */
#include "test_lib.h"
#include "logger/test_logger.h"
#include <stdlib.h>
#include <stdio.h>

int test()
{
	test_logger();
	test_summary();
	return EXIT_SUCCESS;
}

void run_test(test_data test)
{
	if(test.status) {
		printf("[\e[0;32mPASS\e[0m] %s\n",test.func_name);
		results.pass_count++;
	} else {
		printf("[\e[0;31mFAIL\e[0m] %s\n",test.func_name);
		results.fail_count++;
	}
}

void test_summary()
{
	printf("\nResults:\n");
	printf("------------------------------------------\n");
	printf("Pass: %d\n",results.pass_count);
	printf("Warning: %d\n",results.warn_count);
	printf("Error: %d\n",results.fail_count);
}
