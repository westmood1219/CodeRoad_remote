//�������룬һ��������2~20������ʾ�����������Ҳ��ʾ��ɡ�X���ķ�б�ߺ���б�ߵĳ��ȡ�
//����:3
//���:
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

//�������,��Ҫ�õݹ�

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

//����ؼ����Ǹ���������,��Ȼ�ֳ�̫��С���ɴ�����̫����

//����ai��ѭ��д:
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