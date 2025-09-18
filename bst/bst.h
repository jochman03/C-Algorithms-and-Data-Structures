/**
 * Macro that returns the larger of (a) and (b).
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Structure representing a node in a binary tree.
 */
typedef struct treeNode {
    int key;                      /** Key used for ordering the nodes */
    char data;                    /** Data stored in the node */
    struct treeNode* leftNode;    /** Pointer to the left child node */
    struct treeNode* rightNode;   /** Pointer to the right child node */
} treeNode;

/**
 * Structure representing a binary tree.
 */
typedef struct tree {
    treeNode* root;               /** Pointer to the root node */
} tree;

/**
 * Create a new empty binary tree.
 *
 * @return Pointer to the newly created tree
 */
tree* treeCreate();

/**
 * Insert a node into the binary tree. If a node with the same key exists,
 * its data will be updated.
 *
 * @param t Pointer to the tree
 * @param key Key for the new node
 * @param data Data to store in the node
 */
void treeInsert(tree* t, int key, char data);

/**
 * Compute the height of the binary tree.
 *
 * @param t Pointer to the tree
 * @return Height of the tree (0 if empty)
 */
int treeHeight(tree* t);

/**
 * Search for a node with the given key in the binary tree.
 *
 * @param t Pointer to the tree
 * @param key Key to search for
 * @return Data stored in the node if found, '\0' otherwise
 */
char treeSearch(tree* t, int key);

/**
 * Print the binary tree structure to stdout.
 *
 * @param t Pointer to the tree
 */
void treePrint(tree* t);

/**
 * Delete a node with the given key from the binary tree.
 *
 * @param t Pointer to the tree
 * @param key Key of the node to delete
 */
void treeDelete(tree* t, int key);

/**
 * Free all memory associated with the binary tree.
 *
 * @param t Pointer to the tree
 */
void treeFree(tree* t);

