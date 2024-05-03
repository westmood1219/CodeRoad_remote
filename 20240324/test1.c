#include <stdio.h>

int main()
{
	int i = 1;
	int n = 0;
	int ret = 1;
	scanf("%d", &n);
	for (i=0; i < n && n>0; i++)
	{
		
		ret = ret * (i + 1);
	}
	printf("%d", ret);
	
	
	return 0;
}
//花了半个多小时我哭了
