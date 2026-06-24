/**
 * @file Trees.cpp
 * @brief Implementation of the Tree class (Binary Search Tree) and helper functions.
 */

#include <iostream>
#include <queue>
#include <windows.h>
#include "../Headers/Trees.h"
#include "../Headers/Menus.h"
#include "../Headers/Config.h"

using namespace std;

/**
 * @brief Constructor for Tree.
 */
Tree::Tree(){
    rootPtr = nullptr;
}

/**
 * @brief Destructor for Tree.
 */
Tree::~Tree(){
    pruneTree(rootPtr);
}

/**
 * @brief Checks if the tree is empty.
 * @return true if empty, false otherwise.
 */
bool Tree::isEmpty(){
    return rootPtr == nullptr;
}

/**
 * @brief Moves the console cursor to the coordinates (x, y).
 * @param x Column index.
 * @param y Row index.
 */
void Tree::gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * @brief Returns the root pointer of the tree.
 * @return TreeNode* The root pointer.
 */
TreeNode* Tree::getRoot(){
    return rootPtr;
}

/**
 * @brief Inserts a node with the given value into the BST.
 * @param value The value to insert.
 * @param nodePtr Reference to the pointer of the current node.
 */
void Tree::insertNode(int value, TreeNode *&nodePtr){
    if(nodePtr == nullptr){
        nodePtr = new TreeNode();
        nodePtr->data = value;
        nodePtr->leftPtr = nullptr;
        nodePtr->rightPtr = nullptr;
    }else if(value < nodePtr->data){
        insertNode(value, nodePtr->leftPtr);
    }else if(value > nodePtr->data){
        insertNode(value, nodePtr->rightPtr);
    }
}

/**
 * @brief Displays the tree sideways.
 * @param level Indentation level representing depth.
 * @param nodePtr Pointer to the current node.
 */
void Tree::displaySideways(int level, TreeNode* nodePtr){
    if(nodePtr == nullptr){
        return;
    }

    displaySideways(level + 1, nodePtr->rightPtr);

    for(int i = 0; i < level; i++){
        cout << "   ";
    }

    cout << nodePtr->data << endl;

    displaySideways(level + 1, nodePtr->leftPtr);
}

/**
 * @brief Renders the tree visually in 2D console space.
 * @param nodePtr Current node pointer.
 * @param x Column coordinate.
 * @param y Row coordinate.
 * @param n Depth factor for spacing adjustment.
 */
void Tree::renderTree(TreeNode *nodePtr, int x, int y, int n){
    if(nodePtr == nullptr){
        return;
    }
    gotoxy(x, y);
    cout << nodePtr->data;
    renderTree(nodePtr->leftPtr, x - 15 + n * 6, y + 2, n + 1);
    renderTree(nodePtr->rightPtr, x + 15 - n * 6, y + 2, n + 1);
}

/**
 * @brief Searches for a value in the tree.
 * @param x The value to find.
 * @param nodePtr Current node pointer.
 * @return true if found, false otherwise.
 */
bool Tree::search(int x, TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return false;
    }else if(x < nodePtr->data){
        return search(x, nodePtr->leftPtr);
    }else if(x > nodePtr->data){
        return search(x, nodePtr->rightPtr);
    }else{
        return true;
    }
}

/**
 * @brief Finds the node with the minimum value.
 * @param nodePtr Start node pointer.
 * @return TreeNode* The min node pointer.
 */
TreeNode* Tree::findMin(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return nullptr;
    }else if(nodePtr->leftPtr == nullptr){
        return nodePtr;
    }else{
        return findMin(nodePtr->leftPtr);
    }
}

/**
 * @brief Finds the node with the maximum value.
 * @param nodePtr Start node pointer.
 * @return TreeNode* The max node pointer.
 */
TreeNode* Tree::findMax(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return nullptr;
    }else if(nodePtr->rightPtr == nullptr){
        return nodePtr;
    }else{
        return findMax(nodePtr->rightPtr);
    }
}

/**
 * @brief Deletes a node by replacing it with its predecessor.
 * @param x The value to delete.
 * @param nodePtr Subtree root node reference.
 */
void Tree::deletePredecessor(int x, TreeNode *&nodePtr){
    if(nodePtr == nullptr){
        return;
    }else if(x < nodePtr->data){
        deletePredecessor(x, nodePtr->leftPtr);
    }else if(x > nodePtr->data){
        deletePredecessor(x, nodePtr->rightPtr);
    }else if(nodePtr->leftPtr && nodePtr->rightPtr){
        TreeNode* maxNode = findMax(nodePtr->leftPtr);
        nodePtr->data = maxNode->data;
        deletePredecessor(maxNode->data, nodePtr->leftPtr);
    }else{
        TreeNode *temp = nodePtr;
        if(nodePtr->leftPtr == nullptr){
            nodePtr = nodePtr->rightPtr;
        }else if(nodePtr->rightPtr == nullptr){
            nodePtr = nodePtr->leftPtr;
        }

        delete temp;
    }
}

/**
 * @brief Deletes a node by replacing it with its successor.
 * @param x The value to delete.
 * @param nodePtr Subtree root node reference.
 */
void Tree::deleteSuccessor(int x, TreeNode *&nodePtr){
    if(nodePtr == nullptr){
        return;
    }else if(x < nodePtr->data){
        deleteSuccessor(x, nodePtr->leftPtr);
    }else if(x > nodePtr->data){
        deleteSuccessor(x, nodePtr->rightPtr);
    }else if(nodePtr->leftPtr && nodePtr->rightPtr){
        TreeNode* minNode = findMin(nodePtr->rightPtr);
        nodePtr->data = minNode->data;
        deleteSuccessor(minNode->data, nodePtr->rightPtr);
    }else{
        TreeNode *temp = nodePtr;
        if(nodePtr->leftPtr == nullptr){
            nodePtr = nodePtr->rightPtr;
        }else if(nodePtr->rightPtr == nullptr){
            nodePtr = nodePtr->leftPtr;
        }

        delete temp;
    }
}

/**
 * @brief Traverses the tree in pre-order.
 * @param nodePtr Subtree root node pointer.
 */
void Tree::preOrder(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return;
    }

    cout << nodePtr->data << " - ";
    preOrder(nodePtr->leftPtr);
    preOrder(nodePtr->rightPtr);
}

/**
 * @brief Traverses the tree in-order.
 * @param nodePtr Subtree root node pointer.
 */
void Tree::inOrder(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return;
    }

    inOrder(nodePtr->leftPtr);
    cout << nodePtr->data << " - ";
    inOrder(nodePtr->rightPtr);
}

/**
 * @brief Traverses the tree in post-order.
 * @param nodePtr Subtree root node pointer.
 */
void Tree::postOrder(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return;
    }

    postOrder(nodePtr->leftPtr);
    postOrder(nodePtr->rightPtr);
    cout << nodePtr->data << " - ";
}

/**
 * @brief Traverses the tree in level-order.
 * @param nodePtr Subtree root node pointer.
 */
void Tree::levelOrderTraversal(TreeNode *nodePtr){
    if(nodePtr == nullptr) return;
    TreeNode *auxNode;
    queue<TreeNode*> auxQueue;
    auxQueue.push(nodePtr);
    while(!auxQueue.empty()){
        auxNode = auxQueue.front();
        cout << auxNode->data << " - ";
        auxQueue.pop();

        if(auxNode->leftPtr != nullptr){
            auxQueue.push(auxNode->leftPtr);
        }
        if(auxNode->rightPtr != nullptr){
            auxQueue.push(auxNode->rightPtr);
        }
    }
}

/**
 * @brief Computes the height of the tree.
 * @param nodePtr Subtree root node pointer.
 * @return int The height value.
 */
int Tree::height(TreeNode* nodePtr){
    if(nodePtr == nullptr){
        return 0;
    }

    return (1 + max(height(nodePtr->leftPtr), height(nodePtr->rightPtr)));
}

/**
 * @brief Counts leaf nodes in the tree.
 * @param nodePtr Subtree root node pointer.
 * @return int The count of leaf nodes.
 */
int Tree::countLeaves(TreeNode* nodePtr){
    if(nodePtr == nullptr){
        return 0;
    }
    if(nodePtr->leftPtr == nullptr && nodePtr->rightPtr == nullptr){
        return 1;
    }else{
        return countLeaves(nodePtr->leftPtr) + countLeaves(nodePtr->rightPtr);
    }
}

/**
 * @brief Counts total nodes in the tree.
 * @param nodePtr Subtree root node pointer.
 * @return int The count of all nodes.
 */
int Tree::countNodes(TreeNode* nodePtr){
    if(nodePtr == nullptr){
        return 0;
    }

    return 1 + countNodes(nodePtr->leftPtr) + countNodes(nodePtr->rightPtr);
}

/**
 * @brief Swaps the left and right pointers in-place.
 * @param nodePtr Current node pointer.
 */
void Tree::mirrorTree(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return;
    }
    TreeNode *temp = nodePtr->leftPtr;
    nodePtr->leftPtr = nodePtr->rightPtr;
    nodePtr->rightPtr = temp;

    mirrorTree(nodePtr->leftPtr);
    mirrorTree(nodePtr->rightPtr);
}

/**
 * @brief Checks if the tree is complete.
 * @param nodePtr Subtree root node pointer.
 * @return true if complete, false otherwise.
 */
bool Tree::isComplete(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return true;
    }
    TreeNode *auxNode;
    queue<TreeNode*> auxQueue;
    auxQueue.push(nodePtr);
    bool hasIncompleteNode = false;

    while(!auxQueue.empty()){
        auxNode = auxQueue.front();
        auxQueue.pop();

        if(auxNode->leftPtr){
            if(hasIncompleteNode == true){
                return false;
            }
            auxQueue.push(auxNode->leftPtr);
        }else{
            hasIncompleteNode = true;
        }

        if(auxNode->rightPtr){
            if(hasIncompleteNode == true){
                return false;
            }
            auxQueue.push(auxNode->rightPtr);
        }else{
            hasIncompleteNode = true;
        }
    }

    return true;
}

/**
 * @brief Checks if the tree is full.
 * @param nodePtr Subtree root node pointer.
 * @return true if full, false otherwise.
 */
bool Tree::isFull(TreeNode *nodePtr){
    if(nodePtr == nullptr){
        return true;
    }

    if(nodePtr->leftPtr == nullptr && nodePtr->rightPtr == nullptr){
        return true;
    }

    if(nodePtr->leftPtr && nodePtr->rightPtr){
        return (isFull(nodePtr->leftPtr) && isFull(nodePtr->rightPtr));
    }

    return false;
}

/**
 * @brief Deletes all nodes in the tree to free memory.
 * @param nodePtr Subtree root node pointer reference.
 */
void Tree::pruneTree(TreeNode *&nodePtr){
    if(nodePtr == nullptr){
        return;
    }
    pruneTree(nodePtr->leftPtr);
    pruneTree(nodePtr->rightPtr);
    delete nodePtr;
    nodePtr = nullptr;
}

/**
 * @brief Interactive driver to test Tree BST operations.
 */
void createTree(){
    int option;
    int value;
    int x;

    Tree integerTree;
    TreeNode *treeRootPtr = integerTree.getRoot();

    system("color 1F");

    do{
        treeMenu();
        cin >> option;
        if(!validateMenuInput(cin, 22, option)){
            option = 0;
            system("pause");
        }
        if((option > 1 && option < 13) && treeRootPtr == nullptr){
            cout << "\nThe tree is empty\n\n";
            system("pause");
            option = 0;
        }

        switch(option){
            case 1:
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }

                integerTree.insertNode(value, treeRootPtr);
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 2:
                cout << "\nThe root node value is: " << treeRootPtr->data << "\n\n";
                system("pause");
                break;
            case 3:
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 4:
                system("cls");
                integerTree.renderTree(treeRootPtr, 45, 2, 0);
                cout << "\n\n\n\n\n\n\n\n";
                system("pause");
                break;
            case 5:
                cout << "\nEnter the value to search for: ";
                cin >> x;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }

                if(integerTree.search(x, treeRootPtr)){
                    cout << "\nElement " << x << " was found in the tree\n";
                }else{
                    cout << "\nElement not found";
                }
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 6:
                cout << "\nThe minimum value element is: " << integerTree.findMin(treeRootPtr)->data << "\n\n";
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 7:
                cout << "\nThe maximum value element is: " << integerTree.findMax(treeRootPtr)->data << "\n\n";
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 8:
                cout << "\nPreOrder traversal: ";
                integerTree.preOrder(treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 9:
                cout << "\nInOrder traversal: ";
                integerTree.inOrder(treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 10:
                cout << "\nPostOrder traversal: ";
                integerTree.postOrder(treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 11:
                cout << "\nEnter the value to delete (Predecessor): ";
                cin >> x;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }

                integerTree.deletePredecessor(x, treeRootPtr);

                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 12:
                cout << "\nEnter the value to delete (Successor): ";
                cin >> x;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }

                integerTree.deleteSuccessor(x, treeRootPtr);

                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 13:
                cout << "\nLevel-order traversal: ";
                integerTree.levelOrderTraversal(treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 14:
                cout << "\nThe tree height is: " << integerTree.height(treeRootPtr);
                
                cout << "\n\n";
                system("pause");
                break;
            case 15:
                cout << "\nThe number of leaves in the tree is: " << integerTree.countLeaves(treeRootPtr);
                
                cout << "\n\n";
                system("pause");
                break;
            case 16:
                cout << "\nThe number of nodes in the tree is: " << integerTree.countNodes(treeRootPtr);
                
                cout << "\n\n";
                system("pause");
                break;
            case 17:
                system("cls");
                integerTree.mirrorTree(treeRootPtr);
                integerTree.renderTree(treeRootPtr, 45, 2, 0);
                integerTree.mirrorTree(treeRootPtr);
                break;
            case 18:
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";

                if(integerTree.isComplete(treeRootPtr)){
                    cout << "\nIt is a complete binary tree";
                }else{
                    cout << "\nIt is not a complete binary tree";
                }
                cout << "\n\n";
                system("pause");
                break;
            case 19:
                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";

                if(integerTree.isFull(treeRootPtr)){
                    cout << "\nIt is a full binary tree";
                }else{
                    cout << "\nIt is not a full binary tree";
                }
                cout << "\n\n";
                system("pause");
                break;
            case 20:
                integerTree.insertNode(8, treeRootPtr);
                integerTree.insertNode(3, treeRootPtr);
                integerTree.insertNode(1, treeRootPtr);
                integerTree.insertNode(20, treeRootPtr);
                integerTree.insertNode(1, treeRootPtr);
                integerTree.insertNode(5, treeRootPtr);
                integerTree.insertNode(10, treeRootPtr);
                integerTree.insertNode(7, treeRootPtr);
                integerTree.insertNode(4, treeRootPtr);

                cout << "\n\nTree elements displayed sideways (root on the left):\n\n";
                integerTree.displaySideways(0, treeRootPtr);
                cout << "\n\n";
                system("pause");
                break;
            case 21:
                integerTree.pruneTree(treeRootPtr);
                cout << "\nThe tree has been deleted\n";
                cout << "\n\n";
                system("pause");
                break;
        }
    }while(option != 22);

    cout << "\nExiting...\n";
}
