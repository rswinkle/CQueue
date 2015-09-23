#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/Automated.h>


extern void pushpop_i_test();
extern void pushe_i_test();
extern void resize_i_test();

extern void pushpop_d_test();
extern void pushe_d_test();
extern void resize_d_test();

extern void pushpop_str_test();
extern void pushe_str_test();
extern void resize_str_test();

extern void pushpop_void_test();
extern void pushe_void_test();
extern void resize_void_test();

/*
extern void template_test();
extern void template_test2();

*/



CU_TestInfo queue_i_tests[] = {
	{ "pushpop_i_test",        pushpop_i_test },
	{ "pushe_i_test",          pushe_i_test },
	{ "resize_i_test",         resize_i_test },
	CU_TEST_INFO_NULL
};

CU_TestInfo queue_d_tests[] = {
	{ "pushpop_d_test",        pushpop_d_test },
	{ "pushe_d_test",          pushe_d_test },
	{ "resize_d_test",         resize_d_test },
	CU_TEST_INFO_NULL
};


CU_TestInfo queue_str_tests[] = {
	{ "pushpop_str_test",        pushpop_str_test },
	{ "pushe_str_test",          pushe_str_test },
	{ "resize_str_test",         resize_str_test },
	CU_TEST_INFO_NULL
};


CU_TestInfo queue_void_tests[] = {
	{ "pushpop_void_test",        pushpop_void_test },
	{ "pushe_void_test",          pushe_void_test },
	{ "resize_void_test",         resize_void_test },
	CU_TEST_INFO_NULL
};

/*

CU_TestInfo template_tests[] = {
	{ "template_test",       template_test },
	{ "template_test2",       template_test2 },
	CU_TEST_INFO_NULL
};

*/


CU_SuiteInfo queue_suites[] = {
	{ "queue_i",   NULL, NULL, queue_i_tests },
	{ "queue_d",   NULL, NULL, queue_d_tests },
	{ "queue_str", NULL, NULL, queue_str_tests },
	{ "queue",     NULL, NULL, queue_void_tests   },
	/*
	{ "template", NULL, NULL, template_tests },
	*/
	CU_SUITE_INFO_NULL
};



int main()
{
	CU_ErrorCode error;
	error = CU_initialize_registry();
	if (error != CUE_SUCCESS) {
		fprintf(stderr, "Failed to initialize registry\n");
		return CU_get_error();
	}

	error = CU_register_suites(queue_suites);

	if (error != CUE_SUCCESS) {
		fprintf(stderr, "Failed to register test suite\n");
		return CU_get_error();
	}

	CU_automated_run_tests();
	fprintf(stdout, "CU_get_error() returned %d\n", CU_get_error());

	CU_cleanup_registry();

	return CU_get_error();

}
