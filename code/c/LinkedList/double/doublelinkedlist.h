#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include "../../Node/node.h"
#include "../abstractlinkedlist.h"

class DoubleLinkedList : public AbstractLinkedList<DoubleLinkNode> {
 public:
  DoubleLinkedList();
  ~DoubleLinkedList();

  DoubleLinkNode* at(int index) override;
  void insert(DoubleLinkNode node, int index) override;
  DoubleLinkNode remove_at(int index) override;

  void print() override;
  DoubleLinkNode* operator[](int idx);
  friend std::ostream& operator<<(std::ostream& os, DoubleLinkedList& list);
};

#endif  // _DOUBLELINKEDLIST_H_