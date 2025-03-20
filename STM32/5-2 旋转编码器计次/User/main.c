#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1,1,'A');
	OLED_ShowString(1,3, "HelloWorld!");
	OLED_ShowNum(2,2, 1243,4);
	OLED_ShowSignedNum(2,6,-2344,4);
	OLED_Clear();
	while(1)
	{
		
	}
}
