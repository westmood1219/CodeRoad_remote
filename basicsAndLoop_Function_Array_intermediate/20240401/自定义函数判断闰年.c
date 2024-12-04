//#include <stdio.h>
//int run(int x)
//{
//	int g = x % 4, h = x % 100, j = x % 400;
//	if (h == 0 && j == 0 && g ==0)
//		return 1;
//	else if (h != 0 && g == 0)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	int a = run(year);
//	if (a)
//		printf("润");
//	else
//		printf("no");
//	return 0;
//}鹏哥简化版如下,差不多,我的繁琐点
#include <stdio.h>

int is_leap_year(int y)
	{
	if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
		return 1;
	else
		return 0;
	}
int main()
	{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
		{
		if (is_leap_year(year))
			{
			printf("%d   ", year);
			}
		}





	return 0;
	}
