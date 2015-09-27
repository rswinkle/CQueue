#include "queue_all.h"

#include <iostream>



using namespace std;

int main(int argc, char** argv)
{
	queue_i quei;
	queue_d qued;
	queue_str questr;
	queue_void quevoid;


	que_i(&quei, 10);
	que_d(&qued, 10);
	que_str(&questr, 10);
	que_void(&quevoid, 10, sizeof(long double), NULL, NULL);


	//THIS IS REALLY JUST A C++ compilation test
	//functionality testing is done in main.c and queue_tests.h

	free_que_i(&quei);
	free_que_d(&qued);
	free_que_str(&questr);
	free_que_void(&quevoid);


	return 0;
}

