#include <stdio.h>
//void bubble_sort(int arr[], int sz)
//{
//    for (int i = 0; i < sz - 1; i++)
//    {
//        for (int j = 0; j < sz - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//} 冒泡排序
int main()
{
    int n = 0;
    scanf_s("%d", &n);
    int arr[n];//如果不是C99标准，我不知道怎么初始化了。。。
    int i = 0;
    int max = 0;
    int min = 100;
    while (i < n)
    {
        scanf_s("%d ", &arr[i]);
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        i++;
    }
    /*bubble_sort(arr, n);
    printf("%d", arr[n-1] - arr[0]);*/
    //用冒泡有点麻烦且没效率了
    //求最大最小值用循环就好
    
    for(i= 1;i<n;i++)
    {
        

    }
    printf("%d", arr[max] - arr[min]);
    return 0;
}
