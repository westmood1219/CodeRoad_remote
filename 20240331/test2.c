//#include <stdio.h>
//
//void swap(int x,int y)
//{
//	int c = 0;
//	c = y;
//	y = x;
//	x = c;
//	return x,y;
//}
//int main()
//{
//	int a = 0,b = 0;
//	scanf("%d%d", &a, &b);
//	swap(a,b);
//	printf("a=%d,b=%d", a, b);
//	return 0;
//}
// 没有注意实参与形参的区别,形参是实参的一个临时拷贝,对形参的修改不会影响实参
#include <stdio.h>

void swap(int* px, int* py)
{
	int c = px;
	px = py;
	py = c;
}
int main()
{
	int a = 0,b = 0;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("a=%d,b=%d", a, b);
	return 0;
}
