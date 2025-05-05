//基本框架
#include <iostream>
using namespace std;

//常量的定义
#define Day 7//写在函数外部

int main()
{
    int a = 10;

    //常量
    cout << "一周有Day = " << Day << "天" << endl;
    //const常变量写在函数内部
    const int month = 12;
    cout << "一年有month = " << month << "个月" << endl;
    //sizeof
    cout << "long占用内存空间为:" << sizeof(long long) << endl;

    float f1 = 3.1415926f;//float稍微有点不一样,后面要加f不然会当作double处理
    cout << "f1 = " << f1 << endl;//最多六位 3.14159

    //科学计数法
    float f2 = 3e2;//3*10^2
    float f3 = 3e-2;//3*10^-2
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    system("pause");

    return 0;
}

//没说明就是和C一样
/*
命名规则 变量使用 注释
数据类型:整形 
部分关键字:sizeof 
*/