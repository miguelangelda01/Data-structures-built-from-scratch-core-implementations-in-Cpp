/**
 * @file Trees.h
 * @brief Binary Search Tree (BST) class and node declarations.
 *
 * Provides a complete BST implementation with insertion, deletion
 * (predecessor / successor strategies), traversals, and tree property queries.
 */

#ifndef TREES_H
#define TREES_H

/**
 * @class TreeNode
 * @brief Node for a binary search tree.
 */
class TreeNode{
    public:
        int data;               ///< Integer key stored in the node.
        TreeNode *leftPtr;      ///< Pointer to the left child.
        TreeNode *rightPtr;     ///< Pointer to the right child.
};

/**
 * @class Tree
 * @brief Binary Search Tree with console visualisation helpers.
 */
class Tree{
    private:
        TreeNode *rootPtr;      ///< Pointer to the root node.

        /**
         * @brief Checks whether the tree is empty.
         * @return true if the tree has no nodes.
         */
        bool isEmpty();

        /**
         * @brief Moves the console cursor to position (x, y).
         * @param x Column (0-based).
         * @param y Row (0-based).
         */
        void gotoxy(int x, int y);
    public:
        /** @brief Constructs an empty Tree. */
        Tree();

        /** @brief Destroys the Tree, freeing every node via pruneTree(). */
        ~Tree();

        /**
         * @brief Returns a pointer to the root node.
         * @return Pointer to the root TreeNode (may be NULL).
         */
        TreeNode* getRoot();

        /**
         * @brief Recursively inserts a value into the BST.
         * @param value  Integer to insert.
         * @param nodePtr Reference-to-pointer for the current subtree root.
         */
        void insertNode(int value, TreeNode *&nodePtr);

        /**
         * @brief Prints the tree sideways (root on the left) for quick
         *        console visualisation.
         * @param level   Current indentation level (pass 0 initially).
         * @param nodePtr Current subtree root.
         */
        void displaySideways(int level, TreeNode *nodePtr);

        /**
         * @brief Renders the tree graphically by placing values at
         *        calculated console coordinates.
         * @param nodePtr Current subtree root.
         * @param x       Column position.
         * @param y       Row position.
         * @param n       Depth counter used to adjust horizontal spacing.
         */
        void renderTree(TreeNode *nodePtr, int x, int y, int n);

        /**
         * @brief Searches for a value in the BST.
         * @param x       Value to search for.
         * @param nodePtr Current subtree root.
         * @return true if the value exists in the tree.
         */
        bool search(int x, TreeNode *nodePtr);

        /**
         * @brief Finds the node with the smallest key in the subtree.
         * @param nodePtr Root of the subtree to search.
         * @return Pointer to the node with the minimum value.
         */
        TreeNode* findMin(TreeNode *nodePtr);

        /**
         * @brief Finds the node with the largest key in the subtree.
         * @param nodePtr Root of the subtree to search.
         * @return Pointer to the node with the maximum value.
         */
        TreeNode* findMax(TreeNode *nodePtr);

        /**
         * @brief Deletes a node using the in-order predecessor strategy.
         * @param x       Value to delete.
         * @param nodePtr Reference-to-pointer for the current subtree root.
         */
        void deletePredecessor(int x, TreeNode *&nodePtr);

        /**
         * @brief Deletes a node using the in-order successor strategy.
         * @param x       Value to delete.
         * @param nodePtr Reference-to-pointer for the current subtree root.
         */
        void deleteSuccessor(int x, TreeNode *&nodePtr);

        /**
         * @brief Pre-order traversal (root, left, right) — prints each value.
         * @param nodePtr Current subtree root.
         */
        void preOrder(TreeNode *nodePtr);

        /**
         * @brief In-order traversal (left, root, right) — prints each value.
         * @param nodePtr Current subtree root.
         */
        void inOrder(TreeNode *nodePtr);

        /**
         * @brief Post-order traversal (left, right, root) — prints each value.
         * @param nodePtr Current subtree root.
         */
        void postOrder(TreeNode *nodePtr);

        /**
         * @brief Level-order (BFS) traversal — prints each value.
         * @param nodePtr Root of the tree.
         */
        void levelOrderTraversal(TreeNode *nodePtr);

        /**
         * @brief Computes the height of the subtree.
         * @param nodePtr Root of the subtree.
         * @return Height (number of edges on the longest root-to-leaf path).
         */
        int height(TreeNode *nodePtr);

        /**
         * @brief Counts the number of leaf nodes in the subtree.
         * @param nodePtr Root of the subtree.
         * @return Number of leaves.
         */
        int countLeaves(TreeNode *nodePtr);

        /**
         * @brief Counts the total number of nodes in the subtree.
         * @param nodePtr Root of the subtree.
         * @return Total node count.
         */
        int countNodes(TreeNode *nodePtr);

        /**
         * @brief Mirrors the tree in-place (swaps left and right children
         *        at every node).
         * @param nodePtr Root of the subtree to mirror.
         */
        void mirrorTree(TreeNode *nodePtr);

        /**
         * @brief Checks whether the tree is a complete binary tree.
         * @param nodePtr Root of the tree.
         * @return true if the tree is complete.
         */
        bool isComplete(TreeNode *nodePtr);

        /**
         * @brief Checks whether the tree is a full binary tree
         *        (every node has 0 or 2 children).
         * @param nodePtr Root of the tree.
         * @return true if the tree is full.
         */
        bool isFull(TreeNode *nodePtr);

        /**
         * @brief Recursively deletes every node in the subtree
         *        (post-order deletion).
         * @param nodePtr Reference-to-pointer for the current subtree root.
         */
        void pruneTree(TreeNode *&nodePtr);
};

/**
 * @brief Interactive driver: builds and manipulates a BST via a console menu.
 */
void createTree();

#endif
