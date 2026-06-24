/**
 * @file HashTable.cpp
 * @brief Implementation of the HashNode and HashTable classes.
 */

#include <iostream>
#include "../Headers/HashTable.h"
#include "../Headers/Config.h"
#include "../Headers/Menus.h"

using namespace std;

/**
 * @brief Constructor for HashNode.
 * @param name User name string.
 * @param num User numeric value.
 */
HashNode::HashNode(const char* nameVal, int num) {
    int i = 0;
    while(nameVal[i] != '\0' && i < 49){
        name[i] = nameVal[i]; 
        i++;
    }
    name[i] = '\0';
    number = num; 
    next = nullptr;
}

/**
 * @brief Hash function for mapping a key to a table index.
 * @param key The key string.
 * @return int The index.
 */
int HashTable::hashFunction(const char* key) {
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++) {
        sum += key[i] + (i * 31);
    }
    return sum % size;
}

/**
 * @brief Compares two strings.
 * @param a First string.
 * @param b Second string.
 * @return true if equal, false otherwise.
 */
bool HashTable::compare(const char* a, const char* b) {
    int i = 0;
    while(a[i] != '\0' && b[i] != '\0') {
        if(a[i] != b[i]) return false;
        i++;
    }
    return (a[i] == b[i]);
}

/**
 * @brief Constructor for HashTable.
 * @param tableSize Size of the hash table.
 */
HashTable::HashTable(int tableSize) : size(tableSize) {
    table = new HashNode*[size];
    for(int i = 0; i < size; i++) table[i] = nullptr;
}

/**
 * @brief Inserts a key-value pair into the hash table.
 * @param name User name.
 * @param num User number.
 */
void HashTable::insert(const char* name, int num) {
    int idx = hashFunction(name); 
    HashNode* newPtr = new HashNode(name, num);
    newPtr->next = table[idx];
    table[idx] = newPtr; 
    cout << "Log: Registered " << name << " at index " << idx << endl;
    system("pause");
}

/**
 * @brief Searches for a key in the hash table and prints the result.
 * @param name User name key.
 */
void HashTable::search(const char* name) {
    int idx = hashFunction(name); 
    HashNode* temp = table[idx]; 
    while(temp != nullptr) { 
        if(compare(temp->name, name)) {
            cout << "Found: " << temp->number << endl; 
            system("pause");
            return;
        }
        temp = temp->next;
    }
    cout << "No record found." << endl;
    system("pause");
}

/**
 * @brief Destructor.
 */
HashTable::~HashTable() {
    for(int i = 0; i < size; i++) { 
        HashNode* current = table[i]; 
        while(current != nullptr) { 
            HashNode* nextPtr = current->next; 
            delete current; 
            current = nextPtr; 
        }
    }
    delete[] table; 
}

/**
 * @brief Interactive entry point to test HashTable operations.
 * @return int Status code.
 */
int accessHashTable(){
    int tableSize, option = 0, key;
    char name[50];
    cout << "\nEnter the hash table size: ";
    cin >> tableSize;
    if(!validateInteger(cin) && tableSize >= 1){
        cout << "\nInitializing with 10 slots by default\n\n";
        tableSize = 10;
        system("pause");
    }
    HashTable ht(tableSize);
    do{
        hashTableMenu();
        cin >> option;
        if(!validateMenuInput(cin, 3, option)){
            option = 0;
            system("pause");
        }
        switch(option){
            case 1:
                cout << "\nEnter the user name: ";
                cin >> name;
                cout << "\nEnter the user key (integers only): ";
                cin >> key;
                if(!validateInteger(cin)){
                    system("pause");
                    break;
                }
                ht.insert(name, key);
                break;
            case 2:
                cout << "\nEnter the user name to look up their key: ";
                cin >> name;
                ht.search(name);
                break;
            
        }
    }while(option != 3);

    return 0;
}
