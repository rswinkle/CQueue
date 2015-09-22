#ifndef CQUEUE_H
#define CQUEUE_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct queue_i
{
	size_t head;
	size_t tail;

	int* buf;
	size_t capacity;
	int lastop;
} queue_i;

#define QUE_READ  0
#define QUE_WRITE 1

extern size_t QUE_I_START_CAP;

int que_i(queue_i* q, size_t capacity);
int que_push_i(queue_i* q, int a);
int que_pop_i(queue_i* q);
int que_resize_i(queue_i* q, size_t size);
int que_front_i(queue_i* q);
int que_back_i(queue_i* q);
int que_is_empty_i(queue_i* q);
int que_is_full_i(queue_i* q);
size_t que_size_i(queue_i* q);

void free_que_i(void* q);


#ifdef __cplusplus
}
#endif

/* header ends */
#endif 

