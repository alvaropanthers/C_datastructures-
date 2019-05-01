#include <stdio.h>

#include "linkedlist.h"

int main(){
  struct LinkedList* linkedList = createLinkedList();

  int x;
  for(x = 0; x < 5; ++x)
      addNode(linkedList, x);
  ++x;

  insertHead(linkedList, x);
  
  printLinkedList(linkedList);

  deleteEnd(linkedList);
  
  printf("After deletion\n\n");
  
  printLinkedList(linkedList);
  
  
  freeLinkedList(linkedList);

  return 0;
}
