#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int* _queue;
  int count;
  int size;
  int head;
  int tail;
} Queue;

void init_queue(Queue* queue, int size);
bool is_empty(Queue* queue);
bool is_full(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void care_step(int maxSize, int* pipe);
void print_queue(Queue* queue);
int front(Queue* queue);
int back(Queue* queue);
bool action(Queue* queue, int option);
void destroy_stack(Queue* queue);