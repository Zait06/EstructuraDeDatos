#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../Node/Node.h"

typedef struct Queue {
  int count;
  Node* head;
  Node* tail;
} Queue;

void init_queue(Queue* queue);
bool is_empty(Queue* queue);
void enqueue(Queue* queue, Node* value);
void dequeue(Queue* queue, Node* value);
void print_queue(Queue* queue);
void head(Queue* queue, Node* value);
void tail(Queue* queue, Node* value);
bool action(Queue* queue, int option);
void destroy_queue(Queue* queue);