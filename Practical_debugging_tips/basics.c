//�ϵ������������,����i=3ʲô��  
//���鴫��ʱ������arr,n�������������ֵ,arrΪ������,nΪ�뿴��ǰ����Ԫ��

#include <stdio.h>
//void test2()
//{
//    printf("hehe");
//}
//void test1()
//{
//    test2();
//}
//void test()
//{
//    test1();
//}
//int main()
//{
//    //int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    //char ch[] = "abcd";
//    //�������ڴ洰������arr,ch����
//    test();//���Կ�ʼ�����ڴ洰����鿴���ö�ջ
//    //���Կ������Ǵ������ϵ���
//    //�����Կ������ͼĴ���
//    return 0;
//}

//һ��������Ҫ���ԵĴ�����
//int main()
//{
//    int i = 0;
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i=0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}

//���Ե�i=10ʱ�����쳣,��Ӽ�����arr[10],����Ҳ����ֵΪ1,arr[11]ͬ��,��arr[12]ʱ����i��Ϊ��0
//���&i����&i == &arr[12]
//������Ϳ�https://www.bilibili.com/video/BV1Vm4y1r7jY?t=3656.0&p=89

//����Ĵ���Ҫ����const
// ��C���Ժ�C++�У�const �ؼ������ڶ��峣���򲻿��޸ĵı������������������α�����ָ��ͺ�������������ߴ���İ�ȫ�ԺͿɶ���
//const����ָ�����:
//1.const����*�����
//��˼�ǣ�pָ��Ķ�����ͨ��p���ı���(�൱������*p���ܸı�),����p�����ֵ���Ըı�
//*p = 20;//err
//2.�ұ�
//int* const p = &num
//�����ķ���ֵ��ָ����Ϊ��ʵ����ʽ����
//��ʽ������һ�ֱ�̼��ɣ�����������������һ�д������������У�ÿ���������÷���һ�������ָ�룬�ö����ָ���������������һ����������
// eg:
// ʵ�� my_strcpy ����
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src) {
//    assert(src != NULL);
//    assert(dest != NULL);
//    char* original_dest = dest; // ����Ŀ���ַ�������ʼ��ַ
//    while ((*dest++ = *src++)); // ����Դ�ַ�����Ŀ���ַ�����������ֹ�� '\0'
//    return original_dest; // ����Ŀ���ַ�������ʼ��ַ
//}
//
//int main() {
//    char src[] = "hello";
//    char dest[6]; // ȷ�� dest ���㹻�Ŀռ�洢 "hello" ����ֹ�� '\0'
//    my_strcpy(dest, src);
//    printf("Copied string: %s\n", dest);
//    return 0;
//}

//���д�����ڵ��ԵĴ���
int my_strlen(const char* str)
{
    int count = 0;
    assert(str);
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char arr[] = "hello bit";
    int len = my_strlen(arr);
    printf("%d\n", len);
}

//��̳����Ĵ���
//1:�������(�﷨)(�����ڱ���׶�)
//2:�����ʹ���(���������ӽ׶�)
//eg:
//int main() {
//    foo(); // ���� foo ����,����û�ҵ�foo���������û�����������д����
//    //�����ڱ�������ʾ"�Ҳ����ⲿxxxx"
//    return 0;
//}
//3:����ʱ����(ֻ�ܵ��������)
