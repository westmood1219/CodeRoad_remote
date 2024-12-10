#include <STC89C5xRC.H>

// 定义 LED 引脚
sbit LED1 = P2^4;
sbit LED2 = P2^5;
sbit LED3 = P2^6;
sbit LED4 = P2^7;
//sbit定义放在函数外部，通常放在文件的顶部，确保这些定义在整个文件中都有效

static void DelayNms(int nms){
	
			unsigned char j;
			int i;
			for(i=0;i<nms;i++){
            for(j = 0; j < 123; j++) {
                // 延时或其他操作
            }
					}
			}

void main(){
		int nms;// 变量声明放在函数开始部分
		nms = 500;//延迟时间n毫秒

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