#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int menu(char** options, int size, bool full, void (*ptr)(char**, int*, bool));
void copy_options(char** src, char** output, int size);