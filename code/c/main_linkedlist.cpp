#include <stdbool.h>
#include <stdio.h>
#include "LinkedList/simple/linkedlist.h"
#include "utils/utils.h"

char* options[] = {
    "1. Push",
    "2. Append",
    "3. Insert",
    "4. Get at",
    "5. Remove first",
    "6. Remove last",
    "7. Remove at",
    "8. Print list",
    "9. Exit"};

int main() {
  LinkedList list;

  clear();
  std::cout << "\n\tLinked List" << std::endl;

  while (list.menuAction(menu(options, 9, false, NULL)));

  return 0;
}
