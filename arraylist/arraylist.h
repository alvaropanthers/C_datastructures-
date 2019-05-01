#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct ArrayList{
  int* array;
  int currentSize;
  int size;
};

struct ArrayList* create_arraylist();
void expand_arraylist(struct ArrayList* arraylist);
void add_end(struct ArrayList* arraylist, int value);
void free_arraylist(struct ArrayList* arraylist);
void print_arraylist(struct ArrayList* arraylist);
void add_front(struct ArrayList* arraylist, int value);
