# Binary Search Tree Implementation in C

This project contains a **binary search tree (BST) library implemented in C**, as part of learning dynamic memory management and tree data structures.

## Features

- Dynamic tree creation and deletion
- Insert elements with integer keys and character data
- Search for elements by key
- Delete elements (supports all cases: no child, one child, two children)
- Compute the height of the tree
- Print the tree structure in a readable format
- Proper memory management with allocation checks

---

## Function Overview

### Creation & Deletion
- `tree* treeCreate()` – Create a new empty tree
- `void treeFree(tree* t)` – Free all memory associated with the tree

### Insertion
- `void treeInsert(tree* t, int key, char data)` – Insert a new node with given key and data.  
  If a node with the same key already exists, its data is updated.

### Deletion
- `void treeDelete(tree* t, int key)` – Delete a node with the given key.  
  Handles all cases: no children, one child, or two children.

### Search
- `char treeSearch(tree* t, int key)` – Search for a node with the given key.  
  Returns the data if found, or `'\0'` if not found.

### Other Operations
- `int treeHeight(tree* t)` – Compute the height of the tree (0 if empty)
- `void treePrint(tree* t)` – Print the structure of the tree to stdout

---

## Example usage
See `main.c` for a complete example of how to use the library.  
