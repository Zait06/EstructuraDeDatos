#include "linkedlist.h"
#include "../../utils/utils.h"

LinkedList::LinkedList() {
  m_size = 0;
  m_top = nullptr;
}

LinkedList::~LinkedList() {
  m_size = 0;
  Node* curNode = m_top;
  Node* tmpNode;
  while (curNode) {
    tmpNode = curNode;
    curNode = curNode->link;
    delete tmpNode;
  }
}

/**
 * @brief Return the value in the index given
 */
Node* LinkedList::at(int index) {
  Node* tmpNode = m_top;

  if (!fix_index(&index, &m_size)) {
    std::cout << index << std::endl;
    return nullptr;
  }

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->link;

  return tmpNode;
}

/**
 * @brief Insert value at the index given
 */
void LinkedList::insert(Node node, int index) {
  Node* newNode = create_ptr_node(node.data);

  if (isEmpty() || 0 == index) {
    if (!isEmpty()) newNode->link = m_top;
    m_top = newNode;
    m_size++;
    return;
  }

  bool lastIdx = -1 == index || index == m_size - 1;

  Node* prevNode = at(lastIdx ? index : index - 1);

  if (!prevNode) return;

  if (-1 != index) newNode->link = prevNode->link;
  prevNode->link = newNode;
  m_size++;
}

/**
 * @brief Remove value at the index given
 */
Node LinkedList::remove_at(int index) {

  if (isEmpty()) return {INT_MAX, NULL};

  Node* tmpNode = m_top;
  Node auxNode = create_node(m_top->data);

  if (index == 0) {
    m_top = tmpNode->link;
    tmpNode->link = nullptr;
    m_size--;
    delete tmpNode;
    return auxNode;
  }

  tmpNode = at(index - 1);
  Node* rmNode = tmpNode->link;
  auxNode.data = rmNode->data;

  if (!rmNode->link)
    tmpNode->link = nullptr;
  else
    tmpNode->link = rmNode->link;

  rmNode->link = nullptr;
  m_size--;
  delete rmNode;
  return auxNode;
}

void LinkedList::print() {
  std::cout << *this << std::endl;
}

Node* LinkedList::operator[](int idx) {
  return at(idx);
}

std::ostream& operator<<(std::ostream& os, LinkedList& list) {
  os << "[ ";
  for (int idx = 0; idx < list.m_size; idx++)
    os << list.at(idx)->data << " ";
  os << "]";
  return os;
}
