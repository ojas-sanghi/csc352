
<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 4: Columns 

Version 1.0 (2024-02-24) - Initial version


## Due Date:

* Friday, 2024-03-01, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

**NOTE:** The structure of the `distribution` directory has changed slightly.  There is now an `assignments` directory that contains the assignment directories (e.g., `a5`).


## Create a directory for this assignment called `a5`

## Write C Program(s):

For this assignment, you will write three different C programs.  You will write each program in a separate file.  You will turn in all files.

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

* `getchar()`
* `putchar()`
* `fgets()`
* `printf()`
* `strlen()`

**Do not use any other library functions.**

### right_justified.c

Write a program that reads characters from `stdin`, breaks them into "words", and then prints a single column of words, right-justified in a column that is the minimum width to accommodate all the words.  The program should print a newline character after each word, and the words are printed in the order they are read.

For instance, this input:

```
   12345 123

   abcdefgh

```

Would become:

```
   12345
     123
abcdefgh
```

Use only spaces to create the right-justified column.  Do not use tabs or any other characters.

Your implementation must include and use a function, `int extract_words(char *words[], char *line)` that processes the string pointed to by `line` and breaks it into words, 
storing the words in the array `words`.  The function should return the number of words found.  The function should not print anything.

`extract_words` should not use `malloc` or any other dynamic memory allocation.  It should mutate `line` to break it into words by placing zeroes at the end of each word, and should store pointers to the beginning of each word in the array `words`.

Use `fgets()` to read the input.

### row_major.c

Like `right_justified.c`, but the words are going to be printed in 4 columns, each right-justified.  The words are printed in the order they are read, and the columns are filled from left to right, and then top to bottom.

The column widths are the same, and are the minimum width to accommodate all the words in that column with an additional space between columns.

So, the following would have column withd of 2:

```
1 2 3 4 5 6 

7 8 9 
10 11
```

Would become:
    
```
 1  2  3  4
 5  6  7  8
 9 10 11
```

There should be no trailing spaces.

### column_major.c

Just like `row_major.c`, but the words are printed in 4 columns, each right-justified.  The words are printed in the order they are read, and the columns are filled from top to bottom, and then left to right.

The column widths are the same, and are the minimum width to accommodate all the words in that column with an additional space between columns.

So, the following would have column withd of 2:

```
1 2 3 4 5 6

7 8 9
10 11
```

Would become:
    
```
 1  4  7 10
 2  5  8 11
 3  6  9
```

There should be no trailing spaces.

### variable_width.c

Just like `column_major.c`, but the column widths are not the same.  The column widths are the minimum width to accommodate all the words in that column with an additional space between columns.

So, the following would have column widths of 2, 1, 2, and 3:

```
1  2 13 4 5 6 22 23 7 abc d
```

Would become:
    
```
 1 4 22 abc
 2 5 23   d
13 6  7
```

## shared.h and shared.c

You may use a shared header file and a shared source file to hold common code.  You may not use any other source files.

You must turn in a `shared.c` and a `shared.h` file.  The `shared.h` file should contain only function prototypes and type definitions.  The `shared.c` file should contain the implementations of the functions.

If you don't want to use shared code, then you don't have to.  Just turn in empty files.

## Pointers only!

You may declare arrays to hold values, but you may not use array indexing.  You must use pointers to access the values in the arrays.

## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o right_justified right_justified.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./right_justified < ../distribution/assignment/a3/tests.right_justified/t100.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
 ../distribution/assignments/a5/test.sh ./right_justified ../distribution/assignments/a5/tests.right_justified
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in all 4 C programs to Gradescope for Assignment A5.

