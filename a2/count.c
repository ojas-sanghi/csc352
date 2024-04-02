#include <stdio.h>

int main()
{
    int count[256] = {0};
    int ch;

    while ((ch = getchar()) != EOF)
    {
        count[ch]++;
    }

    // 97 thru 122 are ascii codes for a-z
    for (int i = 97; i <= 122; i++)
        printf("%c: %d\n", i, count[i]);
    
    // 48 thru 57 are ascii codes for 0-9
    for (int i = 48; i <= 57; i++)
        printf("%c: %d\n", i, count[i]);
}
