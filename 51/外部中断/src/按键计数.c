#include "Com_Util.h"
#include <REG52.H>

sbit SegmentG1 = P2^0;
sbit SegmentG2 = P2^1;
sbit SegmentG3 = P2^2;
sbit SegmentG4 = P2^3;

sbit KEY1 = P3 ^2;

u8 count;

const unsigned char arrNumber[] = {0x03 , 0x9f , 0x25 , 0x0d , 0x99 , 0x49 , 0x41 , 0x1f , 0x01 , 0x09};//��ʼ���������ʾ����0-9

static void InitInterrupt()
{
  IT0 = 1;   //���� �ⲿ�ж�0 ������ʽΪ�½��ش���
  EX0 = 1;   //�� �ⲿ�ж�0 �ж�����

  IT1 = 1;   //���� �ⲿ�ж�1 ������ʽΪ�½��ش���
  EX1 = 1;   //�� �ⲿ�ж�1 �ж�����
  
  EA  = 1;   //�� ���ж�����
}

void External0_Handler() interrupt 0 
{
    Com_Util_Delaynms(20); //ȥ����
    if(KEY1 == 0) {
        count++;
    }
}

void main()
{
    InitInterrupt(); // �����ж�
    while (1) 
    {
        if (count > 9999) // ��ֹ���
        {
            count = 0; // ���ü������������˳�ѭ��
        }
        
        // ǧλ
        P0 = arrNumber[count / 1000];
        SegmentG4 = 0;
        Com_Util_Delaynms(5);
        SegmentG4 = 1;

        // ��λ
        P0 = arrNumber[(count / 100) % 10];
        SegmentG3 = 0;
        Com_Util_Delaynms(5);
        SegmentG3 = 1;

        // ʮλ
        P0 = arrNumber[(count / 10) % 10];
        SegmentG2 = 0;
        Com_Util_Delaynms(5);
        SegmentG2 = 1;

        // ��λ
        P0 = arrNumber[count % 10];
        SegmentG1 = 0;
        Com_Util_Delaynms(5);
        SegmentG1 = 1;
    }
}
