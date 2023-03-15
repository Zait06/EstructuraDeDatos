#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/menu/menu.h"
#include "queue.h"

char* options[] = {
    "1.- Enqueue",
    "2.- Dequeue",
    "3.- Show top",
    "4.- Print queue",
    "5.- Exit"};

void printFull(char** options, int* size, bool full) {
  if (!full) return;
  for (int i = 1; i < *size; i++) {
    options[i - 1] = options[i];
  }
  *size -= 1;
}

int main() {
  Queue queue;

  init_queue(&queue, 5);

  enqueue(&queue, 1);
  enqueue(&queue, 2);
  enqueue(&queue, 3);
  dequeue(&queue);
  dequeue(&queue);
  enqueue(&queue, 4);
  enqueue(&queue, 5);
  enqueue(&queue, 6);

  print_queue(&queue);

  return 0;
}