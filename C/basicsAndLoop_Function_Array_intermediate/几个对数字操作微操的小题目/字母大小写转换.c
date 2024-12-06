#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char ch;
    while(scanf_s("%c", &ch,1) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            printf("%c\n", ch - 32);
        else if (ch >= 'A' && ch <= 'Z')
            printf("%c\n", ch + 32);
    }
    return 0;
}
