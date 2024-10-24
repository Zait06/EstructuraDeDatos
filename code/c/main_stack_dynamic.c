#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack/dynamic/stack.h"
#include "utils/utils.h"

char* options[] = {
    "1.- Push",
    "2.- Pop",
    "3.- Show top",
    "4.- Print stack",
    "5.- Exit"};

int main() {
  Stack stack;

  srand(time(NULL));
  stack_init(&stack);

  clear();
  printf("\n\tDynamic Stack\n");

  while (stack_action(&stack, menu(options, 5, false, NULL)));

  stack_destroy(&stack);

  return 0;
}