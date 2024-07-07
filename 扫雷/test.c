#include "game.h"

void menu()
{
    printf("**********************\n");
    printf("******   1.play   ****\n");
    printf("******   0.exit   ****\n");
    printf("**********************\n");  
}

void game()
{
    char mine[ROWS][COLS] = {0};//存放防治好的雷的信息
    char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
    //初始化mine数组>--未布置雷的时候，都是'0'
    InitBoard(mine, ROWS, COLS,'0');
    //初始化show数组>--未开始排查雷的时候，都是'*'
    InitBoard(show, ROWS, COLS,'*');
    //埋雷
    SetMine(mine, ROW, COL);

    //可视化棋盘
    DisplayBoard(show,ROW,COL);
    //排查雷
    FindMine(mine, show, ROW, COL);

}
int main()
{
    int input = 0;
    //设置随机数的生成起点
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("请选择：》》");
        scanf_s("%d", &input);
        switch (input)
        {
        case 1:
            printf("enjoy you time!\n");
            game();
            break;
        case 0:
            printf("done\n");
            break;
        default:
            printf("error\n");
        }
    } while (input);//分号！
    return 0;
}