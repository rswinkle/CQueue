#ifndef QUEUED_H
#define QUEUED_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct queue_d
{
	size_t head;
	size_t tail;

	double* buf;
	size_t capacity;
	int lastop;
} queue_d;

#define QUE_READ  0
#define QUE_WRITE 1

extern size_t QUE_D_START_CAP;

int que_d(queue_d* q, size_t capacity);
int que_push_d(queue_d* q, double a);
double que_pop_d(queue_d* q);

int que_pushe_d(queue_d* q, double a);
int que_resize_d(queue_d* q, size_t size);

double que_front_d(queue_d* q);
double que_back_d(queue_d* q);
int que_is_empty_d(queue_d* q);
int que_is_full_d(queue_d* q);
size_t que_size_d(queue_d* q);

void free_que_d(void* q);


#ifdef __cplusplus
}
#endif

/* header ends */
#endif 


