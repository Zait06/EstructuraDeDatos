#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int* _queue;
  int count;
  int size;
} Queue;

void squeue_init(Queue* queue, int size);
bool squeue_is_queue(Queue* queue);
bool squeue_is_full(Queue* queue);
void squeue_enqueue(Queue* queue, int value);
int squeue_dequeue(Queue* queue);
void squeue_print(Queue* queue);
int squeue_head(Queue* queue);
int squeue_tail(Queue* queue);
bool squeue_action(Queue* queue, int option);
void squeue_destroy(Queue* queue);
