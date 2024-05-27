#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* link;
} Node;

Node* create_node(int data);
void print_node(Node* node);