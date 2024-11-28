#include "device_control.h"



int main()
{
    /*小题 1：结构体和初始化
    定义一个结构体 DeviceControl，包含以下成员：
    unsigned char LED：LED 寄存器（0 表示关闭，1 表示打开）。 unsigned char Buzzer：蜂鸣器寄存器（0 表示关闭，1 表示打开）。 float temperature：温度值。 编写一个函数 initDeviceControl，该函数接受一个 DeviceControl 类型的指针，并将所有成员初始化为默认值(全部关闭，温度值为0)。*/
    struct DeviceControl device1;
    initDeviceControl(&device1);
    checkstatus(&device1);
    /*小题 2：动态内存分配与数据记录
    编写一个函数 allocateDeviceArray，动态分配一个 DeviceControl 数组，并返回指向该数组的指针。数组的大小由函数参数指定。在 main 函数中，调用此函数并初始化数组中的每个元素。*/
    int n;
    printf("请输入DeviceControl数组大小：");
    scanf_s("%d", &n); 
    struct DeviceControl *device2 = allocateDeviceArray(n);
    if (device2 == NULL) {
        // 处理内存分配失败的情况
        printf("数组大小小于等于0/内存分配失败");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        initDeviceControl(device2+i);
    }
    checkstatus(device2);
    
        /*小题 3：LED 控制与闪烁功能
        编写一个函数 toggleLED，接受一个 DeviceControl 类型的指针和一个布尔值 status，用于控制 LED 的开关。如果 status 为 1，则打开 LED；如果为 0，则关闭 LED。再编写一个函数 blinkLED，该函数使 LED 持续闪烁指定的次数，每次闪烁的间隔为 500 毫秒（使用 sleep 或模拟延时）。*/
    bool status = true;
    toggleLED(&device1,status);
    checkstatus(&device1);


        /*小题 4：数码管显示温度
        编写一个函数 displayTemperature，接受一个 DeviceControl 类型的指针，将温度值格式化为字符串并打印到控制台，模拟数码管显示。你可以假设温度值在 0 到 100 之间。(可以用随机数，例如：20.0 + (rand() % 81))*/

       /* 小题 5：蜂鸣器控制和状态监测
        编写一个函数 controlBuzzer，接受一个 DeviceControl 类型的指针和一个布尔值 status，用于控制蜂鸣器的开关。然后编写一个函数 monitorDevice，周期性检查设备状态（LED 和蜂鸣器），并在状态发生变化时打印相应的信息。*/

        /*小题 6：释放内存
        对所用的动态数组进行内存释放。*/
    return 0;
}