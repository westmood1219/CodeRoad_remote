#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include <algorithm>
//仿函数 :返回值类型是bool数据类型,称为谓词
//一元谓词
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void test1()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //查找容器中有没有大于5的数字
    //GreaterFive() 匿名函数对象
    vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterFive());
    //find_if 按条件GreaterFive查找并返回第一个符合条件的迭代器或end()
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了大于5的数字是:" << *it << endl;
    }
}

class MyCompare
{
public:
    bool operator()(int num1, int num2)
    {
        return num1 > num2;
    }
};

void test2()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    //默认从小到大
    sort(v.begin(), v.end());
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "----------------------------" << endl;
    //使用函数对象改变算法策略，排序从大到小
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    //一元谓词
    //test1();
    //二元谓词
    test2();


    system("pause");
    return 0;
}