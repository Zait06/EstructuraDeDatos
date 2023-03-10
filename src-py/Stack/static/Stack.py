class Stack:
    def __init__(self, size: int) -> None:
        self._stack = []
        self.size = size
        
    def __del__(self) -> None:
        self._stack.clear()
        
    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        str_stack += " -> ".join(str(e) for e in self._stack[::-1])
        str_stack += " -> NULL\n"
        return str_stack
        
    def is_empty(self) -> bool:
        return len(self._stack) == 0
    
    def is_full(self) -> bool:
        return len(self._stack) == self.size
    
    def push(self, value: int) -> None:
        try:
            if self.is_full():
                raise Exception("Stack is full. Can't push more data")
            self._stack.append(value)
        except Exception as exc:
            msg = exc.args
            print(f"Error: {msg[0]}")
        
    def pop(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self._stack.pop()
        except Exception as exc:
            print(exc[0])
    
    def peek(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self._stack[-1]
        except Exception as exc:
            print(exc[0])