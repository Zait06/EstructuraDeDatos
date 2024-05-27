import os, sys

prev = os.getcwd()
if prev.endswith("EstructuraDeDatos"):
    prev = os.path.join(prev, "src")
else:
    prev = "../.."

sys.path.append(os.path.join(prev, "Node"))
sys.path.append(os.path.join(prev, "StructBase"))

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
        while tmpNode.link:
            str_ += f"{tmpNode.data} -> "
            tmpNode = tmpNode.link
        str_ += f"{tmpNode.data}"
        return str_

    def push(self, value: Node):
        if not self.is_empty():
            value.link = self._top
        self._top = value
        self.size += 1

    def append(self, value: Node):
        if not self.is_empty():
            return self.push(value)

        tmpNode = self._top
        while tmpNode.link:
            tmpNode = tmpNode.link

        tmpNode.link = value
        self.size += 1

    def insert(self, value: Node, index: int = 0):
        if self.is_empty() or index == 0:
            return self.push(value)
        if index > self.size or index == -1:
            return self.append(value)
        index = self.size + index if 0 > index else index

        tmpNode = self._top
        idx = 0
        while idx < index - 1:
            tmpNode = tmpNode.link
            idx += 1

        value.link = tmpNode.link
        tmpNode.link = value
        self.size += 1
