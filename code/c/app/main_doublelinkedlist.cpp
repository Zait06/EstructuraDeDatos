#include <stdbool.h>
#include <stdio.h>
#include "LinkedList/double/doublelinkedlist.h"
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
  DoubleLinkedList list;
  linked_list_init(&list);

  clear();
  printf("\n\tLinked List\n");

  while (linked_list_action(&list, menu(options, 9, false, NULL)));

  linked_list_destroy(&list);

  return 0;
}
