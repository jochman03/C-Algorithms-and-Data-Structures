# Singly Linked List Implementation in C

This project contains a **singly linked list library implemented in C**, as part of learning dynamic memory management.

## Features

- Dynamic list creation and deletion
- Insert elements at the beginning or end
- Delete elements by position, first, last, or entire list
- Search for values
- Get and set values at specific positions
- Print the list
- Memory handling with allocation checks

---

## Function Overview

### Creation & Deletion
- `sLinkedListPtr* head` – Head pointer of the list (initialized to NULL)
- `void linkedListDeleteList(sLinkedListPtr* head)` – Delete the entire list and free memory

### Insertion
- `void sLinkedListInsertFirst(sLinkedListPtr* head, double value)` – Insert a value at the beginning
- `void sLinkedListInsertLast(sLinkedListPtr* head, double value)` – Insert a value at the end

### Deletion
- `void sLinkedListDeleteFirst(sLinkedListPtr* head)` – Delete the first element
- `void sLinkedListDeleteLast(sLinkedListPtr* head)` – Delete the last element
- `void sLinkedListDeletePos(sLinkedListPtr* head, int pos)` – Delete element at specific position

### Access & Update
- `int sLinkedListIsEmpty(sLinkedListPtr* head)` – Check if the list is empty
- `int sLinkedListSearch(sLinkedListPtr* head, double value)` – Search for a value, return position or -1 if not found
- `double sLinkedListGetValue(sLinkedListPtr* head, int pos)` – Get value at a position
- `void sLinkedListSetValue(sLinkedListPtr* head, int pos, double value)` – Set value at a position

### Other Operations
- `void sLinkedListPrint(sLinkedListPtr* head)` – Print all elements in the list

### Example usage
- See `main.c` for a complete example of how to use the library.