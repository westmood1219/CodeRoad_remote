#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Windows�µ�Sleep����
#include <time.h>  // �������������
#include <stdbool.h>  // ʹ��bool����

// �����豸���ƽṹ�壬����LED�����������¶�
struct DeviceControl {
    unsigned char LED;      // LED ״̬
    unsigned char Buzzer;   // ������״̬
    float temperature;      // �¶�
};

// ��������
void initDeviceControl(struct DeviceControl* dev);  // ��ʼ���豸
void checkstatus(struct DeviceControl* dev, int size);  // ����豸״̬
struct DeviceControl* allocateDeviceArray(int n);  // ��̬�����豸����
void toggleLED(struct DeviceControl* dev, bool switchgear);  // ����LED����
void blinkLED(struct DeviceControl* dev, int times);  // ����LED��˸
void displayTemperature(struct DeviceControl* dev, float TEME);  // ��ʾ�豸�¶�
void controlBuzzer(struct DeviceControl* dev, bool switchgear);  // ���Ʒ�����
bool monitorDevice(struct DeviceControl* dev1, struct DeviceControl* dev2);  // ����豸״̬�仯