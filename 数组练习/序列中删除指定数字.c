#include <stdio.h>

int main()
{
	int n = 0;
	int arr[50] = {0};//copilot将arr【】改为arr【1000】，这防止了数组的越界访问
	scanf_s("%d", &n);
	int i = 0;
	int N = n;
	while(i<N)
		{
		scanf_s("%d ",&arr[i]);
			i++;
		}
	int m = 0;
	scanf_s("%d", &m);
	for(i=0;i<N;)//i++不能放在这里，因为下面if语句里相当于已经减少了arr的一个特定数字
	{				//或者说arr【i】已经变成arr【i+1】了，接下来要对arr【i】也就是原arr【i+1】用if判断！copilot太牛了
		if(arr[i]==m)
		{
			int j = i;
			do// 如果刚好最后一个是要删除的，那么while就不会执行了，故应用do while语句！这个我想的！（结合copilot的思想。。。）
			{
				arr[j] = arr[j + 1];
				j++;
			}
			while (j < N - 1);
			N--;
		}
		else
		{
			i++;
		}
	}
	for(i=0;i<N;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
