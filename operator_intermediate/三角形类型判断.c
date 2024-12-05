#include <stdio.h>

int main()
{
    int a, b, c;
    while (scanf_s("%d%d%d", &a, &b, &c) == 3)
    {
        if (a == b && b == c)
        {
            printf("Eqlateral triangle!");
        }
        else if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            if (a == b || a == c || b == c)
            {
                printf("Isosceles triangle!");
            }
            else
            {
                printf("Ordinary triangle!");
            }
        }
        else
        {
            printf("Not a triangle!");
        }

    }
    return 0;
}