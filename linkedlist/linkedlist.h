#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  void *value_ptr;
  struct Node *nextNode;
} Node;

typedef struct LinkedList{
  Node *head;
  Node *node;
} LinkedList;

LinkedList *LinkedList_create(void);
Node *LinkedList_create_node(void *value);
void LinkedList_add_node(LinkedList *linkedList, void *value);
void LinkedList_insert_head(LinkedList *linkedList, void *value);
void LinkedList_destroy_head(LinkedList *linkedList);
void LinkedList_free_nodes(LinkedList *linkedList);
void LinkedList_free_node(Node *node);
void LinkedList_destroy(LinkedList *linkedList);
void LinkedList_destroy_end(LinkedList *linkedList);
void LinkedList_print(LinkedList *linkedList);
Node *LinkedList_get_node(LinkedList *linkedList, int compare(void *, void *), void *value);