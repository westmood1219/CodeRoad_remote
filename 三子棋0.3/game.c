#include "game.h"

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;

    for (i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for (i = 0; i < row; i++)
    {
        //��ӡ����
        //printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);�о�����
        for (int j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
        }
        printf("\n");
        //��ӡ�ָ���Ϣ
        //printf("---|---|---\n");������
        if (i < row - 1)
        {
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("�������:>\n");
    while (1)
    {
        printf("����������:>");
        scanf_s("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')//�ո��ǵ�һ��һ���ַ�,�����õ�����,��˫���Ż��ж�Ϊfalse
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("���걻ռ��,����������λ��\n");
            }
        }
        else
        {
            printf("����Ƿ�,����������\n");
        }
    }
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("��������:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//���˾ͷ���1,��������0
int IsFull(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;

}

//�ж���Ӯ
char judge(char board[ROW][COL], int row, int col)
{
    //��
    for (int i = 0; i < row; i++)
    {

        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];
        }
    }
    //��
    for (int j = 0; j < col; j++)
    {

        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
        {
            return board[1][j];
        }
    }
    //�Խ���
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }

    //û��Ӯ,ƽ��
    if (IsFull(board, ROW, COL))
    {
        return 'Q';
    }

    //����
    return 'C';
}