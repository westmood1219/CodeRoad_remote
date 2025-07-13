//for_each
//transform
#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include <algorithm>

void print01(int val)
{
    cout << val << " ";
}
//函数对象
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

//for_each算法基本用法
void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //遍历算法
    for_each(v.begin(), v.end(), print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
    cout << endl;
}

class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

void test2()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>vTarget; //目标容器
    vTarget.resize(v.size());
    //transform里面有一步，是* _UDest = _Func(*_UFirst);
    //如果用resrve重新指定容量没有指定size,size仍为0,上面一步就会访问一个void值然后error
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}

int main()
{
    //test01();//for_each对遍历区间里的每个值进行函数或者仿函数的一次调用
    test2();//transform 把遍历区间的参数经操作函数_func后 写入给定迭代器后面的空间,注意目标容器要提前resize空间
    system("pause");
    return 0;
}