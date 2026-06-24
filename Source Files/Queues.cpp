/**
 * @file Queues.cpp
 * @brief Implementation of the Queue class and helper operations.
 */

#include <iostream>
#include "../Headers/Config.h"
#include "../Headers/Menus.h"
#include "../Headers/Queues.h"

using namespace std;

/**
 * @brief Checks if the queue is empty.
 * @return true if empty, false otherwise.
 */
bool Queue::isEmpty(){
    return frontPtr == nullptr && rearPtr == nullptr;
}

/**
 * @brief Constructor.
 */
Queue::Queue(){
    frontPtr = nullptr;
    rearPtr = nullptr;
}

/**
 * @brief Destructor.
 */
Queue::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
}

/**
 * @brief Dequeues (removes) the front element of the queue.
 */
void Queue::dequeue(){
    if(isEmpty()){
        cout << "\n The queue is empty\n";
        system("pause");
        return;
    }
    
    Node* tempPtr = frontPtr;
    frontPtr = frontPtr->nextPtr;
    
    if(frontPtr == nullptr){
        rearPtr = nullptr;
    }
    delete tempPtr;
}

/**
 * @brief Enqueues a value at the rear of the queue.
 * @param value The value to enqueue.
 */
void Queue::enqueue(int value){
    Node* newPtr = new Node();
    newPtr->data = value;
    newPtr->nextPtr = nullptr;

    if(rearPtr != nullptr){
        rearPtr->nextPtr = newPtr;
    }

    rearPtr = newPtr;
    
    if(frontPtr == nullptr){
        frontPtr = newPtr;
    }
}

/**
 * @brief Gets the value of the front element.
 * @return int The front value, or -1 if empty.
 */
int Queue::front(){
    if(isEmpty()){
        cout << "\nThe queue is empty\n";
        system("pause");
        return -1;
    }
    return frontPtr->data;
}

/**
 * @brief Gets the value of the rear element.
 * @return int The rear value, or -1 if empty.
 */
int Queue::back(){
    if(isEmpty()){
        cout << "\nThe queue is empty\n";
        system("pause");
        return -1;
    }
    return rearPtr->data;
}

/**
 * @brief Displays the elements of the queue.
 */
void Queue::display(){
    if(isEmpty()){
        cout << "\nThe queue is empty\n";
        system("pause");
        return;
    }

    Node* currentPtr = frontPtr; 

    while(currentPtr != nullptr){ 
        cout << currentPtr->data << " -> "; 
        currentPtr = currentPtr->nextPtr; 
    }
    
    cout << "\n\n";
    system("pause");
}

/**
 * @brief Moves elements from another queue to this queue.
 * @param sourceQueue The source queue.
 */
void Queue::moveFrom(Queue &sourceQueue){
    int tempVal;

    while(!sourceQueue.isEmpty()){
        tempVal = sourceQueue.front(); 
        sourceQueue.dequeue(); 
        enqueue(tempVal); 
    }
}

/**
 * @brief Removes a node containing a specific reference value.
 * @param reference The value to search and remove.
 */
void Queue::removeNode(int reference){
    if(isEmpty()){
        cout << "\nThe queue is empty\n";
        system("pause");
        return;
    }

    Queue auxQueue; 
    int tempVal; 
    bool found = false; 
    while(!isEmpty()){
        tempVal = front();
        dequeue();
        if(tempVal == reference){ 
            cout << "\nRemoving node: " << tempVal << "\n";
            system("pause");
            found = true;
        }else{
            if(tempVal != -1){
                auxQueue.enqueue(tempVal); 
            } 
        }
    }
    moveFrom(auxQueue);

    if(!found){
        cout << "\nThe reference node was not found in the queue.\n";
        system("pause");
    }
}

/**
 * @brief Removes the node at a specific position.
 * @param position The 1-based index position.
 */
void Queue::removeNodeAtPosition(int position){
    if(isEmpty()){
        cout << "\nThe queue is empty\n";
        system("pause");
        return;
    }

    Queue auxQueue;
    int tempVal, counter = 1;
    bool found = false;
    while(!isEmpty()){ 
        tempVal = front(); 
        dequeue(); 
        if(counter == position){
            cout << "\nRemoving node: " << tempVal << "\n";
            system("pause");
            found = true;
        }else{
           if(tempVal != -1){
                auxQueue.enqueue(tempVal);
            } 
        }
        counter++;
    }
    moveFrom(auxQueue);
    if(!found){
        cout << "\nThe given position exceeds the queue size.\n";
        system("pause");
    }
}

/**
 * @brief Counts the total number of elements in the queue.
 * @return int The element count.
 */
int Queue::elementCount(){
    if(isEmpty()){ 
        return 0;
    }

    Node* currentPtr = frontPtr;
    int count = 0; 
    while(currentPtr != nullptr){ 
        count++; 
        currentPtr = currentPtr->nextPtr; 
    }
    return count; 
}

/**
 * @brief Finds the maximum node value in the queue.
 * @return int The maximum value.
 */
int Queue::maxNode(){
    if(isEmpty()){ 
        cout << "\nThe queue is empty\n";
        system("pause");
        return -1;
    }

    Node* currentPtr = frontPtr->nextPtr;
    int maxVal = frontPtr->data; 
    while(currentPtr != nullptr){
        if(maxVal < currentPtr->data){ 
            maxVal = currentPtr->data; 
        }
        currentPtr = currentPtr->nextPtr; 
    }
    return maxVal;
}

/**
 * @brief Merges two queues into this queue.
 * @param q1 First source queue.
 * @param q2 Second source queue.
 */
void Queue::merge(Queue &q1, Queue &q2){
    Node* currentPtr = q1.frontPtr; 

    Queue *result = new Queue(); 
    while(currentPtr != nullptr){ 
        result->enqueue(currentPtr->data); 
        currentPtr = currentPtr->nextPtr; 
    } 

    currentPtr = q2.frontPtr;
    while(currentPtr != nullptr){ 
        result->enqueue(currentPtr->data);
        currentPtr = currentPtr->nextPtr; 
    } 
    result->display(); 
    delete result;
}

/**
 * @brief Entry point function to test queues interactively.
 * @return int Exit code.
 */
int createQueue(){
    int option, value, dataVal, pos1, pos2; 

    Queue integerQueues[2];

    system("color 1F"); 
    do{
        queueMenu();
        cin >> option;
        if(!validateMenuInput(cin, 12, option)){
            option = 0;
            system("pause");
        }
        if(option < 10 && option != 0){
            cout << "Enter the queue you want to modify (1-2): ";
            cin >> pos1;
            if(!validateMenuInput(cin, 2, pos1)){
                option = 0;
                system("pause");
            }
            pos1--;
        }
        switch(option){
            case 1:
                cout << "\nEnter the value: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerQueues[pos1].enqueue(value);
                break;
            case 2:
                integerQueues[pos1].dequeue();
                break;
            case 3:
                dataVal = integerQueues[pos1].front();
                if(dataVal >= 0){
                    cout << "The value is: " << dataVal << "\n"; 
                    system("pause");
                }
                break;
            case 4:
                dataVal = integerQueues[pos1].back(); 
                if(dataVal >= 0){
                    cout << "The value is: " << dataVal << "\n"; 
                    system("pause");
                }
                break;
            case 5:
                integerQueues[pos1].display();
                break;
            case 6:
                cout << "\nEnter the node you want to remove: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerQueues[pos1].removeNode(value);
                break;
            case 7:
                cout << "\nEnter the position of the node to remove: ";
                cin >> value;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                integerQueues[pos1].removeNodeAtPosition(value);
                break;
            case 8:
                value = integerQueues[pos1].elementCount();
                cout << "\nThe number of elements in the queue is: " << value << "\n";
                system("pause");
                break;
            case 9:
                value = integerQueues[pos1].maxNode(); 
                if(value >= 0){
                    cout << "\nThe largest value in the queue is: " << value << "\n";
                    system("pause");
                }
                break;
            case 10:
                integerQueues[0].merge(integerQueues[0], integerQueues[1]);
                break;
            case 11:
                cout << "Enter the queue to move data into: ";
                cin >> pos1;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                cout << "Enter the queue to move data from: ";
                cin >> pos2;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                pos1--;
                pos2--;
                integerQueues[pos1].moveFrom(integerQueues[pos2]);
                break;  
        } 
    }while(option != 12);

    cout << "\n\nExiting...\n";
    return 0;
}
