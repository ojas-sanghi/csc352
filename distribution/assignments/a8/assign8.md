<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 8: Binary Search Trees

Version 1.0 (2024-03-05) - Initial version


## Due Date:

* Friday, 2024-03-29, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

## Create a directory for this assignment called `a8`

## Write C Program(s):

For this assignment, you will write one C file, which will be used by four different C programs.  

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

**Do not use any other library functions.**

### Provided files: bst.h build.c search.c remove_min.c delete.c

You are provided with the following files, which you should not modify:

* `bst.h` - This file contains the definition of the `BST` struct and the function prototypes for the functions you will implement.
* `build.c` - This file contains a main function that will use your routines to build a binary search tree from a sequence of integers read from standard input, and print that tree.
* `search.c` - This file contains a main function that will use your routines to build a binary search tree from a sequence of integers read from standard input, and then search for values in that tree.
* `remove_min.c` - This file contains a main function that will use your routines to build a binary search tree from a sequence of integers read from standard input, and then remove the minimum value from that tree.
* `delete.c` - This file contains a main function that will use your routines to build a binary search tree from a sequence of integers read from standard input, and then delete values from that tree.

DO NOT MODIFY THESE FILES.

### bst.h

`bst.h` contains the definition of a binary search tree for storing integers.  It looks like this:

```c
typedef struct bst {
    int value;
    struct bst *left;
    struct bst *right;
} BST;
```

### bst.c

You will implement `bst.c`, which will contain the following functions:

```c
typedef struct bst {
    int value;
    struct bst *left;
    struct bst *right;
} BST;

extern int read_input(int *arr, int n);
extern BST *create_node(int value, BST *left, BST *right);
extern BST *create_tree(int *arr, int n);
extern BST *insert_node(BST *root, BST *node);
extern void print_tree(BST *root);
extern BST *remove_min(BST *root, BST **min);
extern BST *delete_node(BST *root, int value);
extern BST *search_node(BST *root, int value);
```

I suggest you implement these functions in the order they are listed.

#### `int read_input(int *arr, int n)`
Reads up to `n` integers from standard input and stores them in the array `arr`.  
Returns the number of integers read.

#### `BST *create_node(int value, BST *left, BST *right)`
Creates a new node with the given value, left child, and right child.

#### `void print_tree(BST *root)`
Prints the binary search tree `root` in order.

#### `BST *insert_node(BST *root, BST *node)`
Inserts the node `node` into the binary search tree `root` while maintaining the binary search tree property.
It should return the root of the tree after the insertion.

Note it's possible to call this with a `NULL` root, in which case it should return the node as the root of the tree.

#### `BST *create_tree(int *arr, int n)`
Creates a binary search tree from the first `n` elements of the array `arr`.

It should use the `create_node` and `insert_node` functions to build the tree.


#### `BST *remove_min(BST *root, BST **min)`
Removes the minimum value from the binary search tree `root` and returns the new root of the tree.

The removed node should be stored in the location pointed to by `min`.

#### `BST *delete_node(BST *root, int value)`
Deletes the node with the value `value` from the binary search tree `root` and returns the new root of the tree.

This routine should use the `remove_min` function to remove the minimum value from the right subtree of the node to be deleted, if necessary.

#### `BST *search_node(BST *root, int value)`
Searches for the value `value` in the binary search tree `root` and returns a pointer to the (first) node with that value, or `NULL` if the value is not in the tree.

#### Implementation details:


## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o build build.c bst.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./build < ../distribution/assignment/a8/tests.build/t100.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
../distribution/assignments/a8/test.sh ./build ../distribution/assignments/a5/tests.build
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in all `bst.c` to Gradescope for Assignment A8.

