# C Circular Queue Implementation

This project contains a **circular queue library implemented in C**, as part of learning algorithms and data structures.  

## Features

- Dynamic queue creation and deletion
- Enqueue and dequeue operations
- Peek at the first element without removing it
- Automatic resizing when the queue becomes full
- Check if the queue is empty
- Get the current number of elements in the queue
- Error handling for NULL pointers and empty queues

---

## Function Overview

### Creation & Deletion
- `queue* queueCreate()` – Create a new queue with default size
- `queue* queueAllocate(int size)` – Allocate a queue with a specified size

### Element Access
- `double queuePeek(queue* q)` – Peek at the first element
- `double queueDequeue(queue* q)` – Remove and return the first element

### Queue Status
- `int queueIsEmpty(queue* q)` – Check if the queue is empty
- `int queueLength(queue* q)` – Get the current number of elements

### Element Insertion
- `void queueEnqueue(queue* q, double value)` – Add a new element at the end of the queue (resizes if full)

### Utilities
- `void queuePrint(queue* q)` – Print the current contents of the queue

### Example Usage
- See `main.c` for a complete example of how to use the library.

