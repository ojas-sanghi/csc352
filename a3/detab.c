#include <stdio.h>

int main()
{
    int ch;
    int column = 0;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '\t')
        {
            int spaces = 8 - (column % 8);
            for (int i = 0; i < spaces; i++)
            {
                putchar(' ');
                column++;
            }
        }
        else
        {
            putchar(ch);
            if (ch == '\n')
            {
                column = 0;
            }
            else
            {
                column++;
            }
        }
    }
}