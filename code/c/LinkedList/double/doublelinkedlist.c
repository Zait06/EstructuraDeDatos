#include "doublelinkedlist.h"
#include "../../utils/utils.h"

void linked_list_init(DoubleLinkedList* list) {
  list->size = 0;
  list->top = NULL;
}

bool linked_list_is_empty(DoubleLinkedList* list) {
  return list->top == NULL;
}

void linked_list_destroy(DoubleLinkedList* list) {
  list->size = 0;
  free(list->top);
}

/**
 * @brief Return the value in the index given
 */
DoubleLinkNode* linked_list_at(DoubleLinkedList* list, int index) {
  DoubleLinkNode* tmpNode = list->top;

  fix_index(&index, &(list->size));

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->next;

  return tmpNode;
}

/**
 * @brief Insert value at the index given
 */
void linked_list_insert(DoubleLinkedList* list, DoubleLinkNode value, int index) {
  DoubleLinkNode* tmpNode = create_ptr_node(value.data);
  if (0 == index || linked_list_is_empty(list)) {
    if (!linked_list_is_empty(list)) {
      tmpNode->next = list->top;
      list->top->before = tmpNode;
    }
    list->top = tmpNode;
    list->size++;
    return;
  }

  fix_index(&index, &(list->size));
  if (index != list->size - 1) index -= 1;

  DoubleLinkNode* prevNode = linked_list_at(list, index);
  tmpNode->next = prevNode->next;
  tmpNode->before = prevNode;
  prevNode->next = tmpNode;
  list->size++;
}

/**
 * @brief Insert value at the top
 */
void linked_list_push(DoubleLinkedList* list, DoubleLinkNode value) {
  linked_list_insert(list, value, 0);
}

/**
 * @brief Insert value at the end
 */
void linked_list_append(DoubleLinkedList* list, DoubleLinkNode value) {
  linked_list_insert(list, value, -1);
}

/**
 * @brief Remove and return the value from the index given
 */
DoubleLinkNode linked_list_remove_at(DoubleLinkedList* list, int index) {
  DoubleLinkNode* tmpNode = list->top;
  DoubleLinkNode auxNode = create_double_link_node(tmpNode->data);

  if (index == 0) {
    list->top = tmpNode->next;
    tmpNode->next = NULL;
    list->size--;
    free(tmpNode);
    return auxNode;
  }

  tmpNode = linked_list_at(list, index - 1);
  DoubleLinkNode* rmNode = tmpNode->next;
  auxNode.data = rmNode->data;

  if (rmNode->next == NULL)
    tmpNode->next = NULL;
  else
    tmpNode->next = rmNode->next;

  if (rmNode->before == NULL)
    tmpNode->before = NULL;
  else
    tmpNode->before = rmNode->before;

  rmNode->next = NULL;
  rmNode->before = NULL;
  list->size--;
  free(rmNode);
  return auxNode;
}

/**
 * @brief Remove and return the first value
 */
DoubleLinkNode linked_list_remove_first(DoubleLinkedList* list) {
  return linked_list_remove_at(list, 0);
}

/**
 * @brief Remove and return the last value
 */
DoubleLinkNode linked_list_remove_last(DoubleLinkedList* list) {
  return linked_list_remove_at(list, -1);
}

void linked_list_print(DoubleLinkedList* list) {
  printf("\n\tTop -> ");
  if (linked_list_is_empty(list)) return;

  DoubleLinkNode* tmpNode = list->top;
  while (tmpNode != NULL) {
    printf("%s -> ", double_link_node_to_string(tmpNode));
    tmpNode = tmpNode->next;
  }

  printf("NULL\n");
}

bool linked_list_action(DoubleLinkedList* list, int option) {
  clear();
  DoubleLinkNode node;
  switch (option) {
    int value;
    case 1:
    case 2:
    case 3: {
      printf("Write a value: ");
      scanf("%d", &value);
      node = create_double_link_node(value);
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
      DoubleLinkNode* nodeAt = linked_list_at(list, value);
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
