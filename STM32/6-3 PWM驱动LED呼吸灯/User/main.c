#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"

int main(void)
{
	OLED_Init();
	PWM_Init();
	
	while(1)
	{
		
	}
}
