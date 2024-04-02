#include <stdio.h>
#include <string.h>

int extract_words(char *words[], char *line)
{
    while (*line == ' ')
        line++;

    char *end = line + strlen(line) - 1;

    //! note this doesnt work
    while (*end == ' ' && end > line)
        end--;
    *(end + 1) = '\0';

    // while (*end == ' ' || *end == '\n')
    // {
    //     end--;
    // }

    // if (*end != '\0')
    //     *(end + 1) = '\0';
    // else
    //     *end = '\0';

    ///// separation!!!!!!!!!!!!!!!!!!!!!!!!

    int numWords = 0;

    int wordStart = 0;

    char *ch = line;
    while (*ch != '\0')
    {
        if (*ch == '\n' && strlen(line) == 1)
        {
            printf("\n");
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

    //! note this throetiaclly works
    // int numWords = 0;

    // char *wordStart = &*line;

    // while (*line != '\0')
    // {
    //     if (*line == ' ')
    //     {
    //         words[numWords++] = wordStart;

    //         *line++ = '\0';

    //         while (*line == ' ')
    //         {
    //             line++;
    //         }

    //         wordStart = line;
    //     }
    //     else
    //     {
    //         line++;
    //     }
    // }

    // if (*wordStart != ' ')
    // {
    //     // todo change this comment
    //     // Edge case for the last word
    //     words[numWords++] = wordStart;
    // }

    // return numWords;
}

int main()
{
    char *words[50000];
    // char ***original_start = words;
    char **location_for_next_words = words;

    char line[1000000];
    char *lineOffset = line;
    // int currentLine = 0;

    int totalWords = 0;

    int maxWidth = 0;

    // while (fgets(line + currentLine, 1000, stdin) != NULL)
    // while (fgets(line, sizeof(line), stdin) != NULL)
    while (fgets(lineOffset, sizeof(line), stdin) != NULL)
    {
        int width = 0;

        // char* original = lineOffset;

        // totalWords += extract_words(words + totalWords, line + currentLine);

        // int numWords = extract_words(words, line);
        // int numWords = extract_words(words, lineOffset);
        // int numWords = extract_words(location_for_next_words, line);
        int numWords = extract_words(location_for_next_words, lineOffset);

        // int numWords = extract_words(words + totalWords, line + currentLine);

        printf("----\n%d words: \n", numWords);
        // printf("----\n%ld size: \n", sizeof(line));
        // printf("----\n%ld size: \n", sizeof(location_for_next_words));
        // printf("----\n%ld size: \n", sizeof(words));

        // if (numWords == 0) printf("\n");

        for (int i = 0; i < numWords; i++)
        {
            width = strlen(*(location_for_next_words + i));

            // printf("%s\n, width: %d\n", *(location_for_next_words + i), width);

            if (width > maxWidth)
            {
                maxWidth = width;
            }
            printf("\n");
            ///// *words[i + totalWords] = **(location_for_next_words + i);
        }

        totalWords += numWords;

        // currentLine += 1001;

        // location_for_next_words += 1;
        // lineOffset = original;
        *lineOffset += strlen(lineOffset) + 1;
        location_for_next_words += numWords;
        // location_for_next_words += sizeof(line);

        for (int i = 0; i < totalWords; i++)
        {
            printf("%*s\n", maxWidth, *(words + i));
        }
    }

    printf("\nTOTAL WORDS: %d\n", totalWords);

    // location_for_next_words = words;

    printf("\n------------\n MAX ! width: %d", maxWidth);
    printf("\n\n-----------------------------------------------\n\n");

    // go thru words and prnit it

    int index = 0;
    while (*(words + index))
    {
        printf("%*s\n", maxWidth, *(words + index));
        index++;
    }

    for (int i = 0; i < totalWords; i++)
    {
        // printf("%s\n", words[i]);
        printf("%*s\n", maxWidth, *(words + i));
        // printf("%*s\n", maxWidth, *(location_for_next_words + i));
        // printf("%s", *(words + i));
    }

    // char *my_words[1000];
    // char my_line[1000000];

    // while (fgets(my_line, 1000, stdin) != NULL)
    // {
    //     // int width = 0;
    //     // also in your example you're overwriting words and line each time, you need pointers that you increment after extracting the words
    //     // same thing, you need to store all the characters
    //     // otherwise your pointers in words end up pointing to characters that got overwritten
    //     // totalWords += extract_words(words + totalWords, line + currentLine);
    //     int numWords = extract_words(my_words, my_line);
    //     // int numWords = extract_words(words + totalWords, line + currentLine);
    //     // totalWords += numWords;
    //     printf("----\n%d: ", numWords);
    //     printf("----\n%d: ", maxWidth);
    //     // for (int i = 0; i < numWords; i++)
    //     for (int i = 0; i < numWords; i++)
    //     {
    //         printf("%*s", maxWidth, *(words + i));

    //         // width = strlen(*(words + i));
    //         // printf("width: %d", width);
    //         // if (width > maxWidth)
    //         // {
    //         //     maxWidth = width;
    //         // }
    //         // printf("\n");
    //     }
    //     printf("\n");
    //     // currentLine += 1001;
    // }

    // for (int i = 0; i < totalWords; i++)
    // {
    //     // int wordWidth = strlen(*(words + i));
    //     int wordWidth = strlen(words[i]);
    //     if (wordWidth > width)
    //     {
    //         width = wordWidth;
    //     }
    // }

    // for (int i = 0; i < totalWords; i++)
    // {
    //     // printf("%*s", width, *(words + i));
    //     // printf("%*s", width, words[i]);
    // }
}