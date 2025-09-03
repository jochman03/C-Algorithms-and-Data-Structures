#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

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

void dLinkedListInsertFirst(dLinkedList* list, double value) {
    // Allocate memory for a new node
    dLinkedListPtr newNode = malloc(sizeof(dLinkedListNode));
    // Check if allocation succeeded
    if (newNode == NULL) {
        // Terminate program if allocation fails
        allocationFailure();
    }

    // Store value in the new node
    newNode->value = value;
    // New node will be the first, so prev is NULL
    newNode->prev = NULL;
    // New node points to current head
    newNode->next = list->head;

    // Update old head's prev pointer if head exists
    if (list->head != NULL) {
        list->head->prev = newNode;
    } else {
        // If list was empty, tail also points to new node
        list->tail = newNode;
    }

    // Update head pointer to new node
    list->head = newNode;
}

void dLinkedListInsertLast(dLinkedList* list, double value) {
    // Allocate memory for a new node
    dLinkedListPtr newNode = malloc(sizeof(dLinkedListNode));
    // Check if allocation succeeded
    if (newNode == NULL) {
        allocationFailure();
    }

    // Store value in the new node
    newNode->value = value;
    // New node will be the last, so next is NULL
    newNode->next = NULL;

    // If the list is empty
    if (list->tail == NULL) {
        // New node has no previous node
        newNode->prev = NULL;
        // Head and tail point to new node
        list->head = newNode;
        list->tail = newNode;
    } else {
        // Link new node after current tail
        newNode->prev = list->tail;
        list->tail->next = newNode;
        // Update tail pointer
        list->tail = newNode;
    }
}

int dLinkedListIsEmpty(dLinkedList* list) {
    // Check if the list itself is NULL
    if(list == NULL){
        fprintf(stderr, "List does not exist.\n");
        return -1;
    }
    // Return 1 if list is empty, 0 otherwise
    return (list->head == NULL);
}

void dLinkedListDeleteFirst(dLinkedList* list) {
    // Check if list is empty; nothing to delete
    if (dLinkedListIsEmpty(list)) {
        return;
    }

    // Save current head to free later
    dLinkedListPtr tempNode = list->head;

    // Move head pointer to next node
    list->head = (list->head)->next;

    // Update new head's prev pointer or tail if list becomes empty
    if (list->head != NULL) {
        (list->head)->prev = NULL;
    } else {
        list->tail = NULL;
    }

    // Free old head node
    free(tempNode);
}

int dLinkedListSearch(dLinkedList* list, double value) {
    // Check if list pointer is NULL
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    }

    // Check if list is empty
    if (dLinkedListIsEmpty(list)) {
        return -1;
    }

    // Start traversal from head
    dLinkedListPtr tempNode = list->head;
    int pos = 0; // Position counter

    // Traverse the list
    while (tempNode != NULL) {
        // Return position if value matches
        if (tempNode->value == value) {
            return pos;
        }
        // Move to next node
        tempNode = tempNode->next;
        pos++;
    }

    // Value not found
    return -1;
}

double dLinkedListGetValue(dLinkedList* list, int pos) {
    // Check if list pointer is NULL
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return -1;
    }

    // Check if requested position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return -1;
    }

    // Check if list is empty
    if (dLinkedListIsEmpty(list)) {
        return -1;
    }

    // Start from head
    dLinkedListPtr tempNode = list->head;
    int i = 0; // Position counter

    // Traverse to requested position
    while (tempNode != NULL) {
        if (i == pos) {
            // Return value at position
            return tempNode->value;
        }
        tempNode = tempNode->next;
        i++;
    }

    // Position not found
    fprintf(stderr, "Could not find any element at given position.\n");
    return -1;
}

void dLinkedListSetValue(dLinkedList* list, int pos, double value) {
    // Check if list pointer is NULL
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Check if requested position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return;
    }

    // Check if list is empty
    if (dLinkedListIsEmpty(list)) {
        return;
    }

    // Start from head
    dLinkedListPtr tempNode = list->head;
    int i = 0; // Position counter

    // Traverse to requested position
    while (tempNode != NULL) {
        if (i == pos) {
            // Set value at position
            tempNode->value = value;
            return;
        }
        tempNode = tempNode->next;
        i++;
    }

    // Position not found
    fprintf(stderr, "Could not find any element at given position.\n");
}

void dLinkedListDeletePos(dLinkedList* list, int pos) {
    // Check if list pointer is NULL
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Check if position is valid
    if (pos < 0) {
        fprintf(stderr, "Position should be positive.\n");
        return;
    }

    // Check if list is empty
    if (dLinkedListIsEmpty(list)) {
        return;
    }

    // Start from head
    dLinkedListPtr currentNode = list->head;
    int i = 0;

    // Traverse to node at position
    while (currentNode != NULL && i < pos) {
        currentNode = currentNode->next;
        i++;
    }

    // Position out of range
    if (currentNode == NULL) {
        fprintf(stderr, "Position out of range.\n");
        return;
    }

    // Update links for previous node or head
    if (currentNode->prev != NULL) {
        (currentNode->prev)->next = currentNode->next;
    } else {
        // Deleting first node
        list->head = currentNode->next;
    }

    // Update links for next node or tail
    if (currentNode->next != NULL) {
        (currentNode->next)->prev = currentNode->prev;
    } else {
        // Deleting last node
        list->tail = currentNode->prev;
 }
    // Free the node
    free(currentNode);
}

void dLinkedListDeleteLast(dLinkedList* list) {
    // Check if list pointer is NULL
    if (list == NULL) {
        fprintf(stderr, "List does not exist.\n");
        return;
    }

    // Check if list is empty
    if (dLinkedListIsEmpty(list)) {
        return;
    }

    // Store tail node to free
    dLinkedListPtr tempNode = list->tail;

    // If more than one node, update tail
    if ((list->tail)->prev != NULL) {
        list->tail = (list->tail)->prev;
        (list->tail)->next = NULL;
    } else {
        // Only one node: reset head and tail
        list->head = NULL;
        list->tail = NULL;
    }

    // Free old tail
    free(tempNode);
}

void dLinkedListDeleteList(dLinkedList* list) {
    // Check if list pointer is NULL
    if (list == NULL){
        return;
    }

    // Start from head
    dLinkedListPtr current = list->head;
    // Temporary pointer
    dLinkedListPtr next;

    // Traverse and free all nodes
    while (current != NULL) {
        // Save next node
        next = current->next; 
        // Free current node
        free(current);       
        // Move to next
        current = next;
    }

    // Reset head and tail
    list->head = NULL;
    list->tail = NULL;
}

void dLinkedListPrint(dLinkedList* list) {
    // Start from head
    dLinkedListPtr tempNode = list->head;

    // Check if list is empty
    if (tempNode == NULL) {
        fprintf(stdout, "The list is empty.\n");
        return;
    }

    // Traverse and print values
    while (tempNode != NULL) {
        fprintf(stdout, "%.2lf", tempNode->value);
        if (tempNode->next != NULL) {
            fprintf(stdout, " -> ");
        }
        tempNode = tempNode->next;
    }
    fprintf(stdout, "\n");
}

void dLinkedListPrintReverse(dLinkedList* list) {
    // Start from tail
    dLinkedListPtr tempNode = list->tail;

    // Check if list is empty
    if (tempNode == NULL) {
        fprintf(stdout, "The list is empty.\n");
        return;
    }

    // Traverse backwards and print values
    while (tempNode != NULL) {
        fprintf(stdout, "%.2lf", tempNode->value);
        if (tempNode->prev != NULL) {
            fprintf(stdout, " <- ");
        }
        tempNode = tempNode->prev;
    }
    fprintf(stdout, "\n");
}
