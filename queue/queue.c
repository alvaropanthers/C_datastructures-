#include "queue.h"

struct Queue* create_queue(){
  struct Queue* queue = malloc(sizeof(struct Queue));
  queue->array = malloc(MAX_SIZE * sizeof(int));
  queue->size = MAX_SIZE;
  queue->currentSize = 0;
  return queue;
}

void free_queue(struct Queue* queue){
  if(queue == NULL)
    return;

  if(queue->array != NULL)
    free(queue->array);

  free(queue);
}


void expand_queue(struct Queue* queue){
  if(queue == NULL)
    return;

  int newSize = queue->size * 2;
  queue->array = realloc(queue->array, newSize * sizeof(int));
  queue->size = newSize;

}

void enqueue(struct Queue* queue, int value){
  if(queue == NULL)
    return;

  if((queue->currentSize + 1) == queue->size)
    expand_queue(queue);

  int array[queue->currentSize];
  int x = 0;
  //Create copy
  for(x = 0; x < queue->currentSize; ++x)
    array[x] = queue->array[x];

  x = 0;
  queue->array[x] = value;
  for(x = 1; x < queue->currentSize + 1; ++x)
    queue->array[x] = array[x - 1];

  ++(queue->currentSize);
}

int dequeue(struct Queue* queue){
  if(queue == NULL)
    return -1;

  int last = queue->array[queue->currentSize - 1];
  queue->array[queue->currentSize - 1] = -1;
  --(queue->currentSize);

  return last;
}


void print_queue(struct Queue* queue){
  if(queue == NULL)
    return;

  for(int x = 0; x < queue->currentSize; ++x)
    printf("%d\n", queue->array[x]);
  

  
}
