#include "queue.h"

void init_queue(Queue *queue, int size) {
  queue->_queue = (int *)calloc(size, sizeof(int));
  queue->count = 0;
  queue->size = size;
}

bool isEmpty(Queue *queue) { return !queue->count; }

bool isFull(Queue *queue) { return queue->count == queue->size; }

void enqueue(Queue *queue, int value) {
  if (isFull(queue)) return;
  queue->_queue[queue->count++] = value;
}

int dequeue(Queue *queue) {
  if (isEmpty(queue)) return -1;

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

int head(Queue *queue) {
  if (isEmpty(queue)) return -1;
  return queue->_queue[0];
}

int tail(Queue *queue) {
  if (isEmpty(queue)) return -1;
  return queue->_queue[queue->count - 1];
}

bool action(Queue *queue, int option) {
  clear();
  switch (option) {
    int value;
    case 1:
      if (isFull(queue)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      enqueue(queue, value);
      printf("\n");
      return true;
    case 2:
      printf("Dequeue: %d\n", dequeue(queue));
      return true;
    case 3:
      printf("Top: %d\n", head(queue));
      return true;
    case 4:
      printf("Back: %d\n", tail(queue));
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

void destroy_stack(Queue *queue) { free(queue->_queue); }