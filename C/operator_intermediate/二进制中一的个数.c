#include <stdio.h>
//ͳ�ƶ�������1�ĸ�����Ŀ���ݣ�
//дһ���������ز���neicu��������1�ĸ���
//���磺15  0000 1111  4��1
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
//}//һ��д��
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
//}//ѧ�˲�������д��;
int numof1(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}//����д��..
//ʵ�����������Ƿ���2��n�η��ܷ���,����n&(n-1)==0�Ϳ�����

int main()
{
    int input = 0;
    scanf_s("%d", &input);
    printf("%d��1", numof1(input));
    return 0;
}