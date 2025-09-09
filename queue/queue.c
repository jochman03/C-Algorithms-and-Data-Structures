#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Default initial size of the queue
#define DEFAULT_SIZE 5

/**
 * Handle memory allocation failure.
 *
 * This function prints an error message to `stderr` and terminates
 * the program with `EXIT_FAILURE`. Since it always exits, it is
 * marked with `_Noreturn`.
 */
_Noreturn static void allocationFailure(){
    fprintf(stderr, "There is not enough memory available.\n");
    exit(EXIT_FAILURE);
}

static queue* queueAllocate(int size) {
    // Allocate memory for the queue structure
    queue* q = malloc(sizeof(queue));
    if (!q) {
        allocationFailure();
    }

    // Allocate memory for storing queue values
    q->values = malloc(size * sizeof(double));
    if (!q->values) {
        allocationFailure();
    }

    // Initialize queue parameters
    q->size = size;
    q->readIndex = 0;
    q->writeIndex = 0;

    return q;
}
queue* queueCreate(){
    // Create a new queue with the default size.
    return queueAllocate(DEFAULT_SIZE);
}

int queueIsEmpty(queue* q) {
    // Print error if pointer points to null 
    if (!q){
        fprintf(stderr, "Error: The queue does not exists.\n");
        return -1;
    }
    // Return 1 if empty, 0 otherwise
    return q->readIndex == q->writeIndex;
}

double queuePeek(queue* q){
    if(!q){
        // Print error if pointer points to null
        fprintf(stderr, "Error: The queue does not exists.\n");
        return -1;
    }
    if(queueIsEmpty(q)){
        // Print error if empty
        fprintf(stderr, "Error: The queue is empty.\n");
        return -1;
    }
    // Return value at readIndex
    return (q->values[q->readIndex]);
}

double queueDequeue(queue* q) {
    if(!q){
        // Print error if pointer points to null
        fprintf(stderr, "Error: The queue does not exists.\n");
        return -1;
    }
    if(queueIsEmpty(q)){
        // Print error if empty
        fprintf(stderr, "Error: The queue is empty.\n");
        return -1;
    }
    // Save the element to return
    double value = q->values[q->readIndex];

    // Advance readIndex (circularly)
    q->readIndex = (q->readIndex + 1) % q->size; 
    return value;
}

int queueLength(queue* q){
    if(!q){
        // Print error if pointer points to null
        fprintf(stderr, "Error: The queue does not exists.\n");
        return -1;
    }
    if(queueIsEmpty(q)){
        return 0;
    }
    // Case 1: writeIndex is ahead of readIndex
    if (q->writeIndex >= q->readIndex){
        return q->writeIndex - q->readIndex;
    }
    // Case 2: wrap-around (writeIndex < readIndex)
    else {
        return q->size - (q->readIndex - q->writeIndex);
    }
}

void queueEnqueue(queue* q, double value) {
    if(!q){
        // Print error if pointer points to null
        fprintf(stderr, "Error: The queue does not exists.\n");
        return;
    }
    // Insert element at writeIndex
    q->values[q->writeIndex] = value;

    // Move writeIndex forward circularly
    q->writeIndex = (q->writeIndex + 1) % q->size;

    // Check if queue is full (writeIndex caught up to readIndex)
    if (q->writeIndex == q->readIndex) {
        int newSize = q->size * 2;

        // Allocate bigger array
        double* newTable = malloc(newSize * sizeof(double));
        if (!newTable) allocationFailure();

        // Copy old values in correct order
        int i = 0;
        for(int j = q->readIndex; j < q->size; j++, i++){
            newTable[i] = q->values[j];
        }
        for(int j = 0; j < q->readIndex; j++, i++){
            newTable[i] = q->values[j];
        }
        // Replace old array
        free(q->values);
        q->values = newTable;
        q->size = newSize;
        q->readIndex = 0;
        // set to count of copied elements
        q->writeIndex = i;
    }
}
void queueDelete(queue** q){
    // Check if the queue pointer is valid
    if (!(*q)) {
        // If the pointer is NULL, there is nothing to delete
        return;
    }

    // Free the dynamically allocated array of queue values
    free((*q)->values);

    // Free the queue structure itself
    free(*q);

    // Set the original pointer (in the caller) to NULL
    // to avoid a dangling pointer (pointer to freed memory).
    *q = NULL;
}
void queuePrint(queue* q) {
    if (!q) {
        // Print error if pointer points to null
        fprintf(stderr, "Error: The queue does not exist.\n");
        return;
    }

    if (queueIsEmpty(q)) {
        // Queue is empty
        fprintf(stdout, "The queue is empty.\n");
        return;
    }

    // Get the number of elements currently in the queue
    int count = queueLength(q);

    // Print all elements in logical order
    fprintf(stdout, "[ ");
    for (int i = 0; i < count; i++) {
        // wrap-around using modulo
        int index = (q->readIndex + i) % q->size;
        fprintf(stdout, "%.2lf ", q->values[index]);
    }
    fprintf(stdout, "]\n");
}