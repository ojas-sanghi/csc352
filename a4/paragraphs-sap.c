#include <stdio.h>
#include <string.h>

int extract_words(char *words[], char *line)
{
    //Trim initial whitespace
    while(*line == ' ') line++;

    //Trim trailing whitespace
    char* end = line + strlen(line) - 1;
    while(*end == ' ' && end > line) end--;
    *(end + 1) = '\0';

    int count = 0;
    char* start = &*line;
    while(*line)
    {
        if(*line == ' ')
        {
            words[count++] = start;

            *line++ = '\0';

            while(*line == ' ') line++;
            start = line;
        }
        else line++;
    }

    if(*start != ' ') words[count++] = start; //Edge case for the last word

    return count;
}

int main()
{
    char buffer[100001];
    char* bufferOffset = buffer;

    char* words[50000];
    char** wordsOffset = words;

    int lastPrintedWord = 0;
    int hasWords = 0;
    int init = 1;

    while(fgets(bufferOffset, 1000, stdin))
    {
        for(int i = 0; i < 1000; i++)
            if(bufferOffset[i] == '\n') bufferOffset[i] = '\0'; //Replace trailing new line with null terminator

        char* original = bufferOffset;
        while(*bufferOffset == ' ') bufferOffset++;

        if(strlen(bufferOffset) == 0 && hasWords) //Empty line
        {
            if(!init) putchar('\n');
            init = 0;

            int currentLen = 0;
            while(words[lastPrintedWord] != 0)
            {
                int len = strlen(words[lastPrintedWord]);

                if(currentLen + len > 39)
                {
                    printf("\n");
                    currentLen = 0;
                }

                if(currentLen != 0)
                {
                    putchar(' ');
                    currentLen++;
                }

                printf("%s", words[lastPrintedWord]);
                lastPrintedWord++;

                currentLen += len;
            }

            putchar('\n');
            hasWords = 0;
        }
        else if(strlen(bufferOffset) != 0) hasWords = 1;

        int count = extract_words(wordsOffset, bufferOffset);

        bufferOffset = original;
        bufferOffset += 1000;
        wordsOffset += count;
    }

    if(hasWords)
    {
        putchar('\n');

        int currentLen = 0;
        while(words[lastPrintedWord] != 0)
        {
            int len = strlen(words[lastPrintedWord]);

            if(currentLen + len > 39)
            {
                printf("\n");
                currentLen = 0;
            }

            if(currentLen != 0)
            {
                putchar(' ');
                currentLen++;
            }

            printf("%s", words[lastPrintedWord]);
            lastPrintedWord++;

            currentLen += len;
        }

        putchar('\n');
    }
}