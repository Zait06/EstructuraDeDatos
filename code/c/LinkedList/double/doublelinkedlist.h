#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../Node/node.h"

typedef struct DoubleLinkedList {
  int size;
  DoubleLinkNode* top;
} DoubleLinkedList;

// struct
void linked_list_init(DoubleLinkedList* list);
bool linked_list_is_empty(DoubleLinkedList* list);
void linked_list_destroy(DoubleLinkedList* list);

// get
DoubleLinkNode* linked_list_at(DoubleLinkedList* list, int index);

// add
void linked_list_insert(DoubleLinkedList* list, DoubleLinkNode value, int index);
void linked_list_push(DoubleLinkedList* list, DoubleLinkNode value);
void linked_list_append(DoubleLinkedList* list, DoubleLinkNode value);

// remove
DoubleLinkNode linked_list_remove_at(DoubleLinkedList* list, int index);
DoubleLinkNode linked_list_remove_first(DoubleLinkedList* list);
DoubleLinkNode linked_list_remove_last(DoubleLinkedList* list);

void linked_list_print(DoubleLinkedList* list);
bool linked_list_action(DoubleLinkedList* list, int option);
