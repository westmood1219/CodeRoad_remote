//���ʵ�֣�����it(32λ)����m��n�Ķ����Ʊ���У��ж��ٸ�λbit��ͬ��
//��������
//1999 2299
//�������7

#include <stdio.h>

int main()
{
    int m =0, n= 0,count =0;
    scanf_s("%d %d", &m, &n);
    //��λ��ķ���:
    //for (int i = 0; i < 32; i++)
    //{
    //    if (((m >> i) & 1) == ((n >> i) & 1))
    //    {
    //        count++;
    //    }
    //}
    //��λ���ķ���:
    //��ͬΪ0,����Ϊ1
    int ret = m ^ n;
    //ͳ��ret���м���1
    while (ret)
    {
        ret = ret & (ret - 1);
        count++;
    }
    printf("%d", 32 - count);
    return 0;
}