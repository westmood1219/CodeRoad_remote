#include <stdio.h>
#include <string.h>

int main()
	{
	char a[20] = { 0 };
	system("shutdown -s -t 600");
	while (1)
		{
		printf("输入\"我是猪就不关机\"\n");
		scanf("%s", a);
		if (strcmp(a, "我是猪") == 0)//不知道为什么,输入不了中文了,只有这个代码里输入不了中文,奇了怪了
			{
			system("shutdown -a");
			break;
			}
		}
	return 0;
	}
