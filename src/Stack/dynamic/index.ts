import Stack from "./Stack";
import * as readline from "readline";
import { stdin as input, stdout as output } from "node:process";
import { Node } from "../../Node/Node";

var stack = new Stack();

const rl = readline.createInterface({ input, output });

const closeAll = () => {
  rl.close();
  process.exit();
};

const action = (option: number) => {
  console.clear();
  switch (option) {
    case 1:
      break;
    case 2:
      console.log("Pop:", stack.pop()?.data);
      break;
    case 3:
      console.log("Top:", stack.peek()?.data);
      break;
    case 4:
      console.log(stack.toString());
      break;
    case 5:
      return closeAll();
    default:
      console.log("Option doesn't exists. Please, try again.\n");
      break;
  }
  if (option !== 1) return show_menu();
  rl.question("Write a value: ", (answer) => {
    const node = {
      data: parseInt(answer),
      link: undefined,
    } as Node;
    stack.push(node);
    show_menu();
  });
};

const show_menu = () => {
  console.log("Choose an option");
  Stack.options.forEach((elem, idx) => {
    console.log(`${idx + 1}.- ${elem}`);
  });
  rl.question("Type an option: ", (answer) => {
    action(parseInt(answer));
  });
};

console.log("\tDynamic Stack\n");
show_menu();
