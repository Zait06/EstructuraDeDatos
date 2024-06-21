import { Node } from "../../Node/Node";

export default interface StackInterface {
  push(value: number | Node): void;
  pop(): number | Node | undefined;
  peek(): number | Node | undefined;
}
