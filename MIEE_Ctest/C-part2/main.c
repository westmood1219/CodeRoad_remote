#include "task.h"

//1-->见C-part1.sln/main.c   61

//2
//定义 6个函数，分别实现加、减乘除取余绝对值。
//y = | 2023 % 3 - (2023 + 4.10) * 3 / 2|
//int main()
//{
//    float temp = substract(modulus(2023, 3),
//        divide
//        (multiply
//        (add(2023, 4.10), 3), 2));
//    printf("y=%.2f\n",
//        absolute
//        (temp
//        ));
//    return 0;
//}

//3编写一个函数，用值传递的方式，返回存储在int类型数组中最大值的下标（对数组元素的操作使用指针的形式来实现）。在main中调用该函数进行测试；
//int main()
//{
//    int arr[] = { 31,2,3,11,5,6,7,8,9,10 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    printf("最大值的下标是%d", MaxAddr(arr,sz));
//    return 0;
//}

//challenge:2020年有 366天，将2020年1月1日作为计数起点，即计数1，2020年12月31日作为计数终点，即计数 366。计数1代表“2020年1月1日-星期三”,计数10代表“2020年1月10日-星期五”。参考本章实验，通过键盘输入一个1~366之间的值，包括1和366.基于函数，将其转换为年、月、日、星期，并输出到控制台窗口。
int main() {
    int input = 0;
    printf("请输入你想查看的天数: ");
    scanf_s("%d", &input);

    if (input > 366 || input < 1) {
        printf("只能是一年里的天数1-366\n");
        return 0;
    }

    int m = month(input);
    int d = day(input, m);
    int w = week(input);

    printf("2020年%d月%d日-星期%d\n", m, d, w);

    return 0;
}