#include "device_control.h"

// ��ʼ���豸���ƽṹ��
void initDeviceControl(struct DeviceControl* dev) {
    if (dev != NULL) {
        dev->LED = 0;          // ��ʼ�� LED Ϊ�ر�
        dev->Buzzer = 0;       // ��ʼ�� Buzzer Ϊ�ر�
        dev->temperature = 0.0f; // ��ʼ���¶�Ϊ 0
    }
}

// ��ӡ�豸״̬
void checkstatus(struct DeviceControl* dev, int size) {
    if (size <= 1) {
        // ����豸�����СΪ1�����ӡ�豸״̬
        printf("��ǰdevice״̬��\n");
        printf("LED: %u\n", dev->LED);
        if (dev->LED == 1) {
            printf("This LED is on.\n");
        }
        else {
            printf("This LED is off.\n");
        }
        printf("Buzzer: %u\n", dev->Buzzer);
        printf("Temperature: %.2f\n\n", dev->temperature);
    }
    else {
        // ����豸�����С����1�������ӡ�豸״̬
        printf("��ǰdevice״̬��\n");
        for (int i = 0; i < size; i++) {
            printf("LED: %u\n", (dev + i)->LED);
            if ((dev + i)->LED == 1) {
                printf("This LED is on.\n");
            }
            else {
                printf("This LED is off.\n");
            }
            printf("Buzzer: %u\n", (dev + i)->Buzzer);
            printf("Temperature: %.2f\n\n", (dev + i)->temperature);
        }
    }
}

// ��̬�����豸����
struct DeviceControl* allocateDeviceArray(int n) {
    if (n <= 0) {
        return NULL;  // ��������СС�ڵ���0������NULL
    }
    struct DeviceControl* dev = (struct DeviceControl*)malloc(sizeof(struct DeviceControl) * n);
    if (dev == NULL) {
        // �����ڴ����ʧ�ܵ����
        fprintf(stderr, "�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);  // �ڴ����ʧ��ʱ��ֹ����
    }
    return dev;
}

// ���� LED �Ŀ���
void toggleLED(struct DeviceControl* dev, bool switchgear) {
    if (switchgear) {
        dev->LED = 1;  // ���� LED
    }
    else {
        dev->LED = 0;  // �ر� LED
    }
}

// ���� LED ��˸
void blinkLED(struct DeviceControl* dev, int times) {
    dev->LED = 1;  // ���� LED
    printf("LED is on.\n");
    for (int i = 1; i < times; i++) {  // ������1��ʼ��ȷ����һ�� LED �ѿ���
        printf("LED is off.\n");
        Sleep(500);  // ��ͣ 500 ����
        printf("LED is on.\n");
    }
}

// ��ʾ�豸�¶�
void displayTemperature(struct DeviceControl* dev, float TEME) {
    dev->temperature = TEME;
    char str[50];  // �ַ�����С��������Ϊ 50
    int size = sizeof(str) / sizeof(str[0]);  // ��ȡ�ַ�������
    snprintf(str, size, "%.2f", dev->temperature);  // ��ʽ���¶�
    printf("the device's temperatrue is %s now\n", str);  // ��ӡ�¶�
}

// ���Ʒ������Ŀ���
void controlBuzzer(struct DeviceControl* dev, bool switchgear) {
    if (switchgear) {
        dev->Buzzer = 1;  // ����������
    }
    else {
        dev->Buzzer = 0;  // �رշ�����
    }
}

// ����豸״̬�ı仯
bool monitorDevice(struct DeviceControl* dev1, struct DeviceControl* dev2) {
    if (dev1->LED != dev2->LED) {  // ��� LED ״̬�Ƿ����仯
        printf("��ǰ�豸LED״̬�ı�\n");
        if (dev1->LED == 1) {
            printf("The LED is on now.\n");
        }
        else {
            printf("The LED is off now.\n");
        }
        return true;  // ��������仯������ true
    }
    if (dev1->Buzzer != dev2->Buzzer) {  // ��������״̬�Ƿ����仯
        printf("��ǰ�豸Buzzer״̬�ı�\n");
        if (dev1->Buzzer == 1) {
            printf("The Buzzer is on now.\n");
        }
        else {
            printf("The Buzzer is off now.\n");
        }
        return true;  // ��������仯������ true
    }
    return false;  // ���û�б仯������ false
}