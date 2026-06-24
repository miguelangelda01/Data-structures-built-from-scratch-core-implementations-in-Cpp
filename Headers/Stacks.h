/**
 * @file Stacks.h
 * @brief Definition of the Stack class and helper operations.
 *
 * Implements a LIFO stack using a singly-linked list, supporting insertion,
 * deletion, and utility operations.
 */

#ifndef _STACKS_H
#define _STACKS_H

#include "Config.h"

/**
 * @class Stack
 * @brief A class representing a LIFO (Last In First Out) stack of integers.
 */
class Stack {
    private: 
        Node *topPtr; ///< Pointer to the top element of the stack
        
        /**
         * @brief Checks if the stack is empty.
         * @return true if empty, false otherwise.
         */
        bool isEmpty(); 

    public:
        /**
         * @brief Constructor that initializes an empty stack.
         */
        Stack();

        /**
         * @brief Destructor that deallocates all nodes in the stack.
         */
        ~Stack();

        /**
         * @brief Pushes a new element onto the top of the stack.
         * @param value The value to push.
         */
        void push(int value);

        /**
         * @brief Pops (removes and returns) the top element from the stack.
         * @return int The value of the popped element, or -1 if empty.
         */
        int pop();

        /**
         * @brief Gets the value of the top element without removing it.
         * @return int The top value, or -1 if empty.
         */
        int top();

        /**
         * @brief Moves elements from another stack into this stack.
         * @param sourceStack The source stack.
         */
        void moveFrom(Stack &sourceStack);

        /**
         * @brief Displays the elements of the stack to console.
         */
        void display();

        /**
         * @brief Counts the total number of elements in the stack.
         * @return int The element count.
         */
        int elementCount();

        /**
         * @brief Finds the maximum node value in the stack.
         * @return int The maximum value found.
         */
        int maxNode();

        /**
         * @brief Removes a node containing a specific reference value.
         * @param reference The value to search for and remove.
         */
        void removeNode(int reference);

        /**
         * @brief Removes the node at a specific 1-based index position.
         * @param position The target position.
         */
        void removeNodeAtPosition(int position);

        /**
         * @brief Concatenates another stack onto this stack.
         * @param sourceStack The stack to concatenate.
         */
        void concatenate(Stack &sourceStack);
};

/**
 * @brief Interactive menu function for testing Stack operations.
 * @return int Status code.
 */
int createStack();

#endif
