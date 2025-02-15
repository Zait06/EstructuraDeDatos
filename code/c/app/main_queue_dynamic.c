#include <stdbool.h>
#include <stdio.h>
#include "queue/dynamic.h"
#include "utils.h"

char* options[] = {
    "1. Enqueue",
    "2. Dequeue",
    "3. Show head",
    "4. Show tail",
    "5. Print queue",
    "6. Exit"};

int main() {
  Queue queue;
  dqueue_init(&queue);

  clean();
  printf("\n\tDynamic Queue\n");

  while (dqueue_action(&queue, menu(options, 6, false, NULL)));

  dqueue_destroy(&queue);

  return 0;
}
