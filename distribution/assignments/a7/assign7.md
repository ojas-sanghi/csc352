
<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 7: Lists

Version 1.0 (2024-03-05) - Initial version


## Due Date:

* Friday, 2024-03-22, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

## Create a directory for this assignment called `a7`

## Write C Program(s):

For this assignment, you will create three C programs.  

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

* `getchar()`
* `putchar()`
* `fgets()`
* `printf()`
* `strlen()`
* `scanf()`
* `exit()`
* `malloc()`
* `free()`
* `strcmp()`

**Do not use any other library functions.**

### linked.h

You will be creating a file, `linked.c`, that will implement the functions declared in `linked.h`.  This file will contain the following functions:

```c
typedef struct node {
    char* word;
    struct node *next;
} Node;

extern char *get_word();
extern Node *create_node(char *str, Node *next);
extern Node *read_list();
extern void print_list(Node *head);

extern Node *inorder(Node *head, Node *node);

extern Node *sort_list(Node *head);
```

### linked.c

The `linked.c` file should contain the implementations of the functions declared in `linked.h`.  The functions should be implemented as follows:

#### `char *get_word()`
This function should read a word from standard input and return a pointer to a dynamically allocated array of characters that contains the word.  The function should return `NULL` if there are no more words to read.

#### `Node *create_node(char *str, Node *next)`
This function should create a new node with the given word and next pointer.  The function should return a pointer to the new node.

#### `Node *read_list()`
This function should read a sequence words from standard input and return a pointer to the head of the linked list containing those words.  The list should be stored in the order that the words are read.

#### `void print_list(Node *head)`
This function should print the words in the linked list, one per line.

#### `Node *inorder(Node *head, Node *node)`
This function should insert the given node into the linked list in alphabetical order.  The function should return a pointer to the head of the list.

Alphabetical order should be determined with the C library's `strcmp()` function.


#### `Node *sort_list(Node *head)`
This function should sort the linked list in alphabetical order.  The function should return a pointer to the head of the list.

It should not create a new list, but rather rearrange the pointers in the existing list.

It should not use any additional memory, other than a few pointers.  It should definitely not use any arrays.


### list.c

You will be given a file, `list.c`, that contains the `main()` function for `list` executable.
This file will read a sequence of words from standard input and store them in a linked list.
It will then call the `print_list()` function to print the list.

It will be tested separately.  It will be compiled with `linked.c` to create the executable `list`:
    
    ```bash
    cc -Wall -o list list.c linked.c
    ```


### inorder.c

You will be given a file, `inorder.c`, that contains the `main()` function.  This file will read a sequence of words from standard input and store them in a linked list.  It will then call the `inorder()` function to insert the words in alphabetical order.  Finally, it will call the `print_list()` function to print the list.

### sortlist.c

You will be given a file, `sortlist.c`, that contains the `main()` function.  This file will read a sequence of words from standard input and store them in a linked list.  It will then call the `sort_list()` function to sort the list in alphabetical order.  Finally, it will call the `print_list()` function to print the list.

### distribution/assignments/a7/src directory

You will find the following files in the `distribution/assignments/a7/src` directory:

* `linked.h` - This file contains the declarations of the functions you will implement in `linked.c`.
* `list.c` - This file contains the `main()` function for the `list` executable.
* `inorder.c` - This file contains the `main()` function for the `inorder` executable.
* `sortlist.c` - This file contains the `main()` function for the `sortlist` executable.



## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
 ../distribution/assignments/a7/test.sh ./list ../distribution/assignments/a7/tests.list
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in `linked.c` to Gradescope for Assignment A7.

