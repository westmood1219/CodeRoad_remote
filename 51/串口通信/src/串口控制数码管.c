#include <REG52.H>
#include "Com_Util.h"

static u8 s_Counter = 0;
static u8 arrBuffer[4] = {0};

sbit SegmentG1 = P2^3;
sbit SegmentG2 = P2^2;
sbit SegmentG3 = P2^1;
sbit SegmentG4 = P2^0;

const unsigned char arrNumber[] = {0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

static void DelayNms(int nms)
{
    unsigned int i,j;
    for(i = 0; i < nms; i++)
        for(j = 0; j < 123; j++);
}

void UART_Init()
{
    SCON = 0X50;
    PCON = 0X80;
    TMOD = 0X20;
    TL1 = 0xF3;
    TH1 = 0XF3;
    TR1 = 1;
    EA = 1;
    ES = 1;
    RI = 0;
    TI = 0;
}

void DisplayDigits()
{
    // 显示千位
    P0 = arrNumber[arrBuffer[0]];
    SegmentG1 = 0;
    DelayNms(1);
    SegmentG1 = 1;
    
    // 显示百位
    P0 = arrNumber[arrBuffer[1]];
    SegmentG2 = 0;
    DelayNms(1);
    SegmentG2 = 1;
    
    // 显示十位
    P0 = arrNumber[arrBuffer[2]];
    SegmentG3 = 0;
    DelayNms(1);
    SegmentG3 = 1;
    
    // 显示个位
    P0 = arrNumber[arrBuffer[3]];
    SegmentG4 = 0;
    DelayNms(1);
    SegmentG4 = 1;
}

void main()
{
    UART_Init();
    while (1)
    {
        DisplayDigits();
    }
}

void UART_Handler() interrupt 4
{
    if(RI == 1)
    {
        u8 receivedByte;
        RI = 0;  // 立即清除中断标志
        receivedByte = SBUF;
        
        if(receivedByte >= '0' && receivedByte <= '9')
        {
            arrBuffer[s_Counter] = receivedByte - '0';
            s_Counter = (s_Counter + 1) % 4;  // 循环更新计数器
        }
    }
}
