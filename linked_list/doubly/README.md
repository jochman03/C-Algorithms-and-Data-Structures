# Doubly Linked List Implementation in C

This project contains a **doubly linked list library implemented in C**, as part of learning dynamic memory management.

## Features

- Dynamic list creation and deletion
- Insert elements at the beginning or end
- Delete elements by position, first, last, or entire list
- Search for values
- Get and set values at specific positions
- Print the list from head to tail or tail to head
- Memory handling with allocation checks

---

## Function Overview

### Creation & Deletion
- `dLinkedList* list` – Pointer to a doubly linked list (can be dynamically allocated)
- `void dLinkedListDeleteList(dLinkedList* list)` – Delete the entire list and free memory

### Insertion
- `void dLinkedListInsertFirst(dLinkedList* list, double value)` – Insert a value at the beginning
- `void dLinkedListInsertLast(dLinkedList* list, double value)` – Insert a value at the end

### Deletion
- `void dLinkedListDeleteFirst(dLinkedList* list)` – Delete the first element
- `void dLinkedListDeleteLast(dLinkedList* list)` – Delete the last element
- `void dLinkedListDeletePos(dLinkedList* list, int pos)` – Delete element at specific position

### Access & Update
- `int dLinkedListIsEmpty(dLinkedList* list)` – Check if the list is empty; returns 1 if empty, 0 if not, -1 if list pointer is NULL
- `int dLinkedListSearch(dLinkedList* list, double value)` – Search for a value; returns position or -1 if not found
- `double dLinkedListGetValue(dLinkedList* list, int pos)` – Get value at a position
- `void dLinkedListSetValue(dLinkedList* list, int pos, double value)` – Set value at a position

### Other Operations
- `void dLinkedListPrint(dLinkedList* list)` – Print all elements from head to tail
- `void dLinkedListPrintReverse(dLinkedList* list)` – Print all elements from tail to head

### Example usage
- See `main.c` for a complete example of how to use the library.