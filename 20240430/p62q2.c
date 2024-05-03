#include <stdio.h>
#include <stdlib.h>
//字符串逆序
//将参数字符串中的字符方向排列!不是逆序打印
//就是把数组里的字符位置重排列
//三种方法
//方法一(循环):
//int main()
//{
//	char arr[] = "abcdefg";
//	int left= 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 2;
//	while(right >= left)
//	{
//		char tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right]=tmp;
//		left++;
//		right--;
//	}
//	printf("%s", arr);
//	return 0;
//}//方法二(递归,且有传参和库函数限制):
void reverse(char* str)
{
	char tmp = *str;
	int len = strlen(str);
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
		reverse(str + 1);
	*(str + len - 1) = tmp;
}
int main()
{
	char arr[] = "abcdef";
	reverse(arr);
	printf("%s", arr);

	return 0;
}//如果没有限制,会短很多,也更易懂;也即用迭代的核心思想放到递归中

