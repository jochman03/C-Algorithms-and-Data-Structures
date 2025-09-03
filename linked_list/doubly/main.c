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

int main() {
    // Dynamically allocate the doubly linked list
    dLinkedList* list = malloc(sizeof(dLinkedList));
    if (list == NULL) {
        allocationFailure(); // terminate if allocation fails
    }

    // Initialize head and tail pointers
    list->head = NULL;
    list->tail = NULL;

    // Insert values 0, 2.5, 5, ..., 22.5 at the end of the list
    for (int i = 0; i < 10; i++) {
        dLinkedListInsertLast(list, 2.5 * i);
    }

    // Print the list forward and backward
    printf("List (head -> tail):\n");
    dLinkedListPrint(list);
    printf("List (tail -> head):\n");
    dLinkedListPrintReverse(list);

    // Example operations
    dLinkedListPrint(list);

    dLinkedListDeleteFirst(list);
    dLinkedListDeleteLast(list);
    dLinkedListSetValue(list, 0, 12);
    dLinkedListDeletePos(list, 3);

    // Delete the whole list
    dLinkedListDeleteList(list);

    //Check if list is empty
    printf("List %s empty\n", dLinkedListIsEmpty(list) ? "is" : "is not");

    // Free the list structure itself
    free(list);

    return 0;
}