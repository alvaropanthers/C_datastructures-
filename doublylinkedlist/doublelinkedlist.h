#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* nextNode;
  struct Node* prevNode;
};

struct DoubleLinkedList{
  struct Node* head;
  struct Node* tail;
};

struct DoubleLinkedList* createDoubleLinkedList();
void deleteEnd(struct DoubleLinkedList*);
void deleteHead(struct DoubleLinkedList*);
struct Node* createNode(struct Node*, int);
void addNode(struct DoubleLinkedList*, int);
void freeDoubleLinkedList(struct DoubleLinkedList*);
void printDoubleLinkedList(struct DoubleLinkedList*);
