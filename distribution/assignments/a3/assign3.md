
# Programming Assignment 3: Text processing 

Version 1.0 (2024-02-03) - Initial version

Version 1.1 (2024-02-12) - Simplified how to count lines in `wc.c`.

## Due Date:

* Friday, 2024-02-16, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

Extract the files from the archive using the command:

```bash
tar xvf distribution.tar.gz
```

You should now have a directory called `distribution` in your `csc352` directory.  You can check this by doing:

```bash
ls
```

**This directory will get updated from time to time, so do not make any changes to this directory or its contents.**

Also, note that this directory may contain other assignments, so don't get confused.

## Create a directory for this assignment called `a3`

## Write C Program(s):

For this assignment, you will write three different C programs.  You will write each program in a separate file.  You will turn in all files.

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

*  `getchar()`
* `putchar()`
* `fgets()`
* `printf()`

**Do not use any other library functions.**

### detab.c

Write a program that reads characters from `stdin` and prints them to `stdout`, but with all tabs expanded to spaces.  Assume that a tab character (`'\t'`) moves the cursor to the next column that is a multiple of 8.  You should assume that the input file may contain tabs, and that the output file should contain spaces in place of the tabs.

### wc.c

Write a program that reads characters from `stdin` and counts how many lines, words, and characters are in the input.  It should print out the counts in the following format of lines, words, and characters, right justified in 5 space-padded columns, with a space in between:


```
    1    10   100
```

* To count lines, assume that a newline character (`'\n'`) marks the end of a line.  Simply count the number of newline characters.
* To count words, assume that a word is a sequence of characters separated by whitespace.  Whitespace is any sequence of spaces, tabs, or newlines.
* To count characters, count all characters, including whitespace and newlines.

### fold.c

Write a program that reads characters from `stdin` and prints them to `stdout`, but with a maximum line length of 40 characters.  If a line is longer than 40 characters, it should be broken into multiple lines, with each line being no longer than 40 characters.  The program should break lines only at spaces, and should not break words in the middle.

You should assume the following:

* no input line is longer than 1000 characters.
* no sequence of non-space characters is longer than 40 characters.

When a line is broken into multiple lines, the program should print a newline character at the end of each line, including the last line.

When a line is broken, the first half should end with a newline character and no other spaces, and the second half should start with no other spaces.

The output should end with a newline, even if the input does not.

```
   1234567890 234567890 234567890   abcdefghijklmnopqrstuvwxyz
```

Would become:

```
1234567890 234567890 234567890
abcdefghijklmnopqrstuvwxyz
```
(With no spaces after the last `0` and before the `a`.)

Use `fgets()` to read the input.


## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o wc wc.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./wc < wc.c
```

## Run the test cases

Run the test cases using these commands as appropriate:

```bash
../distribution/a3/test.sh ./detab ../distribution/a3/tests.detab
../distribution/a3/test.sh ./wc ../distribution/a3/tests.wc
../distribution/a3/test.sh ./fold ../distribution/a3/tests.fold
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in `detab.c`, `wc.c` and `fold.c` to Gradescope for Assignment A3.

