import StructBase from "../../StructBase/StructBase";

export default class Stack extends StructBase {
  _stack: Array<number>;

  constructor(size: number) {
    super();
    this._stack = [];
    this.size = size;
  }

  isEmpty(): boolean {
    return !this._stack.length;
  }

  isFull(): boolean {
    return this._stack.length === this.size;
  }

  push(value: number) {
    try {
      if (this.isFull()) throw "Stack is full. Can't push more data.";
      this._stack.push(value);
    } catch (err) {
      console.error(err);
    }
  }

  pop(): number | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty.";
      return this._stack.pop();
    } catch (err: any) {
      console.error(err);
    }
  }

  peek(): number | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty. Please, push some value";
      return this._stack[this._stack.length - 1];
    } catch (err: any) {
      console.error(err);
    }
  }

  toString(): string {
    let str = "\tHEAD -> ";
    str += [...this._stack].reverse().join(" -> ");
    str += "NULL\n";
    return str;
  }
}
