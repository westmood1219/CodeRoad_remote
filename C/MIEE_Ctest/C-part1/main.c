#include "task.h"

//1
//int main()
//{
//    printf("hello world");
//    return 0;
//}

//2
//ʮ���ƣ�0x254d=2*16^3+5*16^2+4*16^1+13*16^0=9549
//�����ƣ�0x254d=0010 0101 0100 1101

//3
int main()
{
    int FirstInput, SecondInput = 0;
    scanf_s("%d %d", &FirstInput, &SecondInput);
    printf("%d\n", FirstInput + SecondInput);
    return 0;
}

//4
//int main()
//{
//    int FirstInput, SecondInput = 0;
//    scanf_s("%d %d", &FirstInput, &SecondInput);
//    MaxAndMin(FirstInput, SecondInput);
//    return 0;
//}

//5
//void main()
//{
//    x = 9;//û�ж��������ʽ
//    y = 3;//û�ж��������ʽ
//    z = 8;//û�ж��������ʽ
//    printf("%d\n", x - y + z)//д��һ��Ӧ�ü�";"
//}

//6
//void main()
//{
//    int i,sum = 0;
//    for (i = 1; i <= 100; i++)
//    {
//        sum = sum + i;
//    }
//}

//7
//void main()
//{
//    int i, sum = 100;
//    for (i = 1; i <= 20; i++)
//    {
//        sum = sum - i;
//    }
//}

//8
//int main()
//{
//    int arr[max_size] = { 0 };
//    int temp,count = 0;
//    while (scanf_s("%d", &temp) == 1)//��Ҫ���������������ctrl+z�Խ������루����һ��ctrl+z�ʹ���EOF���ļ���������ɵ��vs�����޺����bug��
//    {
//        arr[count] = temp;
//        count++;
//    }
//    printf("��������������ǣ�%d\n", count);
//    bubble_sort(arr, count);
//    for (int i = 0; i < count; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//9
//int main()
//{
//    //�������жϺ��߼������̣�ɸѡ2023-2500���е����꣬��������б����
//    //400,4,X100X
//    printf("2023�굽2500��֮��������У�\n");
//    for (int i = 2023; i <= 2500; i++)
//    {
//        if (i % 4 == 0 && i % 100 != 0)
//        {
//            printf("%d ", i);
//
//        }
//        if (i % 400 == 0)
//        {
//            printf("\n%d\n", i);
//        }
//    }
//    return 0;
//}

//10
//int main()
//{
//    double sum = 1.0;
//    for (int i = 1; i <= 10; i++)
//    {
//        sum = sum + (pow(-1,i)*(1.0 / pow(2, i)));
//    }
//    printf("%.10lf\n", sum);
//    return 0;
//}

// the first challenge:����һ������������ temperatures���洢һ����ÿ����¶����ݡ���д������㲢������ܵ�ƽ���¶ȡ���д�����ҳ�����º�����£���������Ƕ�Ӧ�������������һ��Ϊ��0�죩��
//�������ݣ�temperatures = { 23.5, 24.0, 22.8, 21.9, 23.1, 24.6, 25.0 }
//int main()
//{
//    float temperatres[] = {23.5f, 24.0f, 22.8f, 21.9f, 23.1f, 24.6f, 25.0f};
//    int sz = sizeof(temperatres) / sizeof(temperatres[0]);
//    float sum = 0.0f;
//    for (int i = 0; i < sz; i++)
//    {
//        sum = sum + temperatres[i];
//    }
//    printf("���ܵ�ƽ���¶�Ϊ%.2f\n", sum / sz);
//    WeekMaxMin(temperatres, sz);
//    return 0;
//}

//the second challenge:����һ���������� scores���洢�༶��31��ѧ������ѧ�ɼ�����д������㲢���ȫ���ƽ���ɼ���ͳ�Ʋ��������60�ּ����ϣ��Ͳ������ѧ��������
//�������ݣ�scores = {58, 72, 85, 60, 90, 45, 78, 88, 92, 65, 70, 80, 55, 66, 77, 89, 91, 50, 60, 70, 80, 90, 40, 50, 60, 70, 80, 90, 30, 40, 50}

//int main()
//{
//    int scores[] = {58, 72, 85, 60, 90, 45, 78, 88, 92, 65, 70, 80, 55, 66, 77, 89, 91, 50, 60, 70, 80, 90, 40, 50, 60, 70, 80, 90, 30, 40, 50};
//    int sz = sizeof(scores) / sizeof(scores[0]);
//    float sum = 0.0f;
//    for (int i = 0; i < sz; i++)
//    {
//        sum = sum + scores[i];
//    }
//    printf("ȫ���ƽ���ɼ�Ϊ%.2f\n", sum / sz);
//    Pass(scores, sz);
//    return 0;
//}
