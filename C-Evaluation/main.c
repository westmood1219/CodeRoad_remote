#include "device_control.h"



int main()
{
    /*С�� 1���ṹ��ͳ�ʼ��
    ����һ���ṹ�� DeviceControl���������³�Ա��
    unsigned char LED��LED �Ĵ�����0 ��ʾ�رգ�1 ��ʾ�򿪣��� unsigned char Buzzer���������Ĵ�����0 ��ʾ�رգ�1 ��ʾ�򿪣��� float temperature���¶�ֵ�� ��дһ������ initDeviceControl���ú�������һ�� DeviceControl ���͵�ָ�룬�������г�Ա��ʼ��ΪĬ��ֵ(ȫ���رգ��¶�ֵΪ0)��*/
    struct DeviceControl device1;
    initDeviceControl(&device1);
    checkstatus(&device1);
    /*С�� 2����̬�ڴ���������ݼ�¼
    ��дһ������ allocateDeviceArray����̬����һ�� DeviceControl ���飬������ָ��������ָ�롣����Ĵ�С�ɺ�������ָ������ main �����У����ô˺�������ʼ�������е�ÿ��Ԫ�ء�*/
    int n;
    printf("������DeviceControl�����С��");
    scanf_s("%d", &n); 
    struct DeviceControl *device2 = allocateDeviceArray(n);
    if (device2 == NULL) {
        // �����ڴ����ʧ�ܵ����
        printf("�����СС�ڵ���0/�ڴ����ʧ��");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        initDeviceControl(device2+i);
    }
    checkstatus(device2);
    
        /*С�� 3��LED ��������˸����
        ��дһ������ toggleLED������һ�� DeviceControl ���͵�ָ���һ������ֵ status�����ڿ��� LED �Ŀ��ء���� status Ϊ 1����� LED�����Ϊ 0����ر� LED���ٱ�дһ������ blinkLED���ú���ʹ LED ������˸ָ���Ĵ�����ÿ����˸�ļ��Ϊ 500 ���루ʹ�� sleep ��ģ����ʱ����*/
    bool status = true;
    toggleLED(&device1,status);
    checkstatus(&device1);


        /*С�� 4���������ʾ�¶�
        ��дһ������ displayTemperature������һ�� DeviceControl ���͵�ָ�룬���¶�ֵ��ʽ��Ϊ�ַ�������ӡ������̨��ģ���������ʾ������Լ����¶�ֵ�� 0 �� 100 ֮�䡣(����������������磺20.0 + (rand() % 81))*/

       /* С�� 5�����������ƺ�״̬���
        ��дһ������ controlBuzzer������һ�� DeviceControl ���͵�ָ���һ������ֵ status�����ڿ��Ʒ������Ŀ��ء�Ȼ���дһ������ monitorDevice�������Լ���豸״̬��LED �ͷ�������������״̬�����仯ʱ��ӡ��Ӧ����Ϣ��*/

        /*С�� 6���ͷ��ڴ�
        �����õĶ�̬��������ڴ��ͷš�*/
    return 0;
}