#include "Com_Util.h"
#include <REG52.H>

sbit LED1 = P2^4;  //����LED1
sbit LED2 = P2^5;  //����LED2
sbit KEY1 = P3^2;   //���尴��,���ӵ��ⲿ�ж�0����

static void InitInterrupt()
{
  IT0 = 0;   //���� �ⲿ�ж�0 ������ʽΪ��ƽ����
  EX0 = 1;   //�� �ⲿ�ж�0 �ж�����

  IT1 = 1;   //���� �ⲿ�ж�1 ������ʽΪ�½��ش���
  EX1 = 1;   //�� �ⲿ�ж�1 �ж�����
  
  EA  = 1;   //�� ���ж�����
}

void External0_Handler() interrupt 0 
{
    Com_Util_Delaynms(20); //ȥ����
    if(KEY1 == 0) {
        LED1 = 0; // ����LED1
    } else {
        LED1 = 1; // Ϩ��LED1
    }
}

void External1_Handler() interrupt 2
{
  LED2 = ~LED2;   //��תLED2����״̬
}

void main()
{
  InitInterrupt();  //�����ж�
  while (1)
  {

  }
}
