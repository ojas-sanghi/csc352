#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked.h"

int main() {
    Node * head = read_list();
    print_list(head);
    return 0;
}