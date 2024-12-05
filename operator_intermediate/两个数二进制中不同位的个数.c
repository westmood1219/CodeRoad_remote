//编程实现：两个it(32位)整数m和n的二进制表达中，有多少个位bit不同？
//输入例子
//1999 2299
//输出例子7

#include <stdio.h>

int main()
{
    int m =0, n= 0,count =0;
    scanf_s("%d %d", &m, &n);
    //按位与的方法:
    //for (int i = 0; i < 32; i++)
    //{
    //    if (((m >> i) & 1) == ((n >> i) & 1))
    //    {
    //        count++;
    //    }
    //}
    //按位异或的方法:
    //相同为0,相异为1
    int ret = m ^ n;
    //统计ret中有几个1
    while (ret)
    {
        ret = ret & (ret - 1);
        count++;
    }
    printf("%d", 32 - count);
    return 0;
}