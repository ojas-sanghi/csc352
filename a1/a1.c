#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

int main() {
    char buffer[MAX_LINE];
    fgets(buffer, MAX_LINE, stdin);
    int len = strlen(buffer);
    printf("[%d]%s", len, buffer);
    return 0;
}