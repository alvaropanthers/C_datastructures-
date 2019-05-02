#include "arraylist.h"

struct ArrayList* ArrayList_create(void){
  struct ArrayList* arraylist = malloc(sizeof(struct ArrayList));
  if(arraylist == NULL){
    fprintf(stderr, "%s\n", ERR_OUT_OF_MEMORY);
    return NULL;
  }

  arraylist->array = malloc(MAX_SIZE * sizeof(int));
  if(arraylist->array == NULL){
    fprintf(stderr, "%s\n", ERR_OUT_OF_MEMORY);
    free(arraylist);
    return NULL;
  }

  arraylist->size = MAX_SIZE;
  arraylist->currentSize = 0;
  return arraylist;
}

void ArrayList_expand(struct ArrayList* arraylist){
  ArrayList_null_check(arraylist);
  
  int newSize = arraylist->size * 2;
  if((arraylist->array = realloc(arraylist->array, newSize * sizeof(int))) == NULL){
    fprintf(stderr, "%s\n", ERR_OUT_OF_MEMORY);
  }else{
    arraylist->size = newSize;
  }
}

void ArrayList_add(struct ArrayList* arraylist, int value){
  ArrayList_null_check(arraylist);

  if(arraylist->currentSize == arraylist->size){
    ArrayList_expand(arraylist);
  }

  arraylist->array[arraylist->currentSize] = value;
  ++(arraylist->currentSize);
}

void ArrayList_add_at(struct ArrayList *arraylist, size_t index, int value){
  ArrayList_null_check(arraylist);

  if(index >= arraylist->currentSize){
    fprintf(stderr, "%s\n", ERR_OUT_OF_BOUNDS);    
    exit(EXIT_FAILURE);
  }

  if(arraylist->currentSize == arraylist->size){
    ArrayList_expand(arraylist);
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

int ArrayList_get(struct ArrayList *arraylist, size_t index){
  ArrayList_null_check(arraylist);
  
  if(index >= arraylist->currentSize){
    fprintf(stderr, "%s\n", ERR_OUT_OF_BOUNDS);    
    exit(EXIT_FAILURE);
  }

  return arraylist->array[index];
}

int ArrayList_index_of(struct ArrayList *arraylist, int value){
  ArrayList_null_check(arraylist);

  int index = -1;
  for(int x = 0; x < arraylist->currentSize; ++x){
    if(arraylist->array[x] == value){
      index = x;
      break;
    }
  }

  return index;
}

void ArrayList_remov(struct ArrayList *arraylist, size_t index){
  ArrayList_null_check(arraylist);

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

void ArrayList_remov_value(struct ArrayList *arraylist, int value){
  ArrayList_null_check(arraylist);
  
  int index = ArrayList_index_of(arraylist, value);
  if(index != -1){
    ArrayList_remov(arraylist, index);
  }
}

void ArrayList_destroy(struct ArrayList* arraylist){
  free(arraylist->array);
  free(arraylist);
}

void ArrayList_print(struct ArrayList* arraylist){
  ArrayList_null_check(arraylist);
  
  for(int x = 0; x < arraylist->currentSize; ++x){
    printf("%d\n", arraylist->array[x]);
  }
}

size_t ArrayList_size(struct ArrayList* arraylist){
  ArrayList_null_check(arraylist);

  return arraylist->currentSize;
}

void ArrayList_trim_to_size(struct ArrayList *arraylist){
  ArrayList_null_check(arraylist);

  if(realloc(arraylist->array, arraylist->currentSize * sizeof(int)) != NULL){
    arraylist->size = arraylist->currentSize;
  }
}

void ArrayList_null_check(struct ArrayList *arraylist){
  if(arraylist == NULL){
    fprintf(stderr, "%s\n", ERR_ARRAYLIST_NULL);    
    exit(EXIT_FAILURE);
  }
}