#include <stdio.h>
//编写一个函数实现n的k次方(用递归)
double Pow(int n, int k)
{
	double res = 0;
	if(k>1)
	{
		k--;
		res = n*Pow(n,k);
	}
	else if(k==0)
	{
		return 1;
	}
	else if(k==1)
	{
		return n;
	}//看了gpt的代码后,这一步是真没必要...
	if(k<0&&k!=-1)
	{
		k++;
		res = 1/n/Pow(n,-k);
	}
	else if(k==-1)
	{
		res = 1/n;
		return res;
	}//只是一点数学上的算法就难住了么?return 1.0 / (n * Pow(n, -(k + 1)));就行了!
	return res;
}//k<0写不出来,因为不知道为什么return 1/n返回的不是0.333而是0?
 //因为tmd要说多少遍1.0/n(整型)才是浮点型!
int main()//好在是有递归的思想的,只是实现上差了点
//归根结底还是没有遵循变量尽可能少的原则,对变量的敏感度不够,希望以后能变好
{
	int n = 3;
	int k = -1;
	double res = Pow(n,k);
	printf("%f",res);
	return 0;
}//不错又写出来了一个
//好吧,没考虑k<=0的两种情况
//要不说还得是gpt呢
//#include <stdio.h>
//
//// 编写一个函数实现n的k次方(用递归)
//double Pow(int n, int k) {
//	// 当k为正数时
//	if (k > 0) {
//		return n * Pow(n, k - 1);
//	}
//	// 当k为0时，任何数的0次方都是1
//	else if (k == 0) {
//		return 1;
//	}
//	// 当k为负数时
//	else {
//		return 1.0 / (n * Pow(n, -(k + 1)));
//	}
//}
//
//int main() {
//	int n = 3;
//	int k = -1;
//	double res = Pow(n, k);
//	printf("%f\n", res);
//	return 0;
//}

