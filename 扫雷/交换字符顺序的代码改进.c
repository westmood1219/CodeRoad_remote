#include <stdio.h>
#include <string.h>
void reverse(char arr[], int left, int right)
{
	if(left<right)//不能在下面判断否则当有偶数个字符时中间两个会交换回来
	{
	char tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
		//if(left<right)
	reverse(arr, left+1,right-1);
	}
}
int main()
{
	char arr[] = "abcdef";
	int left = 0;
	int right = strlen(arr)-1;
	reverse(arr,left,right);
	printf("%s\n", arr);
	
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
