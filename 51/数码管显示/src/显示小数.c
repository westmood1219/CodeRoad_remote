#include <REG52.H>

sbit SegmentG1 = P2^3;  //定义数码管1
sbit SegmentG2 = P2^2;  //定义数码管2
sbit SegmentG3 = P2^1;  //定义数码管3
sbit SegmentG4 = P2^0;  //定义数码管4

const unsigned char arrNumber[] = {0x03 , 0x9f , 0x25 , 0x0d , 0x99 , 0x49 , 0x41 , 0x1f , 0x01 , 0x09};//初始化数码管显示数字0-9

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
  while (1)
  {
    P0 = arrNumber[3]; 
    SegmentG1 = 0;   
    DelayNms(5);    
    SegmentG1 = 1;

    P0 = 0xFE;
    SegmentG1 = 0;   
    DelayNms(5);    
    SegmentG1 = 1;   
    
    P0 = arrNumber[1]; 
    SegmentG2 = 0;   
    DelayNms(5);    
    SegmentG2 = 1;   
  
    P0 = arrNumber[4]; 
    SegmentG3 = 0;   
    DelayNms(5);    
    SegmentG3 = 1;   
   
    P0 = arrNumber[1]; 
    SegmentG4 = 0;   
    DelayNms(5);    
    SegmentG4 = 1;   
  }
}
