#include "stack.h"

void init_stack(Stack* stack, int size) {
  stack->_stack = (int*)calloc(size, sizeof(int));
  stack->count = 0;
  stack->size = size;
}

bool is_empty(Stack* stack) { return !stack->count; }

bool is_full(Stack* stack) { return stack->count == stack->size; }

void push(Stack* stack, int value) {
  if (is_full(stack)) return;
  stack->_stack[stack->count] = value;
  stack->count++;
}

int pop(Stack* stack) {
  if (is_empty(stack)) return 0;
  stack->count--;
  return stack->_stack[stack->count];
}

int peek(Stack* stack) {
  if (is_empty(stack)) return 0;
  return stack->_stack[stack->count - 1];
}

void print_stack(Stack* stack) {
  printf("\tHEAD -> ");
  for (int i = stack->count; i > 0; i--) {
    printf("%d -> ", stack->_stack[i - 1]);
  }
  printf("NULL\n");
}

bool action(Stack* stack, int option) {
  int value;
  printf("\e[1;1H\e[2J");
  printf("\n");
  switch (option) {
    case 1:
      if (is_full(stack)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      push(stack, value);
      printf("\n");
      return true;
    case 2:
      printf("Pop: %d", pop(stack));
      printf("\n");
      return true;
    case 3:
      printf("Top: %d", peek(stack));
      printf("\n");
      return true;
    case 4:
      print_stack(stack);
      printf("\n");
      return true;
    case 5:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void destroy_stack(Stack* stack) {
  free(stack->_stack);
}