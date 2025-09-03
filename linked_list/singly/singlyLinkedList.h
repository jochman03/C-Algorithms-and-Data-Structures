#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

/**
 * Structure representing a node in a singly linked list.
 */
typedef struct sLinkedListNode {
    double value;                 /** Value stored in the node */
    struct sLinkedListNode* next; /** Pointer to the next node */
} sLinkedListNode, *sLinkedListPtr;

/**
 * Insert a new node with the given value at the beginning of the list.
 *
 * @param head Pointer to the head pointer of the list
 * @param value Value to insert
 */
void sLinkedListInsertFirst(sLinkedListPtr* head, double value);

/**
 * Insert a new node with the given value at the end of the list.
 *
 * @param head Pointer to the head pointer of the list
 * @param value Value to insert
 */
void sLinkedListInsertLast(sLinkedListPtr* head, double value);

/**
 * Check if the list is empty.
 *
 * @param head Pointer to the head pointer of the list
 * @return 1 if empty, 0 otherwise
 */
int sLinkedListIsEmpty(sLinkedListPtr* head);

/**
 * Search for a value in the list.
 *
 * @param head Pointer to the head pointer of the list
 * @param value Value to search for
 * @return index of given value if found, -1 otherwise
 */
int sLinkedListSearch(sLinkedListPtr* head, double value);

/**
 * Get the value of the node at a specific position.
 *
 * @param head Pointer to the head pointer of the list
 * @param pos Position of the node
 * @return Value at the given position
 */
double sLinkedListGetValue(sLinkedListPtr* head, int pos);

/**
 * Set the value of the node at a specific position.
 *
 * @param head Pointer to the head pointer of the list
 * @param pos Position of the node
 * @param value New value to set
 */
void sLinkedListSetValue(sLinkedListPtr* head, int pos, double value);

/**
 * Delete the first node in the list.
 *
 * @param head Pointer to the head pointer of the list
 */
void sLinkedListDeleteFirst(sLinkedListPtr* head);

/**
 * Delete the node at a specific position.
 *
 * @param head Pointer to the head pointer of the list
 * @param pos Position of the node
 */
void sLinkedListDeletePos(sLinkedListPtr* head, int pos);

/**
 * Delete the last node in the list.
 *
 * @param head Pointer to the head pointer of the list
 */
void sLinkedListDeleteLast(sLinkedListPtr* head);

/**
 * Delete the entire linked list and free all allocated memory.
 *
 * @param head Pointer to the head pointer of the list
 */
void sLinkedListDeleteList(sLinkedListPtr* head);


/**
 * Print all values in the list to stdout.
 *
 * @param head Pointer to the head pointer of the list
 */
void sLinkedListPrint(sLinkedListPtr* head);

#endif //SINGLYLINKEDLIST_H