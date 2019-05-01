#include <stdlib.h>

#define SIZE_OF_STACK 100
#define STACK_CHAR 1
#define STACK_INT 2
#define STACK_DOUBLE 3
#define STACK_FLOAT 4

struct Stack{
  int peak;
  int top;
  int *array;
  int lastPos;
  int size;
  int type;
};

struct Stack* createStack(int size, int type);
size_t get_type_size(int type);
int stack_isFull();
void push(struct Stack* stack, void* element);
void pop(struct Stack* stack);
void* stack_peak(struct Stack* stack);
void* stack_top(struct Stack* stack);
int stack_isEmpty(struct Stack* stack);
