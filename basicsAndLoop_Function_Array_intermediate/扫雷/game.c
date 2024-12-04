
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
    printf("---------------扫雷------------\n");

    for (i = 0; i <= row; i++)
    {
        printf("%d ", i);
    }//类似于横轴
    printf("\n");
    for(i = 1; i<= row;i++)
    {
        printf("%d ", i);//类似于纵轴---让棋子位置一目了然
        for(j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("---------------扫雷------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        //随机生成雷的位置
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        //布置雷
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int get_my_count(char board[ROWS][COLS], int x, int y)
{//要计算周围的雷数，只需要把周围的ASCII码值加起来再减去八个字符‘0’的ASCII码值就行了！！！
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
    return count;错误的，只考虑到下第一步棋的情况，前面在棋盘上显示的count会影响后面的count*/
    return (board[x - 1][y] + board[x - 1][y - 1] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y] + board[x + 1][y - 1]-8*'0');//对于扫雷，这样看似麻烦的写法完美的适用
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;// 找到非零的个数
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
                DisplayBoard(mine, ROW, COL);//显示下完一步后的雷盘
                printf("Sorry,you got blown up...\n");
                break;
            }
            else
            {//统计mine数组x，y坐标周围有几个雷
                win++;
                int count = get_my_count(mine, x, y);
                show[x][y] = '0' + count;//将数字3转化为字符‘3’
                DisplayBoard(show, ROW, COL);//显示下完一步后的雷盘
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