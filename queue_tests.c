#include "queue_i.h"

#include <stdio.h>


#include <CUnit/Automated.h>

#define STDERR(X) fprintf(stderr, X)


/* queue_i tests */
void pushpop_i_test()
{
	int in, out, j, tmp;
	queue_i q;
	que_i(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0; in<q.capacity; in++)
		que_push_i(&q, in);

	CU_ASSERT_EQUAL(q.capacity, que_size_i(&q));
	CU_ASSERT(que_is_full_i(&q));


	for (out=0; out<10; ++out) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(10, que_size_i(&q));

	for (j=0; j<10; ++in, ++j)
		que_push_i(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(0, que_size_i(&q));
	CU_ASSERT(que_is_empty_i(&q));

	free_que_i(&q);
}

void pushe_i_test()
{
	int in, out, j, tmp;
	queue_i q;
	que_i(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0; in<100; in++)
		que_pushe_i(&q, in);

	printf("\nsize = %lu\n", (unsigned long)que_size_i(&q));
	CU_ASSERT_EQUAL(100, que_size_i(&q));
	CU_ASSERT_EQUAL(q.capacity, 160);
	CU_ASSERT(!que_is_full_i(&q));


	for (out=0; out<10; ++out) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(90, que_size_i(&q));

	for (j=0; j<10; ++in, ++j)
		que_pushe_i(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(80, que_size_i(&q));

	free_que_i(&q);
}

void resize_i_test()
{
	int i, tmp;
	queue_i q;
	que_i(&q, 100);

	CU_ASSERT_EQUAL(100, q.capacity);

	for (i=0; i<q.capacity; i++)
		que_push_i(&q, i);

	CU_ASSERT_EQUAL(q.capacity, que_size_i(&q));

	for (i=0; i<q.capacity; i++)
		CU_ASSERT_EQUAL(i, q.buf[i]);

	for (i=0; i<60; ++i) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, i);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(40, que_size_i(&q));

	que_resize_i(&q, 50);

	for (i=0; i<10; i++)
		que_push_i(&q, i+100);

	for (i=0; i<15; ++i) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, i+60);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(35, que_size_i(&q));

	free_que_i(&q);

}
