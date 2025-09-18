#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


// Handle memory allocation failure
_Noreturn static void allocationFailure() {
    fprintf(stderr, "There is not enough memory available.\n");
    exit(EXIT_FAILURE);
}

tree* treeCreate() {
    // allocate memory for tree
    tree* t = malloc(sizeof(tree));
    // check allocation
    if (!t) allocationFailure();
    // initialize root to NULL
    t->root = NULL;
    return t;
}

void treeInsert(tree* t, int key, char data) {
    if (!t) {
        fprintf(stderr, "The tree does not exist.\n");
        return;
    }
    if (!t->root) {
        // case: empty tree, create root
        treeNode* root = malloc(sizeof(treeNode));
        if (!root) allocationFailure();
        root->data = data;
        root->key = key;
        root->leftNode = NULL;
        root->rightNode = NULL;
        t->root = root;
        return;
    }
    treeNode* previousNode = NULL;
    treeNode* currentNode = t->root;

    // search for the correct place to insert
    while (currentNode) {
        if (key > currentNode->key) {
            // go right
            previousNode = currentNode;
            currentNode = currentNode->rightNode;
        }
        else if (key < currentNode->key) {
            // go left
            previousNode = currentNode;
            currentNode = currentNode->leftNode;
        }
        else {
            // key already exists -> update data
            currentNode->data = data;
            return;
        }
    }

    // create the new node
    treeNode* newNode = malloc(sizeof(treeNode));
    if (!newNode) allocationFailure();
    newNode->data = data;
    newNode->key = key;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    // attach node as left or right child
    if (key > previousNode->key) {
        previousNode->rightNode = newNode;
    } else {
        previousNode->leftNode = newNode;
    }
}

// recursive helper for printing tree (rotated 90 degrees)
static void printNode(treeNode* node, int level) {
    if (node) {
        // print right subtree first
        printNode(node->rightNode, level + 5);
        // indentation   
        for (int i = 0; i < level; i++) {
            fprintf(stdout, "  ");
        }
        // print current node
        fprintf(stdout, "%d:%c\n", node->key, node->data);
        // print left subtree
        printNode(node->leftNode, level + 5);
    }
}

// free all nodes recursively
static void freeNode(treeNode* node) {
    if (!node) return;
    freeNode(node->leftNode);
    freeNode(node->rightNode);
    free(node);
}

// calculate height of subtree
static int nodeHeight(treeNode* node) {
    if (!node) return 0;
    // height = 1 + max(left, right)
    return 1 + MAX(nodeHeight(node->leftNode), nodeHeight(node->rightNode));
}

int treeHeight(tree* t) {
    // empty tree -> height 0
    if (!t || !t->root) return 0;
    return nodeHeight(t->root);
}

char treeSearch(tree* t, int key) {
    if (!t) {
        fprintf(stderr, "The tree does not exist.\n");
        return '\0';
    }
    treeNode* currentNode = t->root;
    while (currentNode) {
        if (key > currentNode->key) {
            // go right
            currentNode = currentNode->rightNode;
        }
        else if (key < currentNode->key) {
            // go left
            currentNode = currentNode->leftNode;
        }
        else {
            // found -> return data
            return currentNode->data;
        }
    }
    // not found
    return '\0'; 
}

void treePrint(tree* t) {
    if (t) {
        fprintf(stdout, "=============\n");
        printNode(t->root, 0);
        fprintf(stdout, "=============\n");
    }
}

static treeNode* nodeDelete(treeNode* root, int key) {
    if (!root) return NULL;

    if (key < root->key) {
        // go left
        root->leftNode = nodeDelete(root->leftNode, key);
    }
    else if (key > root->key) {
        // go right
        root->rightNode = nodeDelete(root->rightNode, key);
    }
    else {
        // case 1: no children
        if (!root->leftNode && !root->rightNode) {
            free(root);
            return NULL;
        }
        // case 2: one child (only right)
        else if (!root->leftNode) {
            treeNode* temp = root->rightNode;
            free(root);
            return temp;
        }
        // case 2: one child (only left)
        else if (!root->rightNode) {
            treeNode* temp = root->leftNode;
            free(root);
            return temp;
        }
        // case 3: two children
        else {
            // find smallest in right subtree
            treeNode* succ = root->rightNode;
            while (succ->leftNode) {
                succ = succ->leftNode;
            }
            // copy successor data into current node
            root->key = succ->key;
            root->data = succ->data;
            // delete successor node recursively
            root->rightNode = nodeDelete(root->rightNode, succ->key);
        }
    }
    return root;
}

void treeDelete(tree* t, int key) {
    if (!t) {
        return;
    }
    t->root = nodeDelete(t->root, key);
}

void treeFree(tree* t) {
    if (!t){
        return;
    } 
    if (t->root) {
        // free all nodes
        freeNode(t->root);
    }
    // free tree struct
    free(t);                        
}