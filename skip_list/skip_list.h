#ifndef SKIP_LIST_H
#define SKIP_LIST_H

/**
 * Structure representing an element in the skip list.
 */
typedef struct skipListElement {
    unsigned int levels;            /** Number of levels this element spans */
    int key;                        /** Key used to order the element */
    char data;                      /** Data stored in the element */
    struct skipListElement** ptrs;  /** Forward pointers to other elements */
    bool isHead;                    /** Flag indicating if this element is the head */
} skipListElement;

/**
 * Structure representing the skip list.
 */
typedef struct skipList {
    unsigned int maxLevels;   /** Maximum number of levels in the list */
    skipListElement* head;    /** Pointer to the head element */
} skipList;

/**
 * Search for an element by key in the skip list.
 *
 * @param list Pointer to the skip list
 * @param key  Key to search for
 * @return Data stored in the element if found, otherwise '\0'
 */
char skipListSearch(skipList* list, int key);

/**
 * Create a new skip list.
 *
 * @param maxLevels Maximum number of levels for the skip list
 * @return Pointer to the newly created skip list
 */
skipList* skipListCreate(unsigned int maxLevels);

/**
 * Delete an element with the specified key from the skip list.
 *
 * @param list Pointer to the skip list
 * @param key  Key of the element to delete
 */
void skipListDelete(skipList* list, int key);

/**
 * Insert a new element into the skip list.
 *
 * @param list Pointer to the skip list
 * @param key  Key of the new element
 * @param data Data character to store in the new element
 */
void skipListInsert(skipList* list, int key, char data);

/**
 * Display the contents of the skip list by level.
 *
 * @param list Pointer to the skip list
 */
void skipListDisplay(skipList* list);

#endif //SKIP_LIST