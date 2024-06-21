import os


def clear():
    """Clear console output."""
    if os.name == "nt":
        _ = os.system("cls")
    else:
        _ = os.system("clear")


def fix_index(index: int, size: int) -> int:
    """Fix the index with the size given

    Args:
        index (int): The position of element
        size (int): The number of elements in the struct

    Returns:
        int: Index as positive value between 0 to size - 1
    """
    if index > size:
        index = -1
    if 0 > index:
        index = size + index
    if index > size or 0 > index:
        index = 0
    return index


def list_to_string_menu(options: list[str]) -> str:
    """Create a string to options as menu

    Args:
        options (list[str]): Option list

    Returns:
        str: String with break lines
    """
    return "\n".join([f"{idx + 1}.- {opt}" for idx, opt in enumerate(options)]) + "\n"
