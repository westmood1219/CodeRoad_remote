#include <stdio.h>
//二分查找
//找到了就打印出数字所在的下标,找不到就输出找不到
int main()
{
	int input = 0;
	int arr[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	scanf("%d", &input);
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int left = 0;
	int mid = 0;
	while (right >= left)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] > input)
		{
			right = mid - 1;
		}
		else if (arr[mid] < input)
		{
			left = mid + 1;
			//不要再做left / 2的傻事了,另外二分法应该是left = mid-1etc.
			//有一阵子没写代码就是容易犯傻... 			//6,还left-1...
		}
		else
			break;
	}
	if (left <= right)
		printf("%d", mid);
	else
		printf("找不到");
	return 0;
}//input还是改成key好一点
