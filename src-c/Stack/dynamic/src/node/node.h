#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  Node* next;
} Node;

Node* create_node(int data);
void print_node(Node* node);