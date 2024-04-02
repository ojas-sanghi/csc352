#include <stdio.h>
#include <string.h>

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
}

int main()
{
    char *words[1000];
    char line[100000];

    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        int numWords = extract_words(words, line);

        for (int i = 0; i < numWords; i++)
        {
            printf("%s\n", *(words + i));
        }
    }
}