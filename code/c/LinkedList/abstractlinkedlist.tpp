#include "../utils/utils.h"

/**
 * @brief Knows if list is empty
 */
template <typename T>
bool AbstractLinkedList<T>::isEmpty() { return m_top == nullptr; }

/**
 * @brief Insert value at the index given
 */
template <typename T>
void AbstractLinkedList<T>::push(T node) { insert(node, 0); }

/**
 * @brief Insert value at the end
 */
template <typename T>
void AbstractLinkedList<T>::append(T node) { insert(node, -1); }

/**
 * @brief Remove and return the first value
 */
template <typename T>
T AbstractLinkedList<T>::remove_first() { return remove_at(0); }

/**
 * @brief Remove and return the last value
 */
template <typename T>
T AbstractLinkedList<T>::remove_last() { return remove_at(-1); }

template <typename T>
bool AbstractLinkedList<T>::menuAction(int option) {
  clear();
  Node node;
  switch (option) {
    int value;
    case 1:
    case 2:
    case 3: {
      printf("Write a value: ");
      scanf("%d", &value);
      node = create_node(value);
      if (option == 1) push(node);
      if (option == 2) append(node);
      if (option == 3) {
        printf("Give an index: ");
        scanf("%d", &value);
        insert(node, value);
      }
      return true;
    }
    case 4: {
      printf("Give an index: ");
      scanf("%d", &value);
      Node* nodeAt = at(value);
      printf("Value at %d is %d\n", value, nodeAt->data);
      return true;
    }
    case 5:
    case 6:
    case 7: {
      if (option == 5)
        node = remove_first();
      if (option == 6)
        node = remove_last();
      if (option == 7) {
        printf("Give an index: ");
        scanf("%d", &value);
        node = remove_at(value);
      }
      printf("Remove %d\n", node.data);
      return true;
    }
    case 8:
      print();
      return true;
    case 9:
      return false;
    default:
      printf("Option doesn't exist. Please, try again.\n");
      return true;
  }
}
