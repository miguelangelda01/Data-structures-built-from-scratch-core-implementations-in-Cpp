/**
 * @file RedBlackTrees.h
 * @brief Red-Black Tree class and node declarations.
 *
 * Implements a self-balancing BST that enforces red-black properties
 * through rotations and recoloring on insert/delete.
 */

#ifndef _RED_BLACK_TREES_H
#define _RED_BLACK_TREES_H
#include <iostream>


/** @brief Enumeration for red-black node colors. */
enum Color { RED, BLACK };

/**
 * @class RBTNode
 * @brief Node for a Red-Black Tree.
 */
class RBTNode {
    public:
        int data;               ///< Integer key stored in the node.
        Color color;            ///< Color of the node (RED or BLACK).
        RBTNode *left;             ///< Pointer to the left child.
        RBTNode *right;            ///< Pointer to the right child.
        RBTNode *parent;           ///< Pointer to the parent node.

        /**
         * @brief Constructs a RBTNode with the given value (default color RED).
         * @param val Integer key to store.
         */
        RBTNode(int val)
            : data(val),
            color(RED),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {}
};

/**
 * @class RedBlackTree
 * @brief Self-balancing binary search tree with red-black invariants.
 */
class RedBlackTree {
    private:
        RBTNode *root;     ///< Pointer to the root node.
        RBTNode *NIL;      ///< Sentinel nil node (always BLACK).

        /**
         * @brief Performs a left rotation around node x.
         * @param x Node to rotate around.
         */
        void rotateLeft(RBTNode *x);

        /**
         * @brief Performs a right rotation around node y.
         * @param y Node to rotate around.
         */
        void rotateRight(RBTNode *y);

        /**
         * @brief Fixes red-black violations after an insertion.
         * @param z Newly inserted node.
         */
        void fixInsert(RBTNode *z);

        /**
         * @brief Replaces subtree rooted at u with subtree rooted at v.
         * @param u Node to be replaced.
         * @param v Replacement node.
         */
        void transplant(RBTNode *u, RBTNode *v);

        /**
         * @brief Fixes red-black violations after a deletion.
         * @param x Node at which to start fixing.
         */
        void fixDelete(RBTNode *x);

        /**
         * @brief Finds the node with the minimum key in the subtree.
         * @param node Root of the subtree.
         * @return Pointer to the minimum node.
         */
        RBTNode* minimum(RBTNode *node) const;

        /**
         * @brief Finds the node with the maximum key in the subtree.
         * @param node Root of the subtree.
         * @return Pointer to the maximum node.
         */
        RBTNode* maximum(RBTNode *node) const;

        /**
         * @brief Searches for a key in the subtree.
         * @param node Root of the subtree.
         * @param key  Value to search for.
         * @return Pointer to the node if found; nullptr otherwise.
         */
        RBTNode* searchNode(RBTNode *node, int key) const;

        /**
         * @brief Recursive helper for in-order traversal printing.
         * @param node Current subtree root.
         */
        void inorderHelper(RBTNode *node) const;

        /**
         * @brief Recursive helper for pre-order traversal printing.
         * @param node Current subtree root.
         */
        void preorderHelper(RBTNode *node) const;

        /**
         * @brief Recursive helper for post-order traversal printing.
         * @param node Current subtree root.
         */
        void postorderHelper(RBTNode *node) const;

        /**
         * @brief Computes the height of the subtree.
         * @param node Root of the subtree.
         * @return Height (-1 for NIL).
         */
        int heightHelper(RBTNode *node) const;

        /**
         * @brief Counts the total number of nodes in the subtree.
         * @param node Root of the subtree.
         * @return Number of nodes.
         */
        int countHelper(RBTNode *node) const;

        /**
         * @brief Computes the black-height (number of black nodes on any
         *        root-to-leaf path).
         * @param node Root of the subtree.
         * @return Black-height, or -1 if the property is violated.
         */
        int blackHeightHelper(RBTNode *node) const;

        /**
         * @brief Checks for red-red parent-child violations.
         * @param node Root of the subtree to check.
         * @return true if a violation exists.
         */
        bool redViolation(RBTNode *node) const;

        /**
         * @brief Recursively prints the tree structure with indentation.
         * @param node   Current subtree root.
         * @param indent Accumulated indentation string.
         * @param last   Whether the current node is the last child.
         */
        void printTreeHelper(RBTNode *node, std::string indent, bool last) const;

        /**
         * @brief Recursively deallocates every node in the subtree.
         * @param node Root of the subtree to destroy.
         */
        void destroyTree(RBTNode *node);

    public:
        /** @brief Constructs an empty RedBlackTree with a NIL sentinel. */
        RedBlackTree();

        /** @brief Destroys the tree, freeing all nodes and the NIL sentinel. */
        ~RedBlackTree();

        /**
         * @brief Inserts a key into the tree.
         * @param key Value to insert.
         */
        void insert(int key);

        /**
         * @brief Removes a key from the tree.
         * @param key Value to remove.
         */
        void remove(int key);

        /**
         * @brief Searches for a key and prints whether it was found.
         * @param key Value to search for.
         * @return true if the key exists in the tree.
         */
        bool search(int key) const;

        /** @brief Prints the tree in in-order traversal. */
        void inorder() const;

        /** @brief Prints the tree in pre-order traversal. */
        void preorder() const;

        /** @brief Prints the tree in post-order traversal. */
        void postorder() const;

        /**
         * @brief Validates all red-black tree properties.
         * @return true if the tree satisfies every red-black invariant.
         */
        bool isValid() const;

        /**
         * @brief Returns the height of the tree.
         * @return Height of the tree.
         */
        int height() const;

        /**
         * @brief Returns the total number of nodes in the tree.
         * @return Node count.
         */
        int count() const;

        /** @brief Prints summary information (node count, height, validity). */
        void printInfo() const;

        /** @brief Prints the tree structure to the console. */
        void printTree() const;
};

/**
 * @brief Interactive driver: builds and manipulates a Red-Black tree
 *        via a console menu.
 * @return 0 on normal exit.
 */
int createRedBlackTree();

#endif
