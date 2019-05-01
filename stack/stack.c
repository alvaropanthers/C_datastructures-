#include "stack.h"

void initStack(int type){
  lastPos = 0;

  size_t d_size;

  if(type == STACK_CHAR){
    d_size = sizeof(char);
    stack_type = STACK_CHAR;
  }
  else if(type == STACK_INT){
    d_size = sizeof(int);
    stack_type = STACK_INT;
  }
  else if(type == STACK_DOUBLE){
    d_size = sizeof(double);
    stack_type = STACK_DOUBLE;
  }
  else if(type == STACK_FLOAT){
    d_size = sizeof(float);
    stack_type = STACK_FLOAT;
  }
    
  stack = malloc(SIZE_OF_STACK * d_size);
}

void stack_push(void* element){
  if(stack_isFull())
    return;

  if(stack_type == STACK_CHAR)
    stack[lastPos] = *((char*)element);
  else if(stack_type == STACK_INT)
    stack[lastPos] = *((int*)element);
  else if(stack_type == STACK_DOUBLE)
    stack[lastPos] = *((double*)element);
  else if(stack_type == STACK_FLOAT)
    stack[lastPos] = *((float*)element);

  ++lastPos;
}

void stack_pop(){
  --lastPos;
  stack[lastPos] = '\0';
}

int stack_size(){
  return lastPos;
}

int stack_isEmpty(){
  if(lastPos == 0)
    return 1;

  return 0;
}

int stack_isFull(){
  if((lastPos + 1) == SIZE_OF_STACK)
    return 1;

  return 0;
}

void* stack_peak(){
  if(stack[0] == '\0')
    return '\0';

  return &stack[0];
}

void* stack_top(){
  return &stack[lastPos - 1];
}
