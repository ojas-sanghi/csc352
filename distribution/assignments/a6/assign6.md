
<link rel="stylesheet" href="https://unpkg.com/bamboo.css">

# Programming Assignment 6: Bowling 

Version 1.0 (2024-03-05) - Initial version


## Due Date:

* Friday, 2024-03-15, 3:00PM Arizona Time


## Download and extract the assignments files from D2L

Download the file `distribution.tar.gz` from D2L and save it in your `csc352` directory.

## Create a directory for this assignment called `a6`

## Write C Program(s):

For this assignment, you will write one C program.  

All programs will read input from standard input (stdin) and write output to standard output (stdout).

The programs should only use only the following library routines:

* `getchar()`
* `putchar()`
* `fgets()`
* `printf()`
* `strlen()`
* `scanf()`
* `exit()`

**Do not use any other library functions.**


### bowling.c

Write a program that reads a sequence of integers from standard input.  The integers represent the number of pins knocked down by a bowler on each successive roll.  They are separated by whitespace (spaces, tabs or newlines)

There are many good descriptions of how to score a bowling game on the web.  Here is one: [How to Score a Bowling Game](http://www.fryes4fun.com/Bowling/scoring.htm)

### output

After reading the input, the program should print a frame-by-frame score for the game.  The score should be printed in the following format:

```
Frame  1: ( 8/ 2) 17  17 ( Spare)
Frame  2: ( 7/ 3) 20  37 ( Spare)
Frame  3: (10/ -) 18  55 (Strike)
Frame  4: ( 4/ 4)  8  63 (  Open)
Frame  5: ( 4/ 6) 18  81 ( Spare)
Frame  6: ( 8/ 2) 16  97 ( Spare)
Frame  7: ( 6/ 3)  9 106 (  Open)
Frame  8: ( 8/ 1)  9 115 (  Open)
Frame  9: ( 9/ 1) 20 135 ( Spare)
Frame 10: (10/ -) 19 154 (Strike) (+9+0)
```

or 

```
Frame  1: ( 9/ 1) 15  15 ( Spare)
Frame  2: ( 5/ 5) 19  34 ( Spare)
Frame  3: ( 9/ 1) 17  51 ( Spare)
Frame  4: ( 7/ 2)  9  60 (  Open)
Frame  5: ( 6/ 4) 20  80 ( Spare)
Frame  6: (10/ -) 24 104 (Strike)
Frame  7: (10/ -) 20 124 (Strike)
Frame  8: ( 4/ 6) 14 138 ( Spare)
Frame  9: ( 4/ 3)  7 145 (  Open)
Frame 10: ( 9/ 1) 20 165 ( Spare) (+10)
```

or

```
Frame  1: ( 5/ 5) 20  20 ( Spare)
Frame  2: (10/ -) 30  50 (Strike)
Frame  3: (10/ -) 30  80 (Strike)
Frame  4: (10/ -) 30 110 (Strike)
Frame  5: (10/ -) 28 138 (Strike)
Frame  6: (10/ -) 19 157 (Strike)
Frame  7: ( 8/ 1)  9 166 (  Open)
Frame  8: (10/ -) 20 186 (Strike)
Frame  9: ( 7/ 3) 16 202 ( Spare)
Frame 10: ( 6/ 3)  9 211 (  Open)
```

Inside the first set of parentheses is the balls rolled in that frame.  Note that strikes have only one ball.

Following the parentheses is the score for that frame including bonus points awarded for strikes and spares.

Following the frame's score is the running total.

Following the running total is the type of frame: `"Open"`, `"Spare"`, `"Strike"`.

On the last frame, if there are bonus balls, they should be printed in parentheses after the frame's score.


#### Implementation details:

The program should be decomposed into 4 functions:

* `int read_rolls(int rolls[])` - This function should read the rolls from standard input and store them in the array `rolls[]`.  The function should return the number of rolls read.
* `int score_frames(struct frame frames[], int rolls[], int num_rolls)` - This function should compute what happened in each frame and fill in the `frames[]` array with the results.
* `void print_frames(struct frame frames[])` - This function should print the frames in the format shown above.
* `int main()` - This function should call the other functions in the appropriate order, and declare the appropriate variables.

#### Data structures:

You should define a struct to represent a frame.  The struct should have the following fields:

* `int first_roll` - The number of pins knocked down on the first roll of the frame.
* `int second_roll` - The number of pins knocked down on the second roll of the frame.
* `int score` - The score for the frame.
* `char *type` - A string that describes the type of frame: `"Open"`, `"Spare"`, `"Strike"`.

#### Errors

If the input has too few rolls, it should print the following error message:

```
Too few rolls
```

If the input has too many rolls, it should print the following error message:

```
Too many rolls
```

If the input has an invalid roll (e.g., a number less than 0 or greater than 10), it should print the following error message:

```
Invalid roll
```

## Experiment with them

Compile each program using a command like:

```bash
cc -Wall -o bowling bowling.c
```

There must be no warnings or errors.  (Notice the addition of the `-Wall` flag!)

Then, try it with file redirection, like:

```bash
./bowling < ../distribution/assignment/a6/tests.bowling/t100.stdin
```

## Run the test cases

Run the test cases using these commands as appropriate.  E.g.,

```bash
 ../distribution/assignments/a6/test.sh ./bowling ../distribution/assignments/a6/tests.bowling
```

If they don't all pass, then you have a problem.

## Turn it in

Turn in all 4 C programs to Gradescope for Assignment A6.

