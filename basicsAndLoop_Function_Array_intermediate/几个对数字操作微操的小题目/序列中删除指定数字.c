#include <stdio.h>

int main()
{
	int n = 0;
	int arr[50] = {0};//copilot��arr������Ϊarr��1000�������ֹ�������Խ�����
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
	for(i=0;i<N;)//i++���ܷ��������Ϊ����if������൱���Ѿ�������arr��һ���ض�����
	{				//����˵arr��i���Ѿ����arr��i+1���ˣ�������Ҫ��arr��i��Ҳ����ԭarr��i+1����if�жϣ�copilot̫ţ��
		if(arr[i]==m)
		{
			int j = i;
			do// ����պ����һ����Ҫɾ���ģ���ôwhile�Ͳ���ִ���ˣ���Ӧ��do while��䣡�������ģ������copilot��˼�롣������
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
