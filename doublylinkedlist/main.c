#include <stdio.h>
#include "doublelinkedlist.h"


int compare(void *value, void *a){
  if(*((int*)value) == *((int*)a)){
    return 1;
  }

  return 0;
}

int main(){

  struct DoubleLinkedList* doubleLinkedList = DoublyLinkedList_create();

  int integer = 11;
  void *ptr = &integer;
  DoublyLinkedList_add_node(doubleLinkedList, ptr);

  Node *found = DoubleLinkedList_find(doubleLinkedList, compare, ptr);
  if(found != NULL){
    printf("value %d found\n", *((int*)found->value_ptr));
  }

  DoubleLinkedList_destroy_node(doubleLinkedList, found);

  int integer_2 = 13;
  ptr = &integer_2;
  DoublyLinkedList_add_node(doubleLinkedList, ptr);

  int integer_3 = 16;
  ptr = &integer_3;
  DoublyLinkedList_add_node(doubleLinkedList, ptr);

  int integer_4 = 18;
  ptr = &integer_4;
  DoublyLinkedList_add_node(doubleLinkedList, ptr);

  DoublyLinkedList_print_integer(doubleLinkedList);

  ptr = &integer_3;
  found = DoubleLinkedList_find(doubleLinkedList, compare, ptr);
  if(found != NULL){
    printf("value %d found\n", *((int*)found->value_ptr));
  }

  DoubleLinkedList_destroy_node(doubleLinkedList, found);

  printf("everything good\n");
  DoublyLinkedList_print_integer(doubleLinkedList);
  
  DoublyLinkedList_free(doubleLinkedList);
  return 0;
}
