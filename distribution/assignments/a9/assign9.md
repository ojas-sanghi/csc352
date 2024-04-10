<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 9: Postfix Expressions

Version 1.0 (2024-03-24) - Initial version


## Due Date:

* Friday, 2024-04-05, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

## Create a directory for this assignment called `a9`

## General Idea

Arithmetic expressions are typically written in infix notation, where the operator is placed between the operands.  For example, the infix expression `3 + 4` is a simple binary expression.

Expressions can also be written equivalently in postfix expression like `3 4 +`.  In postfix notation, the operator is placed after the operands.

In this assignment, you will write a program that reads a list of postfix expressions from standard input, and then prints them in infix notation.

In this assignment, the expressions will be binary expressions, with only the operators `+`, `-`, and `*`, as well as integer operands.  For instance, here are some equivalent infix and postfix expressions:

Infix: `3 + 4`
Postfix: `3 4 +`

Infix: `3 * 4 + 5`
Postfix: `3 4 * 5 +`

Infix: `3 + 4 * 5`
Postfix: `3 4 5 * +`

Infix: `(3 + 4) * 5`
Postfix: `3 4 + 5 *`

Infix: `3 * (4 + 5)`
Postfix: `3 4 5 + *`

## Write C Program(s):

For this assignment, you will write one C file, which will be used by three different C programs.  

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

* `atoi()`
* `exit()`
* `malloc()`
* `printf()`
* `scanf()`
* `strcmp()`

**Do not use any other library functions.**

### Provided files: expr.h fully.c minimal.c read.c

You are provided with the following files, which you should not modify:

* `expr.h` - This file contains the following definitions:
    * the `Expr` struct
    * the `List` struct, for a linked list of `Expr` nodes
    * the `Stack` struct, for a stack of `Expr` nodes
    * the function prototypes for the functions you will implement.
* `read.c` - This file contains a main function that will use your routines to read a list of `Expr` nodes into a linked list and to print that list.
* `fully.c` - This file contains a main function that read a list of `Expr` nodes, convert them into a tree, and then print the expression in a fully parenthesized fashion.
* `minimal.c` - This file contains a main function that is similar to `fully.c`, except that it will print the expression with as few parentheses as possible.

DO NOT MODIFY THESE FILES.

### expr.h

`expr.h` contains the definition of many structures for manipulating expression trees.
The expression tree nodes will include a `union` becasue some nodes represent simple integers,
and other nodes represent binary expression nodes (e.g., multiplication).

The "type" of the node will be stored in the `type` field of the `Expr` struct, and the value of the node will be stored in the `u` union.

```c
typedef enum exprType {
  NONE = 0,
  NUMBER,
  ADD,
  SUB,
  MUL,
  END,
} ExprType;

typedef struct expr {
  ExprType type;
  union {
    int val;
    struct {
      struct expr* left;
      struct expr* right;
    } binop;
  } u;
} Expr;
```

In addition to those types, your programs will need to maintain a list of expression nodes, and a stack of expression nodes.  Those structures follow:

```c
typedef struct stack {
  Expr* expr;
  struct stack* below;
} Stack;

typedef struct list {
  Expr* expr;
  struct list* next;
} List;
```

Finally, your program will need to implement 6 functions, which are prototyped in `expr.h`:

```c
extern Expr* get_next_expr_node();
extern List* get_all_expr_nodes();
extern void print_expr_node(Expr* expr);

extern Stack* add_node_to_expr_stack(Stack* stack, Expr* expr);
extern void print_fully_parenthesized_expr(Expr* expr);

extern void print_minimally_parenthesized_expr(Expr* expr);
```

The first three are needed for `read.c`.

The first five are needed for `fully.c`.

All six are needed for `minimal.c`.

I suggest you implement these functions in the order they are listed.

#### `Expr* get_next_expr_node()`
`get_next_expr_node` will read the next integer or operator from standard input and return a pointer to a new `Expr` node representing that expression.  

* If the input is an integer, the `type` field of the `Expr` node should be set to `NUMBER`, and the value of the integer should be stored in the `val` field of the `u` union.  
* If the input is an operator, the `type` field of the `Expr` node should be set to `ADD`, `SUB`, or `MUL`.  This function will *not*, however, try to fill in the `left` and `right` fields of the `u` union.  That will be done later.

#### `List* get_all_expr_nodes()`
`get_all_expr_nodes` will read all of the expressions from standard input and return a linked list of `Expr` nodes.  This function should call `get_next_expr_node` repeatedly until it returns an `Expr` node with a `type` of `END`.  The `next` field of the last `Expr` node in the list should be set to `NULL`.

The list should NOT include the `END` node.

#### `void print_expr_node(Expr* expr)`
`print_expr_node` will print the expression represented by the `Expr` node to standard output.

* If the `type` of the `Expr` node is `NUMBER`, then the integer value should be printed.
* If the `type` of the `Expr` node is `ADD`, `SUB`, or `MUL`, then the operator should be printed.  This function will *not*, however, print the `left` and `right` fields of the `u` union.  That will be done later.

#### `Stack* add_node_to_expr_stack(Stack* stack, Expr* expr)`
THIS IS LIKELY A DIFFICULT FUNCTION TO IMPLEMENT.  

This function will take a pointer to a `Stack` of `Expr` nodes and a pointer to an `Expr` node that needs
to be added to the stack.

`NUMBER` nodes will be added to the top of the stack.

This function is responsible for filling in the `left` and `right` fields of binary operator `Expr` nodes that is being added to the stack and then pushing it onto the stack.  It does this by popping the top two elements of the stack and using those expressions as the `left` and `right` fields, and then pushing the new `Expr` node onto the stack.

It will return a pointer to a new `Stack` that includes the new `Expr` node.

#### `void print_fully_parenthesized_expr(Expr* expr)`
Given an `Expr` node that represents a binary expression, this function will print the expression in fully parenthesized form.  For example, the expression `3 4 +` would be printed as `(3 + 4)`.

#### `void print_minimally_parenthesized_expr(Expr* expr)`
Given an `Expr` node that represents a binary expression, this function will print the expression in minimally parenthesized form.  For example, the expression `3 4 +` would be printed as `3 + 4`.

Here are some examples:

Fully parenthesized: `3 4 +` -> `(3 + 4)`
Minimally parenthesized: `3 4 +` -> `3 + 4`

Fully parenthesized: `3 4 5 + *` -> `(3 * (4 + 5))`
Minimally parenthesized: `3 4 5 + *` -> `3 * (4 + 5)`

Fully parenthesized: `3 4 5 * +` -> `(3 + (4 * 5))`
Minimally parenthesized: `3 4 5 * +` -> `3 + 4 * 5`

Fully parenthesized: `3 4 + 5 *` -> `((3 + 4) * 5)`
Minimally parenthesized: `3 4 + 5 *` -> `(3 + 4) * 5`

Fully parenthesized: `3 4 + 5 6 + *` -> `((3 + 4) * (5 + 6))`
Minimally parenthesized: `3 4 + 5 6 + *` -> `(3 + 4) * (5 + 6)`

Note that we will treat the binary operators as left-associative, so

Fully parenthesized: `3 4 + 5 +` -> `((3 + 4) + 5)`
Minimally parenthesized: `3 4 + 5 +` -> `3 + 4 + 5`

Fully parenthesized: `3 4 5 + +` -> `(3 + (4 + 5))`
Minimally parenthesized: `3 4 5 + +` -> `3 + (4 + 5)`



## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o read read.c expr.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./read < ../distribution/assignment/a9/tests.read/t101.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
../distribution/assignments/a9/test.sh ./read ../distribution/assignments/a9/tests.read
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in all `expr.c` to Gradescope for Assignment A9.

