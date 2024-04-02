// #include <stdio.h>
// #include <string.h>

// #define MAX_LINE_LENGTH 1000
// #define MAX_PARAGRAPH_SIZE 100000
// #define MAX_WORD_LENGTH 40

// int extract_words(char *words[], char *line)
// {
//     while (*line == ' ')
//     {
//         line++;
//     }

//     char *end = line + strlen(line) - 1;
//     while (*end == ' ' || *end == '\n')
//     {
//         end--;
//     }

//     if (*end != '\0')
//         *(end + 1) = '\0';
//     else
//         *end = '\0';

//     int numWords = 0;

//     int wordStart = 0;

//     char *ch = line;
//     while (*ch != '\0')
//     {
//         if (*ch == '\n' && strlen(line) == 1)
//         {
//             printf("\n");
//             break;
//         }
//         else if (*ch == ' ')
//         {
//             *ch = '\0';
//             wordStart = 0;
//         }
//         else if (!wordStart)
//         {
//             *(ch - 1) = '\0';
//             words[numWords] = ch;
//             wordStart = 1;
//             numWords++;
//         }
//         ch++;
//     }

//     return numWords;
// }

// int main() {
//   char *words[MAX_LINE_LENGTH / MAX_WORD_LENGTH]; // Assuming max 10 words per line
//   char line[MAX_LINE_LENGTH];
//   char paragraph[MAX_PARAGRAPH_SIZE];
//   int paragraph_len = 0;
//   int in_paragraph = 0;

//   while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
//     int numWords = extract_words(words, line);

//     // Skip empty lines
//     if (numWords == 0) {
//       continue;
//     }

//     // Handle paragraph breaks
//     if (!in_paragraph) {
//       // Print previous paragraph if any
//       if (paragraph_len > 0) {
//         printf("%s\n", paragraph);
//       }
//       paragraph_len = 0;
//       in_paragraph = 1;
//     }

//     // Process each word
//     for (int i = 0; i < numWords; i++) {
//       // Check if word fits in current line
//       if (paragraph_len + strlen(words[i]) + 1 <= MAX_WORD_LENGTH) {
//         // Add word to paragraph
//         strcat(paragraph, words[i]);
//         if (i < numWords - 1) {
//           strcat(paragraph, " ");
//         }
//         paragraph_len += strlen(words[i]) + 1;
//       } else {
//         // Print current line and start new one with the word
//         printf("%s\n", paragraph);
//         paragraph_len = 0;
//         strcpy(paragraph, words[i]);
//         paragraph_len = strlen(words[i]);
//       }
//     }
//   }

//   // Print last paragraph if any
//   if (in_paragraph && paragraph_len > 0) {
//     printf("%s\n", paragraph);
//   }

//   return 0;
// }

// // int main()
// // {
// //     char *words[1000];
// //     char line[100000];

// //     while (fgets(line, sizeof(line), stdin) != NULL)
// //     {
// //         int numWords = extract_words(words, line);

// //         for (int i = 0; i < numWords; i++)
// //         {
// //             printf("%s\n", *(words + i));
// //         }
// //     }
// // }

// /**
// Write a program that reads from stdin, separates each line into words, and then prints “paragraphs” by merging the words back together into lines, with a maximum line length of 40 characters.Adjacent lines are part of the same paragraph.

// An input paragraph is a sequence of lines, separated by empty lines.When printed, paragraphs should be separated by a single empty line.

// The program should not print any leading or trailing spaces, and should not print any leading or trailing empty lines.

// Your program make make the following assumptions :
//     no input line is longer than 1,000 characters.
//     no sequence of non - space characters is longer than 40 characters.
//     the input is less than 100, 000 characters.
//     empty lines are any lines that contain only zero or more spaces

// You are given the following code :

// int extract_words(char *words[], char *line)
// {
//     while (*line == ' ')
//     {
//         line++;
//     }

//     char *end = line + strlen(line) - 1;
//     while (*end == ' ' || *end == '\n')
//     {
//         end--;
//     }

//     if (*end != '\0')
//         *(end + 1) = '\0';
//     else
//         *end = '\0';

//     int numWords = 0;

//     int wordStart = 0;

//     char *ch = line;
//     while (*ch != '\0')
//     {
//         if (*ch == '\n' && strlen(line) == 1)
//         {
//             printf("\n");
//             break;
//         }
//         else if (*ch == ' ')
//         {
//             *ch = '\0';
//             wordStart = 0;
//         }
//         else if (!wordStart)
//         {
//             *(ch - 1) = '\0';
//             words[numWords] = ch;
//             wordStart = 1;
//             numWords++;
//         }
//         ch++;
//     }

//     return numWords;
// }
// */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1001
#define MAX_WORD_LENGTH 41
#define MAX_WORDS 10000

int extract_words(char *words[], char *line)
{
    while (*line == ' ')
    {
        line++;
    }

    char *end = line + strlen(line) - 1;
    while (*end == ' ' || *end == '\n')
    {
        end--;
    }

    if (*end != '\0')
        *(end + 1) = '\0';
    else
        *end = '\0';

    int numWords = 0;

    int wordStart = 0;

    char *ch = line;
    while (*ch != '\0')
    {
        if (*ch == '\n' && strlen(line) == 1)
        {
            // printf("\n");
            break;
        }
        else if (*ch == ' ')
        {
            *ch = '\0';
            wordStart = 0;
        }
        else if (!wordStart)
        {
            *(ch - 1) = '\0';
            words[numWords] = ch;
            wordStart = 1;
            numWords++;
        }
        ch++;
    }

    return numWords;
}

int main()
{
    char *words[MAX_WORDS];
    char line[MAX_LINE_LENGTH];
    int numWords, totalWords = 0;
    int firstParagraph = 1;
    // int multiLine = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
    {
        // totalWords = 0;

        // int len = strlen(line);
        if (strlen(line) == 1 && line[0] == '\n')
        {
            // if (len > 0 && *(line) == '\n') {
            // if (strcmp(line, "\n") == 0) {
            // printf("char: %c, %c, %c", line[-1], line[1], line[2]);
            // printf("%c", line[1]);
            // printf("%c", line[2]);
            // printf("%c", line[-1]);
            // End of paragraph
            if (totalWords > 0)
            {
                // if (!firstParagraph)
                    printf("\n");   
                // if (*(line +1) != '\n'   )
                // printf("%c", *(line+1));
                // printf("%d", *(line-1) == '\n');
                // printf("%d", *(line+1) == '\n');

                // printf("%d", *(line-1) == '\0');
                // printf("%d", *(line) == '\0');
                // printf("%d", *(line+1) == '\0');
                // printf("%d", *(line+2) == '\0');
                // printf("%d", *(line+3) == '\0');
                // if (*(line+2) == '\0')
                // if (*(line+1) == '\0')
                printf("\n");
                totalWords = 0;
            }
            firstParagraph = 1;
        }
        else
        {
            // Extract words from the line
            numWords = extract_words(words, line);
            for (int i = 0; i < numWords; i++)
            {

                if (totalWords == 0)
                {
                    // if (**(words + i) == '\n') break;

                    // printf("%d", *(words[strlen(words[i]) - 1]) == '\n');

                    printf("%s", words[i]);
                    totalWords = strlen(words[i]);
                }
                else if (totalWords + strlen(words[i]) + 1 <= 40)
                {
                    // if (words[i] == "\n") break;

                    // printf("%d", *(words[strlen(words[i]) - 1]) == '\n');

                    printf(" %s", words[i]);
                    totalWords += strlen(words[i]) + 1;

                    // multiLine = 1;
                }
                else
                {

                    // if (!firstParagraph)
                    // {
                    //     // printf("\n");
                    //     // firstParagraph = 0;
                    // }

                    // if (multiLine)
                    // {
                    //     printf("\n");
                    //     multiLine = 0;
                    // }
                    // firstParagraph = 0;
                    // if (!firstParagraph)
                    // {
                    //     printf("\n%s", words[i]);
                    //     // printf("\n");
                    // }
                    // else
                    //     printf("%s", words[i]);
                    // if (words[i] != "\n")
                    // printf("%c", *(words[strlen(words[i]) - 1]));
                    // printf("%d", *(words[strlen(words[i]) - 1]) == '\n');
                    printf("\n%s", words[i]);
                    totalWords = strlen(words[i]);
                    // firstParagraph = 1;
                }
            }
            // if (multiLine)
            // {
            //     printf("\n");
            //     multiLine = 0;
            // }
        }
    }

    // printf("%d", *line == '\n');

    if (*line == '\n') return 0;
    *line = '\0';

    if (totalWords > 0)
    {
        printf("\n");
    }

    return 0;
}
