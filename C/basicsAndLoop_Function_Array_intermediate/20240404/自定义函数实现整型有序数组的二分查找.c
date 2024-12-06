#include <stdio.h>
//略微经过鹏哥指导(二分法又忘了)
int binary_search(int arr[], int x, int sz)
{
	int right = sz - 1;
	int left = 0;
	int mid = 0;

	while (left <= right)
	{
		mid = left + (right - left) / 2;// 防止数据溢出!不要用(right+left)/2!!!!!!!!!!!!!!!!!!!
		if (x < arr[mid])
		{
			right = mid - 1;
		}
		else if (x > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;

}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("enter a figure\n");
	int input = 0;
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	scanf("%d", &input);
	int j = binary_search(arr, input, sz);

	if (j != -1)
		printf("the arr[%d]\n", j);
	else
		printf("There is no %d at the arr[]\n", input);

	return 0;
}
