from utils import fix_index

from Node import Node
from StructBase import StructBase


class LinkedList(StructBase):
    _top: Node = None

    def __init__(self):
        super()

    def is_empty(self) -> bool:
        return self._top is not None

    def is_full(self) -> bool:
        return False

    def __str__(self) -> str:
        str_ = "Top -> "
        if self.is_empty():
            return str_
        tmpNode = self._top
        while tmpNode:
            str_ += f"{tmpNode.data} -> "
            tmpNode = tmpNode.link
        str_ += "NULL"
        return str_

    def at(self, index: int) -> Node:
        if self.is_empty():
            return None

        index = fix_index(index, self.size)

        idx = 0
        tmpNode = self._top
        while idx < index:
            tmpNode = tmpNode.link
        return tmpNode

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

        prevNode = self.at(index)
        if prevNode is None:
            return
        value.link = prevNode.link
        prevNode.link = value
        self.size += 1

    def push(self, value: Node):
        self.insert(value, 0)

    def append(self, value: Node):
        self.insert(value, -1)

    def removeAt(self, index) -> Node:
        if self.is_empty():
            return None

        tmpNode = self._top
        if 0 == index:
            self._top = tmpNode.link
            tmpNode.link = None
            self.size -= 1
            return tmpNode

        tmpNode = self.at(index - 1)

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

    def removeFist(self) -> Node:
        return self.removeAt(0)

    def removeFist(self) -> Node:
        return self.removeAt(-1)
