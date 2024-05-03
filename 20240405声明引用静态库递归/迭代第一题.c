#include <stdio.h>
//求第n个斐波那契数(不考虑溢出)
unsigned int fib(unsigned int n)
{
	
	unsigned int a = 1, b = 1, c = 0;
	while (n >= 3)//鹏哥方法,又高效,又快!
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n-1) + fib(n-2);只用递归解决,太慢了!低效的代码(我写的)
}

int main()
{
	unsigned int n = 1;
	scanf("%u", &n);
	unsigned int ret = fib(n);
	printf("%u\n", ret);
	
	
	
	return 0;
}
