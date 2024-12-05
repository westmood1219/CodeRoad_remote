#include <stdio.h>
//统计二进制中1的个数题目内容：
//写一个函数返回参数neicu二进制中1的个数
//比如：15  0000 1111  4个1
// 
//int numof1(int a)
//{
//    int count = 0;
//    while (a)
//    {
//        if ((a % 2) != 0)
//        {
//            count++;
//        }
//        a /= 2;
//    }
//    return count;
//}//一般写法
//int numof1(int a)
//{
//    int count = 0;
//    for(int i = 0;i<32;i++)
//    {
//        if (a & 1 == 1)
//        {
//            count++;
//        }
//            a >>= 1;
//            //or a>>i
//    }
//    return count;
//}//学了操作符的写法;
int numof1(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}//面试写法..
//实际上用来求是否是2的n次方很方便,比如n&(n-1)==0就可以了

int main()
{
    int input = 0;
    scanf_s("%d", &input);
    printf("%d个1", numof1(input));
    return 0;
}