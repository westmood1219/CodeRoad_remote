#include <stdio.h>
//在屏幕上输出乘法口诀表


int main()
{
	
	int n = 1, m = 1, res = 0;
	for(n = 1;n < 10;n++)
	{
		for(m = 1;m < 10 && m <= n;m++)
		{	
			res = n * m;
			
			printf("%d*%d=%-2d ", n, m, res);
			//%2d可以让输出结果里的4变成 4从而与两位数左对齐
			//同理,%-2d可以让输出结果里的4变成4 从而与两位数右对齐
		}
		printf("\n");
	}
	return 0;
}//我觉得已经很可以了...
//好吧,还能更简单...
//int i = 0;
//for (i = 0; i <= 9; i++)
//{
//		int j = 0;
//		for (j = 1; j <= i; j++);
//			printf("%d*%d=%-2d", i, j, i*j);
//
//	printf("\n");
//}
