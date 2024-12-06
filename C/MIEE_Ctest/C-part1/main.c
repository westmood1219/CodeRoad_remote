#include "task.h"

//1
//int main()
//{
//    printf("hello world");
//    return 0;
//}

//2
//十进制：0x254d=2*16^3+5*16^2+4*16^1+13*16^0=9549
//二进制：0x254d=0010 0101 0100 1101

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
//    x = 9;//没有定义变量格式
//    y = 3;//没有定义变量格式
//    z = 8;//没有定义变量格式
//    printf("%d\n", x - y + z)//写完一行应该加";"
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
//    while (scanf_s("%d", &temp) == 1)//需要输入完后输入三行ctrl+z以结束输入（本来一个ctrl+z就代表EOF即文件结束符，傻鸟vs还不修好这个bug）
//    {
//        arr[count] = temp;
//        count++;
//    }
//    printf("输入的整数个数是：%d\n", count);
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
//    //用条件判断和逻辑运算编程，筛选2023-2500年中的闰年，并将结果列表输出
//    //400,4,X100X
//    printf("2023年到2500年之间的闰年有：\n");
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

// the first challenge:定义一个浮点型数组 temperatures，存储一周内每天的温度数据。编写代码计算并输出这周的平均温度。编写函数找出最高温和最低温，并输出它们对应的天数（假设第一天为第0天）。
//输入数据：temperatures = { 23.5, 24.0, 22.8, 21.9, 23.1, 24.6, 25.0 }
//int main()
//{
//    float temperatres[] = {23.5f, 24.0f, 22.8f, 21.9f, 23.1f, 24.6f, 25.0f};
//    int sz = sizeof(temperatres) / sizeof(temperatres[0]);
//    float sum = 0.0f;
//    for (int i = 0; i < sz; i++)
//    {
//        sum = sum + temperatres[i];
//    }
//    printf("这周的平均温度为%.2f\n", sum / sz);
//    WeekMaxMin(temperatres, sz);
//    return 0;
//}

//the second challenge:定义一个整型数组 scores，存储班级中31个学生的数学成绩。编写代码计算并输出全班的平均成绩。统计并输出及格（60分及以上）和不及格的学生人数。
//输入数据：scores = {58, 72, 85, 60, 90, 45, 78, 88, 92, 65, 70, 80, 55, 66, 77, 89, 91, 50, 60, 70, 80, 90, 40, 50, 60, 70, 80, 90, 30, 40, 50}

//int main()
//{
//    int scores[] = {58, 72, 85, 60, 90, 45, 78, 88, 92, 65, 70, 80, 55, 66, 77, 89, 91, 50, 60, 70, 80, 90, 40, 50, 60, 70, 80, 90, 30, 40, 50};
//    int sz = sizeof(scores) / sizeof(scores[0]);
//    float sum = 0.0f;
//    for (int i = 0; i < sz; i++)
//    {
//        sum = sum + scores[i];
//    }
//    printf("全班的平均成绩为%.2f\n", sum / sz);
//    Pass(scores, sz);
//    return 0;
//}
