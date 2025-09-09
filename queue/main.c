#include <stdio.h>
#include "queue.h"

int main(){
    // Create a new queue with default size
    queue* q = queueCreate();
    // Print the contents of the queue (initially empty)
    queuePrint(q);
    // Enqueue numbers from 1 to 9
    for(int i = 1; i < 10; i++){
        queueEnqueue(q, i);        
    }
    // Print the contents of the queue after adding elements
    queuePrint(q);
    // Peek at the first element in the queue (without removing it)
    printf("First element of queue: %.2lf\n", queuePeek(q));
    // Print the current number of elements in the queue
    printf("Queue length: %d\n", queueLength(q));
    // Dequeue (remove) the first element and print it
    printf("Dequeue first element of queue: %.2lf\n", queueDequeue(q));
    // Print the number of elements again after removing one
    printf("Queue length: %d\n", queueLength(q));
    // Free all allocated memory
    queueDelete(&q);
}