#include <stdio.h>
#include "queue.h"

int main(){
  struct Queue* queue = create_queue();
  enqueue(queue, 11);
  enqueue(queue, 12);

  print_queue(queue);

  dequeue(queue);

  print_queue(queue);
  
  free_queue(queue);
  printf("Everything is done\n");
}
