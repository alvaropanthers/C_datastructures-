#include <stdlib.h>

#define SIZE_OF_STACK 100
#define STACK_CHAR 0
#define STACK_INT 1
#define STACK_DOUBLE 2
#define STACK_FLOAT 3

int* stack;
int lastPos;
int stack_type;

void initStack();
void stack_push(void* element);
void stack_pop();
int stack_size();
int stack_isEmpty();
int stack_isFull();
void* stack_peak();
void* stack_top();
