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


class Stack(StructBase):
    def __init__(self) -> None:
        super()
        self.head = None

    def __del__(self) -> None:
        self.head = None

    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        aux_node = self.head
        while aux_node != None:
            str_stack += f"{aux_node} -> "
            aux_node = aux_node.link
        str_stack += "NULL\n"
        return str_stack

    def is_empty(self) -> bool:
        return self.head == None

    def is_full(self) -> bool:
        return False

    def push(self, value: Node) -> None:
        value.link = self.head
        self.head = value

    def pop(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            node = self.head
            self.head = node.link
            return node
        except Exception as exc:
            print(exc[0])

    def peek(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self.head
        except Exception as exc:
            print(exc[0])
