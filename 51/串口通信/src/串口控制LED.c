#include <REG52.H>
#include "Com_Util.h"

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
    while (1);
}

    void UART_Handler() interrupt 4
{
    u8 i;
    if(RI == 1)
    {
        i = SBUF - '0';  // 将ASCII字符转换为数字
        if(i >= 1 && i <= 4)
        {
            P2 = 0x0F | (0xEF << (i - 1));
        }
        RI = 0;
    }
    if(i < 1 || i > 4)
    {
        // 处理无效输入，闪烁所有LED
        P2 = 0x0F;
    }
}