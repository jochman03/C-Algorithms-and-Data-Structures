#ifndef UNROLLEDLINKEDLIST_H
#define UNROLLEDLINKEDLIST_H
/**
 * Structure representing a node in an unrolled linked list.
 */
typedef struct uLinkedListNode {
    double* values;               /** Array of values stored in the node */
    int used;                     /** Number of elements currently used in the node */
    int capacity;                 /** Maximum capacity of the node */
    struct uLinkedListNode* next; /** Pointer to the next node */
} uLinkedListNode, *uLinkedListPtr;

/**
 * Create a new unrolled linked list node with the given capacity.
 *
 * @param head Pointer to the head pointer of the list
 * @param size Capacity of each node
 */
void uLinkedListCreate(uLinkedListPtr* head, int size);

/**
 * Insert a value into the unrolled linked list.
 *
 * @param head Pointer to the head pointer of the list
 * @param value Value to insert
 */
void uLinkedListInsert(uLinkedListPtr* head, double value);

/**
 * Delete the entire unrolled linked list and free all allocated memory.
 *
 * @param head Pointer to the head pointer of the list
 */
void uLinkedListDeleteList(uLinkedListPtr* head);

/**
 * Get the value at a specific index in the unrolled linked list.
 *
 * @param head Pointer to the head pointer of the list
 * @param index Index of the value (0-based)
 * @return Value at the given index, or -1 if index is out of bounds
 */
double uLinkedListGet(uLinkedListPtr* head, int index);

/**
 * Delete the element at a specific index in the unrolled linked list.
 *
 * @param head Pointer to the head pointer of the list
 * @param index Index of the element to delete (0-based)
 */
void uLinkedListDelete(uLinkedListPtr* head, int index);

/**
 * Search for a value in the unrolled linked list.
 *
 * @param head Pointer to the head pointer of the list
 * @param value Value to search for
 * @return Index of the first occurrence, or -1 if not found
 */
int uLinkedListSearch(uLinkedListPtr* head, double value);

/**
 * Check if the unrolled linked list is empty.
 *
 * @param head Pointer to the head pointer of the list
 * @return 1 if empty, 0 otherwise
 */
int uLinkedListIsEmpty(uLinkedListPtr* head);

/**
 * Print all elements in the unrolled linked list.
 *
 * @param head Pointer to the head pointer of the list
 */
void uLinkedListPrint(uLinkedListPtr* head);

#endif //UNROLLEDLINKEDLIST_H