#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void qi(int a, int b)//������д����ʲô?���д��!
{
    int min = (a < b) ? a : b;//�����С��
    if (a % min == 0 && b % min == 0)
        printf("%d", min);
    else
    {
        int c = min;
        int d = ((a > b) ? a : b) % c;
        qi(c, d);
    }
}//�õ�����ʮ��!
//շת�����(�·���!)
//��������֪��ԭ���д��.
int main()
{
    int a = 0, b = 0;
    scanf_s("%d %d", &a, &b);
    qi(a, b);
    return 0;
}
//��Ҫ�������ŵݹ�,���������ֽ׶�Ӧ���õ�!
//int main()
//{
//    int a = 0, b = 0, c = 0;
//    scanf_s("%d %d", &a, &b);
//    while (c = a % b)//�������ÿ���˳��!
//    {
//        a = b;
//        b = c;
//    }
//    printf("%d", b);
//    return 0;
//}