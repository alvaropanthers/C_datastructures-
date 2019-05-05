#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  void *value_ptr;
  struct Node *nextNode;
  struct Node *prevNode;
} Node;

typedef struct DoubleLinkedList{
  Node *head;
  Node *tail;
} DoubleLinkedList;

DoubleLinkedList *DoublyLinkedList_create();
Node *DoublyLinkedList_create_node(Node *node, void *value);
void DoublyLinkedList_add_node(DoubleLinkedList *doubleLinkedList, void *value);
Node *DoubleLinkedList_find(DoubleLinkedList *doubleLinkedList, int compare(void *value, void *b), void *value);
void DoubleLinkedList_destroy_node(DoubleLinkedList *doubleLinkedList, Node *node);
void DoublyLinkedList_delete_head(DoubleLinkedList *doubleLinkedList);
void DoublyLinkedList_delete_end(DoubleLinkedList *doubleLinkedList);
void DoublyLinkedList_free(DoubleLinkedList *doubleLinkedList);
void DoublyLinkedList_print_integer(DoubleLinkedList *doubleLinkedList);