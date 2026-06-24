/**
 * @file HashTable.h
 * @brief Definition of HashNode and HashTable classes.
 *
 * Implements a hash table with chaining using a basic custom hash function
 * for string keys and integer values.
 */

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

/**
 * @class HashNode
 * @brief Node representation in the Hash Table's bucket chains.
 */
class HashNode {
    public:
        char name[50];       ///< Name identifier (key)
        int number;          ///< Value associated with the key
        HashNode* next;      ///< Pointer to the next node in the chain
        
        /**
         * @brief Constructor for HashNode.
         * @param name The name string.
         * @param num The associated number.
         */
        HashNode(const char* name, int num); 
};

/**
 * @class HashTable
 * @brief A hash table using chaining to resolve collisions.
 */
class HashTable {
    private:
        HashNode** table;    ///< Array of pointers to HashNode chains
        int size;            ///< Capacity of the hash table bucket array
        
        /**
         * @brief Hash function mapping a key to a bucket index.
         * @param key The key string.
         * @return int The index of the bucket.
         */
        int hashFunction(const char* key); 
        
        /**
         * @brief Helper to compare two strings.
         * @param a First string.
         * @param b Second string.
         * @return true if strings are equal, false otherwise.
         */
        bool compare(const char* a, const char* b); 

    public:
        /**
         * @brief Constructor that initializes a hash table of a given size.
         * @param t The capacity size.
         */
        HashTable(int t); 

        /**
         * @brief Inserts a name-number pair into the hash table.
         * @param name The name (key).
         * @param num The number (value).
         */
        void insert(const char* name, int num);

        /**
         * @brief Searches for a key in the hash table and prints the result.
         * @param name The name (key) to search.
         */
        void search(const char* name);

        /**
         * @brief Destructor that deallocates all table resources.
         */
        ~HashTable();
};

/**
 * @brief Interactive menu function for testing HashTable operations.
 * @return int Status code.
 */
int accessHashTable();

#endif
