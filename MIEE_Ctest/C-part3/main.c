#include "task.h"

//1,,,,part2把值传递的题目当地址传递写了，这次就顺手写个值传递吧
//int main()
//{
//    int arr[] = { 8,2,6,4,100 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int MaxIndex = findMaxIndex(arr, size);
//    printf("%d", MaxIndex);
//    return 0;
//}

//2键盘获取输入 6 个整数，存入数组 Arr。以指针访问形式求 Arr 内所有数据的总和、均值，并输出
//int main()
//{
//    int Arr[6] = { 0 };
//    int* ptr = Arr;
//    for (int i = 0; i < 6; i++)
//    {
//        scanf_s("%d", ptr+i);
//    }
//    int sum = 0;
//    for (int i = 0; i < 6; i++)
//    {
//        sum =  sum + *(ptr+i);
//    }
//
//    int avg = sum / 6;
//    printf("sum:%d\navg:%d", sum, avg);
//
//    return 0;
//}

//3接受用户从键盘输入 6个字符串数组，利用指针数组管理上述字符串数组并统计 6个字符串数组的字符个数总和。有余力的同学，可以进一步对上述6个字符串按从大到小做排序并输出\

//int main()
//{
//    char ch[6][MAX] = {0};
//    for (int i = 0; i < 6; i++)
//    {
//        scanf_s("%s", ch[i], MAX);
//    }   
//    int count = 0;
//    char *ptr[6];
//    for (int j = 0; j < 6; j++)
//    {
//        ptr[j] = ch[j];
//    }
//    
//    // 统计字符总数
//    for (int j = 0; j < 6; j++)
//    {
//        count += strlen(ptr[j]);
//    }
//    printf("总字数是: %d\n", count);
//    
//    //从大到小排序输出
//    //冒泡
//    return 0;
//}

//4:MIEE协会新加入了6名同学，有名字(字符串类型)、学号(字符串类型)、学院和专业(字符串类型)。用指针数组管理每位同学的上述信息
//int main()
//{
//    char name[6][MAX];
//    char id[6][MAX];
//    char majors[6][MAX];
//    char* ptr[3][6];
//    for (int i = 0; i < 6; i++)
//    {
//        ptr[0][i] = name[i];
//        ptr[1][i] = id[i];
//        ptr[6][i] = majors[i];
//    }
//    // 提示用户输入每位同学的信息
//    printf("请输入6位同学的信息（每行一个，格式：姓名 学号 学院和专业）：\n");
//    for (int i = 0; i < 6; i++) {
//        printf("同学 %d: ", i + 1);
//        scanf_s("%s %s %s", name[i], MAX, id[i], MAX, majors[i], MAX);\
//    }
//
//    // 输出每位同学的信息
//    printf("\n输入的同学信息如下：\n");
//    for (int i = 0; i < 6; i++) {
//        printf("同学 %d: 姓名: %s, 学号: %s, 学院和专业: %s\n", i + 1, ptr[0][i], ptr[1][i], ptr[6][i]);
//    }
//
//    //0-5分别代表六个同学的信息
//    printf("\n想管理第几个同学的什么信息？（输入格式：数字 name/id/majors）");
//    int number = 0; char info[MAX];
//    scanf_s("%d %s", &number, info);
//    int x = 0;
//    if (strcmp(info, "name") == 0)
//    {
//        x = 0;
//    }
//    if (strcmp(info, "id") == 0)
//    {
//        x = 1;
//    }if (strcmp(info, "majors") == 0)
//    {
//        x = 2;
//    }
//    printf("该同学的%s是：%s", info, ptr[x][number-1]);
//
//    return 0;
//}//半ai

//challenge：输入20个数据，创建数组用于存储 20 个温度传感器的读数，范围在 -50 到 50 之间。使用指针遍历这个数组，计算并输出： 
//温度的总和
//温度的平均值
//找到最大值和最小值
//找出异常值（定义为小于 - 30 或大于 40 的温度），并输出这些值及其索引位置。
int main()
{
    int TEMP[20] = { -24, 9, 33, -37, -19, 23, -42, -49, -1, 44, -39, 31, 16, 39, -39, 38, -28, 50, 27, 22 };
    int* ptr[20];
    int sum = 0;
    for (int i = 0; i < 20; i++)
    {
        ptr[i] = &TEMP[i];
        sum += *ptr[i];
    }
    printf("温度总和: %d\n", sum);
    float avg = sum / 20.0f;
    printf("平均数：%.1f\n", avg);
    int max = *ptr[0];
    int min = *ptr[0];
    int count = 0;
    int placeindex[MAX] = { 0 };
    int valueindex[MAX] = { 0 };
    for (int i = 0; i < 20; i++)
    {
        if (*ptr[i] > max)
        {
            max = *ptr[i];
        }
        if (*ptr[i] < min)
        {
            min = *ptr[i];
        }
        if (*ptr[i] < -30 || *ptr[i] >40)
        {
            placeindex[count] = i;
            valueindex[count] = *ptr[i];
            count++;
        }

    }
    count--;
    int temp = count;
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", min);
    printf("异常值索引：");
    while (count >= 0)
    {
        printf("%d ",placeindex[count]);
        count--;
    }
    count = temp;
    printf("\n对应异常值：");
    while (count >= 0)
    {
        printf("%d ",valueindex[count]);
        count--;
    }
    return 0;
}