#include <stdio.h>
//int judge(int  x)
//{
//	if (x == 2 || x == 3 || x == 5)
//		return 1;
//	else if (x == 1)
//		return 0;
//	int a = x % 5;
//	int b = x % 4;
//	int c = x % 3;
//	int d = x % 2;
//	if (a != 0)
//	{
//		if (b != 0)
//		{
//			if (c != 0)
//			{
//				if (d != 0)
//				{
//					return 1;
//				}
//			}
//		}
//	}
//	else
//	{
//	return 0;
//	}
//}看完标准答案后,我的评价是没有考虑完全
// 判断素数也算是一个算法
//具体说我根据定义求素数,不如用性质来求
//x*y=z,x与y中必有一个数小于sqrt(z)!然后一个for循环就好了
//大大减少了计算量,具体如下(来自gpt)
#include <math.h> // 引入 math.h 头文件
int is_prime(int x)
	{
	if (x <= 1)
		{
		return 0; // 1 不是素数
		}
	for (int i = 2; i <= sqrt(x); ++i)   // 使用 sqrt(x) 来计算平方根
		{
		if (x % i == 0)
			{
			return 0; // 如果存在因子，不是素数
			}
		}
		return 1;
	}
int main()
	{
	int input = 0;
	printf("你输素数我来判断\n");

	scanf("%d", &input);
	int j = 0;
	j = is_prime(input);
	if (j == 1)
		{
		printf("这是一个素数\n");
		}
	else
		{
		printf("这不是素数\n");
		}
	return 0;
	}

