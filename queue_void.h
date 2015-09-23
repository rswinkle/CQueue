#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char byte;

typedef struct queue_void
{
	size_t head;
	size_t tail;

	byte* buf;
	size_t capacity;
	int lastop;

	size_t elem_size;
	void (*elem_init)(void*, void*);
	void (*elem_free)(void*);

} queue_void;

#define QUE_READ  0
#define QUE_WRITE 1

extern size_t QUE_VOID_START_CAP;

#define GET_VOID(QUE, TYPE, I) ((TYPE*)&(QUE)->a[(I)*(QUE)->elem_size])

int que_void(queue_void* q, size_t capacity, size_t elem_sz, void(*elem_free)(void*), void(*elem_init)(void*, void*));
int que_push_void(queue_void* q, void* a);
void que_pop_void(queue_void* q);

int que_pushe_void(queue_void* q, void* a);
int que_resize_void(queue_void* q, size_t size);

void* que_front_void(queue_void* q);
void* que_back_void(queue_void* q);
int que_is_empty_void(queue_void* q);
int que_is_full_void(queue_void* q);
size_t que_size_void(queue_void* q);

void free_que_void(void* q);


#ifdef __cplusplus
}
#endif

/* header ends */
#endif 



