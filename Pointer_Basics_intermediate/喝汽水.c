//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）

#include <stdio.h>

int main()
{
    int money = 20;
    int bottle = money;
    int empty = bottle;
    while (empty)
    {
        bottle += (empty / 2);
        if (empty == 2)
        {
            bottle += 1;
            empty = 0;
        }
        else if (empty == 1)
        {
            break;
        }
        else if (empty % 2 == 1)
        {
            empty = empty / 2 + 1;
        }
        else if(empty%2 ==0)
        {
            empty /= 2;
        }
    }
    printf("%d", bottle);
    return 0;
}