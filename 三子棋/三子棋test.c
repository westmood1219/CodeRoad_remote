//测试代码的逻辑
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
    //初始化棋盘的函数
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);
    //下棋
    while (1)
    {
        //玩家先下
        PlayerMove(board, ROW, COL);
        //判断输赢
        ret = judge(board, ROW, COL);
        if (ret != 'C')
        {
            break;// break跳出的是while的循环，if都不是循环，何谈跳出
        }
        //打印棋盘
        DisplayBoard(board, ROW, COL);

        //电脑再下
        ComputerMove(board, ROW, COL);
        //判断输赢
        ret = judge(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        //打印棋盘
        DisplayBoard(board, ROW, COL);
    }
    if (ret = '*')
    {
        printf("玩家赢\n");
    }
    else if (ret = 'Q')
    {
        printf("电脑赢\n");
    }
    else
    {
        printf("平局\n");
    }
}
int main()
{
    srand((unsigned int)time(NULL));//设置随机数的生成起点

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