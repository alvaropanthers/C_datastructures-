#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

/**
 * 
 * Circular Queue
 * 
**/

typedef struct Queue{
  void **array;
  int currentSize;
  int size;
  int front;
  int rear;
} Queue;

Queue *Queue_create_queue();
void Queue_free_queue(Queue *queue);
void Queue_expand_queue(Queue *queue);
void Queue_enqueue(Queue *queue, void *value);
void *Queue_dequeue(Queue *queue);
void Queue_print_queue(Queue *queue, void print(void*, int));