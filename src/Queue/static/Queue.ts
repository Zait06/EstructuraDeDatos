export default class Queue {
  private _queue: Array<number>;
  private size: number;

  constructor(size: number) {
    this._queue = new Array<number>();
    this.size = size;
  }

  isEmpty(): boolean {
    return this._queue.length === 0;
  }

  isFull(): boolean {
    return this._queue.length === this.size;
  }

  enqueue(value: number) {
    try {
      if (this.isFull()) throw "Queue is full. Can't push more data.";
      this._queue.push(value);
    } catch (err) {
      console.error(err);
    }
  }

  dequeue(): number | undefined {
    try {
      if (this.isEmpty()) throw "Queue is empty.";
      return this._queue.shift();
    } catch (err: any) {
      console.error(err);
    }
  }

  head(): number {
    if (this.isEmpty()) return -1;
    return this._queue[0];
  }

  tail(): number | undefined {
    if (this.isEmpty()) return -1;
    return this._queue.at(-1);
  }

  toString(): string {
    let str = "\nFRONT -> ";
    str += this._queue.join(" -> ");
    str += " <- TAIL\n";
    return str;
  }
}
