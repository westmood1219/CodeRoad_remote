#include <stdio.h>
int max(int x,int y,int z,int w)
{
	if (x>y&&x>z&&x>w)
		return x;
	else if(y>x&&y>z&&y>w)
		return y;
	else if(w>y&&w>z&&w>x)
		return w;
	else
		return z;	
}
int main()
{

	int a = 0, b = 0, c = 0, d = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int da = 0;
	da = max(a, b, c, d);	
	printf("%d", da);	
	return 0;
}//鹏哥写法一!!!!牛逼
//int arr[4] = {0};
//int i = 0;
//while(i<4)
//{
//	scanf("%d", arr[i]);
//	i++;
//	
//}
//int max = arr[0];
//i = 1;
//while(i<4)
//{
//	if(arr[i]>max)
//	{
//		max = arr[i];
//	}
//	i++;
//}
//printf("%d\n", max);
//方法二
//int i = 1;
//int n = 0;
//int max = 0;
//scanf("%d", &max);
//while(i<4)
//{
//	scanf("%d", &n);
//	if (n>max)
//		max = n;
//	i++;
//	
//}
//
//printf("%d\n", max);
//赋值运算符=;比较运算符<,>,==,!=;算术运算符+,-,*,/前后空格;
//逗号分号后面空格;
//关键字之后像if,for,while应该留一个空格，然后跟左括号，以突出关键字。
//函数名后面：不要留空格，紧跟左括号，以与关键字区别。
//括号内部:通常在括号内部不加空格，例如函数调用时的参数列表。
//一元运算符：像!,~,++,--,&(地址运算符)等前后不加空格。
//花括号:在控制语句,如if,for,while后的左花括号前应该有一个空格，右花括号通常独占一行
