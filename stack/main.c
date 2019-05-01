#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
  initStack(STACK_INT);
  int ten = 10;
  int ohundred = 100;
  stack_push(&ten);
  stack_push(&ohundred);

  int* top = (int *)stack_top();
  int* peak = (int *)stack_peak();
  
  printf("Top = %d\n", *top);
  printf("Peak = %d\n", *peak); 

  for(int x = 0; x < lastPos; ++x)
    printf("%d -> %d\n", x, stack[x]);

  printf("poping element: %d\n", stack[lastPos - 1]);
  stack_pop();

  for(int x = 0; x < lastPos; ++x)
    printf("%d -> %d\n", x, stack[x]);

  return 0;
}
