#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct Queue {
  int size;
  Node* head;
  Node* tail;
} Queue;

void dqueue_init(Queue* queue);
bool dqueue_is_empty(Queue* queue);
void dqueue_enqueue(Queue* queue, Node value);
Node dqueue_dequeue(Queue* queue);
void dqueue_print(Queue* queue);
Node dqueue_head(Queue* queue);
Node dqueue_tail(Queue* queue);
bool dqueue_action(Queue* queue, int option);
void dqueue_destroy(Queue* queue);
