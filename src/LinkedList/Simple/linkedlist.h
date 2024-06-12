#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../Node/node.h"

typedef struct LinkedList {
  int size;
  Node* top;
} LinkedList;

// struct
void linked_list_init(LinkedList* list);
bool linked_list_is_empty(LinkedList* list);
void linked_list_destroy(LinkedList* list);

// get
Node* linked_list_at(LinkedList* list, int index);

// add
void linked_list_insert(LinkedList* list, Node value, int index);
void linked_list_push(LinkedList* list, Node value);
void linked_list_append(LinkedList* list, Node value);

// remove
Node linked_list_remove_at(LinkedList* list, int index);
Node linked_list_remove_first(LinkedList* list);
Node linked_list_remove_last(LinkedList* list);

void linked_list_print(LinkedList* list);
bool linked_list_action(LinkedList* list, int option);
