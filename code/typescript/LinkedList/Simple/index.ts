import LinkedList from "./LinkedList";
import * as readline from "readline";
import { stdin as input, stdout as output } from "node:process";

var linkedList: LinkedList;

const menu = [
  "1. Push",
  "2. Append",
  "3. Insert",
  "4. Get at",
  "5. Remove first",
  "6. Remove last",
  "7. Remove at",
  "8. Print list",
  "9. Exit",
];

const rl = readline.createInterface({ input, output });

const closeAll = () => {
  rl.close();
  process.exit();
};

const action = (option: number) => {
  console.clear();
  switch (option) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
      break;
    case 5:
      console.log("Remove First:", linkedList.removeFirst()?.data);
      break;
    case 6:
      console.log("Remove Last", linkedList.removeLast()?.data);
      break;
    case 8:
      console.log(linkedList.toString());
      break;
    case 9:
      return closeAll();
    default:
      console.log("Option doesn't exists. Please, try again.\n");
      break;
  }
  if (![1, 2, 3, 4, 7].includes(option)) return showMenu();
  let question = "Write a value: ";
  if (option === 3) question = "Write value and index (value,index): ";
  if ([4, 7].includes(option)) question = "Give an index: ";
  rl.question(question, (answer) => {
    let index = 0;
    switch (option) {
      case 1:
        linkedList.push({ data: parseInt(answer), link: undefined });
        break;
      case 2:
        linkedList.append({ data: parseInt(answer), link: undefined });
        break;
      case 3:
        const split = answer.split(",");
        const node = { data: parseInt(split[0]), link: undefined };
        linkedList.insert(node, parseInt(split[1]));
        break;
      case 4:
        index = parseInt(answer);
        console.log(`Value at ${index} is ${linkedList.at(index)?.data}`);
        break;
      case 7:
        index = parseInt(answer);
        console.log(`Remove ${linkedList.removeAt(index)?.data}`);
        break;
    }
    showMenu();
  });
};

const showMenu = () => {
  console.log("Choose an option: ");
  menu.forEach((e) => {
    console.log(`${e}`);
  });
  rl.question("Type an option: ", (answer) => {
    action(parseInt(answer));
  });
};

console.log("\tSimple LinkedList\n");
linkedList = new LinkedList();
showMenu();
