typedef struct bst {
    int value;
    struct bst *left;
    struct bst *right;
} BST;

extern int read_input(int *arr, int n);
extern BST *create_node(int value, BST *left, BST *right);
extern BST *create_tree(int *arr, int n);
extern BST *insert_node(BST *root, BST *node);
extern void print_tree(BST *root);
extern BST *remove_min(BST *root, BST **min);
extern BST *delete_node(BST *root, int value);
extern BST *search_node(BST *root, int value);
