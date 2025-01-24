#ifndef _CIRCULARLINKEDLIST_H_
#define _CIRCULARLINKEDLIST_H_

#include "../../Node/node.h"
#include "../abstractlinkedlist.h"

class CircularLinkedList : public AbstractLinkedList<Node> {
 public:
  CircularLinkedList();
  ~CircularLinkedList();

  Node* at(int index) override;
  void insert(Node node, int index) override;
  Node* remove_at(int index) override;

  void print() override;

  friend std::ostream& operator<<(std::ostream& os, const CircularLinkedList& list);
};

#endif  // _CIRCULARLINKEDLIST_H_