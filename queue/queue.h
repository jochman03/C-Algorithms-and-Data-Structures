#ifndef QUEUE_H
#define QUEUE_H

/**
 * Structure representing a circular queue.
 */
typedef struct queue_{
    int size;        /** Current capacity of the queue (number of allocated slots) */
    double* values;  /** Array holding queue elements */
    int readIndex;   /** Index of the first element */
    int writeIndex;  /** Index of the position for the next inserted element */
} queue;

/**
 * Create a new queue with the default size.
 *
 * @return Pointer to the newly created queue
 */
queue* queueCreate();

/**
 * Check if the queue is empty.
 *
 * @param q Pointer to the queue
 * @return 1 if the queue is empty, 0 if not, -1 if the queue is NULL
 */
int queueIsEmpty(queue* q);

/**
 * Peek at the first element in the queue without removing it.
 *
 * @param q Pointer to the queue
 * @return First element value, or -1 if the queue is empty or NULL
 */
double queuePeek(queue* q);

/**
 * Remove and return the first element of the queue.
 *
 * @param q Pointer to the queue
 * @return The dequeued value, or -1 if the queue is empty or NULL
 */
double queueDequeue(queue* q);

/**
 * Get the current number of elements in the queue.
 *
 * @param q Pointer to the queue
 * @return Number of elements, or -1 if the queue is NULL
 */
int queueLength(queue* q);

/**
 * Insert a new element at the end of the queue.
 * If the queue is full, it will resize to twice its current size.
 *
 * @param q Pointer to the queue
 * @param value Value to insert
 */
void queueEnqueue(queue* q, double value);

/**
 * Delete a queue and free all allocated memory.
 *
 * This function frees both the array of values and the queue structure itself.
 * It also sets the caller's queue pointer to NULL to prevent dangling pointers.
 *
 * @param q Double pointer to the queue .
 */
void queueDelete(queue** q);

/**
 * Print the contents of the queue in order from front to back.
 *
 * @param q Pointer to the queue
 */
void queuePrint(queue* q);

#endif //QUEUE_H