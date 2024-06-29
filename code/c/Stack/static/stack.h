#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"

typedef struct Stack {
  int* _stack;
  int count;
  int maxSize;
} Stack;

void stack_init(Stack* stack, int size);
bool stack_is_empty(Stack* stack);
bool stack_is_full(Stack* stack);
void stack_push(Stack* stack, int value);
int stack_pop(Stack* stack);
int stack_peek(Stack* stack);
void stack_print(Stack* stack);
void stack_destroy(Stack* stack);
bool stack_action(Stack* stack, int option);
