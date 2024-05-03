//	char ch[] = "0";
//	scanf("%s", &ch);
//	int b = 0;
//	int sz = sizeof(ch) / sizeof(ch[0]);
//	for (b = 1; b >= sz; b++)
//	{
//		
//		printf("%s ", ch);
//		
//		
//	}
//	printf("%d", sz);没写来
#include <stdio.h>
//	看完视频后,我:用%啊!1234%10得4,/10再%10得3...
//	学递归前
//	unsigned int num = 0;
//	scanf("%u", &num);	
//	while (num)
//	{
//		printf("%u ", num % 10);
//		num = num / 10;
//	}
//	学递归后
//我直接
void print(unsigned int num);
int main()
{


	unsigned int num = 0;
	scanf("%u", &num); 
	print(num);//注意这不是printf,没有f,是自定义函数
		return 0;
}
void print(unsigned int num)
{
	if (num >9)//递归必须有停下来的条件
	{					
		
		print(num / 10);
	}
	printf("%d ", num % 10);
}
