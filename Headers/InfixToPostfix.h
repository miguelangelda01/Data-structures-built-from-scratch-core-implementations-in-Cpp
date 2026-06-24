/**
 * @file InfixToPostfix.h
 * @brief Declarations for the infix-to-postfix expression converter.
 *
 * Provides a character-based stack (CharStack) and utility functions
 * for converting mathematical infix expressions to postfix notation.
 */

#ifndef _INFIX_TO_POSTFIX_H
#define _INFIX_TO_POSTFIX_H


/**
 * @class CharNode
 * @brief Node for a character-based singly-linked list.
 */
class CharNode{
    public:
        char data;              ///< Character payload.
        CharNode *nextPtr;      ///< Pointer to the next node.
};



/**
 * @class CharStack
 * @brief Stack (LIFO) of characters, used during infix-to-postfix conversion.
 */
class CharStack{

    private:
        CharNode *topPtr;       ///< Pointer to the top of the stack.

        /**
         * @brief Checks whether the stack is empty.
         * @return true if the stack contains no elements.
         */
        bool isEmpty();
    public:
        /** @brief Constructs an empty CharStack. */
        CharStack();

        /** @brief Destroys the CharStack, freeing all nodes. */
        ~CharStack();

        /**
         * @brief Pushes a character onto the stack.
         * @param value Character to push.
         */
        void push(char value);

        /**
         * @brief Pops and returns the top character.
         * @return The character that was on top, or '\0' if empty.
         */
        char pop();

        /**
         * @brief Returns the top character without removing it.
         * @return The top character, or '\0' if the stack is empty.
         */
        char top();

        /**
         * @brief Public wrapper that checks whether the stack is empty.
         * @return true if the stack contains no elements.
         */
        bool empty();
};


/**
 * @brief Determines whether a character is a mathematical operator.
 * @param op Character to test.
 * @return true if op is one of +, -, *, /, ^.
 */
bool isOperator(char op);

/**
 * @brief Returns the precedence level of an operator.
 * @param op Operator character.
 * @return 0 for +/-, 1 for * and /, 2 for ^, -1 otherwise.
 */
int priority(char op);

/**
 * @brief Checks whether a character is an ASCII letter (A-Z or a-z).
 * @param letter Character to test.
 * @return true if the character is alphabetic.
 */
bool isAlpha(char letter);

/**
 * @brief Converts an infix expression (C-string) to postfix and prints the result.
 * @param infixExpr Null-terminated infix expression (max 99 characters).
 */
void infixToPostfix(char infixExpr[100]);

/**
 * @brief Interactive loop that reads infix expressions from the user
 *        and converts each one to postfix notation.
 * @return 0 on normal exit.
 */
int accessInfixToPostfix();

#endif
