#ifndef _ABSTRACTLINKEDLIST_H_
#define _ABSTRACTLINKEDLIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
class AbstractLinkedList {
 public:
  virtual T* at(int index) = 0;
  virtual void insert(T node, int index) = 0;
  virtual T remove_at(int index) = 0;

  virtual void print() = 0;

  virtual bool menuAction(int option);

  bool isEmpty();
  void push(T node);
  void append(T node);
  T remove_first();
  T remove_last();

 protected:
  int m_size;
  T* m_top;
};

#include "abstractlinkedlist.tpp"
#endif  // _ABSTRACTLINKEDLIST_H_