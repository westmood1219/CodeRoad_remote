#include <stdio.h>

int main()
{
    int score = 0;
    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%d", &score);
        if (score > max)
        {
            max = score;
        }
    }
    printf("%d", max);
    return 0;
}