#include <REG52.H>
#include <EEPROM.h>
#include "Com_Util.h"

sbit SegmentG1 = P2^0;
sbit SegmentG2 = P2^1;
sbit SegmentG3 = P2^2;
sbit SegmentG4 = P2^3;

u8 count;

const unsigned char arrNumber[] = {0x03 , 0x9f , 0x25 , 0x0d , 0x99 , 0x49 , 0x41 , 0x1f , 0x01 , 0x09};//初始化数码管显示数字0-9

static void InitInterrupt()
{
  IT0 = 1;   //设置 外部中断0 触发方式为下降沿触发
  EX0 = 1;   //打开 外部中断0 中断允许

  IT1 = 1;   //设置 外部中断1 触发方式为下降沿触发
  EX1 = 1;   //打开 外部中断1 中断允许
  
  EA  = 1;   //打开 总中断允许
}

void External0_Handler() interrupt 0 
{
    count++;
    
    if (count > 255) // 防止溢出
    {
        count = 0; // 重置计数器
    }
    IAPSectorErase(0x2000);           //擦除起始地址为0x2000的扇区
    IAPByteWrite(0x2000,count);          //对起始地址为0x2000的扇区写入count的值  
}  

static void DelayNms(int nms)
{
  unsigned int i,j;
  for(i = 0; i < nms; i++)
  {
    for(j = 0; j < 123; j++)
    {
    } 
  }
}

void main()
{
    count = IAPByteRead(0x2000);               //读取起始地址为0x2000的扇区中的值，赋值给count,使计数器保持关闭前的状态
    InitInterrupt(); // 配置中断
    while (1) 
    {
        
        // 百位
        P0 = arrNumber[(count / 100) % 10];
        SegmentG3 = 0;
        DelayNms(5);
        SegmentG3 = 1;

        // 十位
        P0 = arrNumber[(count / 10) % 10];
        SegmentG2 = 0;
        DelayNms(5);
        SegmentG2 = 1;

        // 个位
        P0 = arrNumber[count % 10];
        SegmentG1 = 0;
        DelayNms(5);
        SegmentG1 = 1;
    }
}
