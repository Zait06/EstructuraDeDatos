from utils import fix_index

from Node import Node
from StructBase import StructBase
from LinkedList.base import LinkedListBase


class LinkedList(StructBase, LinkedListBase):
    _top: Node = None

    def __init__(self):
        super()

    def __str__(self) -> str:
        str_ = "Top -> "
        str_ += " -> ".join([str(e) for e in self.__iter__()])
        str_ += " -> NULL\n"
        return str_

    def __iter__(self) -> "LinkedList":
        self._tmpNode = self._top
        return self

    def __next__(self) -> int:
        if self._tmpNode is None:
            raise StopIteration
        data = self._tmpNode
        self._tmpNode = data.link
        return data

    def __len__(self) -> int:
        return self.size

    def __getitem__(self, index: int) -> Node:
        if self.is_empty():
            return None

        index = fix_index(index, self.size)

        for jdx, elem in enumerate(self.__iter__()):
            if index == jdx:
                return elem

    def is_empty(self) -> bool:
        return self._top is None

    def is_full(self) -> bool:
        return False

    def insert(self, value: Node, index: int = 0):
        if self.is_empty() or 0 == index:
            if not self.is_empty():
                value.link = self._top
            self._top = value
            self.size += 1
            return

        index = fix_index(index, self.size)
        if index != self.size - 1:
            index -= 1

        prevNode = self.__getitem__(index)
        if prevNode is None:
            return
        value.link = prevNode.link
        prevNode.link = value
        self.size += 1

    def removeAt(self, index) -> Node:
        if self.is_empty():
            return None

        tmpNode = self._top
        if 0 == index:
            self._top = tmpNode.link
            tmpNode.link = None
            self.size -= 1
            return tmpNode

        tmpNode = self.__getitem__(index - 1)

        rmNode = tmpNode.link
        if rmNode is None:
            return None
        if rmNode.link is None:
            tmpNode.link = None
        else:
            tmpNode.link = rmNode.link
        rmNode.link = None
        self.size -= 1
        return rmNode
