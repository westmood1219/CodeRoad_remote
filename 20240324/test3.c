//在一个有序数组中查找具体的某个数字n
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int arr[] = {1,2,3,4,5,6,7,8,9,10,9};
//	int x = 0;
//	x = sizeof(arr)/sizeof(arr[0]);
//	scanf("%d", &n);
//	for (i=0; i<x; i++)
//	{
//		if(arr[i] != n)
//			continue;
//		else
//			printf("它在数组arr[]中的第%d个位置\n", i+1);
//	}
//	return 0;
//}
//我的方法emm不如二分法下面看示例,效率很好,优雅
#include <stdio.h>
int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int k = 18;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left <= right) {
		int mid = (left + right) / 2;//防数据溢出方法:int mid = left+(right-left)/2;
		if (arr[mid] < k) {
			left = mid + 1;
		} else if (arr[mid] > k) {
			right = mid - 1;
		} else {
			printf("%d", mid);
			break;
		}
	}
	if (left > right)
		printf("zhaobd");
	return 0;
}
