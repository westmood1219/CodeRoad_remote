#include <STC89C5xRC.H>
#include <INTRINS.H>//������ʱ�������_nop_()

void Delay500ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(){
	
	/*unsigned char i;
	unsigned char j;*/
	P27 = 0;
	while (1)
  {
	//��ѭ����ʱ��
		/*P24 = 0;
		for(i=0;i<255;i++)
    {		for(j=0;j<255;j++)
			{	
			
			}
			
    }
		P24 = 1;
		for(i=0;i<255;i++)
    {
			for(j=0;j<255;j++)
    {	
			
    }
    }*/
		
	//�Ż�1:ȡ��
	/*P24 =~ P24;
		for(i=0;i<255;i++){
			for(j=0;j<255;j++){
			}
    }*/
		//�Ż�2:��׼�ٿ���˸ʱ��:
		P24 =~ P24;
		Delay500ms();
  }
	
	
}