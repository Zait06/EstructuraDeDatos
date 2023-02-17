#include "queue.h"

void init_queue(Queue *queue, int size) {
  queue->_queue = (int *)calloc(size, sizeof(int));
  queue->front = 0;
  queue->rear = 0;
  queue->count = 0;
  queue->size = size;
}

bool is_empty(Queue *queue) { return !queue->count; }

bool is_full(Queue *queue) { return queue->count == queue->size; }

void enqueue(Queue *queue, int value) {
  if (is_full(queue)) return;
  if (is_empty(queue)) queue->front = 0;

  queue->_queue[queue->rear] = value;
  queue->count++;
  care_step(queue, false);
}

int dequeue(Queue *queue) {
  if (is_empty(queue)) return;

  queue->count--;
  int *node = queue->_queue[queue->front];
  care_step(queue, true);
  return node;
}

void care_step(Queue *queue, bool is_front) {
  if (is_front) {
    if (queue->front == queue->size) return queue->front = 0;
    return queue->front++;
  }
  if (!queue->rear) return queue->rear = queue->size;
  return queue->rear--;
}

void print_queue(Queue *queue) {
  printf("FRONT -> ");
  int i = queue->front;
  for (; i < queue->size; i++)
    printf("%d -> ", queue->_queue[i]);
  if (queue->front) {
    for (i = 0; i < queue->front; i++)
      printf("%d -> ", queue->_queue[i]);
  }
  printf(" <- REAR\n");
}

void destroy_stack(Queue *queue) { free(queue->_queue); }