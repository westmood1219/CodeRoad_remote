//���Դ�����߼�
#include "game.h"

void menu()
{
    printf("**************************\n");
    printf("********  1:play  ********\n");
    printf("********  2:exit  ********\n");
    printf("**************************\n");
}

void game()
{
    char board[ROW][COL] = { 0 };
    //��ʼ�����̵ĺ���
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
}
int main()
{
    int key = 0;
    do
    {
        menu();
        printf("Please  enter a number:");
        scanf_s("%d", &key);
        switch (key)
        {
        case 1:
            game();
            break;
        case 2:
            printf("exit\n");
            break;
        default:
            printf("Error!Please re-enter a number!\n");
            break;
        }
    } while (key!=2);

    return 0;
}// ��������޷�����