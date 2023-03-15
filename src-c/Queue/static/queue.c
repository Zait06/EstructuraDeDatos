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
  if (is_empty(queue)) return;

  queue->count--;
  int *node = queue->_queue[queue->head];
  care_step(queue->size, &queue->head);
  return node;
}

void care_step(int maxSize, int *pipe) {
  int temp = *pipe;
  *pipe = ++temp;
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

void destroy_stack(Queue *queue) { free(queue->_queue); }