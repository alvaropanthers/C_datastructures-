#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

#define OP_ADD 1
#define OP_SUBTRACT 2
#define OP_MULTIPLY 3
#define OP_DIVIDE 4
#define DELIMITOR ','


int symbol(char* array){
  struct Stack* stack = createStack(100, STACK_CHAR);
  char rightB = ']';
  char leftB = '[';
  for(int x = 0; x < strlen(array); ++x)
    if(array[x] == leftB)
      push(stack, &leftB);
    else if(array[x] == rightB)
      if(stack_isEmpty(stack))
	return 0;
      else
	pop(stack);

  if(stack_isEmpty(stack))
    return 1;

  return 0;
}n

int operation(char* array){
  if(strstr(array, "add"))
     return OP_ADD;
  else if(strstr(array, "subtract"))
     return OP_SUBTRACT;
  else if(strstr(array, "multiply"))
     return OP_MULTIPLY;
  else if(strstr(array, "divide"))
     return OP_DIVIDE;

  return 0;
}

char** split(char* array, int* size){
  char del = DELIMITOR;
  char* delim = &del;
  char** items = malloc(10 * sizeof(char*));
  char* temp;
  int index = 0;
  temp = strtok(array, delim);
  items[index] = temp;
  while(temp = strtok(NULL, delim)){
    ++index;
    items[index] = temp;
  }

  *size = index + 1;

  return items;
}

int toInt(char* string){
  char str[4];
  int index = 0;
  for(int x = 0; x < strlen(string); ++x){
    if(isdigit(string[x])){
      str[index] = string[x];
      ++index;
    }
  }

  if(index == 0)
    return '\0';

  return atoi(str);
}

int* getValues(char** values, int size, int* endSize){
  int* val = malloc(4 * sizeof(int));
  *endSize = 0;
  for(int x = 0; x < size; ++x){
    if((val[*endSize] = toInt(values[x])) != '\0')
      ++(*endSize);
  }

  return val;
}

int perform(int op, int a, int b){
  if(op == OP_ADD)
    return a + b;
  if(op == OP_SUBTRACT)
    return a - b;
  if(op == OP_MULTIPLY)
    return a * b;
  if(op == OP_DIVIDE)
    return a / b;

  return '\0';
}

int* getOperands(char* line, int* opSize){
  int size = 0;
  char** values = split(line, &size);
  return getValues(values, size, opSize);
}

void doIt(char* line){
  printf("Line: %s\n", line);
  int size = 0;
  int* operands = getOperands(line, &size);

  printf("result: %d\n", perform(operation(line), operands[0], operands[1]));
}

int main(){
  char string[] = "multiply,10,10";
  doIt(string);

  char string2[] = "add 11, 111";
  doIt(string2);
  
  return 0;
}
