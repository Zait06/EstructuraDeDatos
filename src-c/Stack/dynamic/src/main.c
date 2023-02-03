#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu/menu.h"

int main() {
  Stack stack;

  srand(time(NULL));

  printf("\e[1;1H\e[2J");
  printf("\n\tSimple Stack\n");

  init_stack(&stack);

  bool doit = true;
  while (doit) doit = action(&stack, menu());

  return 0;
}