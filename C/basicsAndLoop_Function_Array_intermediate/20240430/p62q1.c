#include <stdio.h>
void print(int i)
{
	if (i >= 10)
	{
		print(i / 10);
	}
	printf("%d ", i % 10);

}//tmd这都没写来,我哭了
int main()
{
	int i = 1438;
	print(i);


	return 0;
}
