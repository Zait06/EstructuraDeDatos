#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "../../Node/node.h"
#include "../abstractlinkedlist.h"

class LinkedList : public AbstractLinkedList<Node> {
 public:
  LinkedList();
  ~LinkedList();

  Node* at(int index) override;
  void insert(Node node, int index) override;
  Node remove_at(int index) override;

  void print() override;
  Node* operator[](int idx);
  friend std::ostream& operator<<(std::ostream& os, LinkedList& list);
};

#endif  // _LINKEDLIST_H_