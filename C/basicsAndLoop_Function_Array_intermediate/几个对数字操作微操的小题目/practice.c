#include <stdio.h>

//int main()
//{
//    //sizeof��һ������������������������ͻ�����ĳ���
//    //strlen��һ�����������������ַ����ĳ���
//    char str[] = "hello";
//    printf("sizeof(str) = %d\n", sizeof(str)); //6
//    printf("strlen(str) = %d\n", strlen(str)); //5
//    return 0;
//}

//int main()
//{
//    char acX[] = "abc";//�ַ���
//    char acY[] = {'a', 'b', 'c'};//�ַ�����
//    return 0;
//}

//��������һά���������
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

//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init������ʼ������Ϊȫ
//ʵ��print������ӡ�����ÿ��Ԫ��
//ʵ��reverse���������������Ԫ�ص�����
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
}//...����д��ð����...

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
}//���þ���ð��ȥ���ж�...����,�����õĴ����˱ƽ�

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
    reverse(arr, sz);//ð��
    print(arr, sz);
    reverse1(arr, sz);//ð��ת����1,��ӱ
    print(arr, sz);
    reverse2(arr, sz);//����2,���׶����
    print(arr, sz);
    init(arr, sz);
    print(arr, sz);
    return 0;
}