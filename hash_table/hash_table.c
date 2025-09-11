#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "hash_table.h"

// Handle memory allocation failure by printing an error and exiting
_Noreturn static void allocationFailure(){
    fprintf(stderr, "There is not enough memory available.\n");
    exit(EXIT_FAILURE);
}

// Simple hash function: sum ASCII values of characters modulo table size
static unsigned int hash(const char* key, unsigned int size) {
    unsigned int hashValue = 0;
    // Iterate through each character of the string
    while (*key) {
        hashValue += *key;
        key++;
    }
    return hashValue % size;
}

// Handle collision using quadratic probing
static int addressCollision(hashTable* table, unsigned int index, const char* key){
    if(table == NULL){
        fprintf(stderr, "Table doesn't exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int newIndex;
    // Try all possible positions in the table
    for(int i = 0; i < table->size; i++){
        // Quadratic probing formula
        newIndex = (index + table->c1 * i + table->c2 * i * i) % table->size;
        
        // If the slot is empty or marked deleted, return it
        if(table->table[newIndex] == NULL || table->table[newIndex]->deleted == true){
            return newIndex;
        }
        // If the key already exists, free old element and return index
        if(strcmp(table->table[newIndex]->key, key) == 0){
            free(table->table[newIndex]->key);
            free(table->table[newIndex]);
            return newIndex;
        }
    }
    // Return -1 if no free slot found
    return -1;
}

// Create a new hash table with given size and quadratic probing constants
hashTable* hashTableCreate(unsigned int size, int c1, int c2){
    // Allocate memory for hash table structure
    hashTable* table = malloc(sizeof(hashTable));
    if(table == NULL){
        allocationFailure();
    }

    // Allocate memory for the array of pointers to elements
    table->table = malloc(sizeof(hashTableElement*) * size);
    if(table->table == NULL){
        allocationFailure();
    }

    // Initialize all slots to NULL
    for(int i = 0; i < size; i++){
        table->table[i] = NULL;
    }
    table->size = size;
    table->c1 = c1;
    table->c2 = c2;

    return table;
}

// Insert or update an element in the hash table
void hashTableInsert(hashTable* table, const char* key, double value){
    if(table == NULL){
        fprintf(stderr, "Table doesn't exist.\n");
        exit(EXIT_FAILURE);
    }

    // Compute initial hash index
    unsigned int index = hash(key, table->size);

    // Allocate memory for new element
    hashTableElement* element = malloc(sizeof(hashTableElement));
    if(element == NULL){
        allocationFailure();
    }

    // Copy key and set value
    element->key = strdup(key);
    element->value = value;
    element->deleted = false;

    // Handle collision or update existing element
    if(table->table[index] != NULL && table->table[index]->deleted == false){
        // If the key already exists, replace it
        if(strcmp(table->table[index]->key, key) == 0){
            free(table->table[index]->key);
            free(table->table[index]);
            table->table[index] = element;
            return;
        }
        // Otherwise, find new slot using quadratic probing
        index = addressCollision(table, index, key);
        if(index == -1){
            fprintf(stderr, "There is no space.\n");
            exit(EXIT_FAILURE);
        }
    }
    // If the slot was previously deleted, reuse it
    else if(table->table[index] != NULL && table->table[index]->deleted == true){
        free(table->table[index]->key);
        free(table->table[index]);
    }

    // Insert element into table
    table->table[index] = element;
}

// Search for a value by key in the hash table
double hashTableSearch(hashTable* table, char* key){
    if(table == NULL){
        fprintf(stderr, "Table doesn't exist.\n");
        return NAN;
    }

    // Compute initial hash index
    unsigned int index = hash(key, table->size);
    unsigned int newIndex;

    // Iterate using quadratic probing
    for(int i = 0; i < table->size; i++){
        newIndex = (index + table->c1 * i + table->c2 * i * i) % table->size;
        // If slot is empty, key not found
        if(table->table[newIndex] == NULL){
            return NAN;
        }
        // If slot contains key and is not deleted, return value
        if(table->table[newIndex]->deleted == false && (strcmp(table->table[newIndex]->key, key) == 0)){
            return table->table[newIndex]->value;
        }
    }

    // Key not found
    return NAN;    
}

// Mark an element as deleted
void hashTableDelete(hashTable* table, char* key){
    if(table == NULL){
        fprintf(stderr, "Table doesn't exist.\n");
        return;
    }

    // Compute initial hash index
    unsigned int index = hash(key, table->size);
    unsigned int newIndex;

    // Iterate using quadratic probing to find the key
    for(int i = 0; i < table->size; i++){
        newIndex = (index + table->c1 * i + table->c2 * i * i) % table->size;
        if(table->table[newIndex] != NULL && (strcmp(table->table[newIndex]->key, key) == 0)){
            // Mark the element as deleted
            table->table[newIndex]->deleted = true;
            return;
        }
    }
}

// Free all memory used by the hash table
void hashTableFree(hashTable* table){
    if(table == NULL){
        return;
    }

    // Free each element in the table
    for(int i = 0; i < table->size; i++){
        if(table->table[i] != NULL){
            free(table->table[i]->key); 
            free(table->table[i]);
        }
    }

    // Free the table array and the table itself
    free(table->table);
    free(table);
}

void hashTablePrint(hashTable* table){
    // If the table doesn't exist, print empty brackets and return
    if(table == NULL){
        printf("[ ]\n");
        return;
    }

    // Start printing table contents
    printf("[ ");

    // Iterate over all slots in the table
    for(int i = 0; i < table->size; i++){
        // If the slot is not NULL and not marked as deleted
        if(table->table[i] != NULL && table->table[i]->deleted == false){
            // Print key and value
            printf("%s:%.2lf, ", table->table[i]->key, table->table[i]->value);
        }
    }

    // Close the printed table
    printf("]\n");
}