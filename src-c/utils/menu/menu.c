#include "menu.h"

int menu(char** options, int size, bool full, void (*ptr)(char**, int*, bool)) {
  int option = 0;
  char** c_opt = (char**)calloc(size, sizeof(char*));
  for (int i = 0; i < size; i++)
    c_opt[i] = (char*)calloc(20, sizeof(char));

  copy_options(options, c_opt, size);

  if (ptr != NULL) ptr(c_opt, &size, full);

  printf("Select an option:\n");
  for (int i = 0; i < size; i++)
    printf("%s\n", c_opt[i]);
  printf("Type your option: ");
  scanf("%d", &option);
  return option;
}

void copy_options(char** src, char** output, int size) {
  for (int i = 0; i < size; i++)
    output[i] = src[i];
}