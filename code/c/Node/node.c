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

DoubleLinkNode create_double_link_node(int data) {
  DoubleLinkNode node = {data, NULL, NULL};
  return node;
}

DoubleLinkNode* create_ptr_double_link_node(int data) {
  DoubleLinkNode* node = (DoubleLinkNode*)malloc(sizeof(DoubleLinkNode));
  node->data = data;
  node->before = NULL;
  node->next = NULL;
  return node;
}

char* node_to_string(Node* node) {
  char text[200];
  sprintf(text, "%4d", node->data);
  return text;
}

char* double_link_node_to_string(DoubleLinkNode* node) {
  char text[200];
  sprintf(text, "%4d", node->data);
  return text;
}