#include "queue_d.h"

#include <string.h>
#include <assert.h>

size_t QUE_D_START_CAP = 50;

#define QUE_D_ALLOCATOR(x) ((x) * 2)

int que_d(queue_d* q, size_t capacity)
{
	q->head = q->tail = 0;
	q->lastop = QUE_READ;
	q->capacity = capacity ? capacity : QUE_D_START_CAP;

	if (!(q->buf = (double*)malloc(q->capacity*sizeof(double)))) {
		assert(q->buf != NULL);
		q->capacity = 0;
		return 0;
	}

	return 1;
}

int que_push_d(queue_d* q, double a)
{
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		assert(q->head != q->tail || q->lastop != QUE_WRITE);
		return 0;
	}

	q->buf[q->tail] = a;
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

int que_pushe_d(queue_d* q, double a)
{
	double* tmp;
	size_t tmp_sz, inc;
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		tmp_sz = QUE_D_ALLOCATOR(q->capacity);
		inc = tmp_sz - q->capacity;
		if (!(tmp = (double*)realloc(q->buf, sizeof(double)*tmp_sz))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

		/* hmmm */
		if (q->head) {
			memmove(&q->buf[q->head+inc], &q->buf[q->head], (q->capacity-q->head)*sizeof(double));
		} else {
			q->tail = q->capacity;
		}

		q->capacity = tmp_sz;
	}

	q->buf[q->tail] = a;
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

/*
 * it's programmers responsibility 
 * to make sure it's not empty
*/
double que_pop_d(queue_d* q)
{
	double a;

	assert(q->head != q->tail || q->lastop == QUE_WRITE);

	a = q->buf[q->head];
	q->head++;
	q->head %= q->capacity;
	q->lastop = QUE_READ;

	if (q->head == q->tail)
		q->head = q->tail = 0;

	return a;
}

int que_resize_d(queue_d* q, size_t size)
{
	size_t sz;
	double* tmp = NULL;

	sz = que_size_d(q);
	if (size < sz) {
		assert(size >= sz);
		return 0;
	}

	if (size > q->capacity && q->tail > q->head) {
		if (!(tmp = (double*)realloc(q->buf, sizeof(double)*size))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

	} else {
		tmp = (double*)malloc(size*sizeof(double));
		if (q->tail <= q->head) {
			memcpy(tmp, &q->buf[q->head], (q->capacity-q->head)*sizeof(double));
			memcpy(&tmp[q->capacity-q->head], q->buf, q->tail*sizeof(double));
		} else {
			memcpy(tmp, &q->buf[q->head], (q->tail-q->head)*sizeof(double));
		}

		free(q->buf);
		q->buf = tmp;
		q->head = 0;
		q->tail = sz;
	}

	q->capacity = size;
	return 1;
}

double que_front_d(queue_d* q)
{
	return q->buf[q->head];
}

double que_back_d(queue_d* q)
{
	return q->buf[q->tail-1];
}


int que_is_empty_d(queue_d* q)
{
	return q->head == q->tail && q->lastop == QUE_READ;
}

int que_is_full_d(queue_d* q)
{
	return q->head == q->tail && q->lastop == QUE_WRITE;
}

size_t que_size_d(queue_d* q)
{
	if (q->tail < q->head) {
		return q->capacity - q->head + q->tail;
	} else if (q->tail > q->head) {
		return q->tail - q->head;
	} else if (q->lastop == QUE_WRITE) {
		return q->capacity;
	} else {
		return 0;
	}
}

void free_que_d(void* q)
{
	queue_d* tmp = (queue_d*)q;
	free(tmp->buf);
	tmp->capacity = 0;
}


