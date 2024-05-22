#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "queue.h"

char* options[] = {
    "1. Enqueue",
    "2. Dequeue",
    "3. Show head",
    "4. Show tail",
    "5. Print queue",
    "6. Exit"};

int main() {
  Queue queue;
  init_queue(&queue);

  clear_output();
  printf("\n\tDynamic Queue\n");

  while (action(&queue, menu(options, 6, false, NULL)));

  return 0;
}