#include <stdio.h>
int main()
{
	int hei = 0;
	float hig = 0.0f;
	scanf("%d %f", &hei, &hig);
	hig = hig / 100;
	float BMI = 0.0f;
	BMI = hei/hig/hig;
	printf("%.2f", BMI);
	return 0;
}
//另解(劣质)
//#include <stdio.h>
//
//int main()
//{
//	int hei = 0;
//	int hig = 0;
//	scanf("%d %d", &hei, &hig);
//	float high = hig / 100.0;
//	float BMI = 0.0f;
//	BMI = hei/high/high;
//	printf("%.2f", BMI);
//	return 0;
//}
