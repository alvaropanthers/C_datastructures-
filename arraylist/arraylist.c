#include "arraylist.h"

struct ArrayList* create_arraylist(){
  struct ArrayList* arraylist = malloc(sizeof(struct ArrayList));
  arraylist->array = malloc(MAX_SIZE * sizeof(int));
  arraylist->size = MAX_SIZE;
  arraylist->currentSize = 0;

  return arraylist;
}

void expand_arraylist(struct ArrayList* arraylist){
  if(arraylist == NULL)
    return;
  
  int newSize = arraylist->size * 2;
  arraylist->array = realloc(arraylist->array, newSize * sizeof(int));
  arraylist->size = newSize;
}

void add_front(struct ArrayList* arraylist, int value){
  if(arraylist == NULL)
    return;

  if((arraylist->currentSize + 1) == arraylist->size){
    expand_arraylist(arraylist);
  }

  
  int array[arraylist->currentSize];
  int x = 0;
  for(x = 0; x < arraylist->currentSize; ++x){
    array[x] = arraylist->array[x];
  }

  x = 0;
  arraylist->array[x] = value;
  for(x = 1; x < arraylist->currentSize + 1; ++x){
    arraylist->array[x] = array[x - 1];
  }
  
}

void add_end(struct ArrayList* arraylist, int value){
  if(arraylist == NULL)
    return;

  //Expand array if needed
  if((arraylist->currentSize + 1) == arraylist->size){
    expand_arraylist(arraylist);
  }

  arraylist->array[arraylist->currentSize] = value;
  ++(arraylist->currentSize);
}

void free_arraylist(struct ArrayList* arraylist){
  if(arraylist == NULL)
    return;

  if(arraylist->array != NULL)
    free(arraylist->array);

  free(arraylist);
}

void print_arraylist(struct ArrayList* arraylist){
  if(arraylist == NULL)
    return;
  
  for(int x = 0; x < arraylist->currentSize; ++x){
    printf("%d\n", arraylist->array[x]);
  }
}
