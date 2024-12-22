#include "Dri_UART.h"
#include "Com_Util.h"
#include <REG52.H>


void Dri_UART_Init()
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
