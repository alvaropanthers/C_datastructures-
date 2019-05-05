#include <stdio.h>
#include "queue.h"

void custom_print(void *value, int index){
  printf("value %d index %d\n", *((int*)value), index);
}

int main(){
  Queue *queue = Queue_create_queue(5);

  int int1 = 11;
  void *ptr = &int1;
  Queue_enqueue(queue, ptr);

  int int2 = 50;
  ptr = &int2;
  Queue_enqueue(queue, ptr);

  printf("print\n");
  Queue_print_queue(queue, custom_print);

  Queue_dequeue(queue);

  printf("print\n");
  Queue_print_queue(queue, custom_print);

  Queue_free_queue(queue);
}
