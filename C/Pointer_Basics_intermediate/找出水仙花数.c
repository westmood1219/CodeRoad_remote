//���0~100000֮�������ˮ�ɻ����������
//ˮ�ɻ�����ָһ��nλ�������λ���ֵ�n�η�֮�͸պõ��ڸ��������磺153=1^3 + 5^3 + 3^3, ��153��һ����ˮ�ɻ�����
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
        //��log��д��:
        //int digit = (int)log10(num) + 1;//�жϲ���0
        int digit = 1;
        int temp = n;
        while (temp / 10)
        {
            digit++;
            temp /= 10;
        }//����д��
        int sum = 0;
        /*for (int i = 1; i <= digit; i++)*/
        while(num)//����for�ı׶����ֳ�����
        {
            sum += pow((num % 10), digit);
            num /= 10;
        }
        if (sum == n)
        {
            printf("%d��ˮ�ɻ���\n", n);
        }
    }
    return 0;
}//�����������ټ���һ��