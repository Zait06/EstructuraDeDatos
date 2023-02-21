#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int* _stack;
  int count;
  int maxSize;
} Stack;

void init_stack(Stack* stack, int size);
bool is_empty(Stack* stack);
bool is_full(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
void print_stack(Stack* stack);
void destroy_stack(Stack* stack);
bool action(Stack* stack, int option);