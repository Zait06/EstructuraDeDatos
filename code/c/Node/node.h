#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* link;
} Node;

Node create_node(int data);
Node* create_ptr_node(int data);