#include "device_control.h"

void initDeviceControl(struct DeviceControl* dev) {
    if (dev != NULL) {
        dev->LED = 0;          // ��ʼ�� LED Ϊ�ر�
        dev->Buzzer = 0;       // ��ʼ�� Buzzer Ϊ�ر�
        dev->temperature = 0.0f; // ��ʼ���¶�Ϊ 0
    }
}

void checkstatus(struct DeviceControl* dev)
{
    int n = sizeof(dev) / sizeof(dev);
    printf("��ǰdevice״̬��\n");
    for (int i = 0; i < n; i++)
    {
        initDeviceControl(dev + i);
        printf("LED: %u\n", (dev + i)->LED);
        printf("Buzzer: %u\n", (dev + i)->Buzzer);
        printf("Temperature: %.2f\n", (dev + i)->temperature);
    }
}

struct DeviceControl* allocateDeviceArray(int n)
{
    if (n <= 0)
    {
        return NULL;
    }
    struct DeviceControl* dev = (struct DeviceControl *)malloc(sizeof(struct DeviceControl) * n);
    if (dev == NULL) {
        // �����ڴ����ʧ�ܵ���������緵�ش������ֹ����
        fprintf(stderr, "�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    return dev;
}

void toggleLED(struct DeviceControl* dev, bool switchgear)
{
    if (switchgear)
    {
        dev->LED = 1;
    }
    else
    {
        dev->LED = 0;
    }
}