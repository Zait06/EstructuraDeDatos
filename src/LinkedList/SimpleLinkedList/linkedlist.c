#include "linkedlist.h"

bool isEmpty(LinkedList* list) {
  return list->top == NULL;
}

/**
 * @brief Insert value at the top
 */
void push(LinkedList* list, Node* value) {
  if (!isEmpty(list))
    value->link = list->top;
  list->top = value;
  list->size++;
}

/**
 * @brief Insert value at the end
 */
void append(LinkedList* list, Node* value) {
  if (isEmpty(list))
    return push(list, value);

  Node* tmpNode = list->top;
  while (tmpNode->link != NULL)
    tmpNode = tmpNode->link;

  tmpNode->link = value;
  list->size++;
}

/**
 * @brief Insert value at the index given
 */
void insert(LinkedList* list, Node* value, int index) {
  if (isEmpty(list) || index == 0)
    return push(list, value);

  if (index > list->size)
    return append(list, value);

  Node* tmpNode = list->top;
  for (int idx = 0; idx < index - 1; idx++)
    tmpNode = tmpNode->link;

  value->link = tmpNode->link;
  tmpNode->link = value;
  list->size++;
}

/**
 * @brief Return the value in the index given
 */
Node at(LinkedList* list, int index) {
  Node* tmpNode = list->top;

  index = index > list->size ? list->size : index;

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->link;

  return *tmpNode;
}

/**
 * @brief Remove and return the first value
 */
Node pop(LinkedList* list) {
  Node* tmpNode = list->top;
  list->top = tmpNode->link;
  list->size--;
  return *tmpNode;
}

/**
 * @brief Remove and return the last value
 */
Node remove(LinkedList* list) {
  Node* tmpNode = list->top;
  while (tmpNode->link->link != NULL)
    tmpNode = tmpNode->link;

  Node* rmNode = tmpNode->link->link;
  tmpNode->link = NULL;
  list->size--;
  return *rmNode;
}

/**
 * @brief Remove and return the value from the index given
 */
Node removeAt(LinkedList* list, int index) {
  if (index > list->size)
    return remove(list);

  Node* tmpNode = list->top;
  for (int idx = 0; idx < index - 1; idx++)
    tmpNode = tmpNode->link;

  Node* rmNode = tmpNode->link->link;
  tmpNode->link = NULL;
  list->size--;
  return *rmNode;
}
