#include "dynamic.h"

void dstack_init(Stack* stack) { stack->head = NULL; }

bool dstack_is_empty(Stack* stack) { return stack->head == NULL; }

void dstack_push(Stack* stack, Node node) {
  Node* tmpNode = create_ptr_node(node.data);
  tmpNode->link = stack->head;
  stack->head = tmpNode;
  stack->size++;
}

Node dstack_pop(Stack* stack) {
  Node node = {-1, NULL};
  if (dstack_is_empty(stack)) return node;

  Node* tmpNode = stack->head;
  stack->head = stack->head->link;
  tmpNode->link = NULL;
  node.data = tmpNode->data;
  node.link = tmpNode->link;
  free(tmpNode);
  stack->size--;

  return node;
}

Node dstack_peek(Stack* stack) {
  Node node = {-1, NULL};
  if (dstack_is_empty(stack)) return node;

  node.data = stack->head->data;
  node.link = NULL;

  return node;
}

void dstack_print(Stack* stack) {
  Node* tmpNode = stack->head;
  printf("\tHEAD -> ");
  while (tmpNode != NULL) {
    printf("%s -> ", node_to_string(tmpNode));
    tmpNode = tmpNode->link;
  }
  printf("NULL\n");
}

bool dstack_action(Stack* stack, int option) {
  int value;
  clean();
  printf("\n");
  switch (option) {
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      dstack_push(stack, create_node(value));
      printf("\n");
      return true;
    case 2:
      printf("Pop: ");
      Node node = dstack_pop(stack);
      if (node.data != -1)
        printf("%4d", node.data);
      else
        printf("NULL");
      printf("\n");
      return true;
    case 3:
      printf("Top: ");
      Node node_peek = dstack_peek(stack);
      if (node_peek.data != -1)
        printf("%4d", node_peek.data);
      else
        printf("NULL");
      printf("\n");
      return true;
    case 4:
      printf("Print stack\n");
      dstack_print(stack);
      printf("\n");
      return true;
    case 5:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}

void dstack_destroy(Stack* stack) {
  stack->size = 0;
  stack->head = NULL;
}
