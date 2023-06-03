#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "queue.h"

char* options[] = {
    "1. Enqueue",
    "2. Dequeue",
    "3. Show top",
    "4. Show back",
    "5. Print queue",
    "6. Exit"};

void printFull(char** options, int* size, bool full) {
  if (!full) return;
  for (int i = 1; i < *size; i++) {
    options[i - 1] = options[i];
  }
  *size -= 1;
}

int main() {
  Queue queue;
  void (*ptrFunc)(char**, int*, bool) = &printFull;

  clear_output();
  printf("\n\tSimple Static Queue\n");

  int size;
  printf("Input size queue: ");
  scanf("%d", &size);

  init_queue(&queue, size);

  bool doit = true;
  while (doit) {
    bool full = is_full(&queue);
    if (full) printf("The queue is full\n\n");
    doit = action(&queue, menu(options, 5, full, ptrFunc));
  }

  return 0;
}