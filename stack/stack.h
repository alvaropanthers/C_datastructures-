#include <stdlib.h>

#define SIZE_OF_STACK 100
#define STACK_CHAR 0
#define STACK_INT 1
#define STACK_DOUBLE 2
#define STACK_FLOAT 3

typedef struct Stack{
    void **stack;
    size_t currentSize;
    size_t size;
} Stack;

Stack *Stack_init();
void Stack_free(Stack *stack);
void Stack_push(Stack *stack, void *element);
void *Stack_pop(Stack *stack);
int Stack_is_full(Stack *stack);
