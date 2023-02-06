import sys
sys.path.append("../../utils")

from Node import Node

class Stack:
    def __init__(self) -> None:
        self.head = None
        
    def __del__(self) -> None:
        self.head = None
        
    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        aux_node = self.head
        while (aux_node != None):
            str_stack += f"{aux_node} -> "
            aux_node = aux_node.next
        str_stack += "NULL\n"
        return str_stack
        
    def is_empty(self) -> bool:
        return self.head == None
    
    def push(self, value: Node) -> None:
        value.next = self.head
        self.head = value
        
    def pop(self) -> Node:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            node = self.head
            self.head = node.next
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