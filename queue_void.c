#include "queue_void.h"

#include <string.h>
#include <assert.h>

size_t QUE_VOID_START_CAP = 50;

#define QUE_VOID_ALLOCATOR(x) ((x) * 2)


int que_void(queue_void* q, size_t capacity, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*))
{
	q->head = q->tail = 0;
	q->lastop = QUE_READ;
	q->capacity = capacity ? capacity : QUE_VOID_START_CAP;

	if (!(q->buf = (byte*)malloc(q->capacity*elem_sz))) {
		assert(q->buf != NULL);
		q->capacity = 0;
		return 0;
	}

	q->elem_size = elem_sz;
	q->elem_free = elem_free;
	q->elem_init = elem_init;

	return 1;
}

int que_push_void(queue_void* q, void* a)
{
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		assert(q->head != q->tail || q->lastop != QUE_WRITE);
		return 0;
	}

	if (q->elem_init) {
		q->elem_init(&q->buf[q->tail*q->elem_size], a);
	} else {
		memcpy(&q->buf[q->tail*q->elem_size], a, q->elem_size);
	}
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

int que_pushe_void(queue_void* q, void* a)
{
	byte* tmp;
	size_t tmp_sz;
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		tmp_sz = QUE_VOID_ALLOCATOR(q->capacity);
		if (!(tmp = (byte*)realloc(q->buf, tmp_sz*q->elem_size))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

		/* hmmm */
		if (q->head) {
			memmove(&q->buf[(q->head+tmp_sz-q->capacity)*q->elem_size], &q->buf[q->head*q->elem_size], (q->capacity-q->head)*q->elem_size);
		} else {
			q->tail = q->capacity;
		}

		q->capacity = tmp_sz;
	}

	if (q->elem_init) {
		q->elem_init(&q->buf[q->tail*q->elem_size], a);
	} else {
		memcpy(&q->buf[q->tail*q->elem_size], a, q->elem_size);
	}
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

/*
 * it's programmers responsibility 
 * to make sure it's not empty
*/
void que_pop_void(queue_void* q)
{
	assert(q->head != q->tail || q->lastop == QUE_WRITE);

	if (q->elem_free) {
		q->elem_free(&q->buf[q->head*q->elem_size]);
	}

	q->head++;
	q->head %= q->capacity;
	q->lastop = QUE_READ;

	if (q->head == q->tail)
		q->head = q->tail = 0;
}

int que_resize_void(queue_void* q, size_t size)
{
	size_t sz;
	byte* tmp = NULL;

	sz = que_size_void(q);
	if (size < sz) {
		assert(size < sz);
		return 0;
	}

	if (size > q->capacity && q->tail > q->head) {
		if (!(tmp = (byte*)realloc(q->buf, size*q->elem_size))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

	} else {
		tmp = (byte*) malloc(size * q->elem_size);
		if (q->tail <= q->head) {
			memcpy(tmp, &q->buf[q->head*q->elem_size], (q->capacity-q->head)*q->elem_size);
			memcpy(&tmp[(q->capacity-q->head)*q->elem_size], q->buf, q->tail*q->elem_size);

		} else {
			memcpy(tmp, &q->buf[q->head*q->elem_size], (q->tail-q->head)*q->elem_size);
		}

		free(q->buf);
		q->buf = tmp;
		q->head = 0;
		q->tail = sz;
	}

	q->capacity = size;
	return 1;
}

void* que_front_void(queue_void* q)
{
	return (void*)&q->buf[q->head*q->elem_size];
}

void* que_back_void(queue_void* q)
{
	return (void*)&q->buf[(q->tail-1)*q->elem_size];
}


int que_is_empty_void(queue_void* q)
{
	return q->head == q->tail && q->lastop == QUE_READ;
}

int que_is_full_void(queue_void* q)
{
	return q->head == q->tail && q->lastop == QUE_WRITE;
}

size_t que_size_void(queue_void* q)
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

void free_que_void(void* q)
{
	size_t sz, i;
	queue_void* tmp = (queue_void*)q;
	sz = que_size_void(tmp);
	if (tmp->elem_free) {
		for (i=0; i<sz; ++i) {
			tmp->elem_free(&tmp->buf[((tmp->head+i)%tmp->capacity) * tmp->elem_size]);
		}
	}
	free(tmp->buf);
	tmp->capacity = 0;
}



