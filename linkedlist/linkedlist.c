#include "linkedlist.h"

struct LinkedList* createLinkedList(){
  struct LinkedList* linkedList = malloc(sizeof(struct LinkedList));
  linkedList->head = NULL;
  linkedList->node = NULL;
  return linkedList;
}

void freeLinkedList(struct LinkedList* linkedList){
  if(linkedList == NULL)
    return;

  freeNodes(linkedList);
  free(linkedList);
}

void freeNodes(struct LinkedList* linkedList){
  if(linkedList == NULL)
    return;

  struct Node* currentNode;
  currentNode = linkedList->head;

  struct Node* tmp;
  while(currentNode != NULL){
    tmp = currentNode;
    currentNode = currentNode->nextNode;
    freeNode(tmp);
  }

}

struct Node* createNode(int value){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->value = value;

  return newNode;  
}

void addNode(struct LinkedList* linkedList, int value){
  if(linkedList == NULL)
    return;

  struct Node* newNode = createNode(value);

  if(linkedList->head == NULL){
    linkedList->node = newNode;
    linkedList->head = newNode;
  }else{
    linkedList->node->nextNode = newNode;
    linkedList->node = newNode;
  }
}

void insertHead(struct LinkedList* linkedList, int value){
  if(linkedList == NULL)
    return;

  struct Node* newNode = createNode(value);

  if(linkedList->head == NULL){
    linkedList->head = newNode;
  }else{
    newNode->nextNode = linkedList->head;
    linkedList->head = newNode;

  }

}

void freeNode(struct Node* node){
  if(node == NULL)
    return;
  printf("freing node with value of %d\n", node->value);
  free(node);
}

void deleteTop(struct LinkedList* linkedList){
  if(linkedList == NULL)
    return;

  if(linkedList->head != NULL){
    struct Node* tmp = linkedList->head;
    if(tmp->nextNode != NULL){
      linkedList->head = tmp->nextNode;
    }else{
      linkedList->head = NULL;
    }

    freeNode(tmp);
  }

}

void deleteEnd(struct LinkedList* linkedList){
  if(linkedList == NULL)
    return;

  struct Node* currentNode = linkedList->head;
  if(currentNode->nextNode == NULL){
    linkedList->head = NULL;
    freeNode(currentNode);
  }else{
    struct Node* tmp;
    while(currentNode->nextNode != NULL){
      tmp = currentNode;
      currentNode = currentNode->nextNode;
    }

    if(tmp != NULL){
      freeNode(tmp->nextNode);
      tmp->nextNode = NULL;
      linkedList->node = tmp;
    }
      
  }

}

void printLinkedList(struct LinkedList* linkedList){
  if(linkedList == NULL)
    return;

  struct Node* currentNode;
  currentNode = linkedList->head;

  while(currentNode != NULL){
    printf("%d\n", currentNode->value);
    currentNode = currentNode->nextNode;
  }

}
