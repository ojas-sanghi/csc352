#include <stdio.h>
#include <string.h>

int extract_words(char *words[], char *line)
{
    while (*line == ' ')
    {
        line++;
    }

    // printf("%s", line);

    char *end = line + strlen(line) - 1;
    while (*end == ' ' || *end == '\n')
    {
        end--;
    }
    // printf("%d\n", end);
    // printf("%c\n", end);
    // line[end] = '\0';
    // *(end + 1)  = '\0';
    if (*end != '\0')
    {
        *(end + 1) = '\0';
    }
    else
    {
        *end = '\0';
    }
    // printf("%c\n", *end);
    // printf("%d\n", *end == '\0');
    // *(end + 1)  = '\0';

    // printf("%s", line);

    // processes the string pointed to by line and breaks it into words, storing the words in the array words. The function should return the number of words found. The function should not print anything

    // It should mutate line to break it into words by placing zeroes at the end of each word, and should store pointers to the beginning of each word in the array words.

    int numWords = 0;

    // words[0] = &(line[0]);

    // length of the line, + 1
    // int len = strlen(line);
    // printf("%d\n", len);

    int wordStart = 0;

    char *ch = line;
    while (*ch != '\0')
    {
        // printf("%c", *ch);
        if (*ch == '\n' && strlen(line) == 1)
        {
            // if (*(ch - 1) == '\0' && *(ch + 1) == '\0')
            // {
            printf("\n");
            break;
            // }
            // printf("%c\n", *(ch - 1));
            // printf("%c\n", *(ch + 1));
            // printf("%d\n", *(ch - 1) == '\0');
            // printf("%d\n", *(ch + 1) == '\0');
            // if (!wordStart)
            //     printf("\n");
        }
        else if (*ch == ' ')
        {
            *ch = '\0';
            wordStart = 0;
        }
        else if (!wordStart)
        {
            // if (*ch == '\n') break;
            *(ch - 1) = '\0';
            words[numWords] = ch;
            wordStart = 1;
            numWords++;
            // printf("\n");
        }
        ch++;
    }

    // printf("%d", numWords);
    // printf("%s", words[0]);

    // int i = 0;
    // for (i = 0; i < len; i++)
    // {
    //     char* ch = &(line[i]);

    //     if (*ch == ' ')
    //     {
    //         *ch = '\0';
    //         numWords++;
    //         words[numWords] = &(line[i+1]);
    //     }
    // }

    return numWords;
}

int main()
{

    /**
     *
    getchar()
    putchar()
    fgets()
    printf()
    strlen()

    */

    // Write a program that reads from stdin, and breaks every line into words. A word is a sequence of non-space characters. The program should print each word on a separate line, with no leading or trailing spaces. The program should print a newline character after each word.

    // Use fgets() to read the input.

    char *words[1000];
    char line[100000];

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        // printf("%s", line);
        // break;

        int numWords = extract_words(words, line);
        // break;

        // printf("%d\n", numWords);
        // printf("%ld\n", strlen(*words));

        int wordsP = 0;
        // char* ch = *words;
        // while (wordsP < numWords)
        // {
        //     if (ch++) {
        //         printf("%s", *ch);
        //     } else {
        //         printf("\n");
        //         wordsP++;
        //     }
        //     // printf("%s", *());
        //     // wordsP++;
        // }
        // char* ch = words;
        // while (*(ch++)) {
        // }

        // }

        for (int i = 0; i < numWords; i++)
        {
            // if (*(words + i))
            // {
            //     printf("%s", *(words + i));
            // }
            // else {
            //     printf("\n");
            //     wordsP++;
            // }
            printf("%s\n", *(words + i));
        }
    }

    // char ch;
    // while ((ch = getchar() != EOF)) {
    //     char* start = fgets(line, 1000, stdin);

    // }

    // printf("%s", line);
    // printf("%s", start);

    // printf("%c", line);

    // int numWords = extract_words(words, line);

    // char ch;
    // while ((ch = getchar() != EOF))
    // {
    //     fgets(line, 1000, stdin);

    //     int numWords = extract_words(words, line);

    //     for (int i = 0; i < numWords; i++)
    //     {
    //         printf("%s\n", *(words + i));
    //     }
    // }
}

// !HEREHEREHEREHEREHEREHEREHEREHEREHEREHEREHERE
// !HEREHEREHEREHEREHEREHEREHEREHEREHEREHEREHERE
// !HEREHEREHEREHEREHEREHEREHEREHEREHEREHEREHERE
// #include <stdio.h>
// #include <string.h>

// #define MAX_LINE_LENGTH 1000
// #define MAX_WORD_LENGTH 40

// // Function to extract words from a line and store them in an array
// int extract_words(char *words[], char *line) {
//   int num_words = 0;
//   char *start = line;

//   // Loop through each character in the line
//   while (*line != '\0') {
//     // If we encounter a space, mark the end of the word with a null terminator
//     if (*line == ' ') {
//       *line = '\0';
//       // Add the word to the array
//       words[num_words++] = start;
//       start = line + 1; // Update start pointer to the next word
//     } else if (*line == '\n') {
//       // If we encounter a newline, treat it as an empty word
//       *line = '\0';
//       words[num_words++] = start;
//       start = line + 1; // Update start pointer to the next line
//       break; // Stop processing the current line
//     }
//     line++;
//   }

//   // If the line ends with a word, add it to the array
//   if (*start != '\0') {
//     words[num_words++] = start;
//   }

//   return num_words;
// }

// int main() {
//   char line[MAX_LINE_LENGTH + 1];
//   char *words[MAX_LINE_LENGTH / MAX_WORD_LENGTH + 1]; // Allocate enough space for worst-case scenario

//   // Read lines from stdin until EOF
//   while (fgets(line, sizeof(line), stdin) != NULL) {
//     int num_words = extract_words(words, line);

//     // Print each word on a separate line
//     for (int i = 0; i < num_words; i++) {
//       printf("%s\n", words[i]);
//     }
//   }

//   return 0;
// }
