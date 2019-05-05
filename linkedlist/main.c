#include <stdio.h>
#include "linkedlist.h"

int compare(void *value, void *a){
  if(*((int*)value) == *((int*)a)){
    return 1;
  }

  return 0;
}

int main(){
  LinkedList* linkedList = LinkedList_create();
  LinkedList_destroy_end(linkedList);

  int x = 12;
  void *ptr = &x;
  LinkedList_add_node(linkedList, ptr);
  int c = 15;
  ptr = &c;
  LinkedList_add_node(linkedList, ptr);


  LinkedList_print(linkedList);

  LinkedList_destroy_end(linkedList);
  
  printf("After deletion\n\n");
  
  LinkedList_print(linkedList);
  
  int toFind = 12;
  ptr = &toFind;
  Node *found = LinkedList_get_node(linkedList, compare, ptr);
  if(found == NULL){
    printf("found = NULL\n");
  }else{
    printf("found =  %d\n", *((int*)found->value_ptr));
  }

  LinkedList_destroy(linkedList);

  return 0;
}
