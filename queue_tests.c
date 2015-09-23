#include "queue_i.h"
#include "queue_d.h"
#include "queue_str.h"
#include "queue_void.h"

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
		CU_ASSERT_EQUAL(tmp, out);
	}
	/*
	for (j=0; j<q.capacity; ++j)
		printf("%.1f ", q.buf[j]);
	putchar('\n');
	*/

	for (j=0; j<3; ++j, ++in)
		que_push_d(&q, in);

	que_resize_d(&q, 20);

	for (j=0; j<10; ++j, ++in)
		que_push_d(&q, in);

	for (j=0; j<20; ++j, ++out) {
		tmp = que_pop_d(&q);
		CU_ASSERT_EQUAL(tmp, out);
	}

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




/** Structure used to test generic queue. */
typedef struct t_struct
{
	double d;
	int i;
	char word[30];
} t_struct;

/** Structure used to test generic queue. */
typedef struct f_struct
{
	double d;
	int i;
	char* word;
} f_struct;


t_struct mk_t_struct(double d, int i, char* word)
{
	/*could make this static since I'm just copying the values outside */
	t_struct a;
	a.d = d;
	a.i = i;
	strcpy(a.word, word);
	return a;
}

f_struct mk_f_struct(double d, int i, char* word)
{
	/*could make this static since I'm just copying the values outside */
	f_struct a;
	a.d = d;
	a.i = i;
	a.word = mystrdup(word);
	return a;
}


#define GET_T(X,Y) ((t_struct*)&X.buf[Y*X.elem_size])
#define GET_F(X,Y) ((f_struct*)&X.buf[Y*X.elem_size])

void free_f_struct(void* tmp)
{
	f_struct* f = (f_struct*)tmp;
	if (f->word) {
		free(f->word);
		f->word = NULL;
	}
}


void init_f_struct(void* dest, void* src)
{
	f_struct* d = (f_struct*)dest;
	f_struct* s = (f_struct*)src;
	d->i = s->i;
	d->d = s->d;
	d->word = mystrdup(s->word);
}


void pushpop_void_test()
{
	char buffer[50];
	int in, out, j;
	t_struct temp;
	f_struct temp2;
	t_struct* tptr;
	f_struct* fptr;

	queue_void q1;
	queue_void q2;

	que_void(&q1, 0, sizeof(t_struct), NULL, NULL);
	que_void(&q2, 50,  sizeof(f_struct), free_f_struct, NULL);

	CU_ASSERT_EQUAL(QUE_VOID_START_CAP, q1.capacity);
	CU_ASSERT_EQUAL(50, q2.capacity);

	for (in=0; in<50; ++in) {
		sprintf(buffer, "%d", in);
		temp = mk_t_struct(in, in, buffer);
		temp2 = mk_f_struct(in, in, buffer);

		que_push_void(&q1, &temp);
		que_push_void(&q2, &temp2);
	}

	CU_ASSERT_EQUAL(50, que_size_void(&q1));
	CU_ASSERT_EQUAL(50, que_size_void(&q2));

	
	for (out=0; out<50; ++out) {
		tptr = (t_struct*)que_front_void(&q1);
		fptr = (f_struct*)que_front_void(&q2);


		sprintf(buffer, "%d", out);
		CU_ASSERT_EQUAL(out, tptr->d);
		CU_ASSERT_EQUAL(out, tptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, tptr->word);

		CU_ASSERT_EQUAL(out, fptr->d);
		CU_ASSERT_EQUAL(out, fptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, fptr->word);

		que_pop_void(&q1);
		que_pop_void(&q2);
	}
	CU_ASSERT(que_is_empty_void(&q1));
	CU_ASSERT(que_is_empty_void(&q2));

	free_que_void(&q1);
	free_que_void(&q2);

}

void pushe_void_test()
{
	char buffer[50];
	int in, out, j;
	t_struct temp;
	f_struct temp2;
	t_struct* tptr;
	f_struct* fptr;

	queue_void q1;
	queue_void q2;

	que_void(&q1, 16, sizeof(t_struct), NULL, NULL);
	que_void(&q2, 20,  sizeof(f_struct), free_f_struct, NULL);

	CU_ASSERT_EQUAL(16, q1.capacity);
	CU_ASSERT_EQUAL(20, q2.capacity);

	for (in=0; in<50; ++in) {
		sprintf(buffer, "%d", in);
		temp = mk_t_struct(in, in, buffer);
		temp2 = mk_f_struct(in, in, buffer);

		que_pushe_void(&q1, &temp);
		que_pushe_void(&q2, &temp2);
	}

	CU_ASSERT_EQUAL(50, que_size_void(&q1));
	CU_ASSERT_EQUAL(50, que_size_void(&q2));

	CU_ASSERT_EQUAL(64, q1.capacity);
	CU_ASSERT_EQUAL(80, q2.capacity);

	
	for (out=0; out<50; ++out) {
		tptr = (t_struct*)que_front_void(&q1);
		fptr = (f_struct*)que_front_void(&q2);

		sprintf(buffer, "%d", out);
		CU_ASSERT_EQUAL(out, tptr->d);
		CU_ASSERT_EQUAL(out, tptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, tptr->word);

		CU_ASSERT_EQUAL(out, fptr->d);
		CU_ASSERT_EQUAL(out, fptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, fptr->word);

		que_pop_void(&q1);
		que_pop_void(&q2);
	}
	CU_ASSERT(que_is_empty_void(&q1));
	CU_ASSERT(que_is_empty_void(&q2));

	free_que_void(&q1);
	free_que_void(&q2);
}

void resize_void_test()
{
	char buffer[50];
	int in, out, j;
	t_struct temp;
	f_struct temp2;
	t_struct* tptr;
	f_struct* fptr;

	queue_void q1;
	queue_void q2;

	que_void(&q1, 30, sizeof(t_struct), NULL, NULL);
	que_void(&q2, 30,  sizeof(f_struct), free_f_struct, NULL);

	CU_ASSERT_EQUAL(30, q1.capacity);
	CU_ASSERT_EQUAL(30, q2.capacity);

	for (in=0; in<30; ++in) {
		sprintf(buffer, "%d", in);
		temp = mk_t_struct(in, in, buffer);
		temp2 = mk_f_struct(in, in, buffer);

		que_push_void(&q1, &temp);
		que_push_void(&q2, &temp2);
	}

	CU_ASSERT_EQUAL(30, que_size_void(&q1));
	CU_ASSERT_EQUAL(30, que_size_void(&q2));

	for (out=0; out<5; ++out) {
		tptr = (t_struct*)que_front_void(&q1);
		fptr = (f_struct*)que_front_void(&q2);

		sprintf(buffer, "%d", out);
		CU_ASSERT_EQUAL(out, tptr->d);
		CU_ASSERT_EQUAL(out, tptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, tptr->word);

		CU_ASSERT_EQUAL(out, fptr->d);
		CU_ASSERT_EQUAL(out, fptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, fptr->word);

		que_pop_void(&q1);
		que_pop_void(&q2);
	}

	for (j=0; j<5; ++j, ++in) {
		sprintf(buffer, "%d", in);
		temp = mk_t_struct(in, in, buffer);
		temp2 = mk_f_struct(in, in, buffer);

		que_push_void(&q1, &temp);
		que_push_void(&q2, &temp2);
	}

	CU_ASSERT_EQUAL(30, que_size_void(&q1));
	CU_ASSERT_EQUAL(30, que_size_void(&q2));

	que_resize_void(&q1, 50);
	que_resize_void(&q2, 50);

	
	for (j=0; j<30; ++j, ++out) {
		tptr = (t_struct*)que_front_void(&q1);
		fptr = (f_struct*)que_front_void(&q2);

		sprintf(buffer, "%d", out);
		CU_ASSERT_EQUAL(out, tptr->d);
		CU_ASSERT_EQUAL(out, tptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, tptr->word);

		CU_ASSERT_EQUAL(out, fptr->d);
		CU_ASSERT_EQUAL(out, fptr->i);
		CU_ASSERT_STRING_EQUAL(buffer, fptr->word);

		que_pop_void(&q1);
		que_pop_void(&q2);
	}
	CU_ASSERT(que_is_empty_void(&q1));
	CU_ASSERT(que_is_empty_void(&q2));

	free_que_void(&q1);
	free_que_void(&q2);

}



