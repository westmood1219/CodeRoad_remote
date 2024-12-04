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

        getchar();//把\n读走
        //也可以在scanf_s("%c", &ch, 1)的%c前面加一个空格表示跳过下一个字符之前的所有空白字符
    }
    return 0;
}