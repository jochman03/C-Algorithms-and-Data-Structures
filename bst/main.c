#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


int main() {
    tree* t = treeCreate();  // create tree

    // insert nodes into tree
    treeInsert(t, 5, 'A');
    treeInsert(t, 3, 'B');
    treeInsert(t, 7, 'C');
    treeInsert(t, 2, 'D');
    treeInsert(t, 4, 'E');
    treeInsert(t, 6, 'F');
    treeInsert(t, 8, 'G');
    treeInsert(t, 12, 'H');

    // print tree
    treePrint(t);    

    // search for a key
    int keyToSearch = 2;
    char result = treeSearch(t, keyToSearch);
    if (result != '\0') {
        fprintf(stdout, "Found data '%c' with key '%d'\n", result, keyToSearch);
    } else {
        fprintf(stdout, "Key '%d' not found\n", keyToSearch);
    }

    // delete a node
    treeDelete(t, 7);
    // print tree again
    treePrint(t);

    // print height of tree
    fprintf(stdout, "The height of tree: %d\n", treeHeight(t));

    // free memory
    treeFree(t);
    return 0;
}
