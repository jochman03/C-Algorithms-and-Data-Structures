#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

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

void sLinkedListInsertFirst(sLinkedListPtr* head, double value) {
    // Allocate memory for a new node
    sLinkedListPtr newNode = malloc(sizeof(sLinkedListNode));
    
    // Check if allocation succeeded
    if (newNode == NULL) {
        allocationFailure(); // Terminates program if memory allocation fails
    }

    // Set new node fields
    newNode->next = *head;  // New node points to the current head
    newNode->value = value; // Store the given value in the new node

    // Update the head pointer to point to the new node
    *head = newNode;
}

void sLinkedListInsertLast(sLinkedListPtr* head, double value) {
    // Allocate memory for a new node
    sLinkedListPtr newNode = malloc(sizeof(sLinkedListNode));
    if (newNode == NULL) {
        allocationFailure(); // Terminate program if memory allocation fails
    }

    // Initialize new node fields
    newNode->value = value; // Store the given value
    newNode->next = NULL;   // It will be the last node, so next is NULL

    // Traverse the list to find the last node
    sLinkedListPtr currentNode = *head;
    sLinkedListPtr previousNode = NULL;
    while (currentNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // Insert the new node
    if (previousNode == NULL) {
        // List was empty, new node becomes the head
        *head = newNode;
    } else {
        // Append to the end of the list
        previousNode->next = newNode;
    }
}
int sLinkedListIsEmpty(sLinkedListPtr* head) {
    // Check if the head pointer is NULL
    // Returns 1 if the list is empty, 0 otherwise
    return (*head == NULL);
}

void sLinkedListDeleteFirst(sLinkedListPtr* head) {
    // Check if the list is empty; nothing to delete
    if (sLinkedListIsEmpty(head)) {
        return;
    }

    // Save the current head node to free later
    sLinkedListPtr tempNode = *head;

    // Move the head pointer to the next node
    *head = (*head)->next;

    // Free the memory of the original head node
    free(tempNode);
}

int sLinkedListSearch(sLinkedListPtr* head, double value) {
    // Check if the list is empty; return -1 to indicate value not found
    if (sLinkedListIsEmpty(head)) {
        return -1;
    }

    // Start from the head node
    sLinkedListPtr tempNode = *head;
    int pos = 0; // Position counter

    // Traverse the list
    while (tempNode != NULL) {
        // If the value matches, return the current position
        if (tempNode->value == value) {
            return pos;
        }
        pos++;                 // Move to next position
        tempNode = tempNode->next; // Move to next node
    }

    // Value not found in the list
    return -1;
}

double sLinkedListGetValue(sLinkedListPtr* head, int pos) {
    // Check if the requested position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return -1;
    }

    // Check if the list is empty
    if (sLinkedListIsEmpty(head)) {
        return -1;
    }

    // Start from the head node
    sLinkedListPtr tempNode = *head;
    int i = 0; // Position counter

    // Traverse the list
    while (tempNode != NULL) {
        // If current position matches requested position, return value
        if (i == pos) {
            return tempNode->value;
        }
        i++;
        tempNode = tempNode->next; // Move to next node
    }

    // Position not found in the list
    fprintf(stderr, "Could not find any element at given position.\n");
    return -1;
}

void sLinkedListSetValue(sLinkedListPtr* head, int pos, double value) {
    // Check if the requested position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return;
    }

    // Check if the list is empty
    if (sLinkedListIsEmpty(head)) {
        return;
    }

    // Start from the head node
    sLinkedListPtr tempNode = *head;
    int i = 0; // Position counter

    // Traverse the list
    while (tempNode != NULL) {
        // If current position matches requested position, set the value
        if (i == pos) {
            tempNode->value = value;
            return;
        }
        i++;
        tempNode = tempNode->next; // Move to next node
    }

    // Position not found in the list
    fprintf(stderr, "Could not find any element at given position.\n");
}

void sLinkedListDeletePos(sLinkedListPtr* head, int pos) {
    // Check if the requested position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return;
    }

    // Check if the list is empty
    if (sLinkedListIsEmpty(head)) {
        return;
    }

    // Special case: delete the first node
    if (pos == 0) {
        sLinkedListPtr tempNode = *head;
        *head = (*head)->next;
        free(tempNode);
        return;
    }

    // Traverse the list to find the node at the given position
    sLinkedListPtr currentNode = *head;
    sLinkedListPtr previousNode = NULL;
    int i = 0;

    while (currentNode != NULL) {
        if (i == pos) {
            // If it's the last node, update previous node's next to NULL
            if (currentNode->next == NULL) {
                previousNode->next = NULL;
                free(currentNode);
                return;
            }
            // Otherwise, skip over the current node
            previousNode->next = currentNode->next;
            free(currentNode);
            return;
        }
        i++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

void sLinkedListDeleteLast(sLinkedListPtr* head) {
    // Check if the list is empty
    if (sLinkedListIsEmpty(head)) {
        return;
    }

    // Traverse the list to find the last node
    sLinkedListPtr currentNode = *head;
    sLinkedListPtr previousNode = NULL;

    while (currentNode->next != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    // If the list had only one node
    if (previousNode == NULL) {
        sLinkedListPtr tempNode = *head;
        *head = (*head)->next;
        free(tempNode);
    } else {
        // Remove the last node
        previousNode->next = NULL;
        free(currentNode);
    }
}

void sLinkedListDeleteList(sLinkedListPtr* head){
    sLinkedListPtr current = *head; // Start from the head node
    sLinkedListPtr next;            // Temporary pointer to store next node

    // Traverse the list and free each node
    while (current != NULL) {
        next = current->next; // Save pointer to next node
        free(current);           // Free the current node
        current = next;          // Move to the next node
    }

    *head = NULL; // Set head to NULL to indicate the list is empty
}


void sLinkedListPrint(sLinkedListPtr* head) {
    sLinkedListPtr tempNode = *head;

    // Check if the list is empty
    if (tempNode == NULL) {
        fprintf(stdout, "The list is empty.\n");
        return;
    }

    // Traverse and print each node
    while (tempNode != NULL) {
        fprintf(stdout, "%.2lf", tempNode->value);
        if (tempNode->next != NULL) {
            fprintf(stdout, " -> ");
        }
        tempNode = tempNode->next;
    }
    fprintf(stdout, "\n");
}