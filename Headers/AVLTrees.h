/**
 * @file AVLTrees.h
 * @brief AVL (self-balancing BST) tree class and node declarations.
 *
 * Implements insertion, deletion with automatic rebalancing,
 * search, and sideways visualisation.
 */

#ifndef _AVL_TREES_H
#define _AVL_TREES_H

/**
 * @class AVLNode
 * @brief Node for an AVL tree.
 */
class AVLNode {
public:
    int data;           ///< Integer key stored in the node.
    AVLNode *left;      ///< Pointer to the left child.
    AVLNode *right;     ///< Pointer to the right child.
    int height;         ///< Height of the subtree rooted at this node.

    /**
     * @brief Constructs an AVLNode with the given value.
     * @param v Integer key to store.
     */
    AVLNode(int v);
};

/**
 * @class AVLTree
 * @brief Self-balancing binary search tree (AVL).
 */
class AVLTree {
private:
    AVLNode* root;      ///< Pointer to the root node.

    /**
     * @brief Returns the height of a node (0 if null).
     * @param n Pointer to the node.
     * @return Height of the node.
     */
    int getHeight(AVLNode* n);

    /**
     * @brief Computes the balance factor of a node (left height − right height).
     * @param n Pointer to the node.
     * @return Balance factor.
     */
    int getBalance(AVLNode* n);

    /**
     * @brief Returns the larger of two integers.
     * @param a First integer.
     * @param b Second integer.
     * @return The maximum of a and b.
     */
    int maxVal(int a, int b);

    /**
     * @brief Performs a right rotation on subtree rooted at y.
     * @param y Root of the subtree to rotate.
     * @return New root after rotation.
     */
    AVLNode* rotateRight(AVLNode* y);

    /**
     * @brief Performs a left rotation on subtree rooted at x.
     * @param x Root of the subtree to rotate.
     * @return New root after rotation.
     */
    AVLNode* rotateLeft(AVLNode* x);

    /**
     * @brief Finds the node with the minimum value in the subtree.
     * @param node Root of the subtree.
     * @return Pointer to the node with the smallest key.
     */
    AVLNode* findMinNode(AVLNode* node);

    /**
     * @brief Recursively inserts a value and rebalances the subtree.
     * @param node Current subtree root.
     * @param data Value to insert.
     * @return New subtree root after insertion and rebalancing.
     */
    AVLNode* insert(AVLNode* node, int data);

    /**
     * @brief Recursively removes a value and rebalances the subtree.
     * @param root Current subtree root.
     * @param data Value to remove.
     * @return New subtree root after deletion and rebalancing.
     */
    AVLNode* remove(AVLNode* root, int data);

    /**
     * @brief Recursively searches for a value in the subtree.
     * @param n    Current subtree root.
     * @param data Value to search for.
     * @return true if the value is found.
     */
    bool search(AVLNode* n, int data);

    /**
     * @brief Prints the tree sideways (right subtree on top) with
     *        indentation proportional to depth.
     * @param r       Current subtree root.
     * @param spacing Current indentation level.
     */
    void draw(AVLNode* r, int spacing);

public:
    /** @brief Constructs an empty AVLTree. */
    AVLTree() : root(nullptr) {}

    /**
     * @brief Public insert wrapper.
     * @param d Value to insert.
     */
    void insert(int d) { root = insert(root, d); }

    /**
     * @brief Public remove wrapper.
     * @param d Value to remove.
     */
    void remove(int d) { root = remove(root, d); }

    /**
     * @brief Public search wrapper.
     * @param d Value to search for.
     * @return true if the value exists in the tree.
     */
    bool search(int d) { return search(root, d); }

    /** @brief Prints the tree to the console. */
    void display() { draw(root, 0); }
};

/**
 * @brief Interactive driver: builds and manipulates an AVL tree via a
 *        console menu.
 * @return 0 on normal exit.
 */
int createAVLTree();

#endif
