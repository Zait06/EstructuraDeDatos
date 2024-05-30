#include "linkedlist.h"

void linked_list_init(LinkedList* list) {
  list->size = 0;
  list->top = NULL;
}

bool linked_list_is_empty(LinkedList* list) {
  return list->top == NULL;
}

void linked_list_destroy(LinkedList* list) {
  list->size = 0;
  free(list->top);
}

/**
 * @brief Return the value in the index given
 */
Node* linked_list_at(LinkedList* list, int index) {
  Node* tmpNode = list->top;

  fix_index(&index, &(list->size));

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->link;

  return tmpNode;
}

/**
 * @brief Insert value at the index given
 */
void linked_list_insert(LinkedList* list, Node value, int index) {
  Node* tmpNode = create_ptr_node(value.data);
  if (0 == index || linked_list_is_empty(list)) {
    if (!linked_list_is_empty(list))
      tmpNode->link = list->top;
    list->top = tmpNode;
    list->size++;
    return;
  }

  fix_index(&index, &(list->size));
  if (index != list->size - 1) index = index - 1;

  Node* prevNode = linked_list_at(list, index);
  tmpNode->link = prevNode->link;
  prevNode->link = tmpNode;
  list->size++;
}

/**
 * @brief Insert value at the top
 */
void linked_list_push(LinkedList* list, Node value) {
  linked_list_insert(list, value, 0);
}

/**
 * @brief Insert value at the end
 */
void linked_list_append(LinkedList* list, Node value) {
  linked_list_insert(list, value, -1);
}

/**
 * @brief Remove and return the value from the index given
 */
Node linked_list_remove_at(LinkedList* list, int index) {
  Node* tmpNode = list->top;
  Node auxNode = create_node(tmpNode->data);

  if (index == 0) {
    list->top = tmpNode->link;
    tmpNode->link = NULL;
    list->size--;
    free(tmpNode);
    return auxNode;
  }

  tmpNode = linked_list_at(list, index - 1);
  Node* rmNode = tmpNode->link;
  auxNode.data = rmNode->data;

  if (rmNode->link == NULL)
    tmpNode->link = NULL;
  else
    tmpNode->link = rmNode->link;

  rmNode->link = NULL;
  list->size--;
  free(rmNode);
  return auxNode;
}

/**
 * @brief Remove and return the first value
 */
Node linked_list_remove_first(LinkedList* list) {
  return linked_list_remove_at(list, 0);
}

/**
 * @brief Remove and return the last value
 */
Node linked_list_remove_last(LinkedList* list) {
  return linked_list_remove_at(list, -1);
}

void linked_list_print(LinkedList* list) {
  printf("\n\tTop -> ");
  if (linked_list_is_empty(list)) return;

  Node* tmpNode = list->top;
  while (tmpNode != NULL) {
    printf("%d -> ", tmpNode->data);
    tmpNode = tmpNode->link;
  }

  printf("NULL\n");
}

bool linked_list_action(LinkedList* list, int option) {
  clearOutput();
  Node node;
  switch (option) {
    int value;
    case 1:
    case 2:
    case 3: {
      printf("Write a value: ");
      scanf("%d", &value);
      node = create_node(value);
      if (option == 1) linked_list_push(list, node);
      if (option == 2) linked_list_append(list, node);
      if (option == 3) {
        printf("Give an index: ");
        scanf("%d", &value);
        linked_list_insert(list, node, value);
      }
      return true;
    }
    case 4: {
      printf("Give an index: ");
      scanf("%d", &value);
      Node* nodeAt = linked_list_at(list, value);
      printf("Value at %d is %d\n", value, nodeAt->data);
      return true;
    }
    case 5:
    case 6:
    case 7: {
      if (option == 5)
        node = linked_list_remove_first(list);
      if (option == 6)
        node = linked_list_remove_last(list);
      if (option == 7) {
        printf("Give an index: ");
        scanf("%d", &value);
        node = linked_list_remove_at(list, value);
      }
      printf("Remove %d\n", node.data);
      return true;
    }
    case 8:
      linked_list_print(list);
      return true;
    case 9:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}