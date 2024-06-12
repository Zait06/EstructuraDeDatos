import StructBase from "../../StructBase/StructBase";
import { Node } from "../../Node/Node";

export default class Stack extends StructBase {
  protected head: Node | undefined;

  static options = ["Push", "Pop", "Show top", "Print stack", "Exit"];

  constructor() {
    super();
    this.head = undefined;
  }

  isEmpty() {
    return !this.head;
  }

  isFull(): boolean {
    return false;
  }

  push(node: Node) {
    node.link = this.head;
    this.head = node;
  }

  pop(): Node | undefined {
    try {
      if (this.isEmpty()) throw new Error("Stack is empty.");
      const node = this.head;
      if (!node) return undefined;
      this.head = node.link;
      return node;
    } catch (err: any) {
      console.error;
    }
  }

  peek(): Node | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty. Please, push some value";
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
      aux_node = aux_node.link;
    }
    str += "NULL\n";
    return str;
  }
}
