#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initDeviceControl(struct DeviceControl* dev);
void checkstatus(struct DeviceControl* dev);
struct DeviceControl* allocateDeviceArray(int n);
void toggleLED(struct DeviceControl* dev, bool switchgear);

struct DeviceControl {
    unsigned char LED;
    unsigned char Buzzer;
    float temperature;
};//结构体的定义在头文件中声明！