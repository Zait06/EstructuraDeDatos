#ifndef SIMPLE_LINKEDLIST_H
#define SIMPLE_LINKEDLIST_H

#include "node.h"

Node at(int index);
void insert(Node node, int index) override;
Node remove_at(int index) override;

void print() override;
Node operator[](int idx);

#endif  // SIMPLE_LINKEDLIST_H
