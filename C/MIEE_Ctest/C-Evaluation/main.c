#include "device_control.h"

int main() {
    /* С�� 1���ṹ��ͳ�ʼ�� */
    struct DeviceControl device1;
    initDeviceControl(&device1);  // ��ʼ�� device1

    /* С�� 2����̬�ڴ���������ݼ�¼ */
    int n = 3;
    /*printf("\n������DeviceControl�����С��");
    scanf_s("%d", &n); *///������Թ����鷳��ȥ����
    struct DeviceControl* device2 = allocateDeviceArray(n);  // ��̬�����豸����
    if (device2 == NULL) {
        // �����ڴ����ʧ�ܵ����
        printf("�����СС�ڵ���0/�ڴ����ʧ��");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        initDeviceControl(device2 + i);  // ��ʼ��ÿ���豸Ԫ��
    }

    /* С�� 3��LED ��������˸���� */
    bool status = true;
    toggleLED(&device1, status);  // ���� LED ����
    // ������˸����Ϊ 3
    blinkLED(&device1, 3);  // ���� LED ��˸

    /* С�� 4���������ʾ�¶� */
    srand(time(NULL));  // �������������
    displayTemperature(&device1, 20.00 + (rand() % 81));  // ��ʾ����¶�

    /* С�� 5�����������ƺ�״̬��� */
    controlBuzzer(&device1, status);  // ���Ʒ�����
    int count = 20;
    while (count) {
        struct DeviceControl prevStatus = { device1.LED, device1.Buzzer, device1.temperature };  // ��¼��ǰ״̬
        /*���������豸״̬�仯������������*/
        bool i = monitorDevice(&device1, &prevStatus);  // ����豸״̬�仯
        if (i != true) {
            count--;  // ���û�б仯�����ټ���
        }
        else {
            count = 20;  // ����б仯�����ü���
        }
        Sleep(500);  // �ȴ� 500 ����
    }
    printf("deviceʮ��δ�任״̬��monitorDevice�˳�");

    /* С�� 6���ͷ��ڴ� */
    free(device2);  // �ͷŶ�̬������ڴ�

    return 0;
}