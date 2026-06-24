/**
 * @file Stacks.cpp
 * @brief Implementation of the Stack class and helper operations.
 */

#include <iostream>
#include "../Headers/Config.h"
#include "../Headers/Menus.h"
#include "../Headers/Stacks.h"
#include "../Headers/InfixToPostfix.h"

using namespace std;

/**
 * @brief Checks if the stack is empty.
 * @return true if empty, false otherwise.
 */
bool Stack::isEmpty(){
    return topPtr == nullptr;
}

/**
 * @brief Constructor.
 */
Stack::Stack(){
    topPtr = nullptr;
}

/**
 * @brief Destructor.
 */
Stack::~Stack(){
    while(!isEmpty()){
        pop();
    }
}

/**
 * @brief Pushes a new value onto the stack.
 * @param value The value to push.
 */
void Stack::push(int value){
    Node *newPtr = new Node();
    newPtr->data = value;
    newPtr->nextPtr = topPtr;

    topPtr = newPtr;
}

/**
 * @brief Pops (removes and returns) the top element of the stack.
 * @return int The value of the popped element, or 0 if empty.
 */
int Stack::pop(){
    if(isEmpty()){
        cout << "\nError in pop(): the stack is empty\n";
        system("pause");
        return 0;
    }
    int x = topPtr->data;
    Node *tempPtr = topPtr;
    topPtr = topPtr->nextPtr;
    delete tempPtr;
    return x;
}

/**
 * @brief Gets the value of the top element without removing it.
 * @return int The top value, or -1 if empty.
 */
int Stack::top(){
    if(isEmpty()){
        cout << "\nError in top(): the stack is empty\n";
        system("pause");
        return -1;
    }

    return topPtr->data;
}

/**
 * @brief Moves all elements from another stack into this stack.
 * @param sourceStack The source stack.
 */
void Stack::moveFrom(Stack &sourceStack){
    int tempVal;

    while(!sourceStack.isEmpty()){ 
        tempVal = sourceStack.pop(); 
        push(tempVal); 
    }
}

/**
 * @brief Displays the elements of the stack.
 */
void Stack::display(){
    if(isEmpty()){
        cout << "\nThe stack is empty\n";
        system("pause");
        return;
    }

    Node *currentPtr = topPtr;

    while(currentPtr != nullptr){
        cout << currentPtr->data << " -> ";
        currentPtr = currentPtr->nextPtr;
    }

    cout << "\n\n";
    system("pause");
}

/**
 * @brief Counts the elements in the stack.
 * @return int The count.
 */
int Stack::elementCount(){
    if(isEmpty()){
        return 0;
    }

    Node *currentPtr = topPtr;
    int counter = 0;

    while(currentPtr != nullptr){ 
        currentPtr = currentPtr->nextPtr; 
        counter++; 
    }

    return counter; 
}

/**
 * @brief Finds the maximum node value in the stack.
 * @return int The maximum value.
 */
int Stack::maxNode(){
    if(isEmpty()){
        cout << "\nThe stack is empty\n";
        system("pause");
        return -1;
    }

    int maxVal = topPtr->data;
    Node *currentPtr = topPtr->nextPtr;

    while(currentPtr != nullptr){ 
        if(maxVal < currentPtr->data){ 
            maxVal = currentPtr->data;
        }
        currentPtr = currentPtr->nextPtr; 
    }

    return maxVal;
}

/**
 * @brief Removes a node containing a specific reference value.
 * @param reference The value to remove.
 */
void Stack::removeNode(int reference){
    if(isEmpty()){
        cout << "\nThe stack is empty, nothing left to remove\n";
        system("pause");
        return;
    }

    int tempVal; 
    Stack auxStack;
    bool found = false; 

    while(!isEmpty()){
        tempVal = pop(); 
        if(tempVal == reference){ 
            cout << "\nRemoving node: " << tempVal << "\n";
            system("pause");
            found = true;
        }else{
            auxStack.push(tempVal);
        }
    }

    moveFrom(auxStack); 
    if(!found){
        cout << "\nThe reference node was not found\n";
        system("pause");
    }
}

/**
 * @brief Removes a node at a specific position.
 * @param position The 1-based index position.
 */
void Stack::removeNodeAtPosition(int position){
    if(isEmpty()){
        cout << "\nThe stack is empty, nothing left to remove\n";
        system("pause");
        return ;
    }

    int tempVal, counter = 1;
    Stack auxStack; 
    bool found = false; 

    while(!isEmpty()){
        tempVal = pop();
        if(counter == position){
            cout << "\nRemoving node: " << tempVal << "\n";
            system("pause");
            found = true;
        }else{
            auxStack.push(tempVal);
        }
        counter++;
    }

    moveFrom(auxStack); 
    if(!found){
        cout << "\nThe given position was not found\n";
        system("pause");
    }
}

/**
 * @brief Concatenates another stack onto this stack.
 * @param sourceStack The stack to concatenate.
 */
void Stack::concatenate(Stack &sourceStack){
    Stack auxStack; 

    auxStack.moveFrom(sourceStack); 

    moveFrom(auxStack); 
}

/**
 * @brief Entry point function to test stacks interactively.
 * @return int Exit code.
 */
int createStack(){
    int option, value, pos1 = 0, pos2 = 0;
    Stack integerStacks[3];
    system("color 1F"); 

    do{
        stackMenu();
        cin >> option;
        if(!validateMenuInput(cin, 11, option)){
            option = 0;
            system("pause");
        }
        if(option < 9 && option != 0){
            cout << "\nEnter which stack to use (1-3): ";
            cin >> pos1;
            if(!validateMenuInput(cin, 3, pos1)){
                option = 0;
                system("pause");
            }
            pos1--;
        }
        switch(option){
            case 1:
                cout << "\nEnter the value to push onto the stack: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerStacks[pos1].push(value);
                break;
            case 2:
                integerStacks[pos1].pop();
                break;
            case 3:
                value = integerStacks[pos1].top();
                if(value >= 0){
                    cout << "\nThe top element of the stack is: " << value << "\n";
                    system("pause");
                }
                break;
            case 4:
                integerStacks[pos1].display();
                break;
            case 5:
                value = integerStacks[pos1].elementCount();
                cout << "The number of elements in the stack is: " << value << "\n";
                system("pause");
                break;
            case 6:
                value = integerStacks[pos1].maxNode();
                if(value >= 0){
                    cout << "\nThe largest value in the stack is: " << value << "\n";
                    system("pause");
                }
                break;
            case 7:
                cout << "\nEnter the node you want to remove: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerStacks[pos1].removeNode(value);
                break;
            case 8:
                cout << "\nEnter the position of the node to remove: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerStacks[pos1].removeNodeAtPosition(value);
                break;
            case 9:
                cout << "\nEnter the first stack (elements will be concatenated here): ";
                cin >> pos1;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "\nEnter the second stack (elements will be taken from here): ";
                cin >> pos2;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerStacks[pos1-1].concatenate(integerStacks[pos2-1]);
                break;
            case 10:
                accessInfixToPostfix();
                break;
        }
    }while(option != 11);

    cout << "\nExiting...";
    return 0;
}
