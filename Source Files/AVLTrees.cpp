/**
 * @file AVLTrees.cpp
 * @brief Implementation of AVLNode and AVLTree classes.
 */

#include <iostream>
#include "../Headers/AVLTrees.h"
#include "../Headers/Menus.h"
#include "../Headers/Config.h"

using namespace std;

/**
 * @brief Constructor for AVLNode.
 * @param v The integer key.
 */
AVLNode::AVLNode(int v) : data(v), left(nullptr), right(nullptr), height(1) {}

/**
 * @brief Returns the height of a node.
 * @param n Pointer to the node.
 * @return int The height value.
 */
int AVLTree::getHeight(AVLNode* n) { 
    return n ? n->height : 0; 
}

/**
 * @brief Computes the balance factor of a node.
 * @param n Pointer to the node.
 * @return int The balance factor (left height - right height).
 */
int AVLTree::getBalance(AVLNode* n) { 
    return n ? getHeight(n->left) - getHeight(n->right) : 0; 
}

/**
 * @brief Finds the maximum of two values.
 * @param a First value.
 * @param b Second value.
 * @return int The maximum value.
 */
int AVLTree::maxVal(int a, int b) {
    return (a > b) ? a : b; 
}

/**
 * @brief Performs a right rotation around a node.
 * @param y The node to rotate around.
 * @return AVLNode* The new root of this subtree.
 */
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

/**
 * @brief Performs a left rotation around a node.
 * @param x The node to rotate around.
 * @return AVLNode* The new root of this subtree.
 */
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

/**
 * @brief Finds the node with the minimum value in a subtree.
 * @param node Subtree root node.
 * @return AVLNode* Node with the minimum value.
 */
AVLNode* AVLTree::findMinNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

/**
 * @brief Recursively inserts a value into the AVL tree and rebalances.
 * @param node Subtree root node.
 * @param data Value to insert.
 * @return AVLNode* The new root of the subtree.
 */
AVLNode* AVLTree::insert(AVLNode* node, int data) {
    if (!node) return new AVLNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    else return node;

    node->height = 1 + maxVal(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) return rotateRight(node);
    if (balance < -1 && data > node->right->data) return rotateLeft(node);
    if (balance > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

/**
 * @brief Recursively deletes a value from the AVL tree and rebalances.
 * @param root Subtree root node.
 * @param data Value to delete.
 * @return AVLNode* The new root of the subtree.
 */
AVLNode* AVLTree::remove(AVLNode* root, int data) {
    if (!root) return root;

    if (data < root->data) root->left = remove(root->left, data);
    else if (data > root->data) root->right = remove(root->right, data);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (!temp) { temp = root; root = nullptr; }
            else *root = *temp;
            delete temp;
        } else {
            AVLNode* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }

    if (!root) return root;

    root->height = 1 + maxVal(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) return rotateRight(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) return rotateLeft(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

/**
 * @brief Searches for a value in the AVL tree.
 * @param n Subtree root node.
 * @param data Value to search for.
 * @return true if found, false otherwise.
 */
bool AVLTree::search(AVLNode* n, int data) {
    if (!n) return false;
    if (n->data == data) return true;
    return (data < n->data) ? search(n->left, data) : search(n->right, data);
}

/**
 * @brief Draws the AVL tree sideways on the console.
 * @param r Current node pointer.
 * @param spacing Space offset for indentation.
 */
void AVLTree::draw(AVLNode* r, int spacing) {
    if (!r) return;
    spacing += 8;
    draw(r->right, spacing);
    cout << endl;
    for (int i = 8; i < spacing; i++) cout << " ";
    cout << r->data << "\n";
    draw(r->left, spacing);
}

/**
 * @brief Interactive driver function for AVL tree testing.
 * @return int Exit code.
 */
int createAVLTree() {
    AVLTree tree;
    int option, value;
    system("color 1F");
    do {
        avlTreeMenu();
        cin >> option;
        if(!validateMenuInput(cin, 5, option)){
            system("pause");
            option = 0;
        }
        switch(option) {
            case 1: 
                cout << "Value: "; 
                cin >> value; 
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                tree.insert(value); 
                break;
            case 2: 
                cout << "Delete: "; 
                cin >> value; 
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                tree.remove(value);
                break;
            case 3: 
                cout << "Search: "; 
                cin >> value; 
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << (tree.search(value) ? "Found" : "Not found") << endl; 
                system("pause");
                break;
            case 4: 
                tree.display();
                system("pause"); 
                break;
        }
    } while(option != 5);
    return 0;
}
