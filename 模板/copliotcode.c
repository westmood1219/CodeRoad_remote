#include <stdio.h>
int main()
{
	

		int y = 0, m = 0, d = 0;
		char date[] = "19481219";
		
		scanf(date, "%4d%2d%2d", &y, &m, &d);
		
		if (1990 <= y && y <= 2015) {
			printf("year=%d\n", y);
			if (1 <= m && m <= 12)
				printf("month=%d\n", m);
			if (1 <= d && d <= 30)
				printf("date=%d\n", d);

		
		return 0;
	}




	
	return 0;
}
