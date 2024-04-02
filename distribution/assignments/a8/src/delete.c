#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

int main() {
    int buffer[1000];
    int num = read_input(buffer, 1000);
    BST *root = create_tree(buffer, num);
    print_tree(root);
    int index = 0;
    for (int index = 0; root != NULL; index = (index + 1117) % num) {
        printf("Delete %d\n", buffer[index]);
        root = delete_node(root, buffer[index]);
        print_tree(root);
    }
    return 0;
}