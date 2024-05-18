import { Node } from "../../Node/Node";

export default class Stack {
  head: Node | undefined;

  constructor() {
    this.head = undefined;
  }

  is_empty() {
    return !this.head;
  }

  push(node: Node) {
    node.next = this.head;
    this.head = node;
  }

  pop(): Node | undefined {
    try {
      if (this.is_empty()) throw new Error("Stack is empty.");
      const node = this.head;
      if (!node) return undefined;
      this.head = node.next;
      return node;
    } catch (err: any) {
      console.error;
    }
  }

  peek(): Node | undefined {
    try {
      if (this.is_empty()) throw "Stack is empty. Please, push some value";
      return this.head;
    } catch (err: any) {
      console.error(err);
    }
  }

  toString(): string {
    let str = "\tHEAD -> ";
    let aux_node = this.head;
    while (aux_node !== undefined) {
      str += `${aux_node.data} -> `;
      aux_node = aux_node.next;
    }
    str += "NULL\n";
    return str;
  }
}
