#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdbool.h>
#include "node.h"
#include "utils.h"

typedef struct Stack {
  int size;
  Node* head;
} Stack;

void dstack_init(Stack* stack);
bool dstack_is_empty(Stack* stack);
void dstack_push(Stack* stack, Node node);
Node dstack_pop(Stack* stack);
Node dstack_peek(Stack* stack);
void dstack_print(Stack* stack);
bool dstack_action(Stack* stack, int option);
void dstack_destroy(Stack* stack);

#endif
