#include<iostream>
using namespace std;
#include<string>

//函数对象(仿函数)
/*
* 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
*/

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:

    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count;
};

void doPrint(MyPrint& mp, string test)
{
    mp(test);
}

int main()
{
    //1
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
    //2
    MyPrint myPring;
    myPring("Jheloo wrodl");
    myPring("Jheloo wrodl");
    myPring("Jheloo wrodl");
    cout << "myPring调用次数为:" << myPring.count << endl;
    //3
    MyPrint myPrint;
    doPrint(myPrint, "lsafc");
    system("pause");
    return 0;
}