#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }
    //查找容器中是否有 5 这个元素
    vector<int>::iterator it = find(v.begin(), v.end(),5);
    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到:" << *it << endl;
    }
}

class Person {
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //重载==为什么重载?因为find会将begin()与val用==比较,自定义类型重载==才能比较,详见xutility1659行
    /*bool operator==(const Person& p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }*/
    //count版
    bool operator==(const Person& p)const
    {
        if (this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    string m_Name;
    int m_Age;
};

void test2()
{
    vector<Person> v;

    //创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find(v.begin(), v.end(), p2);
    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
    }
}

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 20;
    }
};

void test3()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "find succeed" << endl;
    }
    vector<Person>v1;
    //data
    Person p1("aaa", 10);
    Person p2("a2a", 20);
    Person p3("a1a", 30);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    vector<Person>::iterator pos = find_if(v1.begin(), v1.end(), Greater20());
    if (pos == v1.end())
    {
        cout << "没有找到!" << endl;
    }
    else
    {
        cout << "找到姓名:" << pos->m_Name << " 年龄: " << pos->m_Age << endl;
    }
}

void test4()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if (pos == v.end()) {
        cout << "找不到!" << endl;
    }
    else {
        cout << "找到相邻重复元素为:" << *pos << endl;
    }
}

void test5()
{
    vector<int>v;

    for (int i = 10; i > 0; i--)
    {
        v.push_back(i);
    }
    //二分查找
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    } 
}

void test6()
{
    vector<int>v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(2);
    int n = count(v.begin(), v.end(), 2);
    cout << n << endl;//2

    vector<Person>v1;
    Person p1("aaa", 10);
    Person p2("a2a", 20);
    Person p3("a1a", 30);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    Person p4("robot", 20);
    int m = count(v1.begin(), v1.end(), p4);
    cout << m << endl;//1
}

class Greater4
{
public:
    bool operator()(const int val)const
    {
        return val >= 4;
    }
};

class Age30
{
public:
    bool operator()(const Person& p)const
    {
        if (p.m_Age > 30)
        {
            return true;
        }
        return false;
    }
};

void test7()
{
    //内置
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num1 = count_if(v.begin(), v.end(), Greater4());
    cout << "大于等于四有"<<num1 << endl;
    //自定义
    vector<Person> v1;

    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 25);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);

    num1 = count_if(v1.begin(), v1.end(), Age30());
    cout << "age greater than 30:" << num1 << endl;
}
    
void test8()
{

}

int main()
{
    //test1();//find查找内置数据类型
    //test2();//find查找自定义类型
    //test3();//find_if内置/custom find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略
    //test4();//adjacent_find (查找相邻重复元素,返回相邻元素的第一个位置迭代器)e.g.查找内置(多出现于面试?)
    //test5();//binary_search 有序升序序列中查找指定元素是否存在,返回bool
    //test6();//count 统计元素个数
    test7();//count_if 按条件统计

    system("pause");
    return 0;
}