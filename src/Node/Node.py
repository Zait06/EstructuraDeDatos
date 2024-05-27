class Node:    
    def __init__(self, value: int) -> None:
        self.data = value
        self.link = None
        
    def __str__(self) -> str:
        return f"{self.data}"