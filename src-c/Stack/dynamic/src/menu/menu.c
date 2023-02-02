#include "menu.h"

int menu() {
  int option = 0;
  char* options[] = {
      "1.- Push",
      "2.- Pop",
      "3.- Show top",
      "4.- Print stack",
      "5.- Exit"};

  printf("Select an option:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s\n", options[i]);
  }
  printf("Type your option: ");
  scanf("%d", &option);
  return option;
}

bool action(Stack* stack, int option) {
  int value;
  printf("\e[1;1H\e[2J");
  printf("\n");
  switch (option) {
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      push(stack, create_node(value));
      printf("\n");
      return true;
    case 2:
      printf("Pop: ");
      Node* node = pop(stack);
      if (node != NULL)
        print_node(node);
      else
        printf("NULL");
      printf("\n");
      return true;
    case 3:
      printf("Top: ");
      if (peek(stack) != NULL)
        print_node(peek(stack));
      else
        printf("NULL");
      printf("\n");
      return true;
    case 4:
      printf("Print stack\n");
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