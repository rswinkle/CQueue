#include "queue_str.h"

#include <string.h>
#include <assert.h>

size_t QUE_STR_START_CAP = 50;

#define QUE_STR_ALLOCATOR(x) ((x) * 2)

char* mystrdup(const char* str)
{
	
	size_t len = strlen(str);
	char* temp = (char*)calloc(len+1, sizeof(char));
	if (!temp) {
		assert(temp != NULL);
		return NULL;
	}
	
	return (char*)memcpy(temp, str, len);  
}

int que_str(queue_str* q, size_t capacity)
{
	q->head = q->tail = 0;
	q->lastop = QUE_READ;
	q->capacity = capacity ? capacity : QUE_STR_START_CAP;

	if (!(q->buf = (char**)malloc(q->capacity*sizeof(char*)))) {
		assert(q->buf != NULL);
		q->capacity = 0;
		return 0;
	}

	return 1;
}

int que_push_str(queue_str* q, char* a)
{
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		assert(q->head != q->tail || q->lastop != QUE_WRITE);
		return 0;
	}

	q->buf[q->tail] = mystrdup(a);
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

int que_pushe_str(queue_str* q, char* a)
{
	char** tmp;
	size_t tmp_sz, inc;
	if (q->head == q->tail && q->lastop == QUE_WRITE) {
		tmp_sz = QUE_STR_ALLOCATOR(q->capacity);
		inc = tmp_sz - q->capacity;
		if (!(tmp = (char**)realloc(q->buf, sizeof(char*)*tmp_sz))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

		/* hmmm */
		if (q->head) {
			memmove(&q->buf[q->head+inc], &q->buf[q->head], (q->capacity-q->head)*sizeof(char*));
		} else {
			q->tail = q->capacity;
		}

		q->capacity = tmp_sz;
	}

	q->buf[q->tail] = mystrdup(a);
	q->tail++;
	q->tail %= q->capacity;
	q->lastop = QUE_WRITE;
	return 1;
}

/*
 * it's programmers responsibility 
 * to make sure it's not empty
*/
void que_pop_str(queue_str* q)
{
	assert(q->head != q->tail || q->lastop == QUE_WRITE);

	free(q->buf[q->head]);

	q->head++;
	q->head %= q->capacity;
	q->lastop = QUE_READ;

	if (q->head == q->tail)
		q->head = q->tail = 0;
}

int que_resize_str(queue_str* q, size_t size)
{
	size_t sz;
	char** tmp = NULL;

	sz = que_size_str(q);
	if (size < sz) {
		assert(size >= sz);
		return 0;
	}

	if (size > q->capacity && q->tail > q->head) {
		if (!(tmp = (char**)realloc(q->buf, sizeof(char*)*size))) {
			assert(tmp != NULL);
			return 0;
		}
		q->buf = tmp;

	} else {
		tmp = (char**)malloc(size*sizeof(char*));
		if (q->tail <= q->head) {
			memcpy(tmp, &q->buf[q->head], (q->capacity-q->head)*sizeof(char*));
			memcpy(&tmp[q->capacity-q->head], q->buf, q->tail*sizeof(char*));
		} else {
			memcpy(tmp, &q->buf[q->head], (q->tail-q->head)*sizeof(char*));
		}

		free(q->buf);
		q->buf = tmp;
		q->head = 0;
		q->tail = sz;
	}

	q->capacity = size;
	return 1;
}

char* que_front_str(queue_str* q)
{
	return q->buf[q->head];
}

char* que_back_str(queue_str* q)
{
	return q->buf[q->tail-1];
}


int que_is_empty_str(queue_str* q)
{
	return q->head == q->tail && q->lastop == QUE_READ;
}

int que_is_full_str(queue_str* q)
{
	return q->head == q->tail && q->lastop == QUE_WRITE;
}

size_t que_size_str(queue_str* q)
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

void free_que_str(void* q)
{
	size_t sz, i;
	queue_str* tmp = (queue_str*)q;
	sz = que_size_str(tmp);
	for (i=0; i<sz; ++i) {
		free(tmp->buf[(tmp->head+i)%tmp->capacity]);
	}
	free(tmp->buf);
	tmp->capacity = 0;
}


