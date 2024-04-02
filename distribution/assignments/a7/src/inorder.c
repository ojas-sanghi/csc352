#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked.h"


int main() {
    Node *head = NULL;
    char *str;
    while ((str = get_word()) != NULL) {
        Node *p = create_node(str, NULL);
        head = inorder(head, p);
    }
    print_list(head);
    return 0;
}