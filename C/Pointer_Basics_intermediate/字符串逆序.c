//дһ���������������ַ���������
#include <stdio.h>
#include <string.h>
void reverse(char* ch, int sz)
{
    for (int i = 0; i < sz / 2; i++)
    {
        char temp = ch[i];
        ch[i] = ch[sz - i - 1];
        ch[sz - i - 1] = temp;
    }
}
int main()
{
    char ch[100] = { 0 };
    gets(ch);//Ϊ�˱���scanf�����ո�Ͳ���ȡ��
    int sz = strlen(ch);
    reverse(ch, sz);
    printf("%s", ch);
    return 0;
}