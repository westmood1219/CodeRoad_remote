//��sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222

#include <stdio.h>
int main()
{
    int a = 2;
    int sum = 0;
    int term = 0;
    for (int i = 0; i < 5; i++)
    {
        term = term * 10 + a; // ����ÿһ���ֵ
        sum += term; // �ۼӵ� sum ��
    }
    printf("%d", sum);
    return 0;
}