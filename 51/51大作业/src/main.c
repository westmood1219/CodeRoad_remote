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

//��ʱ��0���ú�����1ms�����
static void InitTimer0()
{
  TMOD|=0x01;
  TH0 = 0xFC;
  TL0 = 0x18;
  TR0 = 1;
}
 
//�������ú���
static void InitUART()
{
  SCON = 0X50;           //���ô��� ����ģʽ1�����򿪽�������
  TMOD |= 0X20;           //���ö�ʱ��1Ϊ����ģʽ2��8λ�Զ���װ��ʱ����
  PCON = 0X80;           //���ò����ʼӱ�
  TL1  = 0XF3;           //���ö�ʱ��1�ļ�����ֵ��������Ϊ4800
  TH1  = TL1;            //���ö�ʱ��1��װ��ֵ
  TR1  = 1;              //�򿪶�ʱ��1
  TI = 1;                //ʹ����һֱ���ڷ���״̬
}
 
//�ж����ú���
static void InitInterrupt()
{ 
  ET0 = 1; //��ʱ��0�ж�����
	
  EA = 1;  //���ж�����
}

void Timer0_Handler() interrupt 1
{
    static u16 s_iCounter;
    TH0 = 0xFC;
    TL0 = 0x18;
    s_iCounter++;
    if (s_iCounter >= 1000)  // 1��
    {
        s_iCounter = 0;  // ���ü�����
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
                    // ��һ��͸�������
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
        printf(" %d-%d-%d %d:%d:%d ����", year, month, day, hour, minute, second);
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
        //��ѭ��
    }
}

