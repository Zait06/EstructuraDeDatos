#include "stack.h"

void init_stack(Stack* stack) { stack->head = NULL; }

bool is_empty(Stack* stack) { return stack->head == NULL; }

void push(Stack* stack, Node* node) {
  node->next = stack->head;
  stack->head = node;
}

Node* pop(Stack* stack) {
  if (is_empty(stack)) return NULL;
  Node* node = stack->head;
  stack->head = stack->head->next;
  return node;
}

Node* peek(Stack* stack) {
  if (is_empty(stack)) return NULL;
  return stack->head;
}

void print_stack(Stack* stack) {
  Node* aux_node = stack->head;
  printf("\tHEAD -> ");
  while (aux_node != NULL) {
    printf("%d -> ", aux_node->data);
    aux_node = aux_node->next;
  }
  printf("NULL\n");
}

bool action(Stack* stack, int option) {
  int value;
  clear_output();
  printf("\n");
  switch (option) {
    case 1:
      printf("Write a value: ");
      scanf("%d", &value);
      push(stack, create_node(value));
      printf("\n");
      return true;
    case 2:
      printf("Pop: ");
      Node* node = pop(stack);
      if (node != NULL)
        print_node(node);
      else
        printf("NULL");
      printf("\n");
      return true;
    case 3:
      printf("Top: ");
      if (peek(stack) != NULL)
        print_node(peek(stack));
      else
        printf("NULL");
      printf("\n");
      return true;
    case 4:
      printf("Print stack\n");
      print_stack(stack);
      printf("\n");
      return true;
    case 5:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}