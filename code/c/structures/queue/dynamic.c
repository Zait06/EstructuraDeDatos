#include "dynamic.h"
#include "utils.h"

void dqueue_init(Queue* queue) {
  queue->size = 0;
  queue->head = NULL;
  queue->tail = NULL;
}

bool dqueue_is_empty(Queue* queue) {
  return queue->head == NULL && queue->tail == NULL;
}

void dqueue_enqueue(Queue* queue, Node value) {
  Node* tmpNode = create_ptr_node(value.data);

  if (dqueue_is_empty(queue)) {
    queue->head = tmpNode;
    queue->tail = tmpNode;
    return;
  }

  queue->tail->link = tmpNode;
  queue->tail = tmpNode;
  queue->size++;
}

Node dqueue_dequeue(Queue* queue) {
  Node node = { -1, NULL };
  if (dqueue_is_empty(queue))
    return node;

  Node* tmpNode = queue->head;
  queue->head = tmpNode->link;
  tmpNode->link = NULL;
  node.data = tmpNode->data;
  free(tmpNode);
  queue->size--;

  return node;
}

void dqueue_print(Queue* queue) {
  Node* tmpNode = queue->head;
  printf("\nFRONT");
  while (tmpNode != NULL) {
    printf(" -> %s", node_to_string(tmpNode));
    tmpNode = tmpNode->link;
  }
  printf(" <- TAIL\n");
}

Node dqueue_head(Queue* queue) {
  Node node = { -1, NULL };
  if (dqueue_is_empty(queue)) return node;
  node.data = queue->head->data;
  return node;
}

Node dqueue_tail(Queue* queue) {
  Node node = { -1, NULL };
  if (dqueue_is_empty(queue)) return node;
  node.data = queue->tail->data;
  return node;
}

bool dqueue_action(Queue* queue, int option) {
  clean();
  Node node;
  switch (option) {
    int value;
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      dqueue_enqueue(queue, create_node(value));
      printf("\n");
      return true;
    case 2:
      node = dqueue_dequeue(queue);
      if (node.data != -1)
        printf("Dequeue: %d\n", node.data);
      return true;
    case 3:
      node = dqueue_head(queue);
      if (node.data != -1)
        printf("Head: %d\n", node.data);
      return true;
    case 4:
      node = dqueue_tail(queue);
      if (node.data != -1)
        printf("Tail: %d\n", node.data);
      return true;
    case 5:
      dqueue_print(queue);
      printf("\n");
      return true;
    case 6:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void dqueue_destroy(Queue* queue) {
  queue->size = 0;
  free(queue->head);
  free(queue->tail);
}
