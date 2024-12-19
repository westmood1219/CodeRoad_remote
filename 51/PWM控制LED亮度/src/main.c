#include "Com_Util.h"
#include <REG52.H>

sbit LED1 = P2 ^ 4;

static void InitInterrupt()
{
    ET0 = 1;
    EA  = 1;
}

static void InitTimer0()
{
    TMOD = 0x02;
    TH0  = 0X9C;
    TL0  = 0X9C;
    TR0  = 1;
}



void main()
{
    InitInterrupt();
    InitTimer0();
    while(1)
    {

    }
}

void Timer0_Handler() interrupt 1
{
    static u16 s_iCnt1 = 0;
    static u16 s_iCnt2 = 0;
    static u16 s_iDuty = 100;
    static u8 s_iFlag = 0;
    s_iCnt1++;
    if (s_iCnt1 >= 100)
    {
        s_iCnt1 = 0;
    }

    s_iCnt2++;
    if (s_iCnt2 >= 200)
    {
        s_iCnt2 = 0;

        if (s_iDuty >= 100 && 1 == s_iFlag) 
        {
            s_iFlag = 0;
        }
        else if(0 == s_iDuty && 0==s_iFlag)
        {
            s_iFlag = 1;
        }

        if (0==s_iFlag)
        {
            s_iDuty --;
        }
        else if (1 == s_iFlag)
        {
            s_iDuty++;
        }
    }

    if (s_iCnt1 <= s_iDuty)
    {
        LED1 = 1;
    }
    else
    {
        LED1 = 0;
    }
}