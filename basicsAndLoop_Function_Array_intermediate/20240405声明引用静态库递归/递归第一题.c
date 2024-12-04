#include <stdio.h>
//题目:编写函数不允许创建临时变量,求字符串的长度
//int my_strlen(char* str)//也可以写成int my_strlen(char str[])
//{//指针加几，表示位移几个指针指向内容的大小的内存，例如数组名（数组第一个元素地址）和&数组名（整个数组的地址），两者加1，前者表示位移一个元素大小的内存，后者表示位移一个数组大小的内存
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;//主函数里my_strlen(ch)里ch是指向ch[]里的第一个字符的指针,也就是*str
//	}//str是指针变量,char*是字符指针变量format
//	return count;	
//}//有临时变量的递归都写不出来我哭了
int my_strlen(char* str)
{
	if (*str != '\0')
	{
		str++;//鹏哥把我这里直接简化成return 1 + my_strlen(strlen+1)了,牛逼
	}
	else//第一次忘记加这个,栈都溢出了嘿嘿
	{
		return 0;
	}
	return 1 + my_strlen(str);//鹏哥牛逼,还能把我这个代码简化
}		//return 后面好像不用打小括号
int main()
{
	int length = 0;
	char ch[] = "hello1234";
//	int sz = 0;
//	sz = sizeof(ch) / sizeof(ch[0]);
//	scanf("%s", ch);
	length = my_strlen(ch);
//	printf("%s\n", ch);
	printf("%d", length);
	//该说不说,写不来递归也应该会用strlen吧,害!
//	strlen还得包含一个<string.h>也忘了
	
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
