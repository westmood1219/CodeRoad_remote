#include "Com_Util.h"
#include <REG52.H>

sbit LED1 = P2^4;  //定义LED1
sbit LED2 = P2^5;  //定义LED2
sbit KEY1 = P3^2;   //定义按键,连接到外部中断0引脚

static void InitInterrupt()
{
  IT0 = 0;   //设置 外部中断0 触发方式为电平触发
  EX0 = 1;   //打开 外部中断0 中断允许

  IT1 = 1;   //设置 外部中断1 触发方式为下降沿触发
  EX1 = 1;   //打开 外部中断1 中断允许
  
  EA  = 1;   //打开 总中断允许
}

void External0_Handler() interrupt 0 
{
    Com_Util_Delaynms(20); //去抖动
    if(KEY1 == 0) {
        LED1 = 0; // 点亮LED1
    } else {
        LED1 = 1; // 熄灭LED1
    }
}

void External1_Handler() interrupt 2
{
  LED2 = ~LED2;   //翻转LED2开关状态
}

void main()
{
  InitInterrupt();  //配置中断
  while (1)
  {

  }
}
