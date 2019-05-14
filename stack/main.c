#include <stdio.h>
#include "stack.h"

int main(){
  Stack *stack = Stack_init();

  int int1 = 33;
  void *pt = &int1;
  Stack_push(stack, pt);
  printf("Pushed %d\n", int1);

  int int2 = 34;
  pt = &int2;
  Stack_push(stack, pt);
  printf("Pushed %d\n", int2);

  void *void_ptr = Stack_pop(stack);
  int pop_ptr = *((int*)void_ptr);
  printf("Popped %d\n", pop_ptr);


  Stack_free(stack);
 /* initStack(STACK_INT);
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
  */
  return 0;
}
