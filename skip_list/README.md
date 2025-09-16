# C Skip List Implementation

This project contains a **skip list library implemented in C**, as part of learning algorithms and data structures.

## Features

- Create and delete skip lists with configurable maximum levels
- Insert elements with key-value pairs
- Delete elements by key
- Search for elements by key
- Display the skip list level by level
- Error handling for memory allocation failures and NULL pointers

---

## Function Overview

### Creation & Deletion
- `skipList* skipListCreate(unsigned int maxLevels)` – Create a new skip list with a specified number of levels
- `void skipListDelete(skipList* list, int key)` – Delete an element with a given key from the skip list

### Element Access
- `char skipListSearch(skipList* list, int key)` – Search for an element by key and return its data

### Element Insertion
- `void skipListInsert(skipList* list, int key, char data)` – Insert a new element with a key and data into the skip list

### Utilities
- `void skipListDisplay(skipList* list)` – Display the contents of the skip list level by level

### Example Usage
- See `main.c` for a complete example of creating a skip list, inserting elements, deleting an element, displaying the list, and searching for a key.
