<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 10: Binary-Coded Decimals [DRAFT]

Version 1.0 (2024-03-31) - Initial version


## Due Date:

* Friday, 2024-04-12, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

## Create a directory for this assignment called `a10`

## General Idea

Extremely large integers can be stored in binary-coded decimal (BCD) format.  In BCD format, each digit of the number is stored separately.  For example, the number 1234 would be stored as 1, 2, 3, and 4.

In this assignment, you will write C code to read and process BCD numbers.  In typical BCD implementations, each digit is stored in a 4-bit field.  For example, the number 1234 would be stored as 0001, 0010, 0011, and 0100.  We will be doing something very, very different.

Our C programs will be storing the digits in a linked list.  Each node of the linked list will contain a single digit of the number.  The least significant digit will be stored in the first node of the list, and the most significant digit will be stored in the last node of the list.



## Write C Program(s):

For this assignment, you will write one C file, which will be used by three different C programs.  

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

* `isdigit()`
* `strlen()`
* `malloc()`
* `scanf()`
* `free()`

**Do not use any other library functions.**

### Provided files: bcd.h read.c sum.c scale.c

You are provided with the following files, which you should not modify:

* `bcd.h` - This file contains the following definitions:
    * the `BCD` struct
    * the `Digit` struct, for a linked list of `Digit` nodes
    * the function prototypes for the functions you will implement.
* `read.c` - This file contains a main function that will read integers, check that the structs are well-formed, convert them back to integers, and print them.
* `sum.c` - This file contains a main function that read a list of integers and sum them, printing intermediate results.
* `scale.c` - This file contains a main function that reads a list of integers, scales them by integer scalars, and prints the results.

DO NOT MODIFY THESE FILES.

### bcd.h

The `bcd.h` file contains the following definitions:

```
typedef struct digit {
  int digit;
  struct digit* next_higher_digit;
} Digit;

typedef struct bcd {
  Digit* least_significant_digit;
} BCD;
```




Finally, your program will need to implement 6 (of these 7) functions, which are prototyped in `bcd.h`:

```
extern int audit_digits(Digit *d);
extern char *bcd_to_string(BCD *bcd);
extern BCD* string_to_bcd(char *s);
extern BCD* read_bcd();

extern BCD* zero();
extern BCD* add_bcd(BCD* a, BCD* b);

extern BCD* scale_bcd(BCD* a, int scale);

extern BCD* multiply_bcd(BCD* a, BCD* b);
```


The first three are needed for `read.c`.

The first five are needed for `sum.c`.

The first six are needed for `scale.c`.

You do not need to implement `multiply_bcd` for this assignment.

I suggest you implement these functions in the order they are listed.

### `int audit_digits(Digit *d)`
This function will take a pointer to a `Digit` node and return 1 if the `digit` field of the `Digit` node is between 0 and 9 (inclusive) and the `next_higher_digit` field is either `NULL` or a pointer to a correct `Digit` node.  If the `digit` field is not between 0 and 9 or the `next_higher_digit` field is not `NULL` or a pointer to a `Digit` node, then the function will return 0.

### `char *bcd_to_string(BCD *bcd)`
This function will take a pointer to a `BCD` node and return a string that represents the number stored in the `BCD` node.  The string should be dynamically allocated.  The string should contain the digits of the number in order from most significant to least significant.  For example, the number 1234 would be represented by the string "1234".

### `BCD* string_to_bcd(char *s)`
This function will take a string of digits and return a pointer to a `BCD` node that represents the number stored in the string.  The string will contain the digits of the number in order from most significant to least significant.  For example, the string "1234" would represent the number 1234.


### `BCD* read_bcd()`
This function will read a BCD number from standard input and return a pointer to a `BCD` node that represents that number.  The number will be read as a string of digits.  The most significant digit will be read first, and the least significant digit will be read last.  

The function will return `NULL` when there is not more input.

### `BCD* zero()`
This function will return a pointer to a `BCD` node that represents the number 0.

### `BCD* add_bcd(BCD* a, BCD* b)`
This function will take two pointers to `BCD` nodes and return a pointer to a new `BCD` node that represents the sum of the two numbers.  The `BCD` nodes `a` and `b` will not be modified.  The new `BCD` node will be dynamically allocated.

### `BCD* scale_bcd(BCD* a, int scale)`
This function will take a pointer to a `BCD` node and an integer `scale` and return a pointer to a new `BCD` node that represents the number stored in the `BCD` node scaled by the integer `scale`.  The `BCD` node `a` will not be modified.  The new `BCD` node will be dynamically allocated.

### `BCD* multiply_bcd(BCD* a, BCD* b)`
This function will take two pointers to `BCD` nodes and return a pointer to a new `BCD` node that represents the product of the two numbers.  The `BCD` nodes `a` and `b` will not be modified.  The new `BCD` node will be dynamically allocated.

`multiply_bcd` is not needed for this assignment.  You may stub it with a routine that simply returns `NULL`.



## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o read read.c bcd.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./read < ../distribution/assignment/a10/tests.read/t01_01.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
../distribution/assignments/10/test.sh ./read ../distribution/assignments/a10/tests.read
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in all `bcd.c` to Gradescope for Assignment A10.

