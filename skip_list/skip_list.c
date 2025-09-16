#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "skip_list.h"


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

char skipListSearch(skipList* list, int key){
    if(!list){
        fprintf(stderr, "List does not exists");
        return '\0';
    }

    skipListElement* current = list->head;

    // Traverse levels from top to bottom
    for (int i = list->maxLevels - 1; i >= 0; i--) {
        // Move forward while next node's key is smaller
        while (current->ptrs[i] != NULL && current->ptrs[i]->key < key) {
            current = current->ptrs[i];
        }

        // If found, return its data
        if(current->ptrs[i] != NULL && current->ptrs[i]->key == key){
            return current->ptrs[i]->data;
        }
    }

    // Key not found
    return '\0';
}

skipList* skipListCreate(unsigned int maxLevels){
    // Allocate skip list structure
    skipList* list = malloc(sizeof(skipList));
    if(!list){
        allocationFailure();
    }

    // Allocate head element
    skipListElement* head = malloc(sizeof(skipListElement));
    if(!head){
        free(list);
        allocationFailure();
    }

    // Allocate forward pointers for head
    head->ptrs = malloc(maxLevels * sizeof(skipListElement*));
    if(!head->ptrs){
        free(head);
        free(list);
        allocationFailure();
    }

    // Initialize list and head
    list->maxLevels = maxLevels;
    list->head = head;

    head->key = 0;
    head->isHead = true;
    head->data = 'H';
    head->levels = maxLevels;

    // Initialize all head pointers to NULL
    for(int i = 0; i < maxLevels; i++){
        head->ptrs[i] = NULL;
    }

    return list;
}

void skipListDelete(skipList* list, int key) {
    if (!list){ 
        fprintf(stderr, "List does not exists");
        return;
    }

    // Keep track of nodes that point to the node being removed
    skipListElement** update = malloc(list->maxLevels * sizeof(skipListElement*));
    if (!update){
        allocationFailure();
    }

    skipListElement* current = list->head;

    // Traverse list from top level down
    for (int i = list->maxLevels - 1; i >= 0; i--) {
        while (current->ptrs[i] != NULL && current->ptrs[i]->key < key) {
            current = current->ptrs[i];
        }
        update[i] = current;
    }

    // Candidate for deletion
    current = current->ptrs[0];
    if (current == NULL || current->key != key) {
        return; // Key not found
    }

    // Update pointers to bypass the node
    for (int i = 0; i < current->levels; i++) {
        if (update[i]->ptrs[i] == current) {
            update[i]->ptrs[i] = current->ptrs[i];
        }
    }

    // Free memory
    free(current->ptrs);
    free(current);
}

void skipListInsert(skipList* list, int key, char data){
    // Randomize levels for the new node
    unsigned int levels = 1 + rand() % list->maxLevels;

    // Allocate new element
    skipListElement* newElement = malloc(sizeof(skipListElement));
    if(!newElement){
        allocationFailure();
    }

    // Allocate forward pointers for new element
    newElement->ptrs = malloc(levels * sizeof(skipListElement*));
    newElement->levels = levels;
    newElement->key = key;
    newElement->data = data;
    if(!newElement->ptrs){
        free(newElement);
        allocationFailure();
    }

    // Array to track nodes that will point to the new node
    skipListElement** update = malloc(list->maxLevels * sizeof(skipListElement*));
    if (!update){
        allocationFailure();
    }

    skipListElement* current = list->head;

    // Find insertion position at each level
    for (int i = list->maxLevels - 1; i >= 0; i--) {
        while (current->ptrs[i] != NULL && current->ptrs[i]->key < key) {
            current = current->ptrs[i];
        }
        update[i] = current;
    }

    // Insert new node by updating pointers
    for (int i = 0; i < levels; i++) {
        newElement->ptrs[i] = update[i]->ptrs[i];
        update[i]->ptrs[i] = newElement;
    }
}

void skipListDisplay(skipList* list) {
    if (!list) {
        fprintf(stderr, "List does not exists");
        return;
    }

    skipListElement* node = list->head->ptrs[0];
    int keys[100];
    int count = 0;

    // Collect keys in order for spacing
    while (node != NULL) {
        keys[count++] = node->key;
        node = node->ptrs[0];
    }

    // Print each level from top to bottom
    for (int lvl = list->maxLevels - 1; lvl >= 0; lvl--) {
        fprintf(stdout, "%2d  ", lvl);
        node = list->head->ptrs[lvl];
        int idx = 0;

        while (node != NULL && idx < count) {
            // Skip missing keys for alignment
            while (idx < count && node->key > keys[idx]) {
                fprintf(stdout, "     ");
                idx++;
            }

            if (idx >= count) break;

            // Print key:data at this level
            fprintf(stdout, "%2d:%c ", node->key, node->data);

            node = node->ptrs[lvl];
            idx++;
        }
        fprintf(stdout, "\n");
    }
}