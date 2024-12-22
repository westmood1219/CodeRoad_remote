#include <REG52.H>
#include "Com_Util.h"

void UART_Init()
{
    SCON = 0X50;//���� ���� ����ģʽ1�����򿪽�������

    PCON = 0X80;//���� �����ʼӱ�

    TMOD = 0X20;//����ģʽ��

    TL1 = 0xF3;
    TH1 = 0XF3;

    TR1 = 1;

    EA = 1;
    ES = 1;//�򿪴��ڽ����ж�����
    RI = 0;
    TI = 0;

    EX0 = 1;
    IT0 = 1;
}

void External0_Handler() interrupt 0
{
    u8 i;
    u8 arrString[] = "Hello world ";
    for ( i = 0; i < 13; i++)
    {
        SBUF = arrString[i];
        while (!TI);
        TI = 0;
    }
    
}

void main()
{
    UART_Init();
    while (1);
}

