//
//https://www.bilibili.com/video/BV1Vm4y1r7jY?t=213.5&p=95
//
#include <stdio.h>

int main()
{
    int n = 0;
    scanf_s("%d", &n);

    // 打印上半部分
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // 打印下半部分
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}