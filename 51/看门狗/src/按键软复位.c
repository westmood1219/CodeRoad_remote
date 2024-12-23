#include <reg52.H>

sfr ISP_CONTR = 0xE7;


static void DelayNms(int nms)
{
	
    unsigned char j;
    int i;
    for(i=0;i<nms;i++){
    for(j = 0; j < 123; j++) {
        // 延时
        }
    }
}

static void InitInterrupt()
{
    EA = 1;
    EX0 = 1;
    IT0 = 1;
}
void main(){
	unsigned char i;
    InitInterrupt();
    while(1)
    {

		P2 = 0xEF;
		for(i=0;i<4;i++)
        {
			DelayNms(500);
			P2 = P2 << 1;
		}
	}
}

void External0_Handler() interrupt 0 
{
  
    ISP_CONTR |= 0x20;//执行软件复位
}