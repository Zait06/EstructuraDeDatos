#include "queue.h"

void init_queue(Queue* queue) {
  queue->count = 0;
  queue->head = NULL;
  queue->tail = NULL;
}

bool is_empty(Queue* queue) {
  return queue->head == NULL && queue->tail == NULL;
}

void enqueue(Queue* queue, Node* value) {
  if (is_empty(queue)) {
    queue->head = value;
    queue->tail = value;
    return;
  }

  queue->tail->link = value;
  queue->tail = value;
  queue->count++;
}

void dequeue(Queue* queue, Node* value) {
  if (is_empty(queue))
    return value = NULL;

  *value = *queue->head;
  queue->head = queue->head->link;
  value->link = NULL;
  queue->count--;
}

void print_queue(Queue* queue) {
  Node* aux = queue->head;

  printf("\nFRONT -> ");

  while (tmpNode->link != NULL) {
    printf("%d -> ", tmpNode->data);
    aux = tmpNode->link;
  }

  printf("%d", tmpNode->data);
  printf(" <- TAIL\n");
}

void head(Queue* queue, Node* value) {
  if (is_empty(queue))
    return value = NULL;
  *value = *queue->head;
}

void tail(Queue* queue, Node* value) {
  if (is_empty(queue))
    return value = NULL;
  *value = *queue->tail;
}

bool action(Queue* queue, int option) {
  clear_output();
  Node node;
  switch (option) {
    int value;
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      enqueue(queue, create_node(value));
      printf("\n");
      return true;
    case 2:
      dequeue(queue, &node);
      if (&node != NULL)
        printf("Dequeue: %d\n", node.data);
      return true;
    case 3:
      head(queue, &node);
      if (&node != NULL)
        printf("Head: %d\n", node.data);
      return true;
    case 4:
      tail(queue, &node);
      if (&node != NULL)
        printf("Tail: %d\n", node.data);
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

void destroy_queue(Queue* queue) {
  free(queue);
}