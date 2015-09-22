#ifndef QUEUESTR_H
#define QUEUESTR_H

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct queue_str
{
	size_t head;
	size_t tail;

	char** buf;
	size_t capacity;
	int lastop;
} queue_str;

#define QUE_READ  0
#define QUE_WRITE 1

extern size_t QUE_STR_START_CAP;

/* hmm */
char* mystrdup(const char* str);

int que_str(queue_str* q, size_t capacity);
int que_push_str(queue_str* q, char* a);
void que_pop_str(queue_str* q);

int que_pushe_str(queue_str* q, char* a);
int que_resize_str(queue_str* q, size_t size);

char* que_front_str(queue_str* q);
char* que_back_str(queue_str* q);
int que_is_empty_str(queue_str* q);
int que_is_full_str(queue_str* q);
size_t que_size_str(queue_str* q);

void free_que_str(void* q);


#ifdef __cplusplus
}
#endif

/* header ends */
#endif 


