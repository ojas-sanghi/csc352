#include <stdio.h>

int main()
{
    int ch;

    int lines = 0;
    int words = 0;
    int characters = 0;

    int wordStart = 0;

    while ((ch = getchar()) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        // Count words
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            wordStart = 0;
        }
        else if (!wordStart)
        {
            wordStart = 1;
            words++;
        }
    }

    printf("%5d %5d %5d\n", lines, words, characters);
}