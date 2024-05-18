#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "stack.h"

char* options[] = {
    "1.- Push",
    "2.- Pop",
    "3.- Show top",
    "4.- Print stack",
    "5.- Exit"};

void printFull(char** options, int* size, bool full) {
  if (!full) return;
  for (int i = 1; i < *size; i++) {
    options[i - 1] = options[i];
  }
  *size -= 1;
}

int main() {
  Stack stack;
  void (*ptrFunc)(char**, int*, bool) = &printFull;

  printf("\n\Static Stack\n");

  int size;
  printf("Input size stack: ");
  scanf("%d", &size);

  init_stack(&stack, size);

  bool doit = true;
  while (doit) {
    bool full = is_full(&stack);
    if (full) printf("The stack is full\n\n");
    doit = action(&stack, menu(options, 5, full, ptrFunc));
  }

  destroy_stack(&stack);

  return 0;
}