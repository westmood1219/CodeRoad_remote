#include "task.h"

//1,,,,part2��ֵ���ݵ���Ŀ����ַ����д�ˣ���ξ�˳��д��ֵ���ݰ�
//int main()
//{
//    int arr[] = { 8,2,6,4,100 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int MaxIndex = findMaxIndex(arr, size);
//    printf("%d", MaxIndex);
//    return 0;
//}

//2���̻�ȡ���� 6 ���������������� Arr����ָ�������ʽ�� Arr ���������ݵ��ܺ͡���ֵ�������
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

//3�����û��Ӽ������� 6���ַ������飬����ָ��������������ַ������鲢ͳ�� 6���ַ���������ַ������ܺ͡���������ͬѧ�����Խ�һ��������6���ַ������Ӵ�С���������\

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
//    // ͳ���ַ�����
//    for (int j = 0; j < 6; j++)
//    {
//        count += strlen(ptr[j]);
//    }
//    printf("��������: %d\n", count);
//    
//    //�Ӵ�С�������
//    //ð��
//    return 0;
//}

//4:MIEEЭ���¼�����6��ͬѧ��������(�ַ�������)��ѧ��(�ַ�������)��ѧԺ��רҵ(�ַ�������)����ָ���������ÿλͬѧ��������Ϣ
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
//    // ��ʾ�û�����ÿλͬѧ����Ϣ
//    printf("������6λͬѧ����Ϣ��ÿ��һ������ʽ������ ѧ�� ѧԺ��רҵ����\n");
//    for (int i = 0; i < 6; i++) {
//        printf("ͬѧ %d: ", i + 1);
//        scanf_s("%s %s %s", name[i], MAX, id[i], MAX, majors[i], MAX);\
//    }
//
//    // ���ÿλͬѧ����Ϣ
//    printf("\n�����ͬѧ��Ϣ���£�\n");
//    for (int i = 0; i < 6; i++) {
//        printf("ͬѧ %d: ����: %s, ѧ��: %s, ѧԺ��רҵ: %s\n", i + 1, ptr[0][i], ptr[1][i], ptr[6][i]);
//    }
//
//    //0-5�ֱ��������ͬѧ����Ϣ
//    printf("\n�����ڼ���ͬѧ��ʲô��Ϣ���������ʽ������ name/id/majors��");
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
//    printf("��ͬѧ��%s�ǣ�%s", info, ptr[x][number-1]);
//
//    return 0;
//}//��ai

//challenge������20�����ݣ������������ڴ洢 20 ���¶ȴ������Ķ�������Χ�� -50 �� 50 ֮�䡣ʹ��ָ�����������飬���㲢����� 
//�¶ȵ��ܺ�
//�¶ȵ�ƽ��ֵ
//�ҵ����ֵ����Сֵ
//�ҳ��쳣ֵ������ΪС�� - 30 ����� 40 ���¶ȣ����������Щֵ��������λ�á�
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
    printf("�¶��ܺ�: %d\n", sum);
    float avg = sum / 20.0f;
    printf("ƽ������%.1f\n", avg);
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
    printf("���ֵ��%d\n", max);
    printf("��Сֵ��%d\n", min);
    printf("�쳣ֵ������");
    while (count >= 0)
    {
        printf("%d ",placeindex[count]);
        count--;
    }
    count = temp;
    printf("\n��Ӧ�쳣ֵ��");
    while (count >= 0)
    {
        printf("%d ",valueindex[count]);
        count--;
    }
    return 0;
}