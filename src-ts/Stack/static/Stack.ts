export default class Stack {
    _stack: Array<number>;
    size: number;

    constructor(size: number) {
        this._stack = [];
        this.size = size;
    }

    is_empty(): boolean {
        return !this._stack.length;
    }

    is_full(): boolean {
        return this._stack.length === this.size;
    }

    push(value: number) {
        try {
            if (this.is_full())
                throw "Stack is full. Can't push more data.";
            this._stack.push(value);
        } catch (err) {
            console.error(err)
        }
    }

    pop(): number | undefined {
        try {
            if (this.is_empty())
                throw "Stack is empty.";
            return this._stack.pop();
        } catch (err: any) {
            console.error(err)
        }
    }

    peek(): number | undefined {
        try {
            if (this.is_empty())
                throw "Stack is empty. Please, push some value";
            return this._stack[this._stack.length - 1];
        } catch (err: any) {
            console.error(err)
        }
    }

    toString(): string {
        let str = "\tHEAD -> ";
        str += [...this._stack].reverse().join(" -> ")
        str += "NULL\n";
        return str;
    }
}