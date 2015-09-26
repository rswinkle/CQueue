#include "queue_i.h"

#include <string.h>
#include <assert.h>

size_t QUE_I_START_CAP = 50;

#define QUE_I_ALLOCATOR(x) ((x) * 2)

int que_i(queue_i* q, size_t capacity)
{
	q->head = q->tail = 0;
	q->lastop = QUE_READ;
	q->capacity = capacity ? capacity : QUE_I_START_CAP;

	if (!(q->buf = (int*)malloc(q->capacity*sizeof(int)))) {
		assert(q->buf != NULL);
		q->capacity = 0;
		return 0;
	}

	return 1;
}

int que_push_i(queue_i* q, int a)
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

int que_pushe_i(queue_i* q, int a)
{
	int* tmp;
	size_t tmp_sz, inc;
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		tmp_sz = QUE_I_ALLOCATOR(q->capacity);
		inc = tmp_sz - q->capacity;
		if (!(tmp = (int*)realloc(q->buf, sizeof(int)*tmp_sz))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

		/* hmmm */
		if (q->head) {
			memmove(&q->buf[q->head+inc], &q->buf[q->head], (q->capacity-q->head)*sizeof(int));
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
 * like vector pop_i, it's programmers responsibility 
 * to make sure it's not empty
*/
int que_pop_i(queue_i* q)
{
	int a;

	assert(q->head != q->tail || q->lastop == QUE_WRITE);

	a = q->buf[q->head];
	q->head++;
	q->head %= q->capacity;
	q->lastop = QUE_READ;

	if (q->head == q->tail)
		q->head = q->tail = 0;

	return a;
}

int que_resize_i(queue_i* q, size_t size)
{
	size_t sz;
	int* tmp = NULL;

	sz = que_size_i(q);
	if (size < sz) {
		assert(size >= sz);
		return 0;
	}

	if (size > q->capacity && q->tail > q->head) {
		if (!(tmp = (int*)realloc(q->buf, sizeof(int)*size))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

	} else {
		tmp = (int*)malloc(size*sizeof(int));
		if (q->tail <= q->head) {
			memcpy(tmp, &q->buf[q->head], (q->capacity-q->head)*sizeof(int));
			memcpy(&tmp[q->capacity-q->head], q->buf, q->tail*sizeof(int));
		} else {
			memcpy(tmp, &q->buf[q->head], (q->tail-q->head)*sizeof(int));
		}
		free(q->buf);
		q->buf = tmp;
		q->head = 0;
		q->tail = sz;
	}

	q->capacity = size;
	return 1;
}

int que_front_i(queue_i* q)
{
	return q->buf[q->head];
}

int que_back_i(queue_i* q)
{
	return q->buf[q->tail-1];
}


int que_is_empty_i(queue_i* q)
{
	return q->head == q->tail && q->lastop == QUE_READ;
}

int que_is_full_i(queue_i* q)
{
	return q->head == q->tail && q->lastop == QUE_WRITE;
}

size_t que_size_i(queue_i* q)
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

void free_que_i(void* q)
{
	queue_i* tmp = (queue_i*)q;
	free(tmp->buf);
	tmp->capacity = 0;
}

