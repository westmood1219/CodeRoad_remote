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

void main()
{
    if(0 == KEY1)
    {
        DelayNms(50);
        if(0 ==KEY1)
        {
            LED1 = ~LED1;
            while (0 == KEY1);
        }
    }

    if(0 == KEY2)
    {
        DelayNms(50);
        if(0 ==KEY2)
        {
            LED1 = ~LED1;
            while (0 == KEY2);
        }
    }

    if(0 == KEY3)
    {
        DelayNms(50);
        if(0 ==KEY3)
        {
            LED1 = ~LED1;
            while (0 == KEY3);
        }
    }

}