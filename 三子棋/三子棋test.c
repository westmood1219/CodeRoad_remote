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
    char ret = 0;
    char board[ROW][COL] = { 0 };
    //��ʼ�����̵ĺ���
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    //����
    while (1)
    {
        //�������
        PlayerMove(board, ROW, COL);
        //�ж���Ӯ
        ret = judge(board, ROW, COL);
        if (ret != 'C')
        {
            break;// break��������while��ѭ����if������ѭ������̸����
        }
        //��ӡ����
        DisplayBoard(board, ROW, COL);

        //��������
        ComputerMove(board, ROW, COL);
        //�ж���Ӯ
        ret = judge(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //��ӡ����
        DisplayBoard(board, ROW, COL);
    }
    if (ret = '*')
    {
        printf("���Ӯ\n");
    }
    else if (ret = 'Q')
    {
        printf("����Ӯ\n");
    }
    else
    {
        printf("ƽ��\n");
    }
}
int main()
{
    srand((unsigned int)time(NULL));//������������������

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
        case 0:
            printf("exit\n");
            break;
        default:
            printf("Error!Please re-enter a number!\n");
            break;
        }
    } while (key);

    return 0;
}