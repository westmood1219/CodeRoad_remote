#include <stdio.h>

//int main()
//{
//    //sizeof是一个运算符，用来计算数据类型或变量的长度
//    //strlen是一个函数，用来计算字符串的长度
//    char str[] = "hello";
//    printf("sizeof(str) = %d\n", sizeof(str)); //6
//    printf("strlen(str) = %d\n", strlen(str)); //5
//    return 0;
//}

//int main()
//{
//    char acX[] = "abc";//字符串
//    char acY[] = {'a', 'b', 'c'};//字符数组
//    return 0;
//}

//交换两个一维数组的内容
//int main()
//{
//    int tmp = 0;
//    int arr1[] = { 1, 2, 3, 4, 5 };
//    int arr2[] = { 5, 4, 3, 2, 1 };
//    for (int i = 0; i < 5; i++)
//    {
//        tmp = arr1[i];
//        arr1[i] = arr2[i];
//        arr2[i] = tmp;
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        printf("%d ", arr1[i]);
//    }
//    printf("\n");
//    for (int i = 0; i < 5; i++)
//    {
//        printf("%d ", arr2[i]);
//    }
//    int
//    return 0;
//}

//创建一个整形数组，完成对数组的操作
//实现函数init（）初始化数组为全
//实现print（）打印数组的每个元素
//实现reverse（）函数完成数组元素的逆置
void init(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr[i] = 0;
    }
}

void print(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for(int j= 0;j<sz-1-i;j++)
        {
        if (arr[j] > arr[j + 1])
        {
            int tmp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = tmp;
        }
        }
    }
}//...逆置写成冒泡了...

void reverse1(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 0; j < sz - 1 - i; j++)
        {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
        }
    }
}//逆置就是冒泡去掉判断...不对,鹏哥用的从两端逼近

void reverse2(int arr[], int sz)
{
    int left = 0;
    int right = sz - 1;
    while (right >= left)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        right--;
        left++;
    }
}

int main()
{
    int arr[10] = { 1,2,8,7,6,5,4,3,2 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    print(arr, sz);
    reverse(arr, sz);//冒泡
    print(arr, sz);
    reverse1(arr, sz);//冒泡转逆置1,新颖
    print(arr, sz);
    reverse2(arr, sz);//逆置2,更易懂简洁
    print(arr, sz);
    init(arr, sz);
    print(arr, sz);
    return 0;
}