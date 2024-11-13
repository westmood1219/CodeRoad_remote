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
    char mine[ROWS][COLS] = {0};//��ŷ��κõ��׵���Ϣ
    char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
    //��ʼ��mine����>--δ�����׵�ʱ�򣬶���'0'
    InitBoard(mine, ROWS, COLS,'0');
    //��ʼ��show����>--δ��ʼ�Ų��׵�ʱ�򣬶���'*'
    InitBoard(show, ROWS, COLS,'*');
    //����
    SetMine(mine, ROW, COL);

    //���ӻ�����
    DisplayBoard(show,ROW,COL);
    //�Ų���
    FindMine(mine, show, ROW, COL);

}
int main()
{
    int input = 0;
    //������������������
    srand((unsigned int) time(NULL));
    do
    {
        menu();
        printf("��ѡ�񣺡���");
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
    } while (input);//�ֺţ�
    return 0;
}