#include <REG52.H>
#include "Com_Util.h"

sbit KEY1 = P3 ^ 2;
sbit SegmentG1 = P2^3;
sbit SegmentG2 = P2^2;
sbit SegmentG3 = P2^1;
sbit SegmentG4 = P2^0;
sbit LED1 = P2 ^ 4;

static unsigned int s_iCounter;
static bit s_bKeyPressed = 0;

const unsigned char arrNumber[] = {0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

static void InitInterrupt()
{
    EA  = 1;
    ET0 = 1;
    EX0 = 1;
    IT0 = 1;  // 设置为下降沿触发
}

static void InitTimer0()
{
    TMOD = 0x01;
    
    TH0  = 0xFC;
    TL0  = 0x18; // 1ms
    TR0  = 0;    // 初始状态下定时器停止
}

static void DelayNms(int nms)
{
    unsigned int i,j;
    for(i = 0; i < nms; i++)
        for(j = 0; j < 123; j++);
}

void main()
{
    u8 thousands, hundreds, tens, ones;
    u16 temp;
    InitInterrupt();
    InitTimer0();
    
    while (1)
    {
        temp      = s_iCounter;
        thousands = temp / 1000;
        hundreds = (temp / 100) % 10;
        tens = (temp / 10) % 10;
        ones = temp % 10;
        
        // 显示千位
        P0 = arrNumber[thousands];
        SegmentG1 = 0;
        DelayNms(1);
        SegmentG1 = 1;
        
        // 显示百位
        P0 = arrNumber[hundreds];
        SegmentG2 = 0;
        DelayNms(1);
        SegmentG2 = 1;
        
        // 显示十位
        P0 = arrNumber[tens];
        SegmentG3 = 0;
        DelayNms(1);
        SegmentG3 = 1;
        
        // 显示个位
        P0 = arrNumber[ones];
        SegmentG4 = 0;
        DelayNms(1);
        SegmentG4 = 1;
    }
}

void External0_Handler() interrupt 0
{
    if (!s_bKeyPressed)
    {
        s_bKeyPressed = 1;
        s_iCounter = 0;
        TR0 = 1;  // 启动定时器
    }
}

void Timer0_Handler() interrupt 1
{
    if(KEY1 == 0)
    {
        TH0 = 0XFC;  // 重新设置定时器0计数初值高8位 
        TL0 = 0X18;  // 重新设置定时器0计数初值低8位，定时1ms后溢出
    
        s_bKeyPressed = 0;
        s_iCounter++;
    }   
    else
    {
        s_bKeyPressed = 0;
    }
}
