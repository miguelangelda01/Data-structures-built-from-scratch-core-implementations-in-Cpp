/**
 * @file InfixToPostfix.cpp
 * @brief Implementation of the Infix to Postfix expression converter and its CharStack.
 */

#include <iostream>
#include "../Headers/InfixToPostfix.h"

using namespace std;

/**
 * @brief Checks if the character stack is empty.
 * @return true if empty, false otherwise.
 */
bool CharStack::isEmpty(){
    return topPtr == nullptr;
}

/**
 * @brief Public wrapper that checks whether the stack is empty.
 * @return true if the stack contains no elements.
 */
bool CharStack::empty(){
    return isEmpty();
}

/**
 * @brief Constructor for CharStack.
 */
CharStack::CharStack(){
    topPtr = nullptr;
}

/**
 * @brief Destructor for CharStack.
 */
CharStack::~CharStack(){
    while(!isEmpty()){
        pop();
    }
}

/**
 * @brief Pushes a character onto the stack.
 * @param value The character value.
 */
void CharStack::push(char value){
    CharNode *newPtr = new CharNode();
    newPtr->data = value;
    newPtr->nextPtr = topPtr;
    topPtr = newPtr;
}

/**
 * @brief Pops (removes and returns) the top character from the stack.
 * @return char The popped character, or 0 if empty.
 */
char CharStack::pop(){
    if(isEmpty()){
        cout << "\nError in pop(): the stack is empty\n";
        system("pause");
        return 0;
    }
    char x = topPtr->data;
    CharNode *tempPtr = topPtr;
    topPtr = topPtr->nextPtr;
    delete tempPtr;
    return x;
}

/**
 * @brief Returns the top character of the stack without removing it.
 * @return char The top character, or '\0' if empty.
 */
char CharStack::top(){
    if(isEmpty()){
        cout << "\nError in top(): the stack is empty\n";
        system("pause");
        return '\0';
    }
    return topPtr->data;
}

/**
 * @brief Checks if the character is a mathematical operator (+, -, *, /, ^).
 * @param op The character to check.
 * @return true if it's an operator, false otherwise.
 */
bool isOperator(char op){
    const char operators[] = "+-*/^";
    for(int i = 0; i < 5; i++){
        if(op == operators[i]){
            return true;
        }
    }
    return false;
}

/**
 * @brief Returns the priority of a mathematical operator.
 * @param op The operator character.
 * @return int The precedence weight, or -1 if invalid.
 */
int priority(char op){
    switch(op){
        case '+': return 0;
        case '-': return 0;
        case '*': return 1;
        case '/': return 1;
        case '^': return 2;
        default: return -1;
    }
}

/**
 * @brief Checks if the character is an alphabetic character (a-z, A-Z).
 * @param letter The character to check.
 * @return true if alphabetic, false otherwise.
 */
bool isAlpha(char letter){
    if(letter >= 'A' && letter <= 'Z'){
        return true;
    }
    if(letter >= 'a' && letter <= 'z'){
        return true;
    }
    return false;
}

/**
 * @brief Converts an infix mathematical expression to postfix notation and prints it.
 * @param infixExpression The input infix expression string.
 */
void infixToPostfix(char infixExpression[100]){
    char postfixExpression[100] = {'\0'};
    char symbol, data;
    CharStack operators;
    int inIdx = 0, postIdx = 0;
    while(infixExpression[inIdx] != '\0'){
        symbol = infixExpression[inIdx];
        inIdx++;
        if(symbol == '('){
            operators.push(symbol);
        }else if(symbol == ')'){
            while(operators.top() != '('){
                data = operators.pop();
                postfixExpression[postIdx] = data;
                postIdx++;
            }
            operators.pop();
        }else if(isAlpha(symbol)){
            postfixExpression[postIdx] = symbol;
            postIdx++;
        }else if(isOperator(symbol)){
            while(!operators.empty() && priority(symbol) <= priority(operators.top())){
                data = operators.pop();
                postfixExpression[postIdx] = data;
                postIdx++;
            }
            operators.push(symbol);
        }
    }
    while(!operators.empty()){
        data = operators.pop();
        postfixExpression[postIdx] = data;
        postIdx++;
    }
    postfixExpression[postIdx] = '\0';
    cout << "Postfix expression: " << postfixExpression;
    cout << "\n\n"; 
}

/**
 * @brief Interactive function to get infix expressions and convert them to postfix.
 * @return int Status code.
 */
int accessInfixToPostfix(){
    system("color 1F");
    char infixExpression[100];
    int i;
    do{
        i = 0;
        cout << "Enter the infix expression (type 1 to exit): ";
        fgets(infixExpression, sizeof(infixExpression), stdin);
        while(infixExpression[i] != '\0'){
            if(infixExpression[i] == '\n'){
                infixExpression[i] = '\0';
            }
            i++;
        }
        if(infixExpression[0] != '1'){
            infixToPostfix(infixExpression);
        }
    }while(infixExpression[0] != '1');
    return 0;
}
