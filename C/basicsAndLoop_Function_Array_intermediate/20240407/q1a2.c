#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void qi(int a, int b)//函数名写的是什么?依托答辩!
{
    int min = (a < b) ? a : b;//求出较小数
    if (a % min == 0 && b % min == 0)
        printf("%d", min);
    else
    {
        int c = min;
        int d = ((a > b) ? a : b) % c;
        qi(c, d);
    }
}//用迭代就十行!
//辗转相除法(新方法!)
//下面是我知道原理后写的.
int main()
{
    int a = 0, b = 0;
    scanf_s("%d %d", &a, &b);
    qi(a, b);
    return 0;
}
//不要老是想着递归,迭代才是现阶段应该用的!
//int main()
//{
//    int a = 0, b = 0, c = 0;
//    scanf_s("%d %d", &a, &b);
//    while (c = a % b)//甚至不用考虑顺序!
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d", b);
//    return 0;
//}