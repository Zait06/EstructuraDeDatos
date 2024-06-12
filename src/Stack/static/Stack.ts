import StructBase from "../../StructBase/StructBase";

export default class Stack extends StructBase {
  private _items: Array<number>;

  static options = ["Push", "Pop", "Show top", "Print stack", "Exit"];

  constructor(size: number) {
    super();
    this._items = [];
    this.size = size;
  }

  isEmpty(): boolean {
    return !this._items.length;
  }

  isFull(): boolean {
    return this._items.length === this.size;
  }

  push(value: number) {
    try {
      if (this.isFull()) throw "Stack is full. Can't push more data.";
      this._items.push(value);
    } catch (err) {
      console.error(err);
    }
  }

  pop(): number | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty.";
      return this._items.pop();
    } catch (err: any) {
      console.error(err);
    }
  }

  peek(): number | undefined {
    try {
      if (this.isEmpty()) throw "Stack is empty. Please, push some value";
      return this._items[this._items.length - 1];
    } catch (err: any) {
      console.error(err);
    }
  }

  toString(): string {
    let str = "\tHEAD -> ";
    str += [...this._items].reverse().join(" -> ");
    str += "NULL\n";
    return str;
  }
}
