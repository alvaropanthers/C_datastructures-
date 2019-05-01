#include "stack.h"

struct Stack* createStack(int size, int type){
  size_t d_size;
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

  if((d_size = get_type_size(type))){
    stack->size = size;
    stack->peak = 0;
    stack->top = 0;
    stack->lastPos = 0;
    stack->type = type;

    stack->array = malloc(stack->size * d_size);
  }
  
  return stack;
}

size_t get_type_size(int type){
  if(type == STACK_CHAR)
    return sizeof(char);
  else if(type == STACK_INT)
    return sizeof(int);
  else if(type == STACK_DOUBLE)
    return sizeof(double);
  else if(type == STACK_FLOAT)
    return sizeof(float);
  
  return 0;
}

void push(struct Stack* stack, void* element){
  if(stack_isFull())
    return;

  if(stack->type == STACK_CHAR)
    stack->array[stack->lastPos] = *((char*)element);
  else if(stack->type == STACK_INT)
    stack->array[stack->lastPos] = *((int*)element);
  else if(stack->type == STACK_DOUBLE)
    stack->array[stack->lastPos] = *((double*)element);
  else if(stack->type == STACK_FLOAT)
    stack->array[stack->lastPos] = *((float*)element);

  ++(stack->lastPos);
}


void pop(struct Stack* stack){
  --(stack->lastPos);
  stack->array[stack->lastPos] = '\0';
}

void* stack_peak(struct Stack* stack){
  if(stack->array[0] == '\0')
    return '\0';

  return &(stack->array[0]);
}

void* stack_top(struct Stack* stack){
  return &(stack->array[stack->lastPos - 1]);
}


int stack_isFull(struct Stack* stack){
  if((stack->lastPos + 1) == stack->size)
    return 1;

  return 0;
}

int stack_isEmpty(struct Stack* stack){
  if(stack->lastPos == 0)
    return 1;

  return 0;
}

