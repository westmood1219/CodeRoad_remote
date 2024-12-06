//断点可以设置条件,比如i=3什么的  
//数组传参时可以用arr,n来监视数组里的值,arr为数组名,n为想看的前几个元素

#include <stdio.h>
//void test2()
//{
//    printf("hehe");
//}
//void test1()
//{
//    test2();
//}
//void test()
//{
//    test1();
//}
//int main()
//{
//    //int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    //char ch[] = "abcd";
//    //可以在内存窗口输入arr,ch看看
//    test();//调试开始后在内存窗口里查看调用堆栈
//    //可以看出来是从下往上调用
//    //还可以看反汇编和寄存器
//    return 0;
//}

//一个经典需要调试的代码下
//int main()
//{
//    int i = 0;
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i=0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hehe\n");
//    }
//    return 0;
//}

//调试到i=10时发现异常,添加监视项arr[10],发现也被赋值为1,arr[11]同理,到arr[12]时发现i变为了0
//添加&i发现&i == &arr[12]
//具体解释看https://www.bilibili.com/video/BV1Vm4y1r7jY?t=3656.0&p=89

//优秀的代码要善用const
// 在C语言和C++中，const 关键字用于定义常量或不可修改的变量。它可以用来修饰变量、指针和函数参数，以提高代码的安全性和可读性
//const修饰指针变量:
//1.const放在*的左边
//意思是：p指向的对象不能通过p来改变了(相当于限制*p不能改变),但是p本身的值可以改变
//*p = 20;//err
//2.右边
//int* const p = &num
//函数的返回值用指针是为了实现链式访问
//链式访问是一种编程技巧，允许多个函数调用在一行代码中连续进行，每个函数调用返回一个对象或指针，该对象或指针可以立即用于下一个函数调用
// eg:
// 实现 my_strcpy 函数
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src) {
//    assert(src != NULL);
//    assert(dest != NULL);
//    char* original_dest = dest; // 保存目标字符串的起始地址
//    while ((*dest++ = *src++)); // 复制源字符串到目标字符串，包含终止符 '\0'
//    return original_dest; // 返回目标字符串的起始地址
//}
//
//int main() {
//    char src[] = "hello";
//    char dest[6]; // 确保 dest 有足够的空间存储 "hello" 和终止符 '\0'
//    my_strcpy(dest, src);
//    printf("Copied string: %s\n", dest);
//    return 0;
//}

//如何写出易于调试的代码
int my_strlen(const char* str)
{
    int count = 0;
    assert(str);
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
int main()
{
    char arr[] = "hello bit";
    int len = my_strlen(arr);
    printf("%d\n", len);
}

//编程常见的错误
//1:编译错误(语法)(出现在编译阶段)
//2:链接型错误(出现在链接阶段)
//eg:
//int main() {
//    foo(); // 调用 foo 函数,但是没找到foo在哪里或者没定义或者名字写错了
//    //具体在报错里显示"找不到外部xxxx"
//    return 0;
//}
//3:运行时错误(只能调试来解决)
