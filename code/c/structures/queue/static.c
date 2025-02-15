#include "static.h"
#include "utils.h"

void squeue_init(Queue *queue, int size) {
  queue->_queue = (int *)calloc(size, sizeof(int));
  queue->count = 0;
  queue->size = size;
}

bool squeue_is_queue(Queue *queue) { return !queue->count; }

bool squeue_is_full(Queue *queue) { return queue->count == queue->size; }

void squeue_enqueue(Queue *queue, int value) {
  if (squeue_is_full(queue)) return;
  queue->_queue[queue->count++] = value;
}

int squeue_dequeue(Queue *queue) {
  if (squeue_is_queue(queue)) return -1;

  queue->count--;
  int node = queue->_queue[0];
  for (int idx = 1; idx <= queue->count; idx++)
    queue->_queue[idx - 1] = queue->_queue[idx];
  return node;
}

void print_queue(Queue *queue) {
  printf("\nFRONT ->");

  for (int idx = 0; idx < queue->count; idx++)
    printf("%s %d", idx ? " ->" : "", queue->_queue[idx]);

  printf(" <- TAIL\n");
}

int squeue_head(Queue *queue) {
  if (squeue_is_queue(queue)) return -1;
  return queue->_queue[0];
}

int squeue_tail(Queue *queue) {
  if (squeue_is_queue(queue)) return -1;
  return queue->_queue[queue->count - 1];
}

bool squeue_action(Queue *queue, int option) {
  clean();
  switch (option) {
    int value;
    case 1:
      if (squeue_is_full(queue)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      squeue_enqueue(queue, value);
      printf("\n");
      return true;
    case 2:
      printf("Dequeue: %d\n", squeue_dequeue(queue));
      return true;
    case 3:
      printf("Top: %d\n", squeue_head(queue));
      return true;
    case 4:
      printf("Back: %d\n", squeue_tail(queue));
      return true;
    case 5:
      print_queue(queue);
      printf("\n");
      return true;
    case 6:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void squeue_destroy(Queue *queue) { free(queue->_queue); }
