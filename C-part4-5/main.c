#include "swap.h"
//1假设要编写一个与结构相关的函数，是用结构体指针作为参数，还是用结构体作为参数和返回值？两者各有什么优缺点？
//上网找到使用结构体作为函数参数和返回值的示例代码，并将其改写为使用结构体指针作为函数参数的写法，反之也可。

//1答：用结构体指针作为参数。用结构体作为参数和返回值即创建了一个形参，浪费了内存空间，用指针则很好的进行了参数压栈，没有消耗过多性能。
//struct Books
//{
//    char  title[50];
//    char  author[50];
//    char  subject[100];
//    unsigned long long book_id; // 修改为 unsigned long long
//};
//
//void print1(struct Books p)
//{
//    printf("%s %s %s %llu\n", p.title, p.author, p.subject, p.book_id); // 使用 %llu 格式化输出
//}
//
//void print2(struct Books* sp)
//{
//    printf("%s %s %s %llu\n", sp->title, sp->author, sp->subject, sp->book_id); // 使用 %llu 格式化输出
//}
//
//int main()
//{
//    struct Books book = { "\n电路", "邱关源", "电子信息", 9787040565539ULL }; // 使用 ULL 后缀
//    print1(book);
//    print2(&book);
//    return 0;
//}

//2定义荔枝结构体(Litchi) .包括种类(如桂味、糯米、荔枝王、淮枝等)、颜色、核肉大小比、甜度、单价、成熟月份、产地等等信息。
//创建荔枝结构体数组，包括至少 3 个品种的共 6 颗荔枝。用结构体成员符号(.)的形式，访问输出 6 颗荔枝的详细信息。

 // 定义荔枝结构体
//struct Litchi {
//    char type[20];       // 种类
//    char color[20];      // 颜色
//    char kernelSize[20]; // 核肉大小比
//    char sweetness[20];  // 甜度
//    double price;        // 单价
//    char ripeMonth[20];  // 成熟月份
//    char origin[20];     // 产地
//};
//
//int main() {
//    struct Litchi litchis[6] = {
//        {"桂味", "鲜红", "小核", "高甜", 15.5, "6月", "广东"},
//        {"糯米糍", "乳白", "中等核", "中甜", 13.8, "7月", "广西"},
//        {"荔枝王", "深红", "大核", "超高甜", 20.0, "8月", "海南"},
//        {"淮枝", "淡黄", "小核", "低甜", 9.9, "5月", "福建"},
//        {"白糖罂", "鲜红", "小核", "高甜", 18.0, "6月", "广东"},
//        {"挂绿", "青绿", "小核", "中甜", 25.0, "7月", "广东"}
//    };
//    //表格化
//    // 打印表头
//    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//        "种类", "颜色", "核肉大小比", "甜度", "单价", "成熟月份", "产地");
//
//    // 打印每颗荔枝的信息
//    for (int i = 0; i < 6; i++) {
//        printf("%-10s %-10s %-10s %-10s %-10.1f %-10s %-10s\n",
//            litchis[i].type, litchis[i].color, litchis[i].kernelSize, litchis[i].sweetness,
//            litchis[i].price, litchis[i].ripeMonth, litchis[i].origin);
//    }
//    return 0;
//}


//3基于 Task 1，用结构体指针 (->)的形式访问荔枝结构体数组，根据每颗荔枝的价格按从高到低排序输出各荔枝的信息
//struct Litchi {
//    char type[20];       // 种类
//    char color[20];      // 颜色
//    char kernelSize[20]; // 核肉大小比
//    char sweetness[20];  // 甜度
//    double price;        // 单价
//    char ripeMonth[20];  // 成熟月份
//    char origin[20];     // 产地
//};
//
//int main() {
//    struct Litchi litchis[6] = {
//        {"桂味", "鲜红", "小核", "高甜", 15.5, "6月", "广东"},
//        {"糯米糍", "乳白", "中等核", "中甜", 13.8, "7月", "广西"},
//        {"荔枝王", "深红", "大核", "超高甜", 20.0, "8月", "海南"},
//        {"淮枝", "淡黄", "小核", "低甜", 9.9, "5月", "福建"},
//        {"白糖罂", "鲜红", "小核", "高甜", 18.0, "6月", "广东"},
//        {"挂绿", "青绿", "小核", "中甜", 25.0, "7月", "广东"}
//    };
//    //冒个泡
//    for (int i = 0; i < 6 - 1; i++) {
//        for (int j = 0; j < 6 - 1 - i; j++) {
//            struct Litchi* lp1 = &litchis[j];
//            struct Litchi* lp2 = &litchis[j + 1];
//            if (lp1->price < lp2->price) {
//                // 交换两个结构体
//                struct Litchi temp = *lp1;
//                *lp1 = *lp2;
//                *lp2 = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 6; i++) {
//        printf("%-10s %-10s %-10s %-10s %-10.1f %-10s %-10s\n",
//            litchis[i].type, litchis[i].color, litchis[i].kernelSize, litchis[i].sweetness,
//            litchis[i].price, litchis[i].ripeMonth, litchis[i].origin);
//    }
//    return 0;
//}

//4MIEE协会有 10 位同学新增信息录入，有名字(字符串类型)、学号、专业、学院(字符串类型)、已经完成学习的部分如C语言章节2等(字符串类型)。创建结构体数组管理上述 10 位同学的信息，用结构体指针访问该数组，根据用户输入的学号和姓名，输出满足该位同学的信息
//struct MIEE {
//    char name[10];
//    int studentId;
//    char major[20];
//    char college[20];
//    char completedCourses[20];
//};
//int main()
//{
//    struct MIEE newbirds[10] = {
//        {"张三", 1001, "计算机科学", "计算机学院", "C语言章节2"},
//        {"李四", 1002, "软件工程", "计算机学院", "C语言章节1"},
//        {"王五", 1003, "网络工程", "通信学院", "C语言章节3"},
//        {"赵六", 1004, "人工智能", "计算机学院", "C语言章节4"},
//        {"孙七", 1005, "数据科学", "数学学院", "C语言章节5"},
//        {"周八", 1006, "电子信息", "电子工程学院", "C语言章节6"},
//        {"吴九", 1007, "物联网", "计算机学院", "C语言章节7"},
//        {"郑十", 1008, "机器人", "机械工程学院", "C语言章节8"},
//        {"李十一", 1009, "环境工程", "环境学院", "C语言章节9"},
//        {"张十二", 1010, "材料科学", "材料学院", "C语言章节10"}
//    };
//    int id;
//    char name1[20];
//    scanf_s("%d %s", &id, name1);
//    int index = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (newbirds[i].studentId == id)
//        {
//            index = i;
//            break;
//        }
//    }
//    printf("%s %d %s %s %s", newbirds[index].name, newbirds[index].studentId, newbirds[index].major, newbirds[index].college, newbirds[index].completedCourses);
//    return 0;
//}

//challenge:现在有三个LED灯，每个LED灯都有其对应的颜色（红-绿-蓝）和亮度（最低为0，最高为100）
// 现在要实现三个LED灯以红灯->绿灯->蓝灯的顺序显示，且每个灯的点亮时间为2s，亮度为0->100->0，使用printf语句模拟这个过程
//struct LED {
//    char color[10];
//    int brightness;
//
//};
//int main()
//{
//    struct LED Led[3] = {
//        {"Red LED", 0},
//        {"Green LED", 0},
//        {"Blue LED", 0},
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        printf("Turning on %s...\n", Led[i].color);
//        int time_interval = 10;  // 2 秒分成 200 份，每份 10毫秒
//        while (Led[i].brightness <= 100)
//        {
//            printf("LED %d: Brightness = %d%%\n", i+1, Led[i].brightness);
//            Led[i].brightness++;
//            Sleep(time_interval);  // 延迟 10 毫秒
//        }//最后亮度为101，需要减二以实现直接降亮度
//        Led[i].brightness -= 2;
//        while (Led[i].brightness >= 0)
//        {
//            printf("LED %d: Brightness = %d%%\n", i+1, Led[i].brightness);
//            Led[i].brightness--;
//            Sleep(time_interval);  // 延迟 10 毫秒
//        }
//    }
//    return 0;
//}
//从键盘获取输入两个整数赋值给变量 a 和 b,要求以 swap 函数形式实现 a 和b 的数值交换。函数形参要求必须是指针变量。
// //将以上任务以多文件的组织形式实现 ，main.c函数只负责流程管理，具体交换功能由函数调用和实现，且函数声明及其定义分别存放在swap.h和swap.c中。
int main()
{
    int a = 0;
    int b = 0;
    printf("输入a，b：");
    scanf_s("%d %d", &a, &b);
    swap(&a, &b);
    return 0;
}