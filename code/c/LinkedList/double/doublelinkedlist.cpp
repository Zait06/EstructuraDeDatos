#include "doublelinkedlist.h"
#include "../../utils/utils.h"

DoubleLinkedList::DoubleLinkedList() {
  m_size = 0;
  m_top = nullptr;
}

DoubleLinkedList::~DoubleLinkedList() {
  m_size = 0;
  DoubleLinkNode* curNode = m_top;
  DoubleLinkNode* tmpNode;
  while (curNode) {
    tmpNode = curNode;
    curNode = curNode->next;
    delete tmpNode;
  }
}

/**
 * @brief Return the value in the index given
 */
DoubleLinkNode* DoubleLinkedList::at(int index) {
  DoubleLinkNode* tmpNode = m_top;

  if (!fix_index(&index, &m_size)) {
    std::cout << index << std::endl;
    return nullptr;
  }

  for (int idx = 0; idx < index; idx++)
    tmpNode = tmpNode->next;

  return tmpNode;
}

/**
 * @brief Insert value at the index given
 */
void DoubleLinkedList::insert(DoubleLinkNode node, int index) {
  DoubleLinkNode* newNode = create_ptr_double_link_node(node.data);

  if (isEmpty() || 0 == index) {
    if (!isEmpty()) {
      newNode->next = m_top;
      m_top->before = newNode;
    }
    m_top = newNode;
    m_size++;
    return;
  }

  bool lastIdx = -1 == index || index == m_size - 1;

  DoubleLinkNode* prevNode = at(lastIdx ? index : index - 1);

  if (!prevNode) return;

  if (-1 != index) newNode->next = prevNode->next;
  prevNode->next = newNode;
  m_size++;
}

/**
 * @brief Remove value at the index given
 */
DoubleLinkNode DoubleLinkedList::remove_at(int index) {

  if (isEmpty()) return {INT_MAX, NULL};

  DoubleLinkNode* tmpNode = m_top;
  DoubleLinkNode auxNode = create_double_link_node(m_top->data);

  if (index == 0) {
    m_top = tmpNode->next;
    tmpNode->next = nullptr;
    m_size--;
    delete tmpNode;
    return auxNode;
  }

  tmpNode = at(index - 1);
  DoubleLinkNode* rmNode = tmpNode->next;
  auxNode.data = rmNode->data;

  if (!rmNode->next)
    tmpNode->next = nullptr;
  else
    tmpNode->next = rmNode->next;

  rmNode->next = nullptr;
  m_size--;
  delete rmNode;
  return auxNode;
}

void DoubleLinkedList::print() {
  std::cout << *this << std::endl;
}

DoubleLinkNode* DoubleLinkedList::operator[](int idx) {
  return at(idx);
}

std::ostream& operator<<(std::ostream& os, DoubleLinkedList& list) {
  os << "[ ";
  for (int idx = 0; idx < list.m_size; idx++)
    os << list.at(idx)->data << " ";
  os << "]";
  return os;
}
