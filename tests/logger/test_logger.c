#include "test_logger.h"
#include "../../src/logger/logger.h"
#include "../test_lib.h"

void test_logger()
{
	log_file = "log.log";

	RUN_TEST(tc_verbosity())
	RUN_TEST(tc_variadic_args())
}

START_TEST(tc_verbosity())
	log_verbosity_g = LOW;

	char *msg = "This is above and should not print!\n";
	info(AVG,msg);

	msg = "This should print!\n";
	info(LOW,msg,msg);
	info(NONE,msg,msg);
END_TEST

START_TEST(tc_variadic_args())
	info(LOW,"This is an %s%c\n","info",'!');
	warning("This is a %s%c\n","warning",'!');
	error("This is an %s%c\n","error",'!');
	fatal("This is a %s%c\n","fatal error",'!');
END_TEST
