//求sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222

#include <stdio.h>
int main()
{
    int a = 2;
    int sum = 0;
    int term = 0;
    for (int i = 0; i < 5; i++)
    {
        term = term * 10 + a; // 构建每一项的值
        sum += term; // 累加到 sum 中
    }
    printf("%d", sum);
    return 0;
}