
<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 4: More text processing 

Version 1.0 (2024-02-18) - Initial version


## Due Date:

* Friday, 2024-02-123, 3:00PM Arizona Time


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

## Create a directory for this assignment called `a4`

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

### fold.c

NOTE: This is based on the (abandonned) `fold.c` from the previous assignment.  It has changed, however, to be more carefully defined.  Please read it carefully.

Write a program that reads characters from `stdin` and prints them to `stdout`, but with a maximum line length of 40 characters.  If a line is longer than 40 characters, it should be broken into multiple lines, with each line being no longer than 40 characters.  The program should break lines only at spaces, and should not break words in the middle.

You should assume the following:

* no input line is longer than 1000 characters.
* no sequence of non-space characters is longer than 40 characters.

When a line is broken into multiple lines, the program should print a newline character at the end of each line, including the last line.

When a line is broken, each printed part should have no leading or trailing spaces.  All internal spaces are maintained, however.

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

### words.c

Write a program that reads from stdin, and breaks every line into words.  A word is a sequence of non-space characters.  The program should print each word on a separate line, with no leading or trailing spaces.  The program should print a newline character after each word.

Empty lines should be printed as well, with no spaces.

So, the input:

```
    1234567890 234567890 234567890   abcdefghijklmnopqrstuvwxyz


    abc def
```

Would become:
    
```
1234567890
234567890
234567890
abcdefghijklmnopqrstuvwxyz


abc
def
```

Your implementation must include and use a function, `int extract_words(char *words[], char *line)` that processes the string pointed to by `line` and breaks it into words, 
storing the words in the array `words`.  The function should return the number of words found.  The function should not print anything.

`extract_words` should not use `malloc` or any other dynamic memory allocation.  It should mutate `line` to break it into words by placing zeroes at the end of each word, and should store pointers to the beginning of each word in the array `words`.

Use `fgets()` to read the input.

Your program make make the following assumptions:

* no input line is longer than 1,000 characters.
* no sequence of non-space characters is longer than 40 characters.
* the input is less than 100,0000 characters.

### paragraphs.c

Write a program that reads from stdin, separates each line into words, and then prints "paragraphs"
by merging the words back together into lines, with a maximum line length of 40 characters.  Adjacent lines are part of the same paragraph.

An input paragraph is a sequence of lines, separated by empty lines.  When printed, paragraphs should be separated by a single empty line.

The program should not print any leading or trailing spaces, and should not print any leading or trailing empty lines.

NOTE: `extract_words` from the previous program could be useful in this program.

Your program make make the following assumptions:

* no input line is longer than 1,000 characters.
* no sequence of non-space characters is longer than 40 characters.
* the input is less than 100,000 characters.
* empty lines are any lines that contain only zero or more spaces.

The input:

```

    1234567890 
234567890    234567890     123


abcdefghijkl
mnopqrstuvwxyz



```

Would become:

```
1234567890 234567890 234567890 123

abcdefghijkl mnopqrstuvwxyz
```

## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o fold fold.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./fold < ../distribution/a3/tests.fold/t100.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate:

```bash
../distribution/a4/test.sh ./fold ../distribution/a3/tests.fold
../distribution/a4/test.sh ./words ../distribution/a3/tests.words
../distribution/a4/test.sh ./paragraphs ../distribution/a3/tests.paragraphs
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in `fold.c`, `words.c` and `paragraphs.c` to Gradescope for Assignment A4.

