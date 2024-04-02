#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

void test_search_node(BST *root, int v) {
    printf("Search %d\n", v);
    BST *p = search_node(root, v);
    print_tree(p);
}

int main() {
    int buffer[1000];
    int num = read_input(buffer, 1000);
    BST *root = create_tree(buffer, num);
    print_tree(root);
    for (int index = 0; index < num; index++) {
        test_search_node(root, buffer[index]);
        test_search_node(root, buffer[index] + 1);
    }
    return 0;
}