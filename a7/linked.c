#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked.h"
// #include "../distribution/assignments/a7/src/linked.h"

char *get_word()
{
    char buf[100];
    if (scanf("%s", buf) == EOF)
    {
        return NULL;
    }
    else
    {
        char *word = malloc(strlen(buf));
        strcpy(word, buf);
        return word;
    }
}

Node *create_node(char *str, Node *next)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->word = str;
    new_node->next = next;
    return new_node;
}

struct node *read_list()
{
    char buf[1000];

    struct node *last;
    struct node head;
    head.next = NULL;
    last = &head;

    while (scanf("%s", buf) != EOF)
    {
        // Copying
        char *s = malloc(strlen(buf) + 1);
        strcpy(s, buf);

        // node allocation
        struct node *p = malloc(sizeof(struct node));
        p->word = s;
        p->next = NULL;

        // set last node
        last->next = p;
        last = p;
    }
    return head.next;
}

void print_list(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%s\n", current->word);
        current = current->next;
    }
}

Node *inorder(Node *head, Node *node)
{
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL && strcmp(current->word, node->word) < 0)
    {
        prev = current;
        current = current->next;
    }

    // must insert at start of the linked list
    if (prev == NULL)
    {
        node->next = head;
        return node;
    }
    else
    {
        prev->next = node;
        node->next = current;
        return head;
    }
}

Node *sort_list(Node *head)
{
    Node *curr, *prev, *temp;
    int swapped;

    if (head == NULL || head->next == NULL)
        return head; // List is empty or has only one node, no need to sort

    do
    {
        swapped = 0;
        prev = NULL;
        curr = head;

        while (curr->next != NULL)
        {
            if (strcmp(curr->word, curr->next->word) > 0)
            {
                // Swap nodes
                if (prev == NULL)
                {
                    // Swap the head node
                    temp = curr->next;
                    curr->next = temp->next;
                    temp->next = curr;
                    head = temp;
                }
                else
                {
                    // Swap middle nodes
                    temp = curr->next;
                    prev->next = temp;
                    curr->next = temp->next;
                    temp->next = curr;
                }
                swapped = 1;
                prev = temp; // Update prev to the new node
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped);

    return head;
}