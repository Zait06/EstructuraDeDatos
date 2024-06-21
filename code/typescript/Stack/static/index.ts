import Stack from "./Stack";
import * as utils from "../../utils/utils";

var stack: Stack;

const action = (option: number) => {
  console.clear();
  switch (option) {
    case 1:
      break;
    case 2:
      console.log("Pop:", stack.pop());
      break;
    case 3:
      console.log("Top:", stack.peek());
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
    stack.push(parseInt(answer));
    utils.showMenu(Stack.options, action);
  });
};

console.clear();
console.log("\tStatic Stack\n");
utils.readlineInterface.question("Stack size: ", (answer) => {
  stack = new Stack(parseInt(answer));
  utils.showMenu(Stack.options, action);
});
