#include <REG52.H>

sbit KEY1 = P3 ^2;
sbit KEY2 = P3 ^3;
sbit KEY3 = P3 ^4;

sbit LED1 = P2 ^ 4;
sbit LED2 = P2 ^ 5;
sbit LED3 = P2 ^ 6;

static void DelayNms(int nms)
{
    unsigned int i, j;
    for (i = 0; i < nms;i++)
    {
        for (j = 0; j < 123;j++)
        {

        }
    }
}

void LED_TYPE1(){
	unsigned char i;

		P2 = 0xEF;
		for(i=0;i<4;i++){
			DelayNms(500);
			P2 = P2 << 1;
		}
}

void LED_TYPE2()
{

        P2 = 0xEF;
		DelayNms(500);
		
		P2 = 0xCF;
		DelayNms(500);
		
		P2 = 0x8F;
		DelayNms(500);
		
		P2 = 0x0F;
		DelayNms(500);

        P2 = 0x1F;
		DelayNms(500);
		
		P2 = 0x3F;
		DelayNms(500);
		
		P2 = 0x7F;
		DelayNms(500);
		
		P2 = 0xFF;
		DelayNms(500);
    
}

void LED_TYPE3()
{
        unsigned char i;
        P2 = 0x7F;
        for ( i = 0; i < 4; i++)
        {
            DelayNms(500);
            P2 = P2 >> 1;
        }
        
    
}

void main()
{
    if(0 == KEY1)
    {
        DelayNms(50);
        if(0 ==KEY1)
        {
            LED_TYPE1();
        }
    }

    if(0 == KEY2)
    {
        DelayNms(50);
        if(0 ==KEY2)
        {
            LED_TYPE2();
        }
    }

    if(0 == KEY3)
    {
        DelayNms(50);
        if(0 ==KEY3)
        {
            LED_TYPE3();
        }
    }

}