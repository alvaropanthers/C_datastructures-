#include "stack.h"

Stack *Stack_init(){
  Stack *stack = malloc(sizeof(Stack));
  stack->stack = malloc(SIZE_OF_STACK * sizeof(void*));
  stack->size = SIZE_OF_STACK;
  stack->currentSize = 0;

  return stack;
}

void Stack_free(Stack *stack){
  if(stack == NULL){
    return;
  }

  free(stack->stack);
  free(stack);
}

void Stack_push(Stack *stack, void *element){
  if(stack == NULL){
    return;
  }

  if(Stack_is_full(stack) == 0){
    stack->stack[stack->currentSize] = element;
    ++(stack->currentSize);
  }

}

void *Stack_pop(Stack *stack){
  if(stack == NULL || stack->currentSize == 0){
    return NULL;
  }

  void *element = stack->stack[stack->currentSize - 1];
  stack->stack[stack->currentSize - 1] = NULL;
  --(stack->currentSize);

  return element;
}

int Stack_is_full(Stack *stack){
  if(stack == NULL){
    return 1;
  }

  if(stack->currentSize == stack->size){
    return 1;
  }

  return 0;
}