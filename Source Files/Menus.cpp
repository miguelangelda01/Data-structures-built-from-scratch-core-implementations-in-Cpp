/**
 * @file Menus.cpp
 * @brief Implementations of console menu print functions.
 */

#include <iostream>
#include "../Headers/Menus.h"

using namespace std;

/**
 * @brief Displays the main menu of the program.
 */
void mainMenu(){
    system("cls"); 
    cout << "\n=======================================================================\n";
    cout << "                   WELCOME TO DATA STRUCTURES\n";
    cout << "=======================================================================\n";
    cout << "[1] Create Linked List\n";
    cout << "[2] Create Queue\n";
    cout << "[3] Create Stack\n";
    cout << "[4] Create Hash Table\n";
    cout << "[5] Create Tree\n";
    cout << "[6] Create AVL Tree\n";
    cout << "[7] Create Red-Black Tree\n";
    cout << "[8] Create Graph\n";
    cout << "[9] Exit\n";
    cout << "=======================================================================\n";
    cout << "Enter an option: ";
}

/**
 * @brief Displays the singly-linked list operations menu.
 */
void linkedListMenu(){
    system("cls"); 
    cout << "\n=======================================================================\n";
    cout << "                      SINGLY LINKED LIST\n";
    cout << "=======================================================================\n";
    cout << "[1] Insert element at the front of the list\n";
    cout << "[2] Insert element at the end of the list\n";
    cout << "[3] Print list values\n";
    cout << "[4] Print list values using recursion\n";
    cout << "[5] Insert value before a node by reference\n";
    cout << "[6] Insert value before a node by position\n";
    cout << "[7] Insert value after a node by reference\n";
    cout << "[8] Insert value after a node by position\n";
    cout << "[9] Remove the first element of the list\n";
    cout << "[10] Remove a node by reference\n";
    cout << "[11] Remove a node by position\n";
    cout << "[12] Remove the last node of the list\n";
    cout << "[13] Union of lists\n";
    cout << "[14] Intersection of lists\n";
    cout << "[15] Difference of lists\n";
    cout << "[16] Move one list to another\n";
    cout << "[17] EXIT\n";
    cout << "=======================================================================\n";
    cout << "Enter an option: ";
}

/**
 * @brief Displays the FIFO queue operations menu.
 */
void queueMenu(){
    system("cls");
    cout << "\n===================================================\n";
    cout << "                      QUEUE\n";
    cout << "===================================================\n";
    cout << "[1] Enqueue data\n";
    cout << "[2] Dequeue data\n";
    cout << "[3] Get front element\n";
    cout << "[4] Get rear element\n";
    cout << "[5] Display queue data\n";
    cout << "[6] Remove a node by reference\n";
    cout << "[7] Remove a node by position\n";
    cout << "[8] Count the number of elements\n";
    cout << "[9] Find the largest number in the queue\n";
    cout << "[10] Merge queues\n";
    cout << "[11] Move data from one queue to another\n";
    cout << "[12] Exit\n";
    cout << "===================================================\n";
    cout << "Enter an option: ";
}

/**
 * @brief Displays the LIFO stack operations menu.
 */
void stackMenu(){
    system("cls"); 
    cout << "\n=======================================================\n";
    cout << "                          STACK\n";
    cout << "=======================================================\n";
    cout << "[1] Push data onto the stack\n";
    cout << "[2] Pop data from the stack\n";
    cout << "[3] Get top element of the stack\n";
    cout << "[4] Display stack data\n";
    cout << "[5] Count the number of elements in the stack\n";
    cout << "[6] Find the largest number in the stack\n";
    cout << "[7] Remove a node by reference\n";
    cout << "[8] Remove a node by position\n";
    cout << "[9] Concatenate stacks\n";
    cout << "[10] Convert an infix expression to postfix\n";
    cout << "[11] Exit\n";
    cout << "=======================================================\n";
    cout << "Enter an option: ";
}

/**
 * @brief Displays the Hash Table operations menu.
 */
void hashTableMenu(){
    system("cls"); 
    cout << "\n===========================================\n";
    cout << "                  HASH TABLE\n";
    cout << "===========================================\n";
    cout << "[1] Insert name and key into the Hash Table\n";
    cout << "[2] Search for a name in the Hash Table\n";
    cout << "[3] Exit\n";
    cout << "===========================================\n";
    cout << "Enter an option: ";
}

/**
 * @brief Displays the Binary Search Tree operations menu.
 */
void treeMenu(){
    system("cls");
    cout << "\n========================================================\n";
    cout << "                 BINARY SEARCH TREE\n";
    cout << "=========================================================\n";
    cout << "[1] Insert element\n";
    cout << "[2] Show root element\n";
    cout << "[3] Show full tree sideways (root on the left)\n";
    cout << "[4] Render full tree graphically\n";
    cout << "[5] Search for an element in the tree\n";
    cout << "[6] Find the minimum value element\n";
    cout << "[7] Find the maximum value element\n";
    cout << "[8] PreOrder traversal\n";
    cout << "[9] InOrder traversal\n";
    cout << "[10] PostOrder traversal\n";
    cout << "[11] Delete a node (Predecessor)\n";
    cout << "[12] Delete a node (Successor)\n";
    cout << "[13] Level-order traversal\n";
    cout << "[14] Get tree height\n";
    cout << "[15] Get leaf count\n";
    cout << "[16] Get node count\n";
    cout << "[17] Show mirror tree\n";
    cout << "[18] Check if complete binary tree\n";
    cout << "[19] Check if full binary tree\n";
    cout << "[20] Build tree: 8, 3, 1, 20, 1, 5, 10, 7, 4\n";
    cout << "[21] Delete the tree\n";
    cout << "[22] Exit\n";
    cout << "=========================================================\n";
    cout << "Enter your option: ";
}

/**
 * @brief Displays the AVL Tree operations menu.
 */
void avlTreeMenu(){
    system("cls");
    cout << "\n====================================\n";
    cout << "             AVL TREE\n";
    cout << "====================================\n";
    cout << "[1] Insert a value into the tree\n";
    cout << "[2] Delete a value from the tree\n";
    cout << "[3] Search for a value in the tree\n";
    cout << "[4] Display the tree\n";
    cout << "[5] Exit\n";
    cout << "====================================\n";
    cout << "Enter your option: ";   
}

/**
 * @brief Displays the Red-Black Tree operations menu.
 */
void redBlackTreeMenu() {
    cout << "\n============================\n";
    cout << "      RED-BLACK TREE\n";
    cout << "============================\n";
    cout << "[1] Insert\n";
    cout << "[2] Delete\n";
    cout << "[3] Search\n";
    cout << "[4] InOrder\n";
    cout << "[5] PreOrder\n";
    cout << "[6] PostOrder\n";
    cout << "[7] Information\n";
    cout << "[8] Print tree\n";
    cout << "[9] Exit\n";
    cout << "============================\n";
    cout << "Option: ";
}

/**
 * @brief Displays the Graph operations menu.
 */
void graphMenu(){
    system("cls");
    cout << "\n=====================================================================\n";
    cout << "                                GRAPHS\n";
    cout << "=====================================================================\n";
    cout << "[1] Create vertex\n";
    cout << "[2] Delete vertex\n";
    cout << "[3] Create edge\n";
    cout << "[4] Delete edge\n";
    cout << "[5] Modify vertex value\n";
    cout << "[6] Display graph\n";
    cout << "[7] Check adjacency between two vertices\n";
    cout << "[8] Create Graph 1\n";
    cout << "[9] Create Graph 2\n";
    cout << "[10] Create Graph 3\n";
    cout << "[11] Apply Kruskal's algorithm (undirected weighted graphs only)\n";
    cout << "[12] Apply Prim's algorithm (undirected weighted graphs only)\n";
    cout << "[13] Apply Dijkstra's algorithm (weighted graphs with positive weights only)\n";
    cout << "[14] Perform depth-first traversal\n";
    cout << "[15] Perform breadth-first traversal\n";
    cout << "[16] Exit\n";
    cout << "=====================================================================\n";
    cout << "Enter your option: ";
}
