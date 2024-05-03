#include <stdio.h>
int main()
{
	int i = 0;
	double sum = 0.0f;
	double unsignsum= 0.0f;
	for(i = 1; i <= 100; i+=2)
	{
		unsignsum += 1.0 / i;
	}
	for(i = 2; i <= 100; i+=2)
	{
		sum -= 1.0 / i;
	}
	double realsum = 0;
	realsum = sum + unsignsum;
	printf("%1f", realsum);
	return 0;
}
