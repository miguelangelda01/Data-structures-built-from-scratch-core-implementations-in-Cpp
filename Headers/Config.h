/**
 * @file Config.h
 * @brief Shared data structures and input validation function declarations.
 *
 * Defines the generic singly-linked-list Node used by several data structures
 * (Stack, Queue, LinkedList) and declares input validation helpers.
 */

#ifndef _CONFIG_H
#define _CONFIG_H
#include <iostream>

/**
 * @class Node
 * @brief Generic singly-linked-list node storing an integer value.
 */
class Node{
    public:
        int data;          ///< Integer payload stored in the node.
        Node* nextPtr;     ///< Pointer to the next node in the list.
};


/**
 * @brief Validates that the user's menu selection is a valid integer
 *        within the range [1, upperLimit].
 *
 * @param result   Reference to the input stream to check for errors.
 * @param upperLimit Maximum allowed option value (inclusive).
 * @param option   The option value entered by the user.
 * @return true if the input is valid; false otherwise.
 */
bool validateMenuInput(std::istream &result, int upperLimit, int option);

/**
 * @brief Validates that the user entered a valid integer (no decimals,
 *        no letters, no trailing characters).
 *
 * @param result Reference to the input stream to check for errors.
 * @return true if the input is a valid integer; false otherwise.
 */
bool validateInteger(std::istream &result);


#endif
