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


class Queue(StructBase):
    _head = None
    _tail = None

    def __init__(self) -> None:
        super()

    def __del__(self) -> None:
        self._head = None
        self._tail = None

    def __str__(self) -> str:
        str_ = "\n\tHEAD -> "
        str_ += " <- TAIL\n"
        return str_

    def is_empty(self) -> bool:
        return self._head == None and self._tail == None

    def is_full(self) -> bool:
        return False

    def enqueue(self, value: Node):
        if self.is_empty():
            self._head = value
            self._tail = value
            return
        value.link = self._tail
        self._tail.link = value

    def dequeue(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Queue is empty.")
            value = self._head
            self._head = value.link
            return value
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def head(self) -> Node:
        if self.is_empty():
            return None
        return self._head

    def tail(self) -> int:
        if self.is_empty():
            return None
        return self._tail
