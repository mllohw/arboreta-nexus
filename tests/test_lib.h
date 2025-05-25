#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <stddef.h>

#define PROTO_TEST(name) test_data name;

#define START_TEST(name) test_data name\
{ \
	test_data test;\
	test.status = FAIL;\
	test.func_name = __FUNCTION__;\

#define END_TEST\
	test.status = PASS;\
	return test;\
}

#define TEST_FAIL\
	return test;

#define RUN_TEST(test) run_test(test);

typedef enum { FAIL,PASS } status_code;

typedef struct {
	status_code status;
	const char *func_name;
} test_data;

typedef struct {
	int pass_count;
	int warn_count;
	int fail_count;
} test_results;

static test_results results = {0,0,0};
void run_test(test_data test);
void test_summary();
#endif
