#include <REG52.H>
#include "Com_Util.h"

void UART_Init()
{
    SCON = 0X50;//设置 串口 工作模式1，并打开接收允许

    PCON = 0X80;//设置 波特率加倍

    TMOD = 0X20;//工作模式二

    TL1 = 0xF3;
    TH1 = 0XF3;

    TR1 = 1;

    EA = 1;
    ES = 1;//打开串口接收中断允许
    RI = 0;
    TI = 0;

    EX0 = 1;
    IT0 = 1;
}

void External0_Handler() interrupt 0
{
    u8 i;
    u8 arrString[] = "Hello world ";
    for ( i = 0; i < 13; i++)
    {
        SBUF = arrString[i];
        while (!TI);
        TI = 0;
    }
    
}

void main()
{
    UART_Init();
    while (1);
}

