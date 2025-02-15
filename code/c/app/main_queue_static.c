#include <stdbool.h>
#include <stdio.h>
#include "queue/static.h"
#include "utils.h"

char* options[] = {
    "1. Enqueue",
    "2. Dequeue",
    "3. Show head",
    "4. Show tail",
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

  clean();
  printf("\n\tSimple Static Queue\n");

  int size;
  printf("Input size queue: ");
  scanf("%d", &size);

  squeue_init(&queue, size);

  bool doit = true;
  while (doit) {
    bool full = squeue_is_full(&queue);
    if (full) printf("The queue is full\n\n");
    doit = squeue_action(&queue, menu(options, 6, full, &printFull));
  }

  return 0;
}
