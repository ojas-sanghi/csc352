typedef struct node {
    char* word;
    struct node *next;
} Node;

extern char *get_word();
extern Node *create_node(char *str, Node *next);
extern Node *read_list();
extern void print_list(Node *head);

extern Node *inorder(Node *head, Node *node);

extern Node *sort_list(Node *head);
