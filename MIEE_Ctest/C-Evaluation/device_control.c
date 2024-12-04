#include "device_control.h"

// 初始化设备控制结构体
void initDeviceControl(struct DeviceControl* dev) {
    if (dev != NULL) {
        dev->LED = 0;          // 初始化 LED 为关闭
        dev->Buzzer = 0;       // 初始化 Buzzer 为关闭
        dev->temperature = 0.0f; // 初始化温度为 0
    }
}

// 打印设备状态
void checkstatus(struct DeviceControl* dev, int size) {
    if (size <= 1) {
        // 如果设备数组大小为1，则打印设备状态
        printf("当前device状态：\n");
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
        // 如果设备数组大小大于1，逐个打印设备状态
        printf("当前device状态：\n");
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

// 动态分配设备数组
struct DeviceControl* allocateDeviceArray(int n) {
    if (n <= 0) {
        return NULL;  // 如果数组大小小于等于0，返回NULL
    }
    struct DeviceControl* dev = (struct DeviceControl*)malloc(sizeof(struct DeviceControl) * n);
    if (dev == NULL) {
        // 处理内存分配失败的情况
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);  // 内存分配失败时终止程序
    }
    return dev;
}

// 控制 LED 的开关
void toggleLED(struct DeviceControl* dev, bool switchgear) {
    if (switchgear) {
        dev->LED = 1;  // 开启 LED
    }
    else {
        dev->LED = 0;  // 关闭 LED
    }
}

// 控制 LED 闪烁
void blinkLED(struct DeviceControl* dev, int times) {
    dev->LED = 1;  // 开启 LED
    printf("LED is on.\n");
    for (int i = 1; i < times; i++) {  // 次数从1开始，确保第一次 LED 已开启
        printf("LED is off.\n");
        Sleep(500);  // 暂停 500 毫秒
        printf("LED is on.\n");
    }
}

// 显示设备温度
void displayTemperature(struct DeviceControl* dev, float TEME) {
    dev->temperature = TEME;
    char str[50];  // 字符串大小可以设置为 50
    int size = sizeof(str) / sizeof(str[0]);  // 获取字符串长度
    snprintf(str, size, "%.2f", dev->temperature);  // 格式化温度
    printf("the device's temperatrue is %s now\n", str);  // 打印温度
}

// 控制蜂鸣器的开关
void controlBuzzer(struct DeviceControl* dev, bool switchgear) {
    if (switchgear) {
        dev->Buzzer = 1;  // 开启蜂鸣器
    }
    else {
        dev->Buzzer = 0;  // 关闭蜂鸣器
    }
}

// 监控设备状态的变化
bool monitorDevice(struct DeviceControl* dev1, struct DeviceControl* dev2) {
    if (dev1->LED != dev2->LED) {  // 检查 LED 状态是否发生变化
        printf("当前设备LED状态改变\n");
        if (dev1->LED == 1) {
            printf("The LED is on now.\n");
        }
        else {
            printf("The LED is off now.\n");
        }
        return true;  // 如果发生变化，返回 true
    }
    if (dev1->Buzzer != dev2->Buzzer) {  // 检查蜂鸣器状态是否发生变化
        printf("当前设备Buzzer状态改变\n");
        if (dev1->Buzzer == 1) {
            printf("The Buzzer is on now.\n");
        }
        else {
            printf("The Buzzer is off now.\n");
        }
        return true;  // 如果发生变化，返回 true
    }
    return false;  // 如果没有变化，返回 false
}