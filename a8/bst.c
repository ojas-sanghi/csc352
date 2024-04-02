#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
// #include "../distribution/assignments/a8/src/bst.h"

int read_input(int *arr, int n)
{
    int numRead = 0;
    int buf;

    while (scanf("%d", &buf) != EOF)
    {
        *(arr + numRead) = buf;
        numRead++;
    }

    return numRead;
}


BST *create_node(int value, BST *left, BST *right)
{
    BST *node = malloc(sizeof(BST));

    node->value = value;
    node->left = left;
    node->right = right;

    return node;
}


void print_helper(BST *root)
{
    printf("(");

    if (root->left == NULL)
        printf("-");
    else
        print_helper(root->left);

    printf("%d", root->value);

    if (root->right == NULL)
        printf("-");
    else
        print_helper(root->right);

    printf(")");
}


void print_tree(BST *root)
{
    if (root == NULL)
    {
        printf("NULL\n");
        return;
    }

    print_helper(root);
    printf("\n");
}


BST *insert_node(BST *root, BST *node)
{
    if (root == NULL)
        return node;

    if (node->value < root->value)
        root->left = insert_node(root->left, node);
    else
        root->right = insert_node(root->right, node);

    return root;
}


BST *create_tree(int *arr, int n)
{
    BST *root = NULL;

    for (int i = 0; i < n; i++)
    {
        BST *node = create_node(arr[i], NULL, NULL);
        root = insert_node(root, node);
    }

    return root;
}


BST *remove_min(BST *root, BST **min)   
{
    if (root->left == NULL)
    {
        *min = root;
        return root->right;
    }

    root->left = remove_min(root->left, min);

    return root;
}


BST *delete_node(BST *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->value)
        root->left = delete_node(root->left, value);
    else if (value > root->value)
        root->right = delete_node(root->right, value);
    else
    {
        // return either sub-tree if it's that easy
        if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }

        // swap value of root with the value of the minimum node in the right sub-tree
        // and set right sub-tree to be itself without said minimum node
        BST *min;
        root->right = remove_min(root->right, &min);

        root->value = min->value;

        free(min);
    }

    return root;
}


BST *search_node(BST *root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->value == value)
        return root;

    if (value < root->value)
        return search_node(root->left, value);
    else
        return search_node(root->right, value);
}
