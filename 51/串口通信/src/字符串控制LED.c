#include <REG52.H>
#include "Com_Util.h"

static u8 s_Counter = 0;
static u8 arrBuffer[4];

void UART_Init()
{
    SCON = 0X50;//设置 串口 工作模式1，并打开接收允许

    PCON = 0X80;//设置 波特率加倍

    TMOD = 0X20;//工作模式二

    TL1 = 0xF3;
    TH1 = 0XF3;//波特率4800

    TR1 = 1;

    EA = 1;//all
    ES = 1;//打开串口接收中断允许
    RI = 0;
    TI = 0;
}

void main()
{
    UART_Init();
    while (1)
    {
        P2 = 0x0F | (0xEF << (arrBuffer[s_Counter-1]-'0'-1));
    }
}

    void UART_Handler() interrupt 4
{
    if(RI == 1)
    {
        arrBuffer[s_Counter] = SBUF;
        RI                   = 0;

        if (arrBuffer[s_Counter]>='0' && arrBuffer[s_Counter] <= 'z')
        {
            s_Counter++;
        }
    }
}