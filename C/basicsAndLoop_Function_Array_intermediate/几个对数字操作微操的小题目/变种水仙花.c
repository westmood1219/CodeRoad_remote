#include <stdio.h>
/*����ˮ�ɻ�����Lily Number:����������֣����м��ֳ��������֣�����1461���Բ�ֳ�(1��461),(14��61),(146��1).������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number,.���磺
655=6*55+65��5
1461=1461+1461+14610
���5λ���е�����Lily Number,*/
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
        //����Ȼ��ȷ���ǵ�Ч�ѿ���������
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