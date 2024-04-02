
# Programming Assignment 1: Getting Started [DRAFT]

Version 1.0 (2024-01-15) - Initial version

## Due Date:

* Friday, 2024-01-19, 3:00PM Arizona Time

## Create a directory (aka folder) for this course called `csc352`

(I'm going to assume that you are going to put your work for this course in a directory called `csc352` in your home directory.  If you want to use a different directory, then adjust the instructions accordingly.)

Create a directory called `csc352` in your home directory using the command in a terminal window:

```bash
mkdir ~/csc352
```

Now, change into that directory using the command:

```bash
cd ~/csc352
```

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

## Create a directory for this assignment called `a1`

Create a directory called `a1` in your `csc352` directory using the command:

```bash
mkdir a1
```

Now, change into that directory using the command:

```bash
cd a1
```

## Create C Program:

Create a file called `a1.c` that contains the following code in this directory.

```C
#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int main) {
    char buffer[MAX_LINE;
    fgets(buffer, MAX_LINE, stdin);
    int len = strlen(buffer)
    printf("[%d]%s", len, buffer);
    return 0;
}
```

You may need to use an editor to create this file.  You can use any editor you like.  If you don't have a favorite editor, then you can use `nano` or `vim`.  You may also use an IDE such as `code` or `eclipse`.


## Experiment with it

Compile the program using the command:

```bash
cc -o a1 a1.c
```

It has syntax errors, that you will need to correct in the obvious way.

Once you have corrected the syntax errors, compile the program again using the same command.

Run the program using the command:

```bash
./a1 < a1.c
```

What does it do?

## Run the test cases

Run the test cases using the command:

```bash
../distribution/a1/test.sh ./a1
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in `a1.c` to Gradescope for Assignment A1.

