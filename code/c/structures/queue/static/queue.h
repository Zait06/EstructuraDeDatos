#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int* _queue;
  int count;
  int size;
} Queue;

void init_queue(Queue* queue, int size);
bool isEmpty(Queue* queue);
bool isFull(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void print_queue(Queue* queue);
int head(Queue* queue);
int tail(Queue* queue);
bool action(Queue* queue, int option);
void destroy_stack(Queue* queue);