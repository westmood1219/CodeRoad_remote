#include <stdio.h>
//计算一个数每位之和
int DigitSum(int x)
{
	int sum = 0;
	int tem = 0;
	tem = x % 10;
	if(x>0)
	sum = tem + DigitSum(x /10);
	else
	return sum;
}
int main()
{
	int sum = DigitSum(1516951);
	printf("%d", sum);
	return 0;
}//上面是我写的,对了,先不写了,睡觉去了
//tmd原来只用写4行...泪目了
//if(sum > 9)
//		return DigitSum(sum / 10)+ sum % 10;
//else
//		return sum;

