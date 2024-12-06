#include <stdio.h>

int main()
{
    int a = -1;
    int even[16] = { 0 };
    int odd[16] = { 0 };
    for (int i = 0; i < 16; i++)
    {
        if (a >> (2 * i + 1) & 1 == 1)
        {
            even[16 - i - 1] = 1;
        }
        else
        {
            even[16 - i - 1] = 0;
        }
        if (a >> (2 * i) & 1 == 1)
        {
            odd[16 - i - 1] = 1;
        }
        else
        {
            odd[16 - i - 1] = 0;
        }
    }
    printf("even:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%d", even[i]);
    }
    printf("\nodd:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("%d", odd[i]);
    }
    return 0;
}