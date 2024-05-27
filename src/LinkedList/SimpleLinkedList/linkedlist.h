#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../Node/node.h"

typedef struct LinkedList {
  int size;
  Node* top;
} LinkedList;

bool isEmpty(LinkedList* list);
void push(LinkedList* list, Node* value);
void append(LinkedList* list, Node* value);
void insert(LinkedList* list, Node* value, int index);
Node at(LinkedList* list, int index);
Node pop(LinkedList* list);
Node remove(LinkedList* list);
Node removeAt(LinkedList* list, int index);
