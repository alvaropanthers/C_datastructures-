#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define ERR_OUT_OF_BOUNDS "index out of bounds"
#define ERR_ARRAYLIST_NULL "ArrayList can't be NULL"

struct ArrayList{
  int *array;
  int currentSize;
  int size;
};

struct ArrayList* create_arraylist();
void expand_arraylist(struct ArrayList *arraylist);
void free_arraylist(struct ArrayList *arraylist);
void print_arraylist(struct ArrayList *arraylist);
void add(struct ArrayList *arraylist, int value);
void addAt(struct ArrayList *arraylist, int index, int value);
int get(struct ArrayList *arraylist, int index);
int indexOf(struct ArrayList *arraylist, int value);
void remov(struct ArrayList *arraylist, int index);
void remov_value(struct ArrayList *arraylist, int value);
void null_check(struct ArrayList *arraylist);