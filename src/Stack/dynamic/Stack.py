from Node import Node
from StructBase import StructBase


class Stack(StructBase):
    def __init__(self) -> None:
        super()
        self._head = None

    def __del__(self) -> None:
        self._head = None

    def __str__(self) -> str:
        str_ = "\tHEAD -> "
        tmpNode = self._head
        while tmpNode is not None:
            str_ += f"{tmpNode} -> "
            tmpNode = tmpNode.link
        str_ += "NULL\n"
        return str_

    def is_empty(self) -> bool:
        return self._head is None

    def is_full(self) -> bool:
        return False

    def push(self, value: Node) -> None:
        value.link = self._head
        self._head = value

    def pop(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            node = self._head
            self._head = node.link
            return node
        except Exception as exc:
            print(exc[0])

    def peek(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self._head
        except Exception as exc:
            print(exc[0])

    @staticmethod
    def options():
        return ["Push", "Pop", "Show top", "Print stack", "Exit"]
