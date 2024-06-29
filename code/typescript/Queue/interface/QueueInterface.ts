import { Node } from "../../Node/Node";

export default interface QueueInterface {
  enqueue(value: number | Node): void;
  dequeue(): number | Node | undefined;
  head(): number | Node | undefined;
  tail(): number | Node | undefined;
}
