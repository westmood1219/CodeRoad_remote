#include <stdio.h>

int main()
{
    char ch = 0;
    while (scanf_s("%c", &ch, 1) == 1)
    {
        if ((ch <= 90 && ch >= 65) || (ch <= 122 && ch >= 97))
        {
            printf("%c is an alphabet.\n", ch);
        }
        else
        {
            printf("%c is not an alphabet.\n", ch);
        }

        getchar();//��\n����
        //Ҳ������scanf_s("%c", &ch, 1)��%cǰ���һ���ո��ʾ������һ���ַ�֮ǰ�����пհ��ַ�
    }
    return 0;
}