#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void clear();
void fix_index(int* index, int* size);
int menu(char** options, int size, bool full, void (*ptr)(char**, int*, bool));
void copyOptions(char** src, char** output, int size);