#include "doublelinkedlist.h"

struct DoubleLinkedList* createDoubleLinkedList(){
  struct DoubleLinkedList* doubleLinkedList = malloc(sizeof(struct DoubleLinkedList));
  doubleLinkedList->head = NULL;
  doubleLinkedList->tail = NULL;

  return doubleLinkedList;
}

struct Node* createNode(struct Node* currentNode, int value){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->value = value;
  newNode->prevNode = currentNode;
  newNode->nextNode = NULL;
  
  return newNode;
}

void addNode(struct DoubleLinkedList* doubleLinkedList, int value){
  if(doubleLinkedList == NULL)
    return;

  if(doubleLinkedList->head == NULL){
    struct Node* newNode = createNode(NULL, value);
    doubleLinkedList->head = newNode;
    doubleLinkedList->tail = newNode;
  }else{
    struct Node* newNode = createNode(doubleLinkedList->tail, value);
    doubleLinkedList->tail->nextNode = newNode;
    doubleLinkedList->tail = newNode;
  }

}

void freeDoubleLinkedList(struct DoubleLinkedList* doubleLinkedList){
  if(doubleLinkedList == NULL)
    return;

  struct Node* currentNode = doubleLinkedList->head;
  struct Node* tmp;
  while(currentNode != NULL){
    tmp = currentNode->nextNode;
    free(currentNode);
    currentNode = tmp;
  } 
}

void printDoubleLinkedList(struct DoubleLinkedList* doubleLinkedList){
  if(doubleLinkedList == NULL)
    return;

  struct Node* currentNode = doubleLinkedList->head;
  while(currentNode != NULL){
    printf("Node value: %d ", currentNode->value);
    if(currentNode->prevNode != NULL){
      printf(":prevNode: %d ", currentNode->prevNode->value);
    }
    if(currentNode->nextNode != NULL){
      printf("nextNode: %d ", currentNode->nextNode->value);
    }
    printf("\n");
    currentNode = currentNode->nextNode;
  } 
}
//void deleteEnd(struct DoubleLinkedList);
//void deleteHead(struct DoubleLinkedList);
