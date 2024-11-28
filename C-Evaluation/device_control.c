#include "device_control.h"

void initDeviceControl(struct DeviceControl* dev) {
    if (dev != NULL) {
        dev->LED = 0;          // 初始化 LED 为关闭
        dev->Buzzer = 0;       // 初始化 Buzzer 为关闭
        dev->temperature = 0.0f; // 初始化温度为 0
    }
}

void checkstatus(struct DeviceControl* dev)
{
    int n = sizeof(dev) / sizeof(dev);
    printf("当前device状态：\n");
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
        // 处理内存分配失败的情况，例如返回错误或终止程序
        fprintf(stderr, "内存分配失败\n");
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