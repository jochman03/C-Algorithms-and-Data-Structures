# C Hash Table Implementation

This project contains a **hash table library implemented in C**, using **quadratic probing** for collision resolution.  
It is part of learning data structures and dynamic memory management.

## Features

- Dynamic hash table creation and deletion
- Insert, search, and delete elements by key
- Handles collisions with quadratic probing
- Mark elements as deleted without freeing immediately
- Automatic error handling for NULL pointers and memory allocation failures
- Print the current table contents

---

## Function Overview

### Creation & Deletion
- `hashTable* hashTableCreate(unsigned int size, int c1, int c2)` – Create a new hash table with given size and quadratic probing constants
- `void hashTableFree(hashTable* table)` – Free all memory used by the hash table

### Element Access
- `double hashTableSearch(hashTable* table, char* key)` – Search for a value by key (returns `NAN` if not found)

### Element Insertion
- `void hashTableInsert(hashTable* table, const char* key, double value)` – Insert a new element or update an existing key

### Element Deletion
- `void hashTableDelete(hashTable* table, char* key)` – Mark an element as deleted

### Utilities
- `void hashTablePrint(hashTable* table)` – Print all non-deleted elements in the table for debugging

### Example Usage
- See `main.c` for a complete example demonstrating creation, insertion, search, deletion, and printing of the table.
