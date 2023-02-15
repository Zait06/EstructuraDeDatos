#include "node.h"

Node* create_node(int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void print_node(Node* node) { printf("%4d\n", node->data); }