#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // Windows下的Sleep函数
#include <time.h>  // 用于生成随机数
#include <stdbool.h>  // 使用bool类型

// 定义设备控制结构体，包含LED、蜂鸣器和温度
struct DeviceControl {
    unsigned char LED;      // LED 状态
    unsigned char Buzzer;   // 蜂鸣器状态
    float temperature;      // 温度
};

// 函数声明
void initDeviceControl(struct DeviceControl* dev);  // 初始化设备
void checkstatus(struct DeviceControl* dev, int size);  // 检查设备状态
struct DeviceControl* allocateDeviceArray(int n);  // 动态分配设备数组
void toggleLED(struct DeviceControl* dev, bool switchgear);  // 控制LED开关
void blinkLED(struct DeviceControl* dev, int times);  // 控制LED闪烁
void displayTemperature(struct DeviceControl* dev, float TEME);  // 显示设备温度
void controlBuzzer(struct DeviceControl* dev, bool switchgear);  // 控制蜂鸣器
bool monitorDevice(struct DeviceControl* dev1, struct DeviceControl* dev2);  // 监控设备状态变化