#include <stdio.h>
#include <stdlib.h>
#include "unrolledLinkedList.h"
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

void uLinkedListCreate(uLinkedListPtr* head, int size){
    // Check if the provided node capacity is valid
    if(size < 1){
        fprintf(stderr, "Node size must be greater than 1.\n");
        return;
    }

    // Allocate memory for a new node
    *head = malloc(sizeof(uLinkedListNode));
    if(!(*head)){
        // Handle memory allocation failure
        allocationFailure();
    }

    // Allocate memory for the values array inside the node
    (*head)->values = malloc(size * sizeof(double));
    if(!((*head)->values)){
        // Handle memory allocation failure
        allocationFailure();
    }

    // Initialize the number of used elements to 0
    (*head)->used = 0;

    // Set the node's capacity
    (*head)->capacity = size;

    // Initialize the pointer to the next node as NULL
    (*head)->next = NULL;

    // Optionally initialize all values to 0
    for(int i = 0; i < size; i++){
        (*head)->values[i] = 0;
    }
}

static void insertValueToNode(uLinkedListPtr node, double value){
    // Check if the node is NULL
    if(node == NULL){
        return;
    }

    // Check if the node is full
    if(node->capacity == node->used){
        // Node is full - need to split it
        uLinkedListPtr newNode;

        // Create a new node with the same capacity
        uLinkedListCreate(&newNode, node->capacity);

        // Calculate the index to split the node in half
        int newSize = node->used / 2;

        // Copy the second half of elements from the old node to the new node
        for(int i = 0; i < node->used - newSize; i++){
            newNode->values[i] = node->values[i + newSize];
        }

        // Update the number of used elements in the new and old nodes
        newNode->used = node->used - newSize;
        node->used = newSize;

        // Recursively insert the value into the correct node
        if (value <= node->values[node->used - 1]){
            insertValueToNode(node, value);
        }
        else {
            insertValueToNode(newNode, value);
        }

        // Insert the new node into the list
        newNode->next = node->next;
        node->next = newNode;

        return;
    }
    else{
        // Node is not full - insert the value in sorted order
        int i = node->used - 1;
        // Shift elements to the right to make space for the new value
        while (i >= 0 && node->values[i] > value) {
            node->values[i + 1] = node->values[i];
            i--;
        }
        // Insert the new value at the correct position
        node->values[i + 1] = value;
        node->used++;
    }
}

void uLinkedListInsert(uLinkedListPtr* head, double value){
    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Start from the first node in the list
    uLinkedListPtr nextNode = *head;

    // Traverse the list to find the correct node to insert the value
    while(nextNode != NULL){
        // If the node is empty, insert the value directly
        if (nextNode->used == 0) {
            nextNode->used = 1;
            nextNode->values[0] = value;
            break;
        }

        // If this is the last node, insert the value here
        if(nextNode->next == NULL){
            insertValueToNode(nextNode, value);
            break;
        }

        // If the value is less than or equal to the maximum value in this node
        if( value <= nextNode->values[nextNode->used - 1]){
            insertValueToNode(nextNode, value);
            break;
        }

        // Move to the next node
        nextNode = nextNode->next;
    }
}

double uLinkedListGet(uLinkedListPtr* head, int index){
    // Check if the index is negative
    if(index < 0){
        fprintf(stderr, "Index should be positive.\n");
        return -1;
    }

    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return -1;
    }

    // Check if the list is empty
    if(*head == NULL){
        fprintf(stderr, "The list is empty.\n");
        return -1;
    }

    // Start from the first node
    uLinkedListPtr nextNode = *head;
    // Counter for the overall index in the list
    int i = 0;

    // Traverse the nodes
    while(nextNode != NULL){
        // Traverse the values in the current node
        for(int j = 0; j < nextNode->used; j++, i++){
            // If the current index matches the requested index, return the value
            if(i == index){
                return nextNode->values[j];
            }
        }
        // Move to the next node
        nextNode = nextNode->next;
    }

    // Index is out of bounds
    return -1;
}

void uLinkedListDelete(uLinkedListPtr* head, int index){
    // Check if the index is negative
    if(index < 0){
        fprintf(stderr, "Index should be positive.\n");
        return;
    }

    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Check if the list is empty
    if(*head == NULL){
        fprintf(stderr, "The list is empty.\n");
        return;
    }

    // Start from the first node
    uLinkedListPtr currentNode = *head;
    // Keep track of the previous node
    uLinkedListPtr previousNode = NULL;
    // Overall index counter
    int i = 0; 

    // Traverse the nodes to find the node containing the index
    while(currentNode != NULL){
        // If the index is within the current node
        if(index < i + currentNode->used){
            // Index within the node
            int localIndex = index - i; 

            // Shift elements left to remove the target element
            for(int j = localIndex; j < currentNode->used - 1; j++){
                currentNode->values[j] = currentNode->values[j + 1];
            }
            currentNode->used--; // Decrease the used count

            // If the node is less than half full and there is a previous node
            if(currentNode->used < currentNode->capacity / 2 && previousNode != NULL){
                int total = previousNode->used + currentNode->used;

                // If all elements fit into the previous node
                if(total <= previousNode->capacity){
                    // Move elements from current node to previous node
                    for(int j = 0; j < currentNode->used; j++){
                        previousNode->values[previousNode->used + j] = currentNode->values[j];
                    }
                    previousNode->used += currentNode->used;

                    // Remove the now-empty current node from the list
                    previousNode->next = currentNode->next;
                    free(currentNode);
                }
            }
            // Element deleted, exit
            return;
        }

        // Update overall index and move to the next node
        i += currentNode->used;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

int uLinkedListSearch(uLinkedListPtr* head, double value){
    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return -1;
    }

    // Check if the list is empty
    if(*head == NULL){
        fprintf(stderr, "The list is empty.\n");
        return -1;
    }

    // Start from the first node
    uLinkedListPtr nextNode = *head;
    int j = 0; // Overall index counter

    // Traverse all nodes
    while(nextNode != NULL){
        // Traverse elements in the current node
        for(int i = 0; i < nextNode->used; i++, j++){
            // If the value matches, return the index
            if(nextNode->values[i] == value){
                return j;
            }
        }

        // Move to the next node
        nextNode = nextNode->next;
    }

    // Value not found in the list
    return -1;
}

int uLinkedListIsEmpty(uLinkedListPtr* head) {
    // Return 1 if the list is empty (head is NULL), otherwise 0
    return (*head == NULL);
}

void uLinkedListDeleteList(uLinkedListPtr* head){
    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return;
    }
    // Start from the first node
    uLinkedListPtr nextPtr = *head;
    // Traverse all nodes and free memory
    while(nextPtr != NULL){
        // Free the array of values in the current node
        free(nextPtr->values);
        // Keep a temporary pointer to the current node
        uLinkedListPtr tempPtr = nextPtr;
        // Move to the next node
        nextPtr = nextPtr->next;
        // Free the current node itself
        free(tempPtr);
    }
    // Reset head to NULL
    *head = NULL;
}

void uLinkedListPrint(uLinkedListPtr* head){
    // Check if the head pointer is NULL
    if(head == NULL){
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Check if the list is empty
    if(*head == NULL){
        fprintf(stdout, "The list is empty.\n");
    }

    // Start from the first node
    uLinkedListPtr nextNode = *head;

    // Traverse all nodes
    while(nextNode != NULL){
        // Print all elements in the current node
        for(int i = 0; i < nextNode->used; i++){
            fprintf(stdout, "%.2lf ", nextNode->values[i]);
        }

        // Print an arrow if there is a next node
        if(nextNode->next){
            fprintf(stdout, " -> ");
        }

        // Move to the next node
        nextNode = nextNode->next;
    }

    // Print a newline at the end
    printf("\n");
}