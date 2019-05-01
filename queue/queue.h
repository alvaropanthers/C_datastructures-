#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue{
  int* array;
  int currentSize;
  int size;
};

struct Queue* create_queue();
void free_queue(struct Queue*);
void expand_queue(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
void print_queue(struct Queue* queue);
