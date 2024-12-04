#include <stdio.h>
#include <stdlib.h>
int Add(int a, int b, int* pnum)
{
	++(*pnum);//最好来个括号
	int result = (a + b);
	return result;
}

int main()
{
	int num = 0;
	int a = 1;
	int b = 1;
	int j = 0;
	int m = 0;
	scanf("%d", &m);
	while (1)
	{
		j = Add(a, b, &num);
		if (j > m)
		{
			printf("%d  %d\n", num, j);
			break;
		}
		else
		{
			a++;
			b++;
		}
	}
	return 0;
}//我写的,有点复杂啊,不过方法上是吻合的
