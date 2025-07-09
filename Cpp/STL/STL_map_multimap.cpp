#include <iostream>
using namespace std;
#include <map>
#include <string>

void printMap(map<int, int>& mp)
{
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "key = " << (*it).first << "val:" << (*it).second << endl;
    }
}

void test1()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));

    printMap(mp);
    map<int, int>mp1(mp);
    printMap(mp1);
    //赋值
    map<int, int>mp2 = mp1;
    printMap(mp2);
}

void test2()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));
    map<int, int>mp1(mp);

    cout << "size:" << mp.size() << endl;
    if (mp.empty())
    {
    cout << "is empty"<<endl;
    }
    else
    {
        cout << "not empty" << endl;
    }
    mp1.swap(mp);

    cout << "size:" << mp.size() << endl;
}

void test3()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));//推荐
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;//不建议,因为插错了会使值为零,用途:利用key访问value
    cout << m[4] << endl;
    cout << m[5] << endl;//0

    //delete
    m.erase(m.begin());
    m.erase(3);//按key删除
    m.erase(30);//无效
    printMap(m);

    m.clear();//清空

    
}

void test4()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));

    map<int, int>::iterator pos = mp.find(3);//找到了返回迭代器 没找到返回map.end()

    if (pos != mp.end())
    {
        cout << "查到了元素key = " << (*pos).first << "val" << (*pos).second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    //统计
    //map 不允许插入重复key
    int num = mp.count(3);
    cout << num << endl;
}
class MyCompare
{
public:
    bool operator()(const int v1, const int v2)const
    {//加const是因为： 不希望在这个函数中对用来进行赋值的“原版”做任何修改。函数加上const后缀的作用是表明函数本身不会修改类成员变量。
        //对自定义类型作比较才需要&
        return v1 > v2;
    }
};
void test7()
{
    map<int, int,MyCompare>mp;//仿函数也要加入到参数列表里
    //排序自定义类型比如Person,需要把Person作为key.因为只能以key来排序,同时类似set也要定义排序规则
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));
    
    for (map<int, int,MyCompare>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "key = " << (*it).first << "val:" << (*it).second << endl;
    }
}

int main()
{
    //test1();//构造和赋值
    //test2();//大小和交换
    //test3();//插入和删除
    //test4();//查找和统计
    test7();//map容器排序

    return 0;
}