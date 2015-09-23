#include "queue_i.h"
#include "queue_d.h"
#include "queue_str.h"

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

	for (i=0; i<q.capacity; ++i)
		que_push_i(&q, i);

	CU_ASSERT_EQUAL(q.capacity, que_size_i(&q));

	for (i=0; i<q.capacity; ++i)
		CU_ASSERT_EQUAL(i, q.buf[i]);

	for (i=0; i<60; ++i) {
		tmp = que_pop_i(&q);
		printf("%d ", tmp);
		CU_ASSERT_EQUAL(tmp, i);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(40, que_size_i(&q));

	que_resize_i(&q, 50);

	for (i=0; i<10; ++i)
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


/* queue_d tests */
void pushpop_d_test()
{
	double in, out, j, tmp;
	queue_d q;
	que_d(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0.5; in<q.capacity; in++)
		que_push_d(&q, in);

	CU_ASSERT_EQUAL(q.capacity, que_size_d(&q));
	CU_ASSERT(que_is_full_d(&q));


	for (out=0.5; out<10; ++out) {
		tmp = que_pop_d(&q);
		printf("%f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(10, que_size_d(&q));

	for (j=0; j<10; ++in, ++j)
		que_push_d(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_d(&q);
		printf("%f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(0, que_size_d(&q));
	CU_ASSERT(que_is_empty_d(&q));

	free_que_d(&q);
}

void pushe_d_test()
{
	double in, out, j, tmp;
	queue_d q;
	que_d(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0.5; in<100; in++)
		que_pushe_d(&q, in);

	printf("\nsize = %lu\n", (unsigned long)que_size_d(&q));
	CU_ASSERT_EQUAL(100, que_size_d(&q));
	CU_ASSERT_EQUAL(q.capacity, 160);
	CU_ASSERT(!que_is_full_d(&q));


	for (out=0.5; out<10; ++out) {
		tmp = que_pop_d(&q);
		printf("%f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(90, que_size_d(&q));

	for (j=0; j<10; ++in, ++j)
		que_pushe_d(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_d(&q);
		printf("%f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(80, que_size_d(&q));

	free_que_d(&q);
}

void resize_d_test()
{
	double in, out, tmp;
	int j;
	queue_d q;
	que_d(&q, 10);

	CU_ASSERT_EQUAL(10, q.capacity);

	for (in=0.5; in<q.capacity; in++)
		que_push_d(&q, in);

	CU_ASSERT_EQUAL(q.capacity, que_size_d(&q));

	for (j=0; j<q.capacity; ++j)
		CU_ASSERT_EQUAL(j+0.5, q.buf[j]);

	for (out=0.5, j=0; j<3; ++j, ++out) {
		tmp = que_pop_d(&q);
		printf("%.1f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');
	for (j=0; j<q.capacity; ++j)
		printf("%.1f ", q.buf[j]);
	putchar('\n');

	for (j=0; j<3; ++j, ++in)
		que_push_d(&q, in);
	for (j=0; j<q.capacity; ++j)
		printf("%.1f ", q.buf[j]);
	putchar('\n');

	que_resize_d(&q, 20);
	for (j=0; j<q.capacity; ++j)
		printf("%.1f ", q.buf[j]);
	putchar('\n');

	for (j=0; j<10; ++j, ++in)
		que_push_d(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_d(&q);
		printf("%.1f ", tmp);
		CU_ASSERT_EQUAL(tmp, out);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(0, que_size_d(&q));

	free_que_d(&q);

}

/* queue_str tests */
void pushpop_str_test()
{
	int in, out, j;
	char buffer[50];
	queue_str q;
	que_str(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0; in<q.capacity; in++) {
		sprintf(buffer, "hello %d", in);
		que_push_str(&q, buffer);
	}

	CU_ASSERT_EQUAL(q.capacity, que_size_str(&q));
	CU_ASSERT(que_is_full_str(&q));


	for (out=0; out<10; ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(que_front_str(&q), buffer);
		que_pop_str(&q);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(10, que_size_str(&q));

	for (j=0; j<10; ++in, ++j) {
		sprintf(buffer, "hello %d", in);
		que_push_str(&q, buffer);
	}

	for (j=0; j<20; ++j, ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(que_front_str(&q), buffer);
		que_pop_str(&q);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(0, que_size_str(&q));
	CU_ASSERT(que_is_empty_str(&q));

	free_que_str(&q);
}

void pushe_str_test()
{
	int in, out, j;
	char buffer[50];
	queue_str q;
	que_str(&q, 20);

	CU_ASSERT_EQUAL(20, q.capacity);

	for (in=0; in<100; in++) {
		sprintf(buffer, "hello %d", in);
		que_pushe_str(&q, buffer);
	}

	printf("\nsize = %lu\n", (unsigned long)que_size_str(&q));
	CU_ASSERT_EQUAL(100, que_size_str(&q));
	CU_ASSERT_EQUAL(q.capacity, 160);
	CU_ASSERT(!que_is_full_str(&q));


	for (out=0; out<10; ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(q.buf[q.head], buffer);
		que_pop_str(&q);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(90, que_size_str(&q));

	for (j=0; j<10; ++in, ++j) {
		sprintf(buffer, "hello %d", in);
		que_pushe_str(&q, buffer);
	}

	for (j=0; j<20; ++j, ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(q.buf[q.head], buffer);
		que_pop_str(&q);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(80, que_size_str(&q));

	free_que_str(&q);
}

void resize_str_test()
{
	int in, out, j;
	char buffer[50];
	queue_str q;
	que_str(&q, 100);

	CU_ASSERT_EQUAL(100, q.capacity);

	for (in=0; in<q.capacity; ++in) {
		sprintf(buffer, "hello %d", in);
		que_push_str(&q, buffer);
	}

	CU_ASSERT_EQUAL(q.capacity, que_size_str(&q));

	for (j=0; j<q.capacity; ++j) {
		sprintf(buffer, "hello %d", j);
		CU_ASSERT_STRING_EQUAL(q.buf[j], buffer);
	}

	for (out=0; out<60; ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(q.buf[q.head], buffer);
		que_pop_str(&q);
	}
	putchar('\n');
	CU_ASSERT_EQUAL(40, que_size_str(&q));

	que_resize_str(&q, 50);

	for (j=0; j<10; ++j, ++in) {
		sprintf(buffer, "hello %d", in);
		que_push_str(&q, buffer);
	}

	for (j=0; j<15; ++j, ++out) {
		sprintf(buffer, "hello %d", out);
		CU_ASSERT_STRING_EQUAL(q.buf[q.head], buffer);
		que_pop_str(&q);
	}
	putchar('\n');

	CU_ASSERT_EQUAL(35, que_size_str(&q));

	free_que_str(&q);

}

