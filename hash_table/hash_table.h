#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/**
 * @struct hashTableElement
 * @brief Structure representing a single element in the hash table.
 *
 * Stores the key-value pair and a flag indicating whether
 * the element has been logically deleted.
 */
typedef struct {
    char* key;     /** Pointer to the string key */
    double value;  /** Value associated with the key */
    bool deleted;  /** Flag indicating logical deletion */
} hashTableElement;

/**
 * @struct hashTable
 * @brief Structure representing the entire hash table.
 *
 * Contains a table of pointers to elements, its size,
 * and coefficients used in double hashing.
 */
typedef struct {
    hashTableElement** table; /** Pointer to the array of hash table elements */
    unsigned int size;        /** Size of the hash table (number of slots) */
    int c1;                   /** First coefficient for double hashing */
    int c2;                   /** Second coefficient for double hashing */
} hashTable;

/**
 * @brief Creates a new hash table.
 *
 * @param size Number of slots in the table
 * @param c1 First coefficient for double hashing
 * @param c2 Second coefficient for double hashing
 * @return Pointer to the newly created hash table
 */
hashTable* hashTableCreate(unsigned int size, int c1, int c2);

/**
 * @brief Inserts a key-value pair into the hash table.
 *
 * If the key already exists, its value is updated.
 *
 * @param table Pointer to the hash table
 * @param key Key string
 * @param value Value to associate with the key
 */
void hashTableInsert(hashTable* table, const char* key, double value);

/**
 * @brief Searches for a value associated with the given key.
 *
 * @param table Pointer to the hash table
 * @param key Key string
 * @return Value associated with the key, or NAN if not found
 */
double hashTableSearch(hashTable* table, char* key);

/**
 * @brief Deletes a key-value pair from the hash table.
 *
 * Marks the element as logically deleted.
 *
 * @param table Pointer to the hash table
 * @param key Key string
 */
void hashTableDelete(hashTable* table, char* key);

/**
 * @brief Frees the memory used by the hash table.
 *
 * Deallocates all elements and the table itself.
 *
 * @param table Pointer to the hash table
 */
void hashTableFree(hashTable* table);

/**
 * @brief Prints all elements in the hash table.
 *
 * Iterates through the table and prints each key-value pair.
 *
 * @param table Pointer to the hash table
 */
void hashTablePrint(hashTable* table);

#endif // HASH_TABLE_H