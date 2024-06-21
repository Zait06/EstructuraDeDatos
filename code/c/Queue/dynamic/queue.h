#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../Node/node.h"

typedef struct Queue {
  int size;
  Node* head;
  Node* tail;
} Queue;

void queue_init(Queue* queue);
bool queue_is_empty(Queue* queue);
void queue_enqueue(Queue* queue, Node value);
Node queue_dequeue(Queue* queue);
void queue_print(Queue* queue);
Node queue_head(Queue* queue);
Node queue_tail(Queue* queue);
bool queue_action(Queue* queue, int option);
void queue_destroy(Queue* queue);