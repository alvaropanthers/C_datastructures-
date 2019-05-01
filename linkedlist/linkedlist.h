#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* nextNode;
};

struct LinkedList{
  struct Node* head;
  struct Node* node;
};

struct LinkedList* createLinkedList();
void freeLinkedList(struct LinkedList* linkedList);
void addNode(struct LinkedList* linkedList, int value);
void printLinkedList(struct LinkedList* linkedList);
void freeNodes(struct LinkedList* linkedList);
void deleteTop(struct LinkedList* linkedList);
void freeNode(struct Node* node);
void insertHead(struct LinkedList* linkedList, int value);
struct Node* createNode(int value);
void deleteEnd(struct LinkedList* linkedList);
