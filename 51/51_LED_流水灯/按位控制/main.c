#include <STC89C5xRC.H>

// ���� LED ����
sbit LED1 = P2^4;
sbit LED2 = P2^5;
sbit LED3 = P2^6;
sbit LED4 = P2^7;
//sbit������ں����ⲿ��ͨ�������ļ��Ķ�����ȷ����Щ�����������ļ��ж���Ч

static void DelayNms(int nms){
	
			unsigned char j;
			int i;
			for(i=0;i<nms;i++){
            for(j = 0; j < 123; j++) {
                // ��ʱ����������
            }
					}
			}

void main(){
		int nms;// �����������ں�����ʼ����
		nms = 500;//�ӳ�ʱ��n����

    while(1) {
        LED1 = 0;
				DelayNms(nms);
			
        LED1 = 1;
        LED2 = 0;
				DelayNms(nms);

        LED2 = 1;
        LED3 = 0;
				DelayNms(nms);

        LED3 = 1;
        LED4 = 0;
				DelayNms(nms);
			
				LED4 = 1;
        }
    }