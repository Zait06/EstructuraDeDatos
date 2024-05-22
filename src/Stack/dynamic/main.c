#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../utils/utils.h"
#include "stack.h"

char* options[] = {
    "1.- Push",
    "2.- Pop",
    "3.- Show top",
    "4.- Print stack",
    "5.- Exit"};

int main() {
  Stack stack;

  srand(time(NULL));
  init_stack(&stack);

  clear_output();
  printf("\n\tDynamic Stack\n");

  while (action(&stack, menu(options, 5, false, NULL)));

  return 0;
}