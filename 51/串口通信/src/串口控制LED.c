#include <REG52.H>
#include "Com_Util.h"

void UART_Init()
{
    SCON = 0X50;//���� ���� ����ģʽ1�����򿪽�������

    PCON = 0X80;//���� �����ʼӱ�

    TMOD = 0X20;//����ģʽ��

    TL1 = 0xF3;
    TH1 = 0XF3;//������4800

    TR1 = 1;

    EA = 1;//all
    ES = 1;//�򿪴��ڽ����ж�����
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
        i = SBUF - '0';  // ��ASCII�ַ�ת��Ϊ����
        if(i >= 1 && i <= 4)
        {
            P2 = 0x0F | (0xEF << (i - 1));
        }
        RI = 0;
    }
    if(i < 1 || i > 4)
    {
        // ������Ч���룬��˸����LED
        P2 = 0x0F;
    }
}