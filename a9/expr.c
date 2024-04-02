#include <stdio.h>
#include <stdlib.h>

// #include "expr.h"
#include "../distribution/assignments/a9/src/expr.h"

/**
 * The programs should only use only the following library routines:

    atoi()
    exit()
    malloc()
    printf()
    scanf()
    strcmp()

Do not use any other library functions.
*/


// tested
Expr *get_next_expr_node()
{
    char* str = malloc(sizeof(char) * 100);
    Expr *expr = malloc(sizeof(Expr));

    if (scanf("%s", str) == EOF)
    {
        expr->type = END;
    }
    else
    {
        if (str[0] == '+')
        {
            expr->type = ADD;
        }
        else if (str[0] == '-')
        {
            expr->type = SUB;
        }
        else if (str[0] == '*')
        {
            expr->type = MUL;
        }
        else if (str[0] != '\n')
        {
            expr->u.val = atoi(str);
            expr->type = NUMBER;
        }
        else
        {
            expr->type = END;
        }
    }

    // todo: printing extra spac. i think we r making an exra node over here. or we r making an empty node of the final END node that is empty in get_all
    // printf("expr->type: %d\n", expr->type);
    // printf("expr->u.val: %d\n", expr->u.val);

    return expr;
}

// tested
List *get_all_expr_nodes()
{
    List *head = malloc(sizeof(List));

    List *current = head;
    current->expr = get_next_expr_node();
    current->next = NULL;

    while (current->expr->type != END)
    {
        List *new_node = malloc(sizeof(List));
        new_node->expr = get_next_expr_node();
        new_node->next = NULL;

        current->next = new_node;
        current = new_node;
    }

    return head;
}


// tested
void print_expr_node(Expr* expr) {
    if (expr->type == NUMBER) {
        printf("%d", expr->u.val);
    } else if (expr->type == ADD) {
        printf("+");
    } else if (expr->type == SUB) {
        printf("-");
    } else if (expr->type == MUL) {
        printf("*");
    } else if (expr->type == DIV) {
        printf("/");
    } 
}

/**
 * THIS IS LIKELY A DIFFICULT FUNCTION TO IMPLEMENT.

This function will take a pointer to a Stack of Expr nodes and a pointer to an Expr node that needs to be added to the stack.

NUMBER nodes will be added to the top of the stack.

This function is responsible for filling in the left and right fields of binary operator Expr nodes that is being added to the stack and then pushing it onto the stack. It does this by popping the top two elements of the stack and using those expressions as the left and right fields, and then pushing the new Expr node onto the stack.

It will return a pointer to a new Stack that includes the new Expr node.
*/
// Stack* add_node_to_expr_stack(Stack* stack, Expr* expr);

/**
 * Given an Expr node that represents a binary expression, this function will print the expression in fully parenthesized form. For example, the expression 3 4 + would be printed as (3 + 4).
 */
// void print_fully_parenthesized_expr(Expr* expr);

/**
 * Given an Expr node that represents a binary expression, this function will print the expression in minimally parenthesized form. For example, the expression 3 4 + would be printed as 3 + 4.
 */
// void print_minimally_parenthesized_expr(Expr* expr);
