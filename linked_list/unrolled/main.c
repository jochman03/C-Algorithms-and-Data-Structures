#include <stdio.h>
#include "unrolledLinkedList.h"

int main(){
    // Head pointer for the unrolled linked list
    uLinkedListPtr list = NULL;       
    // Create the list with node capacity 6
    uLinkedListCreate(&list, 6);      
                                    
    // Insert values 1 to 9 into the list
    for(int i = 1; i < 10; i++){
        uLinkedListInsert(&list, i);
    }
    // Print the current state of the list
    uLinkedListPrint(&list);
    // Search for value 9 and print its index
    printf("Value 9 is at index %d\n", uLinkedListSearch(&list, 9));
    // Get the value at index 4 and print it
    printf("Value at index 4 is: %.2lf\n", uLinkedListGet(&list, 4));
    // Insert value 10 into the list
    uLinkedListInsert(&list, 10);     
    // Delete the element at index 3
    uLinkedListDelete(&list, 3);      
    // Print the list
    uLinkedListPrint(&list);          
    // Delete entire list and free memory
    uLinkedListDeleteList(&list);     

    return 0;
}