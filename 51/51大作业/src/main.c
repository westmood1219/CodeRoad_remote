#include <REG52.H>
#include "Com_Util.h"
#include <STDIO.H>

static u16 year = 2025;
static u16 month = 2;
static u16 day   = 28;
static u16 hour  = 23;
static u16 minute = 59;
static u16 second = 50;
static u16 week = 5;
static u16 days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//定时器0配置函数（1ms溢出）
static void InitTimer0()
{
  TMOD|=0x01;
  TH0 = 0xFC;
  TL0 = 0x18;
  TR0 = 1;
}
 
//串口配置函数
static void InitUART()
{
  SCON = 0X50;           //设置串口 工作模式1，并打开接收允许
  TMOD |= 0X20;           //设置定时器1为工作模式2（8位自动重装定时器）
  PCON = 0X80;           //设置波特率加倍
  TL1  = 0XF3;           //设置定时器1的计数初值，波特率为4800
  TH1  = TL1;            //设置定时器1重装载值
  TR1  = 1;              //打开定时器1
  TI = 1;                //使串口一直处于发送状态
}
 
//中断配置函数
static void InitInterrupt()
{ 
  ET0 = 1; //定时器0中断允许
	
  EA = 1;  //总中断允许
}

void Timer0_Handler() interrupt 1
{
    static u16 s_iCounter;
    TH0 = 0xFC;
    TL0 = 0x18;
    s_iCounter++;
    if (s_iCounter >= 1000)  // 1秒
    {
        s_iCounter = 0;  // 重置计数器
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
            if (minute >= 60)
            {
                minute = 0;
                hour++;
                if (hour >= 24)
                {
                    hour = 0;
                    day++;
                    // 加一天就更新星期
                    week = (week % 7) + 1;
                    if (week > 7)
                    {
                        week = 1;
                    }
                    if (day > days_in_month[month - 1])
                    {
                        day = 1;
                        month++;
                        if (month > 12)
                        {
                            month = 1;
                            year++;
                        }
                    }
                }
            }
        }
        printf(" %d-%d-%d %d:%d:%d 星期", year, month, day, hour, minute, second);
        printf("%d ", week);
    }
}

void main()
{
    InitTimer0();
    InitUART();
    InitInterrupt();
    while (1)
    {
        //主循环
    }
}

