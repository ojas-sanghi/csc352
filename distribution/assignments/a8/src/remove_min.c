#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

int main() {
    int buffer[1000];
    int num = read_input(buffer, 1000);
    BST *root = create_tree(buffer, num);
    print_tree(root);
    while (root != NULL) {
        BST *min;
        root = remove_min(root, &min);
        printf("Min value: %d\n", min->value);
        print_tree(root);
    }
    return 0;
}