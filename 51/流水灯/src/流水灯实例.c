#include <STC89C5xRC.H>

static void DelayNms(int nms){
	
			unsigned char j;
			int i;
			for(i=0;i<nms;i++){
            for(j = 0; j < 123; j++) {
                // ÑÓÊ±
            }
					}
			}

void main(){
	unsigned char i;
	while(1){
		/*P2 = 0xEF;
		DelayNms(500);
		
		P2 = 0xDF;
		DelayNms(500);
		
		P2 = 0xBF;
		DelayNms(500);
		
		P2 = 0x7F;
		DelayNms(500);*/
		
		P2 = 0xEF;
		for(i=0;i<4;i++){
			DelayNms(500);
			P2 = P2 << 1;
		}
	}
}