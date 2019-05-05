#include "doublelinkedlist.h"

DoubleLinkedList *DoublyLinkedList_create(){
  DoubleLinkedList *doubleLinkedList = malloc(sizeof(DoubleLinkedList));
  doubleLinkedList->head = NULL;
  doubleLinkedList->tail = NULL;

  return doubleLinkedList;
}

Node *DoublyLinkedList_create_node(Node *currentNode, void *value){
  Node *newNode = malloc(sizeof(Node));
  newNode->value_ptr = value;
  newNode->prevNode = currentNode;
  newNode->nextNode = NULL;
  
  return newNode;
}

void DoublyLinkedList_add_node(DoubleLinkedList *doubleLinkedList, void *value){
  if(doubleLinkedList == NULL){
    return;
  }

  if(doubleLinkedList->head == NULL){
    Node *newNode = DoublyLinkedList_create_node(NULL, value);
    doubleLinkedList->head = newNode;
    doubleLinkedList->tail = newNode;
  }else{
    Node *newNode = DoublyLinkedList_create_node(doubleLinkedList->tail, value);
    doubleLinkedList->tail->nextNode = newNode;
    doubleLinkedList->tail = newNode;
  }

}

Node *DoubleLinkedList_find(DoubleLinkedList *doubleLinkedList, int compare(void *value, void *b), void *value){
  if(doubleLinkedList == NULL){
    return NULL;
  }

  Node *currentNode = doubleLinkedList->head;
  while(currentNode != NULL){
    if(compare(value, currentNode->value_ptr)){
      return currentNode;
    }
    currentNode = currentNode->nextNode;
  }

  return NULL;
}

void DoubleLinkedList_destroy_node(DoubleLinkedList *doubleLinkedList, Node *node){
  if(doubleLinkedList == NULL){
    return;
  }

  Node *currentNode = doubleLinkedList->head;
  while(currentNode != NULL){
    if(currentNode == node){
      break;
    }

    currentNode = currentNode->nextNode;
  }

  if(currentNode != NULL && currentNode->prevNode == NULL){
    free(currentNode);
    doubleLinkedList->head = NULL;
    doubleLinkedList->tail = NULL;
  }else if(currentNode != NULL){
    currentNode->prevNode->nextNode = currentNode->nextNode;
    if(currentNode->nextNode != NULL){
      currentNode->nextNode->prevNode = currentNode->prevNode;
    }
    free(currentNode);  
  }


}

void DoublyLinkedList_free(DoubleLinkedList *doubleLinkedList){
  if(doubleLinkedList == NULL){
    return;
  }

  Node *currentNode = doubleLinkedList->head;
  Node *tmp;
  while(currentNode != NULL){
    tmp = currentNode->nextNode;
    free(currentNode);
    currentNode = tmp;
  } 
}

void DoublyLinkedList_print_integer(DoubleLinkedList *doubleLinkedList){
  if(doubleLinkedList == NULL){
    return;
  }

  Node* currentNode = doubleLinkedList->head;
  while(currentNode != NULL){
    printf("Node value: %d ", *((int*)currentNode->value_ptr));
    if(currentNode->prevNode != NULL){
      printf(":prevNode: %d ", *((int*)currentNode->prevNode->value_ptr));
    }
    if(currentNode->nextNode != NULL){
      printf("nextNode: %d ", *((int*)currentNode->nextNode->value_ptr));
    }
    printf("\n");
    currentNode = currentNode->nextNode;
  } 
}