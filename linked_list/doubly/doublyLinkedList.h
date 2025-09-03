#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
/**
 * Structure representing a node in a doubly linked list.
 */
typedef struct dLinkedListNode {
    double value;                 /** Value stored in the node */
    struct dLinkedListNode* next; /** Pointer to the next node in the list */
    struct dLinkedListNode* prev; /** Pointer to the previous node in the list */
} dLinkedListNode, *dLinkedListPtr;

/**
 * Structure representing the doubly linked list itself.
 * Stores pointers to the head and tail of the list.
 */
typedef struct {
    dLinkedListPtr head; /** Pointer to the first node of the list */
    dLinkedListPtr tail; /** Pointer to the last node of the list */
} dLinkedList;

/**
 * Insert a new node with the given value at the beginning of the list.
 *
 * @param list Pointer to the doubly linked list
 * @param value Value to insert
 */
void dLinkedListInsertFirst(dLinkedList* list, double value);

/**
 * Insert a new node with the given value at the end of the list.
 *
 * @param list Pointer to the doubly linked list
 * @param value Value to insert
 */
void dLinkedListInsertLast(dLinkedList* list, double value);

/**
 * Check if the list is empty.
 *
 * @param list Pointer to the doubly linked list
 * @return 1 if the list is empty, 0 otherwise, -1 if the list pointer is NULL
 */
int dLinkedListIsEmpty(dLinkedList* list);

/**
 * Search for a value in the list.
 *
 * @param list Pointer to the doubly linked list
 * @param value Value to search for
 * @return Position of the value if found, -1 otherwise
 */
int dLinkedListSearch(dLinkedList* list, double value);

/**
 * Get the value at the given position in the list.
 *
 * @param list Pointer to the doubly linked list
 * @param pos Position of the node
 * @return Value at the position, or -1 if position is invalid
 */
double dLinkedListGetValue(dLinkedList* list, int pos);

/**
 * Set the value of the node at the given position.
 *
 * @param list Pointer to the doubly linked list
 * @param pos Position of the node
 * @param value Value to set
 */
void dLinkedListSetValue(dLinkedList* list, int pos, double value);

/**
 * Delete the first node of the list.
 *
 * @param list Pointer to the doubly linked list
 */
void dLinkedListDeleteFirst(dLinkedList* list);

/**
 * Delete the node at the given position.
 *
 * @param list Pointer to the doubly linked list
 * @param pos Position of the node to delete
 */
void dLinkedListDeletePos(dLinkedList* list, int pos);

/**
 * Delete the last node of the list.
 *
 * @param list Pointer to the doubly linked list
 */
void dLinkedListDeleteLast(dLinkedList* list);

/**
 * Delete all nodes and clear the list.
 *
 * @param list Pointer to the doubly linked list
 */
void dLinkedListDeleteList(dLinkedList* list);

/**
 * Print the list from head to tail.
 *
 * @param list Pointer to the doubly linked list
 */
void dLinkedListPrint(dLinkedList* list);

/**
 * Print the list from tail to head.
 *
 * @param list Pointer to the doubly linked list
 */
void dLinkedListPrintReverse(dLinkedList* list);


#endif //SINGLYLINKEDLIST_H