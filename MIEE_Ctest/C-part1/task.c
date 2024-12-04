#include "task.h"

void MaxAndMin(int x, int y)
{
    if (x - y > 0)
    {
        printf("���ֵ��%d\n��Сֵ��%d\n", x, y);
    }
    else 
        printf("���ֵ��%d\n��Сֵ��%d\n", y, x);
}

void bubble_sort(int arr[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }

    }
}

void WeekMaxMin(float TEMP[], int days)
{
    float max = 0.0f;
    float min = 0.0f;
    int maxaddr = 0;
    int minaddr = 0;
    for (int i = 1; i < days; i++)
    {
        if (TEMP[i] > TEMP[maxaddr])
            {
                max = TEMP[i];
                maxaddr = i;
            }
        if (TEMP[i] <= TEMP[minaddr])
            {
                min = TEMP[i];
                minaddr = i;
            }
    }
    printf("�������%.1f���ڵ�%d��\n", max, maxaddr);
    printf("�������%.1f���ڵ�%d��\n", min, minaddr);
}

void Pass(int scores[], int sz)
{
    int pass = 60;
    int count = 0;
    for (int i = 0; i < sz; i++)
    {
        if (scores[i] >= pass)
        {
            count++;
        }
    }
    printf("�������%d�������������%d��\n", count, sz-count);
}