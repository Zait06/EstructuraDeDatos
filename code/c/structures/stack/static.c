#include "static.h"
#include "utils.h"

void sstack_init(Stack* stack, int size) {
  stack->_stack = (int*)calloc(size, sizeof(int));
  stack->count = 0;
  stack->maxSize = size;
}

bool sstack_is_empty(Stack* stack) { return !stack->count; }

bool sstack_is_full(Stack* stack) { return stack->count == stack->maxSize; }

void sstack_push(Stack* stack, int value) {
  if (sstack_is_full(stack)) return;
  stack->_stack[stack->count] = value;
  stack->count++;
}

int sstack_pop(Stack* stack) {
  if (sstack_is_empty(stack)) return 0;
  stack->count--;
  return stack->_stack[stack->count];
}

int sstack_peek(Stack* stack) {
  if (sstack_is_empty(stack)) return 0;
  return stack->_stack[stack->count - 1];
}

void sstack_print(Stack* stack) {
  printf("\tHEAD -> ");
  for (int i = stack->count; i > 0; i--) {
    printf("%d -> ", stack->_stack[i - 1]);
  }
  printf("NULL\n");
}

bool sstack_action(Stack* stack, int option) {
  int value;
  clean();
  printf("\n");
  switch (option) {
    case 1:
      if (sstack_is_full(stack)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      sstack_push(stack, value);
      printf("\n");
      return true;
    case 2:
      printf("Pop: %d\n", sstack_pop(stack));
      return true;
    case 3:
      printf("Top: %d\n", sstack_peek(stack));
      return true;
    case 4:
      sstack_print(stack);
      printf("\n");
      return true;
    case 5:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void sstack_destroy(Stack* stack) {
  free(stack->_stack);
}
