#include "arraylist.h"

struct ArrayList* create_arraylist(){
  struct ArrayList* arraylist = malloc(sizeof(struct ArrayList));
  arraylist->array = malloc(MAX_SIZE * sizeof(int));
  arraylist->size = MAX_SIZE;
  arraylist->currentSize = 0;

  return arraylist;
}

void expand_arraylist(struct ArrayList* arraylist){
  null_check(arraylist);
  
  int newSize = arraylist->size * 2;
  arraylist->array = realloc(arraylist->array, newSize * sizeof(int));
  arraylist->size = newSize;
}

void add(struct ArrayList* arraylist, int value){
  null_check(arraylist);

  //Expand array if needed
  if((arraylist->currentSize + 1) == arraylist->size){
    expand_arraylist(arraylist);
  }

  arraylist->array[arraylist->currentSize] = value;
  ++(arraylist->currentSize);
}

void addAt(struct ArrayList *arraylist, size_t index, int value){
  null_check(arraylist);

  if(index >= arraylist->currentSize){
    fprintf(stderr, "%s\n", ERR_OUT_OF_BOUNDS);    
    exit(EXIT_FAILURE);
  }

  if((arraylist->currentSize + 1) == arraylist->size){
    expand_arraylist(arraylist);
  }

  int tmpArr[arraylist->currentSize];
  for(size_t x = 0; x < arraylist->currentSize; ++x){
    tmpArr[x] = arraylist->array[x];
  }

  arraylist->array[index] = value;
  for(size_t x = index; x < arraylist->currentSize; ++x){
    arraylist->array[x + 1] = tmpArr[x];
  }

  ++(arraylist->currentSize);
}

int get(struct ArrayList *arraylist, size_t index){
  null_check(arraylist);
  
  if(index >= arraylist->currentSize){
    fprintf(stderr, "%s\n", ERR_OUT_OF_BOUNDS);    
    exit(EXIT_FAILURE);
  }

  return arraylist->array[index];
}

int indexOf(struct ArrayList *arraylist, int value){
  null_check(arraylist);

  int index = -1;
  for(int x = 0; x < arraylist->currentSize; ++x){
    if(arraylist->array[x] == value){
      index = x;
      break;
    }
  }

  return index;
}

void remov(struct ArrayList *arraylist, size_t index){
  null_check(arraylist);

  if(index >= arraylist->currentSize){
    fprintf(stderr, "%s\n", ERR_OUT_OF_BOUNDS);    
    exit(EXIT_FAILURE);
  }

  for(int x = index; x < arraylist->currentSize; ++x){
    arraylist->array[x] = arraylist->array[x + 1];
  }

  if (arraylist->currentSize > 0){
    --(arraylist->currentSize);
  }
}

void remov_value(struct ArrayList *arraylist, int value){
  null_check(arraylist);
  
  int index = indexOf(arraylist, value);
  if(index != -1){
    remov(arraylist, index);
  }
}

void free_arraylist(struct ArrayList* arraylist){
  free(arraylist->array);
  free(arraylist);
}

void print_arraylist(struct ArrayList* arraylist){
  null_check(arraylist);
  
  for(int x = 0; x < arraylist->currentSize; ++x){
    printf("%d\n", arraylist->array[x]);
  }
}

size_t size(struct ArrayList* arraylist){
  null_check(arraylist);

  return arraylist->currentSize;
}

void null_check(struct ArrayList *arraylist){
  if(arraylist == NULL){
    fprintf(stderr, "%s\n", ERR_ARRAYLIST_NULL);    
    exit(EXIT_FAILURE);
  }
}