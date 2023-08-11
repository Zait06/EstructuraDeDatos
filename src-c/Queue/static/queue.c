#include "queue.h"

void init_queue(Queue *queue, int size) {
  queue->_queue = (int *)calloc(size, sizeof(int));
  queue->head = 0;
  queue->tail = 0;
  queue->count = 0;
  queue->size = size;
}

bool is_empty(Queue *queue) { return !queue->count; }

bool is_full(Queue *queue) { return queue->count == queue->size; }

void enqueue(Queue *queue, int value) {
  if (is_full(queue)) return;
  if (is_empty(queue)) {
    queue->head = 0;
    queue->tail = 0;
  }

  queue->_queue[queue->tail] = value;
  queue->count++;
  care_step(queue->size, &queue->tail);
}

int dequeue(Queue *queue) {
  if (is_empty(queue)) return -1;

  queue->count--;
  int *node = queue->_queue[queue->head];
  care_step(queue->size, &queue->head);
  return node;
}

void care_step(int maxSize, int *pipe) {
  int temp = *pipe;
  *pipe = ++temp;
  printf("%d - %d", maxSize, *pipe);
  if (maxSize == *pipe) *pipe = 0;
}

void print_queue(Queue *queue) {
  printf("\nFRONT ->");
  int idx = queue->head;
  int size = queue->count;

  for (int count = 0; count < size; count++) {
    printf("%s %d", count ? " <-" : "", queue->_queue[idx]);
    care_step(queue->size, &idx);
  }

  printf(" <- TAIL\n");
}

int front(Queue *queue) {
  if (is_empty(queue)) return -1;
  return queue->_queue[queue->head];
}

int back(Queue *queue) {
  if (is_empty(queue)) return -1;
  return queue->_queue[queue->tail - 1];
}

bool action(Queue *queue, int option) {
  clear_output();
  switch (option) {
    int value;
    case 1:
      if (is_full(queue)) return true;
      printf("Write a value: ");
      scanf("%d", &value);
      enqueue(queue, value);
      printf("\n");
      return true;
    case 2:
      printf("Dequeue: %d\n", dequeue(queue));
      return true;
    case 3:
      printf("Top: %d\n", front(queue));
      return true;
    case 4:
      printf("Back: %d\n", back(queue));
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