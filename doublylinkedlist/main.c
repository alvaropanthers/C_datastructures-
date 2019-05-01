#include <stdio.h>
#include "doublelinkedlist.h"


int main(){

  struct DoubleLinkedList* doubleLinkedList = createDoubleLinkedList();
  addNode(doubleLinkedList, 11);
  addNode(doubleLinkedList, 13);
  addNode(doubleLinkedList, 16);
  addNode(doubleLinkedList, 18);
  printDoubleLinkedList(doubleLinkedList);
  freeDoubleLinkedList(doubleLinkedList);
  return 0;
}
