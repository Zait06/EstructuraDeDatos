import { Node } from "../../Node/Node";
import StructBase from "../../StructBase/StructBase";
import StackInterface from "../interface/StackInterface";

export default class Stack extends StructBase implements StackInterface {
  private items: Array<number>;

  static options = ["Push", "Pop", "Show top", "Print stack", "Exit"];

  constructor(size: number) {
    super();
    this.items = [];
    this.size = size;
  }

  isEmpty(): boolean {
    return !this.items.length;
  }

  isFull(): boolean {
    return this.items.length === this.size;
  }

  push(value: number | Node): void {
    try {
      if (this.isFull()) throw "Stack is full. Can't push more data.";
      if (typeof value !== "number") value = value.data;
      this.items.unshift(value);
    } catch (err) {
      console.error(err);
    }
  }

  pop(): number | Node | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty.";
      return this.items.shift();
    } catch (err: any) {
      console.error(err);
    }
  }

  peek(): number | Node | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty. Please, push some value";
      return this.items[0];
    } catch (err: any) {
      console.error(err);
    }
  }

  toString(): string {
    let str = "\tHEAD -> ";
    str += [...this.items].join(" -> ");
    str += this.items.length ? "-> NULL\n" : "NULL\n";
    return str;
  }
}
