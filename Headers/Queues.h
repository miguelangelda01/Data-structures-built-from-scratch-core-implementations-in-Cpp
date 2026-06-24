/**
 * @file Queues.h
 * @brief Definition of the Queue class and helper operations.
 *
 * Implements a FIFO queue using a singly-linked list, supporting insertion,
 * deletion, and utility operations.
 */

#ifndef _QUEUES_H
#define _QUEUES_H

#include "Config.h"

/**
 * @class Queue
 * @brief A class representing a FIFO (First In First Out) queue of integers.
 */
class Queue {
    private: 
        Node* frontPtr; ///< Pointer to the first element in the queue
        Node* rearPtr;  ///< Pointer to the last element in the queue
        
        /**
         * @brief Checks if the queue is empty.
         * @return true if empty, false otherwise.
         */
        bool isEmpty(); 
        
    public: 
        /**
         * @brief Constructor that initializes an empty queue.
         */
        Queue();

        /**
         * @brief Destructor that deallocates all nodes in the queue.
         */
        ~Queue();

        /**
         * @brief Enqueues a value at the rear of the queue.
         * @param value The value to insert.
         */
        void enqueue(int value);

        /**
         * @brief Dequeues (removes) the front element of the queue.
         */
        void dequeue();

        /**
         * @brief Gets the value of the front element.
         * @return int The front value.
         */
        int front();

        /**
         * @brief Gets the value of the rear element.
         * @return int The rear value.
         */
        int back();

        /**
         * @brief Displays the elements of the queue to console.
         */
        void display();

        /**
         * @brief Moves elements from another queue into this queue.
         * @param sourceQueue The source queue.
         */
        void moveFrom(Queue &sourceQueue);

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
         * @brief Counts the total number of elements in the queue.
         * @return int The element count.
         */
        int elementCount();

        /**
         * @brief Finds the maximum node value in the queue.
         * @return int The maximum value found.
         */
        int maxNode();

        /**
         * @brief Merges two source queues into this queue.
         * @param q1 The first source queue.
         * @param q2 The second source queue.
         */
        void merge(Queue &q1, Queue &q2);
};

/**
 * @brief Interactive menu function for testing Queue operations.
 * @return int Status code.
 */
int createQueue();

#endif
