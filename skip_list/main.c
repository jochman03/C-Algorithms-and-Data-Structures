#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "skip_list.h"

int main(){
    // Set random seed for level generation
    srand(42);

    // Create a skip list with 5 levels
    skipList* list = skipListCreate(5);

    // Insert 15 elements with keys 1–15 and data 'A'–'O'
    for(int i = 0; i < 15; i++){
        skipListInsert(list, i+1, (char) i + 65);
    }

    // Display the current contents of the skip list
    skipListDisplay(list);

    // Delete the element with key = 7
    skipListDelete(list, 7);

    // Display the list again after deletion
    skipListDisplay(list);

    // Search for element with key = 11 and print its data
    fprintf(stdout, "Element with key: %d has data: %c", 
            11, skipListSearch(list, 11));

    return 0;
}