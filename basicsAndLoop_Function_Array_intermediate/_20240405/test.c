#include <stdio.h>
//函数的声明在这儿
#include "add.h"
#include "sub.h"
int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	int sum = Add(a, b);
	printf("%d\n", sum);
	int ret = Sub(a, b);
	printf("%d", ret);
	return 0;
}
