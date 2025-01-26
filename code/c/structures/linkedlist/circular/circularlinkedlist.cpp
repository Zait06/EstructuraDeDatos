#include "circularlinkedlist.h"
#include "../../utils/utils.h"

CircularLinkedList::CircularLinkedList() {
  m_size = 0;
  m_top = nullptr;
}

CircularLinkedList::~CircularLinkedList() {
  m_size = 0;
  free(m_top);
}

/**
 * @brief Return the value in the index given
 */
Node* CircularLinkedList::at(int index) {
  Node* tmpNode = m_top;

  fix_index(&index, &m_size);

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->link;

  return tmpNode;
}

/**
 * @brief Insert value at the index given
 */
void CircularLinkedList::insert(Node node, int index) {
  Node* tmpNode = create_ptr_node(node.data);

  if (isEmpty()) {
    m_top = tmpNode;
    m_size++;
    return;
  }

  if (0 == index) {
    tmpNode->link = m_top;
    if (1 == m_size) m_top->link = tmpNode;
    m_top = tmpNode;
    m_size++;
    return;
  }

  fix_index(&index, &(m_size));
  if (index != m_size - 1) index -= 1;

  Node* prevNode = at(index);
  tmpNode->link = prevNode->link;
  prevNode->link = tmpNode;
  if (index == m_size - 1) m_top->link = tmpNode;
  m_size++;
}

/**
 * @brief Remove value at the index given
 */
Node* CircularLinkedList::remove_at(int index) {
  Node* tmpNode = m_top;
  Node* auxNode = create_ptr_node(tmpNode->data);

  if (index == 0) {
    m_top = tmpNode->link;
    tmpNode->link = NULL;
    m_size--;
    free(tmpNode);
    return auxNode;
  }

  tmpNode = at(index - 1);
  Node* rmNode = tmpNode->link;
  auxNode->data = rmNode->data;

  if (rmNode->link == NULL)
    tmpNode->link = NULL;
  else
    tmpNode->link = rmNode->link;

  rmNode->link = NULL;
  m_size--;
  free(rmNode);
  return auxNode;
}

void CircularLinkedList::print() {
  std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const CircularLinkedList& list) {
  Node* current = list.m_top;
  os << "[ ";
  while (current) {
    os << current->data << " ";
    current = current->link;
  }
  os << "]";
  return os;
}
