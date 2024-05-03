#include <stdio.h>
//求十个整数中的最大值


//int main()
//{
//	int arr[] = {0};
//	scanf("%d %d %d %d %d %d %d %d %d %d", arr);
//	int i = 0;
//	int j = 1;
//	for(i = 0;i < 9;i++)
//	{
//		if (arr[i] <= arr[j])//如果i<j
//		{
//			j++;
//		}
//		else
//			
//			
//	}
//	return 0;
//}//好久没写代码,写不来了
int main()
{
	int arr[10] = { 1,998,3,4,18,6,7,11,9,10 };
	//准备了十个数,开始"打擂台"
	int i = 0;
	int j = 1;
	int num = 1;
	for(num = 0;num < 9;num += 1)
	{
		if (arr[i] <= arr[j])
		{
			i = j;
		}
		j++;
	}
	printf("%d", arr[i]);	
	return 0;
}//经过鹏哥提醒后做出来了,主要还是不确定我的方法行不行
//确实不行,因为把八的位置换成11就不行了,我调试一下看看
///调了近十分钟才调出来,但是有点麻烦啰嗦,鹏哥用了九行,我用了十三行
//下面看看鹏哥写法
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int max = arr[0];
//	int i = 0;
//	for(i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		printf("%d\n", max);	
