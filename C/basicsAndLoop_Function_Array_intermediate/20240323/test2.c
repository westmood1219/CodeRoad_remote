#include <stdio.h>

int main()
{
	int num = 0;
	float C = 0.0f, math = 0.0f, eng = 0.0f;
	while(1)
	{
	scanf("%d;%f,%f,%f", &num, &C, &math, &eng);
	if (1 <= num && 20000000 >= num)
		printf("The each subject score of No. %d is %.2f, %.2f, %.2f",num,C,math,eng);
	continue;
}
	
	
	
	return 0;
}
//赋值运算符=;比较运算符<,>,==,!=;算术运算符+,-,*,/前后空格;
//逗号分号后面空格;
//关键字之后像if,for,while应该留一个空格，然后跟左括号，以突出关键字。
//函数名后面：不要留空格，紧跟左括号，以与关键字区别。
//括号内部:通常在括号内部不加空格，例如函数调用时的参数列表。
//一元运算符：像!,~,++,--,&(地址运算符)等前后不加空格。
//花括号:在控制语句,如if,for,while后的左花括号前应该有一个空格，右花括号通常独占一行
