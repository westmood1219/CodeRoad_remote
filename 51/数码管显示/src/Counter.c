#include <REG52.H>

sbit SegmentG1 = P2^3;
sbit SegmentG2 = P2^2;

sbit KEY1 = P3 ^2;

const unsigned char arrNumber[] = {0x03 , 0x9f , 0x25 , 0x0d , 0x99 , 0x49 , 0x41 , 0x1f , 0x01 , 0x09};//��ʼ���������ʾ����0-9

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
  unsigned char count = 0;
  unsigned char i;
  while(1){

    if (count>99)//��ֹ���
    {
      break;
    }
    
  for ( i = 0; i < 10; i++)
  {
      if (i == count / 10) {
          i = 10;//�˳�forѭ��
      }
  }
  P0= arrNumber[count/10];//ʮλ��
  SegmentG1 = 0;
  DelayNms(5);
  SegmentG1 = 1;

  for ( i = 0; i < 10; i++)
  {
      if (i == count % 10) {
          i = 10;//�˳�forѭ��
      }
  }
  P0 = arrNumber[count % 10];//��λ��
  SegmentG2 = 0;
  DelayNms(5);
  SegmentG2 = 1;
  

  if (0 == KEY1) {
      DelayNms(50);
      if (0 == KEY1) 
      {
          while (0 == KEY1);//��ֹ��һ�¼������������
          count++;
      }
    }      
  }

} 