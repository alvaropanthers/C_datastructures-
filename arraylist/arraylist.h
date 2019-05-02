#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define ERR_OUT_OF_BOUNDS "index out of bounds"
#define ERR_ARRAYLIST_NULL "ArrayList can't be NULL"

struct ArrayList{
  int *array;
  size_t currentSize;
  size_t size;
};

struct ArrayList* ArrayList_create();
void ArrayList_expand(struct ArrayList *arraylist);
void ArrayList_destroy(struct ArrayList *arraylist);
void ArrayList_print(struct ArrayList *arraylist);
void ArrayList_add(struct ArrayList *arraylist, int value);
void ArrayList_add_at(struct ArrayList *arraylist, size_t index, int value);
int ArrayList_get(struct ArrayList *arraylist, size_t index);
int ArrayList_index_of(struct ArrayList *arraylist, int value);
void ArrayList_remov(struct ArrayList *arraylist, size_t index);
void ArrayList_remov_value(struct ArrayList *arraylist, int value);
size_t ArrayList_size(struct ArrayList* arraylist);
void ArrayList_null_check(struct ArrayList *arraylist);