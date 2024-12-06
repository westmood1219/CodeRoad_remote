//多组输入，一个整数（2~20），表示输出的行数，也表示组成“X”的反斜线和正斜线的长度。
//输入:3
//输出:
//* *
// *
//* *
#include <stdio.h>
//void drawevenx(int x,int y,int z)
//{
//    if(y!=0 && x!= 0)
//    {
//        for (int i = (z/2 - y/2); i > 0; i--)
//        {
//            printf(" ");
//        }
//        printf("*");
//        for (int i = y - 2; i > 0; i--)
//        {
//            printf(" ");
//        }
//        printf("*");
//        for (int i = (z / 2 - y / 2); i > 0; i--)
//        {
//            printf(" ");
//        }
//        printf("\n");
//        y -= 2;
//        drawevenx(x, y, z);
//    }
//    if (y == 0 && x != 0)
//    {
//        for (int i = (x-2)/2; i > 0; i--)
//        {
//            printf(" ");
//        }
//        printf("*");
//        for (int i = (z-x); i > 0; i--)
//        {
//            printf(" ");
//        }
//        printf("*");
//        for (int i = (x - 2) / 2; i > 0; i--)
//        {
//            printf(" ");
//        }
//        x-=2;
//        if(x != 0)
//        {
//            printf("\n");
//            drawevenx(x, y, z);
//        }
//    }
//}

//不是天才,不要用递归

//int main()
//{
//    int x = 0;
//    scanf_s("%d", &x);
//    if(x%2 == 0)
//    {
//        drawevenx(x,x,x);
//    }
//    return 0;
//
//}

//从最关键的那个规律入手,不然分成太多小规律代码量太多了

//来看ai用循环写:
#include <stdio.h>

void drawX(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n >= 2 && n <= 20) {
        drawX(n);
    }
    return 0;
}