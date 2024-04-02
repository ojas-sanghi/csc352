#include <stdio.h>
#include <stdlib.h>

#include "expr.h"
// #include "../distribution/assignments/a9/src/expr.h"

Expr *get_next_expr_node()
{
    char *str = malloc(sizeof(char) * 100);
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
    }

    return expr;
}

List *get_all_expr_nodes()
{
    List *head = malloc(sizeof(List));

    List *current = head;
    current->expr = get_next_expr_node();
    current->next = NULL;

    Expr *expr;

    while ((expr = get_next_expr_node())->type != END)
    {
        List *new_node = malloc(sizeof(List));
        new_node->expr = expr;
        new_node->next = NULL;

        current->next = new_node;
        current = new_node;
    }

    return head;
}

void print_expr_node(Expr *expr)
{
    if (expr->type == NUMBER)
    {
        printf("%d", expr->u.val);
    }
    else if (expr->type == ADD)
    {
        printf("+");
    }
    else if (expr->type == SUB)
    {
        printf("-");
    }
    else if (expr->type == MUL)
    {
        printf("*");
    }
    else if (expr->type == DIV)
    {
        printf("/");
    }
}


Stack* add_node_to_expr_stack(Stack* stack, Expr* expr) {
    
    if (expr->type == NUMBER) {
        Stack* new_stack = malloc(sizeof(Stack));
        new_stack->expr = expr;
        new_stack->below = stack;
        return new_stack;
    }

    Expr* expr1 = stack->expr;

    stack = stack->below;

    Expr* expr2 = stack->expr;
    stack = stack->below;

    expr->u.binop.right = expr1;
    expr->u.binop.left = expr2;

    Stack* new_stack = malloc(sizeof(Stack));
    new_stack->expr = expr;
    new_stack->below = stack;

    return new_stack;
}

void print_fully_parenthesized_expr(Expr* expr)
{
    if (expr->type == NUMBER)
    {
        printf("%d", expr->u.val);
    }
    else
    {
        printf("(");
        print_fully_parenthesized_expr(expr->u.binop.left);
        if (expr->type == ADD)
        {
            printf("+");
        }
        else if (expr->type == SUB)
        {
            printf("-");
        }
        else if (expr->type == MUL)
        {
            printf("*");
        }
        else if (expr->type == DIV)
        {
            printf("/");
        }
        print_fully_parenthesized_expr(expr->u.binop.right);
        printf(")");
    }
}


void print_minimally_parenthesized_expr(Expr* expr)
{
    if (expr->type == NUMBER)
    {
        printf("%d", expr->u.val);
    }
    else
    {
        if ((expr->u.binop.left->type == ADD || expr->u.binop.left->type == SUB) && expr->type == MUL)
        {
            printf("(");
            print_minimally_parenthesized_expr(expr->u.binop.left);
            printf(")");
        }
        else
        {
            print_minimally_parenthesized_expr(expr->u.binop.left);
        }

        if (expr->type == ADD)
        {
            printf("+");
        }
        else if (expr->type == SUB)
        {
            printf("-");
        }
        else if (expr->type == MUL)
        {
            printf("*");
        }
        else if (expr->type == DIV)
        {
            printf("/");
        }

        if (expr->type == MUL && expr->u.binop.right->type != NUMBER)
        {
            printf("(");
            print_minimally_parenthesized_expr(expr->u.binop.right);
            printf(")");
        }
        else if ((expr->type == ADD || expr->type == SUB) && (expr->u.binop.right->type == ADD || expr->u.binop.right->type == SUB))
        {
            printf("(");
            print_minimally_parenthesized_expr(expr->u.binop.right);
            printf(")");
        }
        else
        {
            print_minimally_parenthesized_expr(expr->u.binop.right);
        }
    }
        
}
