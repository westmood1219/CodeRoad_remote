#include <REG52.H>

sbit BEEP = P1 ^ 0;
sbit KEY1 = P3 ^ 2;
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
    while(1)
    {
        if(0 == KEY1)
        {
            DelayNms(50);
            if(0 ==KEY1)
            {
                BEEP_ON;
                while (0 == KEY1);
                BEEP_OFF;
            }
        }

    }
}