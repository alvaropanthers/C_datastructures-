#include "queue.h"

Queue *Queue_create_queue(int size){
  Queue *queue = malloc(sizeof(Queue));
  queue->array = malloc(size * sizeof(void*));
  queue->size = size;
  queue->currentSize = 0;
  queue->front = 0;
  queue->rear = 0;

  return queue;
}

void Queue_enqueue(Queue *queue, void *value){
  if(queue == NULL){
    return;
  }

  if((queue->rear == queue->size) && (queue->currentSize < queue->size)){
    queue->rear = 0;
  }

  if(queue->currentSize != queue->size){
    queue->array[queue->rear] = value;
    ++(queue->rear);
    ++(queue->currentSize);
  }
}

void *Queue_dequeue(Queue *queue){
  if(queue == NULL){
    return NULL;
  }

  void *firstIn = queue->array[queue->front];
  queue->array[queue->front] = NULL;

  if((queue->front + 1) == queue->size){
    queue->front = 0;
  }else{
    ++(queue->front);
  }

  --(queue->currentSize);
 
  return firstIn;
}

void Queue_free_queue(Queue *queue){
  if(queue == NULL){
    return;
  }

  if(queue->array != NULL){
    free(queue->array);
  }

  free(queue);
}

void Queue_print_queue(Queue *queue, void print(void*, int)){
  if(queue == NULL){
    return;
  }

  for(int x = 0; x < queue->size; ++x){
    if(queue->array[x] != NULL){
      print(queue->array[x], x);
    }
  }

}
