#include "linkedlist.h"

LinkedList *LinkedList_create(void){
  LinkedList *linkedList = malloc(sizeof(LinkedList));
  linkedList->head = NULL;
  linkedList->node = NULL;

  return linkedList;
}

Node *LinkedList_create_node(void *value){
  Node *newNode = malloc(sizeof(Node));
  newNode->value_ptr = value;
  newNode->nextNode = NULL;

  return newNode;  
}

void LinkedList_insert_head(LinkedList *linkedList, void *value){
  if(linkedList == NULL){
    return;
  }

  Node *newNode = LinkedList_create_node(value);

  if(linkedList->head == NULL){
    linkedList->head = newNode;
  }else{
    newNode->nextNode = linkedList->head;
    linkedList->head = newNode;
  }

}

void LinkedList_add_node(LinkedList *linkedList, void *value){
  if(linkedList == NULL){
    return;
  }

  Node *newNode = LinkedList_create_node(value);

  if(linkedList->head == NULL){
    linkedList->node = newNode;
    linkedList->head = newNode;
  }else{
    linkedList->node->nextNode = newNode;
    linkedList->node = newNode;
  }
}

Node *LinkedList_get_node(LinkedList *linkedList, int compare(void *, void *), void *value){
  if(linkedList == NULL){
    return NULL;
  }

  Node *currentNode = linkedList->head;
  do{
    if(compare(value, currentNode->value_ptr)){
      return currentNode;
    }
    currentNode = currentNode->nextNode;
  }while(currentNode != NULL);
  
  return NULL;
}

void LinkedList_destroy(LinkedList *linkedList){
  if(linkedList == NULL){
    return;
  }

  LinkedList_free_nodes(linkedList);
  free(linkedList);
}

void LinkedList_destroy_head(LinkedList *linkedList){
  if(linkedList == NULL){
    return;
  }

  if(linkedList->head != NULL){
    Node *tmp = linkedList->head;
    if(tmp->nextNode != NULL){
      linkedList->head = tmp->nextNode;
    }else{
      linkedList->head = NULL;
    }

    LinkedList_free_node(tmp);
  }

}

void LinkedList_destroy_end(LinkedList *linkedList){
  if(linkedList == NULL){
    return;
  }

  Node *currentNode =  linkedList->head;
  Node *prevNode = NULL;
  if(currentNode != NULL){
    while(currentNode->nextNode != NULL){
      prevNode = currentNode;
      currentNode = currentNode->nextNode;
    }

    if(prevNode != NULL){
      prevNode->nextNode = NULL;
      linkedList->node = prevNode;
      LinkedList_free_node(currentNode);
    }else if(prevNode == NULL){
      linkedList->node = NULL;
      linkedList->head = NULL;
      LinkedList_free_node(currentNode);
    }

  }
}

void LinkedList_free_nodes(LinkedList *linkedList){
  if(linkedList == NULL){
    return;
  }

  Node *currentNode;
  currentNode = linkedList->head;

  Node *tmp;
  while(currentNode != NULL){
    tmp = currentNode;
    currentNode = currentNode->nextNode;
    LinkedList_free_node(tmp);
  }

  linkedList->head = NULL;
  linkedList->node = NULL;
}

void LinkedList_free_node(Node *node){
  if(node == NULL){
    return;
  }
  free(node);
}

void LinkedList_print(LinkedList *linkedList){
  if(linkedList == NULL){
    return;
  }

  Node *currentNode = linkedList->head;
  while(currentNode != NULL){
    printf("%d\n", *((int*)currentNode->value_ptr));
    currentNode = currentNode->nextNode;
  }

}