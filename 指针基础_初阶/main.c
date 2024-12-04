#include <stdio.h>

//内存空间是分成内存单元来管理的，每个最小的内存单元大小1byte（8bit）

//指针是什么？
//两个要点
//1.指针是内存中一个最小单元的编号，也就是地址
//2.常说的指针是指针变量，指针变量是用来存放地址的变量

//地址的产生：对于32位的机器，假设有32根地址线，那么假设每根地址线有两个状态，那么就有2^32个地址，也就是4G的地址空间
// 地址既然由32根地址线产生，那么地址就是一个32位的二进制数，也就是一个4字节的整数
//相应的，64位的机器有2^64个地址，也就是16EB的地址空间
//同上，64位的地址就是一个8字节的整数

//int main()
//{
//    int a = 10;//a是整型变量，占用4个字节
//    int* pa = &a;//pa是指针变量，存放a的地址
//    //pa是a四个字节的首地址
//    return 0;
//}

//int main()
//{
//    char* pc = NULL;//pc是指针变量，存放地址，NULL是一个宏定义，表示空指针
//    short* ps = NULL;
//    double* pd = NULL;
//    int* pi = NULL;
//    printf("%u\n", sizeof(pc));//指针变量的大小是8个字节,处于64位环境
//    printf("%u\n", sizeof(ps));//8
//    printf("%u\n", sizeof(pd));//8
//    printf("%u\n", sizeof(pi));//8
//    return 0;
//}

//指针和指针类型

//指针类型的意义：
//1：
//int main()
//{
//    int a = 0x11223344;
//    /*int* pa = &a;
//    *pa = 0;*/
//
//    /*char* pc = &a;*/
//
//    char* pc = (char*)&a;
//    *pc = 0;//内存监视窗口中，a的值变成了0x11223300
//      结论一：
//    //指针类型决定了指针在被解引用的时候访问几个字节
//    //如果是int*的指针，解引用访问4个字节
//    //如果是char*的指针，解引用访问1个字节
//    return 0;
//}
//
//2：
//int main()
//{
//    int a = 0x11223344;
//    int* pa = &a;
//    char* pc = &a;
//
//    printf("%p\n", pa);//
//    printf("%p\n", pc);//与上面一样
//
//    printf("%p\n", pa + 1);//
//    printf("%p\n", pc + 1);//地址比上面大三
//    //结论二：
//    //指针类型决定了指针进行加减运算时跨几个字节
//    //决定了指针的步长
//    return 0;
//}

//野指针、指针运算
//1:越界访问的原因
// 指针未初始化
//int main()
//{
//    int* p;
//    //p没有初始化，就意味着没有明确的指向
//    //一个局部变量不初始化，放的是随机值
//
//    *p = 10;//非法访问内存了，因为这里的p没有指向任何地方，是野指针
//    return 0;
//}
//越界访问
//int main()
//{
//    int arr[10] = { 0 };
//    int* p = arr;//&arr[0]
//    int i = 0;
//    for (i = 0; i <= 10; i++)
//    {
//        *p = i;//i=10时越界访问，形成野指针
//        p++;
//    }
//    return 0;
//}
//函数造成的野指针：函数调用结束后，函数内部的局部变量会被释放
//int* test()
//{
//    int a = 10;
//    return &a;
//}
//int main() {
//    int* p = test();//a已经被释放，p指向的是一个无效的内存空间，p是野指针
//    printf("%d\n", *p);//能打印出来是因为这个内存空间虽然被释放了但是里面的值还没有被覆盖（被其他程序使用）
//    return 0;
//}
//空指针导致的野指针
//int main()
//{
//    int b = 0;
//    int a = 10;
//    int* p = &a;
//    *p = 20;
//    //NULL是一个宏定义，表示空指针
//    int* p2 = NULL;
//    *p2 = 100;//没有权限访问这个地址，会报错
//    int* p3 = NULL;
//    if (p3 != NULL)//指针使用前检查有效性
//    {
//        *p3 = 20;
//    }
//    return 0;
//}

//指针运算
//1:指针加减整数
//#define N_VALUES 5
//int main()
//{
//    float values[N_VALUES];
//    float* vp;
//    //指针加减整数
//    for (vp = &values[0]; vp < &values[N_VALUES];)
//    {
//        *vp++ = 0;//先是*vp=0,然后vp++
//    }
//    return 0;
//}
//指针减指针//没有指针加指针,就好像没有日期加日期
//int main()
//{
//    int arr[10] = { 0 };
//    printf("%d\n", &arr[9] - &arr[0]);//9
//    //指针减指针，得到的是两个指针之间相差的元素个数
//    //注意,不是所有指针都可以相减，只有指向同一空间(比如数组)中的元素才可以相减
//    int arr[10] = { 0 };
//    char ch[5] = { 0 };
//    printf("%d\n", &arr[9] - &ch[0]);//err
//    return 0;
//}
//使用场景/用法
//int my_strlen(char* str)
//{
//    int count = 0;
//    while (*str != '\0')
//    {
//        count++;
//        str++;
//    }
//}//原版本
//指针减指针版本
//int my_strlen(char* str)
//{
//    char* start = str;
//    while (*str != '\0')
//    {
//        str++;
//    }
//    return str - start;
//}
//int main()
//{
//    int len = my_strlen("bacdef");
//    printf("%d\n", len);
//    return 0;
//}
//指针的关系运算
//#define N_VALUES 5
//int main()
//{
//    float values[N_VALUES];
//    float* vp;
//    for (vp = &values[N_VALUES]; vp > &values[N_VALUES];)
//    {
//        *--vp = 0;//先是--vp,然后*vp=0
//    }
//    for (vp = &values[N_VALUES-1]; vp >= &values[N_VALUES];vp--)
//    {
//        *vp = 0;
//    }//应该避免这样写,因为标准规定：
//    /*允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。*/
//    return 0;
//}
//&数组名时，得到的是整个数组的地址
//sizeof(数组名)得到的是整个数组的大小

//二级指针
//定义:指向指针的指针
//int main()
//{
//    int a = 10;
//    int* pa = &a;
//    int** ppa = &pa;//第二个*表示ppa是一个指针变量,第一个与int一起表示ppa指向的是一个int类型的指针变量
//    //二级指针变量用来存放一级指针变量的指针
//    printf("%d\n", **ppa);//10
//    return 0;
//}

//指针数组
//存放指针的数组
//int main()
//{
//    int a = 10;
//    int b = 20;
//    int c = 30;
//    int* arr[] = { &a, &b, &c };//arr是一个数组，数组中存放的是int*类型的指针
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        printf("%d\n", *arr[i]);
//    }
//    return 0;
//}
//指针数组模拟二维数组
int main()
{
    int arr1[4] = { 1, 2, 3, 4 };
    int arr2[4] = { 5, 6, 7, 8 };
    int arr3[4] = { 9, 10, 11, 12 };
    int* pArr[] = { arr1, arr2, arr3 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", pArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}