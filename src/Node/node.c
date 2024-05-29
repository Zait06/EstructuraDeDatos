#include "node.h"

Node create_node(int data) {
  Node node = {data, NULL};
  return node;
}

Node* create_ptr_node(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->link = NULL;
  return node;
}

void print_node(Node* node) { printf("%4d\n", node->data); }