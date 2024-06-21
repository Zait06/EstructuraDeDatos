from Node import Node
from StructBase import StructBase


class Queue(StructBase):

    def __init__(self) -> None:
        super()
        self._head = None
        self._tail = None

    def __del__(self) -> None:
        self._head = None
        self._tail = None

    def __str__(self) -> str:
        str_ = "\n\tHEAD"
        tmpNode = self._head
        while tmpNode is not None:
            str_ += f" -> {tmpNode}"
            tmpNode = tmpNode.link
        str_ += " <- TAIL\n"
        return str_

    def is_empty(self) -> bool:
        return self._head is None and self._tail is None

    def is_full(self) -> bool:
        return False

    def enqueue(self, value: Node):
        if self.is_empty():
            self._head = value
            self._tail = value
            return
        self._tail.link = value
        self._tail = value

    def dequeue(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Queue is empty.")
            value = self._head
            self._head = value.link
            value.link = None
            return value
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def head(self) -> Node:
        return self._head

    def tail(self) -> Node:
        return self._tail

    @staticmethod
    def options():
        return [
            "Enqueue",
            "Dequeue",
            "Show head",
            "Show tail",
            "Print queue",
            "Exit",
        ]
