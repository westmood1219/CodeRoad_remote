#include "Com_Util.h"
#include <REG52.H>

sbit KEY1 = P3^2;      // ���尴������

bit current_style = 0;   // ��ǰ��ʽ��0 ��ʾ StyleOne��1 ��ʾ StyleTwo

void InitInterrupt()
{
    IT0 = 0;    // �����ⲿ�ж�0Ϊ�͵�ƽ����
    EX0 = 1;    // ʹ���ⲿ�ж�0
    EA  = 1;    // ʹ�����ж�
}

void External0_Handler() interrupt 0
{
    u16 i = 0;
    Com_Util_Delaynms(10);  // ����

    if(KEY1 == 0)
    {
        // ������ⰴ���Ƿ���
        while(KEY1 == 0)
        {
            Com_Util_Delaynms(1);  // ��ʱ1ms
            i++;
            if(i >= 3000)  // ���� 3 ��
            {
                break;
            }
        }

        if(i >= 3000)
        {
            // ���������л�����ʽ��
            current_style = 1;
        }
        else
        {
            // �̰������л�����ʽһ
            current_style = 0;
        }
    }
}

void StyleOne()
{
    // ��ʽһ���룬��������
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
    // ��ʽ�����룬��������
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
