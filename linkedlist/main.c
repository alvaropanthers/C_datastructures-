#include <stdio.h>

#include "linkedlist.h"

int main(){
  LinkedList* linkedList = LinkedList_create();
  LinkedList_destroy_end(linkedList);

  int x;
  for(x = 0; x < 5; ++x)
      LinkedList_add_node(linkedList, x);
  ++x;

  LinkedList_insert_head(linkedList, x);
  
  LinkedList_print(linkedList);

  LinkedList_destroy_end(linkedList);
  
  printf("After deletion\n\n");
  
  LinkedList_print(linkedList);
  
  


  Node *found = LinkedList_get_node(linkedList, 3);
  if(found == NULL){
    printf("found = NULL\n");
  }else{
    printf("found =  %d\n", found->value);
  }

  LinkedList_destroy(linkedList);
  
  return 0;
}
