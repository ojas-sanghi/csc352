#include <stdio.h>

int main()
{
    int count[256] = {0};
    int ch;

    int largestVal = 0;

    while ((ch = getchar()) != EOF)
    {
        count[ch]++;

        if ((ch >= 97 && ch <= 122) && (count[ch] > largestVal))
            largestVal = count[ch];
    }


    for (int i = largestVal; i > 0; i--)
    {
        for (int j = 97; j <= 122; j++)
        {
            if (count[j] >= i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("abcdefghijklmnopqrstuvwxyz\n");

}
