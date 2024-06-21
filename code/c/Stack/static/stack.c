#include "stack.h"

void stack_init(Stack* stack, int size) {
  stack->_stack = (int*)calloc(size, sizeof(int));
  stack->count = 0;
  stack->maxSize = size;
}

bool stack_is_empty(Stack* stack) { return !stack->count; }

bool isFull(Stack* stack) { return stack->count == stack->maxSize; }

void stack_push(Stack* stack, int value) {
  if (isFull(stack)) return;
  stack->_stack[stack->count] = value;
  stack->count++;
}

int stack_pop(Stack* stack) {
  if (stack_is_empty(stack)) return 0;
  stack->count--;
  return stack->_stack[stack->count];
}

int stack_peek(Stack* stack) {
  if (stack_is_empty(stack)) return 0;
  return stack->_stack[stack->count - 1];
}

void stack_print(Stack* stack) {
  printf("\tHEAD -> ");
  for (int i = stack->count; i > 0; i--) {
    printf("%d -> ", stack->_stack[i - 1]);
  }
  printf("NULL\n");
}

bool stack_action(Stack* stack, int option) {
  int value;
  clear();
  printf("\n");
  switch (option) {
    case 1:
      if (isFull(stack)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      stack_push(stack, value);
      printf("\n");
      return true;
    case 2:
      printf("Pop: %d\n", stack_pop(stack));
      return true;
    case 3:
      printf("Top: %d\n", stack_peek(stack));
      return true;
    case 4:
      stack_print(stack);
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