#include "queue.h"

void queue_init(Queue* queue) {
  queue->size = 0;
  queue->head = NULL;
  queue->tail = NULL;
}

bool queue_is_empty(Queue* queue) {
  return queue->head == NULL && queue->tail == NULL;
}

void queue_enqueue(Queue* queue, Node value) {
  Node* tmpNode = create_ptr_node(value.data);

  if (queue_is_empty(queue)) {
    queue->head = tmpNode;
    queue->tail = tmpNode;
    return;
  }

  queue->tail->link = tmpNode;
  queue->tail = tmpNode;
  queue->size++;
}

Node queue_dequeue(Queue* queue) {
  Node node = {NULL, NULL};
  if (queue_is_empty(queue))
    return node;

  Node* tmpNode = queue->head;
  queue->head = tmpNode->link;
  tmpNode->link = NULL;
  node.data = tmpNode->data;
  free(tmpNode);
  queue->size--;

  return node;
}

void queue_print(Queue* queue) {
  Node* tmpNode = queue->head;
  printf("\nFRONT");
  while (tmpNode != NULL) {
    printf(" -> %d", tmpNode->data);
    tmpNode = tmpNode->link;
  }
  printf(" <- TAIL\n");
}

Node queue_head(Queue* queue) {
  Node node = {NULL, NULL};
  if (queue_is_empty(queue)) return node;
  node.data = queue->head->data;
  return node;
}

Node queue_tail(Queue* queue) {
  Node node = {NULL, NULL};
  if (queue_is_empty(queue)) return node;
  node.data = queue->tail->data;
  return node;
}

bool queue_action(Queue* queue, int option) {
  clear();
  Node node;
  switch (option) {
    int value;
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      queue_enqueue(queue, create_node(value));
      printf("\n");
      return true;
    case 2:
      node = queue_dequeue(queue);
      if (node.data != NULL)
        printf("Dequeue: %d\n", node.data);
      return true;
    case 3:
      node = queue_head(queue);
      if (node.data != NULL)
        printf("Head: %d\n", node.data);
      return true;
    case 4:
      node = queue_tail(queue, &node);
      if (node.data != NULL)
        printf("Tail: %d\n", node.data);
      return true;
    case 5:
      queue_print(queue);
      printf("\n");
      return true;
    case 6:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void queue_destroy(Queue* queue) {
  queue->size = 0;
  free(queue->head);
  free(queue->tail);
}