#ifndef STATIC_STACK
#define STATIC_STACK

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int* _stack;
  int count;
  int maxSize;
} Stack;

void sstack_init(Stack* stack, int size);
bool sstack_is_empty(Stack* stack);
bool sstack_is_full(Stack* stack);
void sstack_push(Stack* stack, int value);
int sstack_pop(Stack* stack);
int sstack_peek(Stack* stack);
void sstack_print(Stack* stack);
void sstack_destroy(Stack* stack);
bool sstack_action(Stack* stack, int option);

#endif
