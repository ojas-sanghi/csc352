
# Programming Assignment 2: C Programming 

Version 1.0 (2024-01-26) - Initial version

Version 1.1 (2024-02-04) - Corrected the test invocation commands

## Due Date:

* Friday, 2024-02-09, 3:00PM Arizona Time


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

## Create a directory for this assignment called `a2`

## Write C Program(s):

For this assignment, you will write three different C programs.  You will write each program in a separate file.  You will turn in all files.

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use `getchar()`, `putchar()`, and `printf()` to read and write characters.  **Do not use any other library functions.**

### count.c

Write a program that reads characters from `stdin` and counts how many times each character appears using an array of integers.  The array should have 256 elements, one for each possible character value.  

After counting all the characters, it should print out the counts of all the letters, `a` through `z`, and all the digits, `0` through `9`, in that order.

An example of the output is:

```
a: 1
b: 12
c: 3
...
z: 26
0: 193
1: 2
...
9: 9
```

**NOTE** that there is a colon and a single space between the character and the count, and that they are done in the order shown above, one per line.

### horizontal.c

Like count.c, horizontal.c should read characters from `stdin` and count how many times each character appears.  However, instead of printing the counts in a vertical list, it will print a horizontal histogram of the counts using the `*` character.

Like count.c, it should print out the counts of all the letters, `a` through `z`, and all the digits, `0` through `9`, in that order.

An example of the output is:

```
a: *
b: ************
c: ***
...
z: **************************
0: 
1: **
...
9: *********
```

Just like count.c, there is a colon and a single space between the character and the count, and that they are done in the order shown above, one per line.

**NOTE** There is a space after the colon (`:`) and before the `*` characters.  Those are the only spaces in the output---there are no spaces after the asterisks.

### vertical.c

Like count.c, vertical.c should read characters from `stdin` and count how many times each character appears.  However, instead of printing the counts in a vertical list, it will print a vertical histogram of the counts using the `*` character.

This program is trickier than the others, so do the others first and leave plenty of time to work on it.

Unlike the others, this program should print the histogram for only `a` through `z`, and not for any other characters.

An example of the output is:

```
* * ** **  *  ** ****     
* * ** **  *  ** ****  *  
* *******  * *** ****  *  
* *******  ***** ****  *  
* *******  ***** ******* *
abcdefghijklmnopqrstuvwxyz
```

Note that the bottom line is the letters that label the histogram, and that the histogram is directly above the letters.

**NOTE** All of the "blanks" in the vertical histogram should be spaces.

## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o count count.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./count < count.c
```

(Obviously, you don't need to use `count.c` as the input file.  You can use any file you like, and much smaller files may be useful during testing.)

## Run the test cases

Run the test cases using these commands as appropriate:

```bash
../distribution/a2/test.sh  ./count       ../distribution/a2/tests.count/
../distribution/a2/test.sh  ./horizontal  ../distribution/a2/tests.horizontal/
../distribution/a2/test.sh  ./vertical    ../distribution/a2/tests.vertical/
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in `count.c`, `horizontal.c` and `vertical.c` to Gradescope for Assignment A2.

