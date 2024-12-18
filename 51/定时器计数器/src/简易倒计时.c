#include <REG52.H>
#include "Com_Util.h"

sbit LED1 = P2 ^ 4;
sbit BEEP = P1 ^ 0;
sbit SegmentG1 = P2^3;
sbit SegmentG2 = P2^2;

static u16 count;

const unsigned char arrNumber[] = {0x03 , 0x9f , 0x25 , 0x0d , 0x99 , 0x49 , 0x41 , 0x1f , 0x01 , 0x09};

static void InitInterrrupt()
{
    ET0 = 1;
    EX0 = 1;
    EA  = 1;
    IT0 = 1;
}

static void InitTimer0()
{
    TMOD = 0x01;
    TH0  = 0xFC;
    TL0  = 0x18; // 1ms
    TR0  = 1;
}

static void DelayNms(int nms)
{
    unsigned int i,j;
    for(i = 0; i < nms; i++)
        for(j = 0; j < 123; j++);
}

void main()
{
    u8 tens, ones;
    InitInterrrupt();
    InitTimer0();
    
    while (1)
    {
        tens = count / 10000; // 十位
        ones = (count / 1000) % 10; // 个位
        
        // 显示十位
        P0 = arrNumber[tens];
        SegmentG1 = 0;
        DelayNms(1);
        SegmentG1 = 1;
        
        // 显示个位
        P0 = arrNumber[ones];
        SegmentG2 = 0;
        DelayNms(1);
        SegmentG2 = 1;
    }
}

void External0_Handler() interrupt 0
{
    BEEP  = 1;
    count = 0;
}

void Timer0_Handler() interrupt 1
{
    
    TH0  = 0xFC;
    TL0  = 0x18;
    if (count >= 60000) // 60秒
    {
        BEEP = 0;
    }
    else
    {
        
        TH0 = 0xFC;
        TL0 = 0x18; // 1ms
        count++;
    }
}
