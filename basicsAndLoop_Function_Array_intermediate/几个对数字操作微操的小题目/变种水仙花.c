#include <stdio.h>
/*变种水仙花数。Lily Number:把任意的数字，从中间拆分成两个数字，比如1461可以拆分成(1和461),(14和61),(146和1).如果所有拆分后的乘积之和等于自身，则是一个Lily Number,.例如：
655=6*55+65·5
1461=1461+1461+14610
求出5位数中的所有Lily Number,*/
#include <math.h>
int main()
{
    for (int lily =10000;lily<100000;lily++)
    {
        /*int a = lily / 10000;
        int b = lily % 10000;
        int d = lily / 1000;
        int e = lily % 1000;
        int f = lily / 100;
        int g = lily % 100;
        int h = lily / 10;
        int i = lily % 10;
        int ret = a * b + d * e + f * g + h * i;
        if (ret == lily)
        {
            printf("%d ", lily);
        }*/
        //↑虽然正确但是低效难看繁琐复杂
        int sum = 0;
        for (int j = 0; j <= 4; j++)
        {
            int k = (int)pow(10, j);
            sum += (lily % k) * (lily / k);
        }
        if (sum == lily)
            printf("%d ", lily);
    }

    return 0;
}