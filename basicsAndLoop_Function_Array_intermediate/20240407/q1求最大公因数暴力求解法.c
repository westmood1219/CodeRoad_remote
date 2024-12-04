#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int min = (a < b) ? a : b;
    while (1)
    {
        if (a % min == 0 && b % min == 0)
            break;
        min--;
    }
    printf("%d\n", min);


    return 0;
}