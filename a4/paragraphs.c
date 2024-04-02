#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1001
#define MAX_WORD_LENGTH 41
#define MAX_WORDS 10000

int extract_words(char *words[], char *line)
{
    while (*line == ' ' || *line == '\n')
    {
        line++;
    }

    if (*line == '\0')
    {
        return 0;
    }

    char *end = line + strlen(line) - 1;
    while (*end == ' ' || *end == '\n')
    {
        end--;
    }

    if (*end != '\0')
    {
        *(end + 1) = '\0';
    }
    else
    {
        *end = '\0';
    }

    int numWords = 0;

    int wordStart = 0;

    char *ch = line;
    while (*ch != '\0')
    {
        if (*ch == '\n' && strlen(line) == 1)
        {
            break;
        }
        else if (*ch == ' ')
        {
            *ch = '\0';
            wordStart = 0;
        }
        else if (!wordStart)
        {
            if (*ch == '\n')
                printf("caught");

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

    int justPrinted = 0;

    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
    {
        if (strlen(line) == 1 && line[0] == '\n')
        {
            // End of paragraph
            if (totalWords > 0)
            {
                if (!(getchar() == EOF))
                    printf("\n");
                printf("\n");
                totalWords = 0;
            }
        }
        else
        {
            // Extract words from the line
            numWords = extract_words(words, line);
            for (int i = 0; i < numWords; i++)
            {
                if (totalWords == 0)
                {
                    printf("%s", words[i]);
                    totalWords = strlen(words[i]);
                }
                else if (totalWords + strlen(words[i]) + 1 <= 40)
                {
                    printf(" %s", words[i]);
                    totalWords += strlen(words[i]) + 1;
                }
                else
                {
                    printf("\n%s", words[i]);
                    totalWords = strlen(words[i]);
                }
            }
        }
    }

    if (totalWords > 0)
    {
        printf("\n");
    }

    return 0;
}
