//#include <stdio.h>
//
//int main()
//{
//	int i = 1;
//	int n = 10;
//
//	int arr[10] = {0};
//	int j = 0;
//	
//	while (j<=10)
//	{	
//		int m = 1;
//	for (i=0; i <= n && n>0; i++)
//	{
//		
//		m = m * (i + 1);
//	}
//		arr[j] = m;
//		j++;
//		n--;
//	}
//	int he = 0;
//	he = arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9];
//	printf("%d", he);
//	
//	
//	return 0;
//我也是能写出屎山代码的男人了,,下面的代码更简洁,方便
#include <stdio.h>

int main()
{
	int i = 1;
	int n = 0;
	int ret = 1;
	int sum = 0;

	for (n=1; n<=10;n++)
	{
		ret = ret * n;
		sum = sum + ret;
	}
	printf("%d", sum);
	
	
	return 0;
}
