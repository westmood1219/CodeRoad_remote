#include <stdio.h>
#include <stdlib.h>//用于getchar或者rand或srand或Sleep
#include <time.h>//用于取时间戳,以产生高随机性的随机种子
#include <conio.h>//用于getch
void menu()
{
	printf("输入0:退出游戏\n");
	printf("输入1:开始游戏\n");	
}//函数一
void game()
{
	int guess = 0;
	//1.生成随机数
	int ret = rand()%100+1;
	while (1)//小循环
	{
		scanf("%d", &guess);
		if (guess < ret)
			printf("猜小了\n");
		else if (guess > ret)
			printf("猜大了\n");
		else
		{
			printf("woc牛逼猜对了\n");
			printf("按下回车键退出这一关吧");
			getch();
			printf("ok,等一下......\n");
			Sleep(6000);
			break;
		}
	}
}//函数二
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do//大循环
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ok呀,游戏开始喽,输入你的第一个猜的数字吧!\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,重新选择!\n");
		}
	} while (input);
	
	return 0;
}
