#include "Com_Util.h"
#include <REG52.H>

sbit KEY1 = P3^2;      // 定义按键引脚

bit current_style = 0;   // 当前样式，0 表示 StyleOne，1 表示 StyleTwo

void InitInterrupt()
{
    IT0 = 0;    // 设置外部中断0为低电平触发
    EX0 = 1;    // 使能外部中断0
    EA  = 1;    // 使能总中断
}

void External0_Handler() interrupt 0
{
    u16 i = 0;
    Com_Util_Delaynms(10);  // 消抖

    if(KEY1 == 0)
    {
        // 持续检测按键是否按下
        while(KEY1 == 0)
        {
            Com_Util_Delaynms(1);  // 延时1ms
            i++;
            if(i >= 3000)  // 长按 3 秒
            {
                break;
            }
        }

        if(i >= 3000)
        {
            // 长按处理，切换到样式二
            current_style = 1;
        }
        else
        {
            // 短按处理，切换到样式一
            current_style = 0;
        }
    }
}

void StyleOne()
{
    // 样式一代码，持续运行
    P2 = 0xEF;
    Com_Util_Delaynms(500);
    P2 = 0xCF;
    Com_Util_Delaynms(500);
    P2 = 0x8F;
    Com_Util_Delaynms(500);
    P2 = 0x0F;
    Com_Util_Delaynms(500);
    P2 = 0x1F;
    Com_Util_Delaynms(500);
    P2 = 0x3F;
    Com_Util_Delaynms(500);
    P2 = 0x7F;
    Com_Util_Delaynms(500);
    P2 = 0xFF;
    Com_Util_Delaynms(500);
}

void StyleTwo()
{
    // 样式二代码，持续运行
    P2 = 0xFE;
    Com_Util_Delaynms(500);
    P2 = 0xFD;
    Com_Util_Delaynms(500);
    P2 = 0xFB;
    Com_Util_Delaynms(500);
    P2 = 0xF7;
    Com_Util_Delaynms(500);
    P2 = 0xEF;
    Com_Util_Delaynms(500);
    P2 = 0xDF;
    Com_Util_Delaynms(500);
    P2 = 0xBF;
    Com_Util_Delaynms(500);
    P2 = 0x7F;
    Com_Util_Delaynms(500);
}

void main()
{
    InitInterrupt();
    while(1)
    {
        if(current_style == 0)
        {
            StyleOne();
        }
        else
        {
            StyleTwo();
        }
    }
}
