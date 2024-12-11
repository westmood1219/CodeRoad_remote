#include <REG52.H>

static void DelayNms(int nms){
	
			unsigned char j;
			int i;
			for(i=0;i<nms;i++){
            for(j = 0; j < 123; j++) {
                // ÑÓÊ±
            }
					}
			}

void main()
{
    while (1)
    {
        P2 = 0xFF;
		DelayNms(1000);

        P2 = 0x7F;
		DelayNms(1000);

		P2 = 0x3F;
		DelayNms(1000);

        P2 = 0x1F;
		DelayNms(1000);
        
		P2 = 0x0F;
		DelayNms(1000);
    }
    
}