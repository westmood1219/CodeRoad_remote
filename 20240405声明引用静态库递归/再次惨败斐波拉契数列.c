#include <stdio.h>

//int count(int n)
//{
//	if(n>3)
//	{
//		return count(n-1)+count(n-2);//再次忘了这茬
//	}
//	else
//	{
//		return n;
//	}
//}//低效的递归。。。。
//int main()
//{
//	
//	int m = 0;
//	int n =0;
//	scanf("%d",&n);
//	m = count(n);
//	printf("%d ways", m);
//	return 0;
//}
int count(int n)
{
	if(n==1)
		return 1;
	int a=1,b=1,c=0;
	while(n>1)
	{
		c = a+b;
		a=b;
		b=c;
		n--;
	}
	return c;
}
int main()
{
	
	int m = 0;
	int n =0;
	scanf("%d",&n);
	m = count(n);
	printf("%d ways", m);
	return 0;
}


//赋值运算符=;比较运算符<,>,==,!=;算术运算符+,-,*,/前后空格
//逗号分号后面空格;
//关键字之后像if,for,while应该留一个空格，然后跟左括号
//函数名后面：不要留空格，紧跟左括号，以与关键字区别。
//括号内部:通常在括号内部不加空格，例如函数调用时的参数列表。
//一元运算符：像!,~,++,--,&(地址运算符)等前后不加空格。
//花括号:在控制语句,如if,for,while后的左花括号前有一个空格
//右花括号通常独占一行
//数组里花括号与数有一个空格
