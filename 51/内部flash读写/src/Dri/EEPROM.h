#ifndef __DRI_EEPROM__
#define __DRI_EEPROM__

sfr ISP_DATA  = 0XE2;    //����ISP-IAP����ʱ�����ݼĴ���
sfr ISP_ADDRH = 0XE3;    //����ISP-IAP������ַ�Ĵ�����λ
sfr ISP_ADDRL = 0XE4;    //����ISP-IAP������ַ�Ĵ�����λ
sfr ISP_CMD   = 0XE5;    //����ISP-IAP����Ĵ���
sfr ISP_TRIG  = 0XE6;    //����ISP-IAP������Ĵ���
sfr ISP_CONTR = 0XE7;    //����ISP-IAP����Ĵ���

void IAPSectorErase(unsigned int addr);                      //����ָ����������
void IAPByteWrite(unsigned int addr, unsigned char dat);     //�ֽ�д�뺯��
unsigned char IAPByteRead(unsigned int addr);                //�ֽڶ�ȡ����

#endif // !1