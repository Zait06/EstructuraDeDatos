#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack/dynamic.h"
#include "utils.h"

char* options[] = {
    "1.- Push",
    "2.- Pop",
    "3.- Show top",
    "4.- Print stack",
    "5.- Exit"};

int main() {
  Stack stack;

  srand(time(NULL));
  dstack_init(&stack);

  clean();
  printf("\n\tDynamic Stack\n");

  while (dstack_action(&stack, menu(options, 5, false, NULL)));

  dstack_destroy(&stack);

  return 0;
}
