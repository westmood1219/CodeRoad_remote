#include "device_control.h"

int main() {
    /* 小题 1：结构体和初始化 */
    struct DeviceControl device1;
    initDeviceControl(&device1);  // 初始化 device1

    /* 小题 2：动态内存分配与数据记录 */
    int n = 3;
    /*printf("\n请输入DeviceControl数组大小：");
    scanf_s("%d", &n); *///避免调试过程麻烦免去输入
    struct DeviceControl* device2 = allocateDeviceArray(n);  // 动态分配设备数组
    if (device2 == NULL) {
        // 处理内存分配失败的情况
        printf("数组大小小于等于0/内存分配失败");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        initDeviceControl(device2 + i);  // 初始化每个设备元素
    }

    /* 小题 3：LED 控制与闪烁功能 */
    bool status = true;
    toggleLED(&device1, status);  // 控制 LED 开关
    // 假设闪烁次数为 3
    blinkLED(&device1, 3);  // 控制 LED 闪烁

    /* 小题 4：数码管显示温度 */
    srand(time(NULL));  // 设置随机数种子
    displayTemperature(&device1, 20.00 + (rand() % 81));  // 显示随机温度

    /* 小题 5：蜂鸣器控制和状态监测 */
    controlBuzzer(&device1, status);  // 控制蜂鸣器
    int count = 20;
    while (count) {
        struct DeviceControl prevStatus = { device1.LED, device1.Buzzer, device1.temperature };  // 记录当前状态
        /*假设这里设备状态变化······*/
        bool i = monitorDevice(&device1, &prevStatus);  // 监测设备状态变化
        if (i != true) {
            count--;  // 如果没有变化，减少计数
        }
        else {
            count = 20;  // 如果有变化，重置计数
        }
        Sleep(500);  // 等待 500 毫秒
    }
    printf("device十秒未变换状态，monitorDevice退出");

    /* 小题 6：释放内存 */
    free(device2);  // 释放动态分配的内存

    return 0;
}