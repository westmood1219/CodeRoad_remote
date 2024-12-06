#include <stdio.h>
int main()
{
	int i = 0;
	double sum = 0;//浮点数初始化不用0.0;
	int flag = 1;
	for(i = 1; i <= 100; i+=1)
	{
		sum += flag*(1.0 / i);
		flag = -flag;//计算-,+,-,+...的方法
	}
	printf("%1f",sum);//%1f
	return 0;
}//鹏哥的解法还是叼
