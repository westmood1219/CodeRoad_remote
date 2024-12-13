#include <REG52.H>

sbit KEY1 = P3 ^2;
sbit KEY2 = P3 ^3;
sbit KEY3 = P3 ^4;

sbit LED1 = P2 ^ 4;
sbit LED4 = P2 ^ 7;

sbit BEEP = P1 ^ 0;
#define BEEP_ON BEEP = 0
#define BEEP_OFF BEEP = 1;

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



void main()
{
    while (1)
    {
        if (0 == KEY1)
        {
            DelayNms(50);
            if (0 == KEY1)
            {
                LED4 = 1;
                while(0 == KEY1)
                {
                    LED1 = 0;
                    BEEP_ON;
                    DelayNms(500);
                    LED1 = 1;
                    BEEP_OFF;
                    DelayNms(500);
                }
            }
        }

        if (0 == KEY2)
        {
            DelayNms(50);
            if (0 == KEY2)
            {
                LED1 = 1;
                while(0==KEY2)
                {
                    LED4 = 0;
                    BEEP_ON;
                    DelayNms(500);
                    LED4 = 1;
                    BEEP_OFF;
                    DelayNms(500);
                }
            }
        }

        if (0 == KEY3)
        {
            DelayNms(50);
            if (0 == KEY3)
            {
                while(1)
                {
                    LED1 = 0;
                    LED4 = 0;
                    BEEP_ON;
                    DelayNms(500);
                    LED1 = 1;
                    LED4 = 1;
                    BEEP_OFF;
                    DelayNms(500);
                }

            }
        }
        
    }
    
}