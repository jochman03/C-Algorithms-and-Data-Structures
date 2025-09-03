#include <stdio.h>
#include "singlyLinkedList.h"

int main(){
    // Initialize the head of the list to NULL
    sLinkedListPtr list = NULL;

    // Insert values 0, 2.5, 5, ..., 22.5 at the end of the list
    for (int i = 0; i < 10; i++) {
        sLinkedListInsertLast(&list, 2.5 * i); // Pass pointer to head
    }

    // Print the list
    sLinkedListPrint(&list);

    // Search for some values
    printf("Element of value 7.5 is at position: %d\n", sLinkedListSearch(&list, 7.5));
    printf("Element of value 20 is at position: %d\n", sLinkedListSearch(&list, 20));
    printf("Element of value 123 is at position: %d\n", sLinkedListSearch(&list, 123));

    // Get values at specific positions
    printf("Value at position 3: %.2lf\n", sLinkedListGetValue(&list, 3));
    printf("Value at position 8: %.2lf\n", sLinkedListGetValue(&list, 8));

    // Invalid positions
    printf("Value at position 100: %.2lf\n", sLinkedListGetValue(&list, 100));
    printf("Value at position -50: %.2lf\n", sLinkedListGetValue(&list, -50));

    // Delete the first element
    sLinkedListDeletePos(&list, 0);
    sLinkedListPrint(&list);

    // Set value at the first position to 12
    sLinkedListSetValue(&list, 0, 12);
    sLinkedListPrint(&list);

    // Check if the list is empty
    printf("List %s empty\n", sLinkedListIsEmpty(&list) ? "is" : "is not");

    // // Delete all remaining elements
    // while (!sLinkedListIsEmpty(&list)) {
    //     sLinkedListDeleteLast(&list);
    // }
    sLinkedListDeleteList(&list);
    sLinkedListPrint(&list);
    printf("List %s empty\n", sLinkedListIsEmpty(&list) ? "is" : "is not");

    return 0;

}