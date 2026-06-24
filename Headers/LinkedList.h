/**
 * @file LinkedList.h
 * @brief Definition of the LinkedList class and set operation declarations.
 *
 * Implements a singly-linked list with typical insertion, deletion, and
 * traversal operations, as well as list-based set operations.
 */

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "Config.h"

/**
 * @class LinkedList
 * @brief A class representing a singly-linked list of integers.
 */
class LinkedList {
    private: 
        Node *headPtr; ///< Pointer to the first node in the list
        
        /**
         * @brief Checks if the list is empty.
         * @return true if the list contains no elements, false otherwise.
         */
        bool isEmpty();

    public: 
        /**
         * @brief Constructor that initializes an empty list.
         */
        LinkedList(); 

        /**
         * @brief Destructor that deallocates all nodes in the list.
         */
        ~LinkedList(); 

        /**
         * @brief Gets the pointer to the first node.
         * @return Node* Pointer to the head node.
         */
        Node* getFirst();

        /**
         * @brief Checks if a value exists in the list.
         * @param value The value to search for.
         * @return true if the value is found, false otherwise.
         */
        bool contains(int value);

        /**
         * @brief Inserts a new node with the given value at the front of the list.
         * @param value The value to insert.
         */
        void insertAtFront(int value);

        /**
         * @brief Inserts a new node with the given value at the end of the list.
         * @param value The value to insert.
         */
        void insertAtEnd(int value);

        /**
         * @brief Traverses the list iteratively and prints its elements.
         */
        void traverseIterative();

        /**
         * @brief Public entry point to start recursive traversal.
         */
        void callTraverseRecursive();

        /**
         * @brief Recursively traverses and prints the list starting from the given node.
         * @param currentPtr The starting node pointer.
         */
        void traverseRecursive(Node *currentPtr);

        /**
         * @brief Inserts a value before a specific reference value.
         * @param reference The value to search for.
         * @param value The value to insert.
         */
        void insertBefore(int reference, int value);

        /**
         * @brief Inserts a value before a specific 1-based index position.
         * @param position The target position.
         * @param value The value to insert.
         */
        void insertBeforePosition(int position, int value);

        /**
         * @brief Inserts a value after a specific reference value.
         * @param reference The value to search for.
         * @param value The value to insert.
         */
        void insertAfter(int reference, int value);

        /**
         * @brief Inserts a value after a specific 1-based index position.
         * @param position The target position.
         * @param value The value to insert.
         */
        void insertAfterPosition(int position, int value);

        /**
         * @brief Deletes the first node of the list.
         */
        void removeFirst();

        /**
         * @brief Deletes the node containing the specified reference value.
         * @param reference The value to remove.
         */
        void removeNode(int reference);

        /**
         * @brief Deletes the node at a specific 1-based index position.
         * @param position The target position.
         */
        void removeNodeAtPosition(int position);

        /**
         * @brief Deletes the last node of the list.
         */
        void removeLast();

        /**
         * @brief Moves all nodes from another list into this list, clearing the other list.
         * @param sourceList The source list to move from.
         */
        void moveFrom(LinkedList &sourceList);
};

/**
 * @brief Interactive menu function for testing LinkedList operations.
 * @return int Status code.
 */
int createLinkedList();

/**
 * @brief Performs the mathematical union of two linked lists as sets and prints the result.
 * @param A The first set/list.
 * @param B The second set/list.
 */
void setUnion(LinkedList &A, LinkedList &B);

/**
 * @brief Performs the mathematical intersection of two linked lists as sets and prints the result.
 * @param A The first set/list.
 * @param B The second set/list.
 */
void setIntersection(LinkedList &A, LinkedList &B);

/**
 * @brief Performs the mathematical difference (A - B) of two linked lists as sets and prints the result.
 * @param A The first set/list.
 * @param B The second set/list.
 */
void setDifference(LinkedList &A, LinkedList &B);

#endif
