#include <iostream>
#include <string>
using namespace std;

////函数模板
//void swapInt(int& a, int& b)//浮点？class？
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//template<typename T>//声明模板
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//void test1()
//{
//    int a = 10;
//    int b = 20;
//    //swapInt(a, b);
//    //两种方式使用
//    //1.自动类型推导
//    //mySwap(a, b);
//    //2.显示指定类型
//    mySwap<int>(a, b);
//    cout << "a=" << a << endl;
//    cout << "b=" << b << endl;
//}
//
////notice
//// 
////1自动类型推导，必须推导出一致的数据类型T, 才可以使用
////void test2()
////{
////    int a = 10;
////    char b = 20;
////    mySwap(a, b);//T不一致报错
////    cout << "a=" << a << endl;
////    cout << "b=" << b << endl;
////}
//
////2模板必须要确定出T的数据类型，才可以使用
//template<class T>
//void func()
//{
//    cout << "func 调用" << endl;
//}
//
//void test3()
//{
//    //func();会报错
//    func<int>();//Specify any one
//}
//
//int main()
//{
//    /*test1();
//    test3();*/
//
//    system("pause");
//
//    return 0;
//}


////模板案例
////实现通用的对数组进行排序的函数
////要求从大到小 ,用选择排序,用char数组,int数组测试
//
////选择排序需要交换,因此再写一个交换模板
//template<class T>
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//template<class T>
//void mySort(T arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        int max = i;//每次循环确定最大值下标
//        for (int j = i + 1; j < len; j++)// 找到真实最大值下标
//        {
//            if (arr[max] < arr[j])
//            {
//                max = j;
//            }
//        }
//        mySwap(arr[max], arr[i]);
//    }
//}
//
////测试的时候要打印,故提供打印模板
//template<class T>
//void myPrintArray(T arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void test1()
//{
//    //测试char数组
//    char charArr[] = "badcfe";
//    int num = sizeof(charArr) / sizeof(char);
//    mySort(charArr, num);
//    myPrintArray(charArr, num);
//}
//
//void test2()
//{
//    int intArr[] = { 2,4,5,3,7,89,100 };
//    int num = sizeof(intArr) / sizeof(int);
//    mySort(intArr, num);
//    myPrintArray(intArr, num);
//}
//
//int main()
//{
//    test1();
//    test2();
//    system("pause");
//
//    return 0;
//}


////普通函数与函数模板调用规则
////1、如果函数模板和普通函数都可以实现，优先调用普通函数
//    // 注意 如果告诉编译器  普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
//
//void myPrint(int a, int b)
//{
//    cout << "original fun" << endl;
//}
//
//template <class T>
//void myPrint(T a, T b)
//{
//    cout << "template" << endl;
//}
////函数模板可以重载
//template <class T>
//void myPrint(T a, T b,T c)
//{
//    cout << "Reload template" << endl;
//}
//
//
//
//void test1()
//{
//    int a = 10;
//    int b = 20;
//    //myPrint(a, b);
//
//    //通过空模板参数列表强制调用函数模板
//    myPrint<>(a, b);
//
//
//    myPrint<>(a, b,100);
//
//    //4、 如果函数模板可以产生更好的匹配,优先调用函数模板
//    char c1 = 'a';
//    char c2 = 'b';
//    myPrint(c1, c2); //调用函数模板
//
//}
//
//int main()
//{
//    test1();
//
//    return 0;
//}

//模板的局限性
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
    
};
//e.g. :判断相等的模板用之前的语法无法判断对象是否相等

//普通函数模板
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//具体化优先于常规模板
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void test2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);

	//自定义数据类型，不会调用普通的函数模板
	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}