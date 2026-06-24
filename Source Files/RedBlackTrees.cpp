/**
 * @file RedBlackTrees.cpp
 * @brief Implementation of RedBlackTree class and helper functions.
 */

#include <iostream>
#include "../Headers/RedBlackTrees.h"
#include "../Headers/Menus.h"
#include "../Headers/Config.h"

using namespace std;

/**
 * @brief Performs a left rotation around node x.
 * @param x The node to rotate around.
 */
void RedBlackTree::rotateLeft(RBTNode *x) {
    RBTNode *y = x->right;

    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

/**
 * @brief Performs a right rotation around node y.
 * @param y The node to rotate around.
 */
void RedBlackTree::rotateRight(RBTNode *y) {
    RBTNode *x = y->left;

    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

/**
 * @brief Fixes red-black violations after an insertion.
 * @param z The newly inserted node.
 */
void RedBlackTree::fixInsert(RBTNode *z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent->parent == nullptr)
            break;

        RBTNode *gp = z->parent->parent;

        if (z->parent == gp->left) {
            RBTNode *uncle = gp->right;

            if (uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;
                z = gp;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(z);
                }

                z->parent->color = BLACK;
                gp->color = RED;
                rotateRight(gp);
            }
        }
        else {
            RBTNode *uncle = gp->left;

            if (uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                gp->color = RED;
                z = gp;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(z);
                }

                z->parent->color = BLACK;
                gp->color = RED;
                rotateLeft(gp);
            }
        }
    }

    root->color = BLACK;
}

/**
 * @brief Replaces subtree rooted at u with subtree rooted at v.
 * @param u The node to be replaced.
 * @param v The replacement node.
 */
void RedBlackTree::transplant(RBTNode *u, RBTNode *v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    v->parent = u->parent;
}

/**
 * @brief Fixes red-black violations after a deletion.
 * @param x The node at which to start fixing.
 */
void RedBlackTree::fixDelete(RBTNode *x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            RBTNode *w = x->parent->right;

            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight(w);
                    w = x->parent->right;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        }
        else {
            RBTNode *w = x->parent->left;

            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft(w);
                    w = x->parent->left;
                }

                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }

    x->color = BLACK;
}

/**
 * @brief Finds the minimum node of a subtree.
 * @param node Subtree root.
 * @return RBTNode* Minimum node.
 */
RBTNode* RedBlackTree::minimum(RBTNode *node) const {
    while (node->left != NIL)
        node = node->left;

    return node;
}

/**
 * @brief Finds the maximum node of a subtree.
 * @param node Subtree root.
 * @return RBTNode* Maximum node.
 */
RBTNode* RedBlackTree::maximum(RBTNode *node) const {
    while (node->right != NIL)
        node = node->right;

    return node;
}

/**
 * @brief Searches for a key node in the tree.
 * @param node Subtree root.
 * @param key Value to search for.
 * @return RBTNode* The node if found, nullptr otherwise.
 */
RBTNode* RedBlackTree::searchNode(RBTNode *node, int key) const {
    while (node != NIL) {
        if (key == node->data)
            return node;

        if (key < node->data)
            node = node->left;
        else
            node = node->right;
    }

    return nullptr;
}

/**
 * @brief Helper for in-order traversal.
 * @param node Subtree root.
 */
void RedBlackTree::inorderHelper(RBTNode *node) const {
    if (node == NIL)
        return;

    inorderHelper(node->left);

    cout << node->data
        << "("
        << (node->color == RED ? "R" : "B")
        << ") ";

    inorderHelper(node->right);
}

/**
 * @brief Helper for pre-order traversal.
 * @param node Subtree root.
 */
void RedBlackTree::preorderHelper(RBTNode *node) const {
    if (node == NIL)
        return;

    cout << node->data
        << "("
        << (node->color == RED ? "R" : "B")
        << ") ";

    preorderHelper(node->left);
    preorderHelper(node->right);
}

/**
 * @brief Helper for post-order traversal.
 * @param node Subtree root.
 */
void RedBlackTree::postorderHelper(RBTNode *node) const {
    if (node == NIL)
        return;

    postorderHelper(node->left);
    postorderHelper(node->right);

    cout << node->data
        << "("
        << (node->color == RED ? "R" : "B")
        << ") ";
}

/**
 * @brief Helper to calculate tree height.
 * @param node Subtree root.
 * @return int The height value.
 */
int RedBlackTree::heightHelper(RBTNode *node) const {
    if (node == NIL)
        return -1;

    int lh = heightHelper(node->left);
    int rh = heightHelper(node->right);

    return 1 + (lh > rh ? lh : rh);
}

/**
 * @brief Helper to count nodes.
 * @param node Subtree root.
 * @return int The node count.
 */
int RedBlackTree::countHelper(RBTNode *node) const {
    if (node == NIL)
        return 0;

    return 1 + countHelper(node->left) + countHelper(node->right);
}

/**
 * @brief Helper to calculate black-height.
 * @param node Subtree root.
 * @return int Black-height value, or -1 if violated.
 */
int RedBlackTree::blackHeightHelper(RBTNode *node) const {
    if (node == NIL)
        return 1;

    int lbh = blackHeightHelper(node->left);
    int rbh = blackHeightHelper(node->right);

    if (lbh == -1 || rbh == -1 || lbh != rbh)
        return -1;

    return lbh + (node->color == BLACK ? 1 : 0);
}

/**
 * @brief Checks for red-red invariant violation.
 * @param node Subtree root.
 * @return true if violation exists, false otherwise.
 */
bool RedBlackTree::redViolation(RBTNode *node) const {
    if (node == NIL)
        return false;

    if (node->color == RED) {
        if (node->left->color == RED || node->right->color == RED)
            return true;
    }

    return redViolation(node->left) || redViolation(node->right);
}

/**
 * @brief Helper to print the tree structure.
 * @param node Subtree root.
 * @param indent Prefix indentation string.
 * @param last True if the node is the last child.
 */
void RedBlackTree::printTreeHelper(RBTNode *node, string indent, bool last) const {
    if (node != NIL) {
        cout << indent;

        if (last) {
            cout << "R----";
            indent += "     ";
        }
        else {
            cout << "L----";
            indent += "|    ";
        }

        cout << node->data
            << "("
            << (node->color == RED ? "RED" : "BLACK")
            << ")"
            << endl;

        printTreeHelper(node->left, indent, false);
        printTreeHelper(node->right, indent, true);
    }
}

/**
 * @brief Recursively deletes a subtree.
 * @param node Subtree root.
 */
void RedBlackTree::destroyTree(RBTNode *node) {
    if (node == NIL)
        return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

/**
 * @brief Constructor.
 */
RedBlackTree::RedBlackTree() {
    NIL = new RBTNode(0);

    NIL->color = BLACK;
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->parent = nullptr;

    root = NIL;
}

/**
 * @brief Destructor.
 */
RedBlackTree::~RedBlackTree() {
    destroyTree(root);
    delete NIL;
}

/**
 * @brief Inserts a key into the Red-Black tree.
 * @param key Key value to insert.
 */
void RedBlackTree::insert(int key) {
    RBTNode *z = new RBTNode(key);

    z->left = NIL;
    z->right = NIL;

    RBTNode *y = nullptr;
    RBTNode *x = root;

    while (x != NIL) {
        y = x;

        if (z->data < x->data)
            x = x->left;
        else if (z->data > x->data)
            x = x->right;
        else {
            cout << "Duplicate value.\n";
            delete z;
            return;
        }
    }

    z->parent = y;

    if (y == nullptr)
        root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(z);

    cout << "Inserted: " << key << endl;
}

/**
 * @brief Deletes a key from the Red-Black tree.
 * @param key Key value to delete.
 */
void RedBlackTree::remove(int key) {
    RBTNode *z = searchNode(root, key);

    if (z == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    RBTNode *y = z;
    RBTNode *x;

    Color yOriginalColor = y->color;

    if (z->left == NIL) {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == NIL) {
        x = z->left;
        transplant(z, z->left);
    }
    else {
        y = minimum(z->right);
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z) {
            x->parent = y;
        }
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    delete z;

    if (yOriginalColor == BLACK)
        fixDelete(x);

    cout << "Deleted: " << key << endl;
}

/**
 * @brief Searches for a key in the Red-Black tree.
 * @param key Key to search.
 * @return true if found, false otherwise.
 */
bool RedBlackTree::search(int key) const {
    RBTNode *result = searchNode(root, key);

    if (result != nullptr) {
        cout << "Found: " << key << endl;
        return true;
    }

    cout << "Not found.\n";
    return false;
}

/**
 * @brief Prints the tree in in-order.
 */
void RedBlackTree::inorder() const {
    cout << "InOrder: ";
    inorderHelper(root);
    cout << endl;
}

/**
 * @brief Prints the tree in pre-order.
 */
void RedBlackTree::preorder() const {
    cout << "PreOrder: ";
    preorderHelper(root);
    cout << endl;
}

/**
 * @brief Prints the tree in post-order.
 */
void RedBlackTree::postorder() const {
    cout << "PostOrder: ";
    postorderHelper(root);
    cout << endl;
}

/**
 * @brief Checks if the Red-Black tree is valid.
 * @return true if valid, false otherwise.
 */
bool RedBlackTree::isValid() const {
    if (root == NIL)
        return true;

    if (root->color != BLACK)
        return false;

    if (redViolation(root))
        return false;

    return blackHeightHelper(root) != -1;
}

/**
 * @brief Returns the height of the tree.
 * @return int Height of the tree.
 */
int RedBlackTree::height() const {
    return heightHelper(root);
}

/**
 * @brief Returns the node count.
 * @return int RBTNode count.
 */
int RedBlackTree::count() const {
    return countHelper(root);
}

/**
 * @brief Prints the tree metadata.
 */
void RedBlackTree::printInfo() const {
    cout << "========================\n";
    cout << "Nodes  : " << count() << endl;
    cout << "Height : " << height() << endl;
    cout << "Valid  : " << (isValid() ? "YES" : "NO") << endl;
    cout << "========================\n";
}

/**
 * @brief Prints the tree structure visually.
 */
void RedBlackTree::printTree() const {
    if (root == NIL) {
        cout << "(empty tree)\n";
        return;
    }

    printTreeHelper(root, "", true);
}

/**
 * @brief Interactive driver function for Red-Black tree testing.
 * @return int Exit code.
 */
int createRedBlackTree() {
    RedBlackTree rbt;
    int option;
    int value;

    do {
        redBlackTreeMenu();
        cin >> option;
        if(!validateMenuInput(cin, 9, option)){
            cout << "\n\n";
            option = 0;
        }

        switch (option) {
            case 1:
                cout << "Value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    cout << "\n\n";
                    break;
                }
                rbt.insert(value);
                break;

            case 2:
                cout << "Value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    cout << "\n\n";
                    break;
                }
                rbt.remove(value);
                break;

            case 3:
                cout << "Value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    cout << "\n\n";
                    break;
                }
                rbt.search(value);
                break;

            case 4:
                rbt.inorder();
                break;

            case 5:
                rbt.preorder();
                break;

            case 6:
                rbt.postorder();
                break;

            case 7:
                rbt.printInfo();
                break;

            case 8:
                rbt.printTree();
                break;

            case 9:
                cout << "Done.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (option != 9);

    return 0;
}
