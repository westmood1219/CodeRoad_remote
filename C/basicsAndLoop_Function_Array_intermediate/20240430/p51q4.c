#include <stdio.h>
//实现一个函数,打印乘法口诀表,口诀表的行数和列数自己指定
void mul(int x)
{
	int i = 0;
	for (i = 1; i <= x; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)//因为一个分号...输出直接没了还好copilot发现了
			printf("%d*%d=%-2d ", i, j, i*j);
		
		printf("\n");
	}
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	mul(x);
	
	return 0;
}
