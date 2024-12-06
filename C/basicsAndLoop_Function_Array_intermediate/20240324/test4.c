//编写代码,演示多个字符从两端移动,向中间汇聚
#include <stdio.h>
//int main() {
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int left = 0;
//	int right = sz-2;
//	printf("%s\n", arr2);
//	while (left<=right) {
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left++;
//		right--;
//	}	
//	return 0;
//}
//整型数组用int sz = sizeof(arr)/sizeof(arr[0])算
//终于和鹏哥写的思路一样了,泪目!!!!
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main() {
	char arr1[] = "welcome to bit!!!!";
	char arr2[] = "##################";
	int left = 0;
	int right = strlen(arr2) - 1;
	while (left<=right) {
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);//休息一秒,或者说延迟一秒 
		//如果想要清空屏幕,用system,system是一个库函数,可执行系统命令
		system("cls");
		left++;
		right--;
	}	
	printf("%s\n", arr2);
	return 0;
}
