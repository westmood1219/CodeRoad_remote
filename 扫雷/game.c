
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("---------------ɨ��------------\n");

    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }//�����ں���
    printf("\n");
    for(i = 1; i<= row;i++)
    {
        printf("%d ", i);//����������---������λ��һĿ��Ȼ
        for(j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------ɨ��------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        //��������׵�λ��
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        //������
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_my_count(char board[ROWS][COLS], int x, int y)
{//Ҫ������Χ��������ֻ��Ҫ����Χ��ASCII��ֵ�������ټ�ȥ�˸��ַ���0����ASCII��ֵ�����ˣ�����
    /*int i = 0;
    int j = 0;
    int count = 0;
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            count = count + board[i][j] - '0';
        }
    }
    return count;����ģ�ֻ���ǵ��µ�һ����������ǰ������������ʾ��count��Ӱ������count*/
    return (board[x - 1][y] + board[x - 1][y - 1] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y] + board[x + 1][y - 1]-8*'0');//����ɨ�ף����������鷳��д������������
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;// �ҵ�����ĸ���
    while (win<row*col-EASY_COUNT)
    {
        printf("please enter coordinate>:");
        scanf_s("%d %d", &x, &y);

        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] != '*')
            {
                printf("please do not repeat the input!\n");
            }
            if (mine[x][y] == '1')
            {
                DisplayBoard(mine, ROW, COL);//��ʾ����һ���������
                printf("Sorry,you got blown up...\n");
                break;
            }
            else
            {//ͳ��mine����x��y������Χ�м�����
                win++;
                int count = get_my_count(mine, x, y);
                show[x][y] = '0' + count;//������3ת��Ϊ�ַ���3��
                DisplayBoard(show, ROW, COL);//��ʾ����һ���������
            }
        }
        else
        {
            printf("illegal coordinate,please re-enter!!!\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        DisplayBoard(mine, ROW, COL);
        printf("Congratulations on your successful demining!");
    }
}