import Stack from "./Stack";
import { Node } from "../../Node/Node";
import * as utils from "../../utils/utils";

var stack = new Stack();

const action = (option: number) => {
  console.clear();
  let auxValue: number | Node | undefined;
  switch (option) {
    case 1:
      break;
    case 2:
      auxValue = stack.pop();
      if (typeof auxValue !== "number") auxValue = auxValue?.data;
      console.log("Pop:", auxValue);
      break;
    case 3:
      auxValue = stack.peek();
      if (typeof auxValue !== "number") auxValue = auxValue?.data;
      console.log("Top:", auxValue);
      break;
    case 4:
      console.log(stack.toString());
      break;
    case 5:
      return utils.closeAll();
    default:
      console.log("Option doesn't exists. Please, try again.\n");
      break;
  }
  if (option !== 1) return utils.showMenu(Stack.options, action);
  utils.readlineInterface.question("Write a value: ", (answer) => {
    const node = {
      data: parseInt(answer),
      link: undefined,
    } as Node;
    stack.push(node);
    utils.showMenu(Stack.options, action);
  });
};

console.clear();
console.log("\tDynamic Stack\n");
utils.showMenu(Stack.options, action);
