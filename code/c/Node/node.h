#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* link;
} Node;

typedef struct DoubleLinkNode {
  int data;
  struct DoubleLinkNode* before;
  struct DoubleLinkNode* next;
} DoubleLinkNode;

Node create_node(int data);
Node* create_ptr_node(int data);

DoubleLinkNode create_double_link_node(int data);
DoubleLinkNode* create_ptr_double_link_node(int data);

char* node_to_string(Node* node);
char* double_link_node_to_string(DoubleLinkNode* node);