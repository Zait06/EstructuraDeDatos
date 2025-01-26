#include "utils.h"

/**
 * @brief Clear output terminal
 */
void clean() {
#ifdef __unix__
  system("clear");
#else
  system("cls");
#endif
}

/**
 * @brief Fix the index with the size given
 * @param index The position of element
 * @param size The number of elements in the struct
 * @return If fix index correct return true. Otherwise, false
 */
bool fix_index(int* index, int* size) {
  if (0 > *index) *index = *size + *index;
  if (*index > *size || 0 > *index) return false;
  return true;
}

/**
 * @brief Print menu and wait for option selected
 * @param options const char** Array with menu options
 * @param size int Options numer
 * @param full bool If a struct is dynamic, the full value is false. Otherwise is the value of isFull() function returned
 * @param ptr void (char**, int*, bool) It's the function to do actions for the struct
 * @return int Option selected from the menu
 */
int menu(char** options, int size, bool full, void (*ptr)(char**, int*, bool)) {
  int option = 0;
  char** menu_opts = (char**)calloc(size, sizeof(char*));
  for (int i = 0; i < size; i++)
    menu_opts[i] = (char*)calloc(20, sizeof(char));

  copyOptions(options, menu_opts, size);

  if (ptr != NULL) ptr(menu_opts, &size, full);

  printf("Select an option:\n");
  for (int i = 0; i < size; i++)
    printf("%s\n", menu_opts[i]);
  printf("Type your option: ");
  scanf("%d", &option);
  return option;
}

/**
 * @brief From menu, copy options with specific size
 */
void copyOptions(char** src, char** output, int size) {
  for (int i = 0; i < size; i++)
    output[i] = src[i];
}
