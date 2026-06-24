/**
 * @file Main.cpp
 * @brief Main entry point of the project showcasing various data structures.
 */

#include "../Headers/AVLTrees.h"
#include "../Headers/Config.h"
#include "../Headers/Graphs.h"
#include "../Headers/HashTable.h"
#include "../Headers/LinkedList.h"
#include "../Headers/Menus.h"
#include "../Headers/Queues.h"
#include "../Headers/RedBlackTrees.h"
#include "../Headers/Stacks.h"
#include "../Headers/Trees.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function. Runs the main interactive menu loop.
 * @return int Exit status code.
 */
int main() {
  int option;
  system("color 1F");
  do {
    mainMenu();
    cin >> option;
    if (!validateMenuInput(cin, 9, option)) {
      option = 0;
      system("pause");
    }
    switch (option) {
    case 1:
      createLinkedList();
      break;
    case 2:
      createQueue();
      break;
    case 3:
      createStack();
      break;
    case 4:
      accessHashTable();
      break;
    case 5:
      createTree();
      break;
    case 6:
      createAVLTree();
      break;
    case 7:
      createRedBlackTree();
      break;
    case 8:
      createGraph();
      break;
    }
  } while (option != 9);

  cout << "Exiting...";
  return 0;
}
