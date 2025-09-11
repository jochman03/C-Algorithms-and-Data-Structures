#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "hash_table.h"

int main(){
    // Create hash table with size 10 and quadratic probing constants
    hashTable* table = hashTableCreate(10, 1, 3);

    // Insert elements
    hashTableInsert(table, "banana", 5.5);
    hashTableInsert(table, "coconut", 7.3);
    hashTableInsert(table, "pomegranate", 3.3);
    hashTableInsert(table, "pineapple", 22.11);

    // Update existing element
    hashTableInsert(table, "banana", 12.5);

    // Search for elements
    double v1 = hashTableSearch(table, "banana");
    double v2 = hashTableSearch(table, "pomegranate");
    double v3 = hashTableSearch(table, "grape");

    // Print all elements
    hashTablePrint(table);

    if(!isnan(v1)){
        printf("banana -> %.2lf\n", v1);
    }
     
    if(!isnan(v2)){
        printf("pomegranate -> %.2lf\n", v2);
    }
     
    if(isnan(v3)){
        printf("grape not found\n");
    }  

    // Delete an element
    hashTableDelete(table, "pomegranate");

    // Check if deletion worked
    double v4 = hashTableSearch(table, "pomegranate");
    if(isnan(v4)){
        printf("pomegranate not found (ok)\n");
    } 

    // Free all allocated memory
    hashTableFree(table);

    return 0;
}
