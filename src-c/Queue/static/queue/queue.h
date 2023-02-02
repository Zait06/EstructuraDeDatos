#include <stdbool.h>

typedef struct Queue {
  int* _queue;
  int count;
  int size;
  int front;
  int rear;
} Queue;

void init_queue(Queue* queue, int size);
bool is_empty(Queue* queue);
bool is_full(Queue* queue);
void enqueue(Queue* queue, int value);
Node* dequeue(Queue* queue);
void care_step(Queue* queue, bool is_front);
void print_queue(Queue* queue);
void destroy_stack(Queue* queue);