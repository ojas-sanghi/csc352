#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
  int buffer[1000];
  int num = read_input(buffer, 1000);
  BST* root = create_tree(buffer, num);
  print_tree(root);

  printf("Insert 10\n");
  BST* fifty = create_node(10, NULL, NULL);
  root = insert_node(root, fifty);
  print_tree(root);
  return 0;
}