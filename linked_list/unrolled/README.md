# Unrolled Linked List Implementation in C

This project contains an **unrolled linked list library implemented in C**, designed to efficiently store sequences of elements using nodes that hold multiple values. It is part of learning dynamic memory management and advanced data structures.

## Features

- Dynamic list creation and deletion
- Insert elements in sorted order
- Delete elements by index
- Node splitting when full and merging when underutilized
- Search for values
- Access values by index
- Print the list
- Memory handling with allocation checks

---

## Function Overview

### Creation & Deletion
- `sLinkedListPtr list` – Head pointer of the list (initialized to NULL)

- `void uLinkedListCreate(uLinkedListPtr* head, int size)` – Create a new unrolled linked list with node capacity size

- `void uLinkedListDeleteList(uLinkedListPtr* head)` – Delete the entire list and free all memory

### Insertion

- `void uLinkedListInsert(uLinkedListPtr* head, double value)` – Insert a value into the list in sorted order

### Deletion

- `void uLinkedListDelete(uLinkedListPtr* head, int index)` – Delete element at a specific index

### Access & Search

- `int uLinkedListIsEmpty(uLinkedListPtr* head)` – Check if the list is empty

- `int uLinkedListSearch(uLinkedListPtr* head, double value)` – Search for a value, return index or -1 if not found

- `double uLinkedListGet(uLinkedListPtr* head, int index)` – Get value at a specific index

### Other Operations

- `void uLinkedListPrint(uLinkedListPtr* head)` – Print all elements in the list

### Example Usage

- See `main.c` for a complete example of how to use the library.