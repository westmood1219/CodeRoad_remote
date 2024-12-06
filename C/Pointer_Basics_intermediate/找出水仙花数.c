//求出0~100000之间的所有水仙花数并输出。
//水仙花数是指一个n位数，其各位数字的n次方之和刚好等于该数本身，如：153=1^3 + 5^3 + 3^3, 则153是一个“水仙花数。
#include <stdio.h>
#include <math.h>
int main()
{
    for(int n = 0; n <= 100000; n++)
    {
        int num = n;
        //for (int i = 0; i < 6; i++)
        //{
        //    if ((num / (int)pow(10, i)) > 0)
        //    {
        //        digit = i+1;
        //    }
        //    else
        //    {
        //        break;
        //    }
        //}
        //用log的写法:
        //int digit = (int)log10(num) + 1;//判断不了0
        int digit = 1;
        int temp = n;
        while (temp / 10)
        {
            digit++;
            temp /= 10;
        }//鹏哥写法
        int sum = 0;
        /*for (int i = 1; i <= digit; i++)*/
        while(num)//天天for的弊端体现出来了
        {
            sum += pow((num % 10), digit);
            num /= 10;
        }
        if (sum == n)
        {
            printf("%d是水仙花数\n", n);
        }
    }
    return 0;
}//变量还可以再减少一个