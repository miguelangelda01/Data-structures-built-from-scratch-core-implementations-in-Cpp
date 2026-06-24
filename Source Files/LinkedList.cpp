/**
 * @file LinkedList.cpp
 * @brief Implementation of the LinkedList class and associated set operations.
 */

#include <iostream>
#include "../Headers/Config.h"
#include "../Headers/Menus.h"
#include "../Headers/LinkedList.h"

using namespace std;

/**
 * @brief Checks if the list is empty.
 * @return true if empty, false otherwise.
 */
bool LinkedList::isEmpty(){
    return headPtr == nullptr;
}

/**
 * @brief Constructor.
 */
LinkedList::LinkedList(){
    headPtr = nullptr;
}

/**
 * @brief Destructor.
 */
LinkedList::~LinkedList(){
    if(!isEmpty()){
        cout << "\n\nDestroying nodes... \n\n";
        
        Node *currentPtr = headPtr;
        Node *tempPtr;

        while(currentPtr != nullptr){
            tempPtr = currentPtr;
            cout << tempPtr->data << ' ';
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
     }
    cout << "\n\nAll nodes have been destroyed\n\n";
    system("pause");
}

/**
 * @brief Gets the first node pointer of the list.
 * @return Node* The head pointer.
 */
Node* LinkedList::getFirst(){
    return headPtr;
}

/**
 * @brief Inserts a value at the front of the list.
 * @param value The value to insert.
 */
void LinkedList::insertAtFront(int value){
    Node *newPtr = new Node();
    newPtr->data = value;

    if(isEmpty()){
        newPtr->nextPtr = nullptr;
    }else{
        newPtr->nextPtr = headPtr;
    }

    headPtr = newPtr;
}

/**
 * @brief Iteratively traverses the list and displays elements.
 */
void LinkedList::traverseIterative(){
    if(isEmpty()){
        cout << "\nThe list is empty\n\n";
        system("pause"); 
        return;
    }

    Node *currentPtr = headPtr;

    cout << "\nThe elements of the list are: ";

    while(currentPtr != nullptr){ 
        cout << currentPtr->data << " -> ";
        currentPtr = currentPtr->nextPtr; 
    }

    cout << "\n\n";
    system("pause");
}

/**
 * @brief Inserts a value at the end of the list.
 * @param value The value to insert.
 */
void LinkedList::insertAtEnd(int value){
    Node *newPtr = new Node();
    newPtr->data = value; 
    newPtr->nextPtr = nullptr; 

    if(isEmpty()){ 
        headPtr = newPtr;
    }else{ 
        Node *currentPtr = headPtr; 
        while(currentPtr->nextPtr != nullptr){ 
            currentPtr = currentPtr->nextPtr; 
        }
        currentPtr->nextPtr = newPtr;
    }
}

/**
 * @brief Public interface to recursively traverse the list.
 */
void LinkedList::callTraverseRecursive(){
    if(isEmpty()){
        cout << "\nThe list is empty\n\n";
        system("pause"); 
        return;
    }

    cout << "\nThe elements of the list using recursion are:";

    traverseRecursive(headPtr);

    cout << "\n\n";
    system("pause");
}

/**
 * @brief Recursive traversal helper.
 * @param currentPtr The current node pointer.
 */
void LinkedList::traverseRecursive(Node *currentPtr){
    if(currentPtr != nullptr){ 
        cout << currentPtr->data << ' '; 
        traverseRecursive(currentPtr->nextPtr); 
    }
}

/**
 * @brief Inserts a value before a reference value.
 * @param reference The reference value.
 * @param value The value to insert.
 */
void LinkedList::insertBefore(int reference, int value){
    if(isEmpty()){ 
        cout << "\n\nThe reference node was not found in the list.\n\n";
        system("pause"); 
        return;
    }

    Node *newPtr = new Node(); 
    newPtr->data = value; 
    newPtr->nextPtr = nullptr; 

    Node *currentPtr = headPtr; 
    Node *previousPtr = nullptr; 

    while(currentPtr->data != reference && currentPtr->nextPtr != nullptr){
        previousPtr = currentPtr; 
        currentPtr = currentPtr->nextPtr;     
    }
    if(currentPtr->data == reference){ 
        if(headPtr == currentPtr){ 
            newPtr->nextPtr = headPtr; 
            headPtr = newPtr; 
        }else{ 
            previousPtr->nextPtr = newPtr; 
            newPtr->nextPtr = currentPtr; 
        }
    }else{ 
        cout << "\n\nThe reference node was not found in the list.\n\n";
        system("pause");
        delete newPtr;
    }
}

/**
 * @brief Inserts a value after a reference value.
 * @param reference The reference value.
 * @param value The value to insert.
 */
void LinkedList::insertAfter(int reference, int value){
    if(isEmpty()){
        cout << "\n\nThe reference node was not found in the list.\n\n";
        system("pause"); 
        return;
    }

    Node *newPtr = new Node(); 
    newPtr->data = value;
    newPtr->nextPtr = nullptr; 

    Node *currentPtr = headPtr; 

    while(currentPtr->data != reference && currentPtr->nextPtr != nullptr){
        currentPtr = currentPtr->nextPtr; 
    }
    if(currentPtr->data == reference){ 
        newPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = newPtr; 
    }else{ 
        cout << "\n\nThe reference node was not found in the list.\n\n";
        system("pause");
        delete newPtr;
    }
}

/**
 * @brief Inserts a value before a 1-based index position.
 * @param position The position index.
 * @param value The value to insert.
 */
void LinkedList::insertBeforePosition(int position, int value){
    if(isEmpty()){ 
        cout << "\n\nThe list is empty.\n\n";
        system("pause");
        return;
    }
    
    if(position == 0){ 
        insertAtFront(value);  
        return;
    }

    Node *newPtr = new Node();
    newPtr->data = value; 
    newPtr->nextPtr = nullptr; 

    Node *currentPtr = headPtr; 
    Node *previousPtr = nullptr; 
    int counter = 0; 

    while(currentPtr != nullptr && counter < position){ 
        previousPtr = currentPtr; 
        currentPtr = currentPtr->nextPtr; 
        counter++; 
    }
    if(currentPtr == nullptr){ 
        cout << "\n\nThe given position does not exist in the list.\n\n";
        system("pause");
        delete newPtr; 
        return; 
    }else{
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr; 
    }
}

/**
 * @brief Inserts a value after a 1-based index position.
 * @param position The position index.
 * @param value The value to insert.
 */
void LinkedList::insertAfterPosition(int position, int value){
    if(isEmpty()){ 
        cout << "\n\nThe list is empty.\n\n";
        system("pause");
        return;
    }

    Node *newPtr = new Node();
    newPtr->data = value; 
    newPtr->nextPtr = nullptr; 

    Node *currentPtr = headPtr; 
    int counter = 0; 

    while(currentPtr != nullptr && counter < position){ 
        currentPtr = currentPtr->nextPtr; 
        counter++; 
    }
    if(currentPtr == nullptr){ 
        cout << "\n\nThe given position does not exist in the list.\n\n";
        system("pause");
        delete newPtr;
        return; 
    }else{
        newPtr->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = newPtr;
    }
}

/**
 * @brief Removes the first node from the list.
 */
void LinkedList::removeFirst(){
    if(isEmpty()){ 
        cout << "\nThe list is empty\n\n";
        system("pause");
        return;
    }

    cout << "\nDestroying node: " << headPtr->data << "\n"; 
    Node *tempPtr = headPtr; 
    headPtr = headPtr->nextPtr; 
    delete tempPtr; 
    system("pause");
}

/**
 * @brief Removes a node containing a specific reference value.
 * @param reference The reference value to remove.
 */
void LinkedList::removeNode(int reference){
    if(isEmpty()){ 
        cout << "\nThe list is empty\n\n";
        system("pause");
        return;
    }

    Node *currentPtr = headPtr; 
    Node *previousPtr = nullptr; 

    while(currentPtr->data != reference && currentPtr->nextPtr != nullptr){ 
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if(currentPtr->data == reference){ 
        Node *tempPtr = currentPtr; 
        if(headPtr == currentPtr){
            headPtr = headPtr->nextPtr; 
        }else{
            previousPtr->nextPtr = currentPtr->nextPtr;
        }
        
        cout << "\nDestroying node: " << tempPtr->data << "\n"; 
        delete tempPtr; 
        system("pause");
    }else{ 
        cout << "\n\nThe reference node was not found in the list.\n\n";
        system("pause");
    }
}

/**
 * @brief Removes the node at a specific position.
 * @param position The position index.
 */
void LinkedList::removeNodeAtPosition(int position){
    if(isEmpty()){ 
        cout << "\nThe list is empty\n\n";
        system("pause");
        return;
    }

    if(position == 0){
        removeFirst(); 
        return;
    }

    Node *currentPtr = headPtr; 
    Node *previousPtr = nullptr; 
    int counter = 0; 

    while(currentPtr != nullptr && counter < position){ 
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr; 
        counter++;
    }
    
    if(currentPtr == nullptr){ 
            cout << "\n\nThe given position does not exist in the list.\n\n";
            system("pause");
            return;
    }else{
        Node *tempPtr = currentPtr; 
        previousPtr->nextPtr = currentPtr->nextPtr; 
        cout << "\nDestroying node: " << tempPtr->data << "\n"; 
        delete tempPtr; 
        system("pause");
    } 
}

/**
 * @brief Removes the last node from the list.
 */
void LinkedList::removeLast(){
    if(isEmpty()){
        cout << "\nThe list is empty\n\n";
        system("pause");
        return;
    }

    if(headPtr->nextPtr == nullptr){ 
        removeFirst();
        return;
    }

    Node *currentPtr = headPtr;
    Node *previousPtr = nullptr; 

    while(currentPtr->nextPtr != nullptr){
        previousPtr = currentPtr; 
        currentPtr = currentPtr->nextPtr; 
    }
    
    Node *tempPtr = currentPtr; 
    previousPtr->nextPtr = nullptr; 
    cout << "\nDestroying node: " << currentPtr->data << "\n"; 
    delete tempPtr; 
    system("pause");
}

/**
 * @brief Checks if a value exists in the list.
 * @param value The value to check.
 * @return true if exists, false otherwise.
 */
bool LinkedList::contains(int value){
    Node *currentPtr = headPtr; 
    while(currentPtr != nullptr){ 
        if(currentPtr->data == value){ 
            return true;
        }   
        currentPtr = currentPtr->nextPtr; 
    }
    return false;
}

/**
 * @brief Moves elements from another list into this list.
 * @param sourceList The source list.
 */
void LinkedList::moveFrom(LinkedList &sourceList){
    Node *currentPtr = sourceList.getFirst(); 
    LinkedList *result = new LinkedList();
    while(currentPtr != nullptr){ 
        result->insertAtEnd(currentPtr->data); 
        sourceList.removeFirst(); 
        currentPtr = currentPtr->nextPtr; 
    }
    currentPtr = result->getFirst();
    while(currentPtr != nullptr){
        insertAtEnd(currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    delete result;
}

/**
 * @brief Computes the union of two linked lists.
 * @param A First linked list.
 * @param B Second linked list.
 */
void setUnion(LinkedList &A, LinkedList &B){
    cout << "\nSet union: ";
    LinkedList* result = new LinkedList(); 

    Node* currentPtr = A.getFirst(); 
    while(currentPtr != nullptr){ 
        if(!result->contains(currentPtr->data)){ 
            result->insertAtEnd(currentPtr->data);
        }
        currentPtr = currentPtr->nextPtr;
    }

    currentPtr = B.getFirst(); 
    while(currentPtr != nullptr){ 
        if(!result->contains(currentPtr->data)){ 
            result->insertAtEnd(currentPtr->data);
        }
        currentPtr = currentPtr->nextPtr; 
    }

    result->traverseIterative(); 
    delete result;
}

/**
 * @brief Computes the intersection of two linked lists.
 * @param A First linked list.
 * @param B Second linked list.
 */
void setIntersection(LinkedList &A, LinkedList &B){
    cout << "\nSet intersection: ";
    LinkedList* result = new LinkedList(); 

    Node* currentPtr = A.getFirst(); 
    while(currentPtr != nullptr){ 
        if(B.contains(currentPtr->data) && !result->contains(currentPtr->data)){
            result->insertAtEnd(currentPtr->data);
        }
        currentPtr = currentPtr->nextPtr; 
    }

    result->traverseIterative(); 
    delete result;
}

/**
 * @brief Computes the difference (A - B) of two linked lists.
 * @param A First linked list.
 * @param B Second linked list.
 */
void setDifference(LinkedList &A, LinkedList &B){
    cout << "\nSet difference: ";
    LinkedList* result = new LinkedList();

    Node* currentPtr = A.getFirst(); 
    while(currentPtr != nullptr){
        if(!B.contains(currentPtr->data) && !result->contains(currentPtr->data)){
            result->insertAtEnd(currentPtr->data); 
        }
        currentPtr = currentPtr->nextPtr; 
    }

    result->traverseIterative(); 
    delete result;
}

/**
 * @brief Entry point function to test linked lists interactively.
 * @return int Exit code.
 */
int createLinkedList(){
    int option; 
    int value, reference, position; 

    LinkedList integerLists[2];

    system("color 1F"); 

    do{
        linkedListMenu(); 
        cin >> option;
        if(!validateMenuInput(cin, 17, option)){
            option = 0;
            system("pause");
        }
        if(option < 13 && option != 0){
            cout << "\nEnter the list you want to modify (1-2): ";
            cin >> position;
            if(!validateMenuInput(cin, 2, position)){
                option = 0;
                system("pause");
            }
            position--;
        }
        
        switch( option ){
            case 1:
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                }else{
                    integerLists[position].insertAtFront( value );
                    integerLists[position].traverseIterative();
                }
                break;
            case 2: 
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                }else{
                    integerLists[position].insertAtEnd( value );
                    integerLists[position].traverseIterative();
                }
                break;
            case 3: 
                integerLists[position].traverseIterative();
                break;
            case 4:
                integerLists[position].callTraverseRecursive();
                break;
            case 5:
                cout << "\nEnter the reference value: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerLists[position].insertBefore(reference, value);
                integerLists[position].traverseIterative();
                break;
            case 6:
                cout << "\nEnter the node position: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                reference--;
                integerLists[position].insertBeforePosition(reference, value);
                integerLists[position].traverseIterative();
                break;
            case 7:
                cout << "\nEnter the reference value: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerLists[position].insertAfter(reference, value);
                integerLists[position].traverseIterative();
                break;
            case 8:
                cout << "\nEnter the node position: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "\nEnter an integer value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                reference--;
                integerLists[position].insertAfterPosition(reference, value);
                integerLists[position].traverseIterative();
                break;
            case 9:
                integerLists[position].removeFirst();
                integerLists[position].traverseIterative();
                break;
            case 10:
                cout << "\nEnter the reference value: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                }else{
                    integerLists[position].removeNode(reference);
                    integerLists[position].traverseIterative();
                }
                break;
            case 11:
                cout << "\nEnter the position value: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                }else{
                    integerLists[position].removeNodeAtPosition(reference);
                    integerLists[position].traverseIterative();
                }
                break;
            case 12:
                integerLists[position].removeLast();
                integerLists[position].traverseIterative();
                break;
            case 13:
                setUnion(integerLists[0], integerLists[1]);
                break;
            case 14:
                setIntersection(integerLists[0], integerLists[1]);
                break;
            case 15:
                setDifference(integerLists[0], integerLists[1]);
                break;
            case 16:
                cout << "Enter the list to move data into: ";
                cin >> position;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the list to move data from: ";
                cin >> reference;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                reference--;
                position--;
                integerLists[position].moveFrom(integerLists[reference]);
                break;
        }
    }while( option != 17 );

    return 0;
}
