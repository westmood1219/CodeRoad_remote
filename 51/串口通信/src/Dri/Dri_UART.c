#include "Dri_UART.h"
#include "Com_Util.h"
#include <REG52.H>


void Dri_UART_Init()
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
