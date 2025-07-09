#include <iostream>
#include<list>
using namespace std;
#include <algorithm>

void printList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test1()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

    printList(L1);

    //区间构造
    list<int>L2(L1.begin(), L1.end());
    printList(L2);

    list<int>L3(L2);
    printList(L3);

    list<int>L4(3, 90);
    printList(L4);
}

void test2()
{
    //赋值
    list<int>L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);

    list<int>L2 = L1;
    printList(L2);

    list<int>L3;
    L3.assign(L2.begin(), L2.end());

    list<int>L4(12, 199);
    printList(L4);

    //swap
    cout << "交换前： " << endl;
    printList(L1);
    printList(L4);

    cout << endl;

    L1.swap(L4);

    cout << "交换后： " << endl;
    printList(L1);
    printList(L4);
}

void test3()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(30);
    L1.push_back(20);

    if (L1.empty())
    {
        cout << "L1 empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
        cout << "element size " << L1.size() << endl;
    }
    L1.resize(10, 10000);
    printList(L1);

    L1.resize(2);
    printList(L1);
}

void test4()
{
    list<int> L;
    //尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    //头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);
    //尾删
    L.pop_back();
    printList(L);

    //头删
    L.pop_front();
    printList(L);
    //插入
    list<int>::iterator it = L.begin();
    L.insert(++it, 1000);
    printList(L);

    //删除
    it = L.begin();
    L.erase(++it);
    printList(L);
    //移除
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);
    L.remove(10000);
    printList(L);
    //清空
    L.clear();
    printList(L);
}

void test5()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);


    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误  不支持[]方式访问数据
    cout << "第一个元素为： " << L1.front() << endl;
    cout << "最后一个元素为： " << L1.back() << endl;
    //list 本质是链表,不是用连续线性空间存储数据,迭代器也不支持随机访问 
    //list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = L1.begin();
    //it = it + 1;//错误，不可以跳跃访问，即使是+1
    //++重载了,+没有

}

bool compare(int val1, int val2)
{
    return val1 > val2;
}

void test6()
{
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);

    //反转容器的元素
    L.reverse();
    printList(L);

    //排序
    //所有不支持随机访问迭代器的容器,不可以用标准算法
    //不支持随机访问迭代器的容器,内部会提供对应一些算法
    L.sort(); //默认的排序规则 从小到大
    printList(L);

    L.sort(compare); //指定规则，从大到小
    printList(L);
}

class Person {
public:
    Person(string name, int age, int height)
    {
        m_Name = name;
        m_Age = age;
        m_Height = height;
    }
    string m_Name;
    int m_Age;
    int m_Height;
};

bool myCompareP(Person& p1, Person& p2)
{
    if (p1.m_Age == p2.m_Age) {
        return p1.m_Height > p2.m_Height;
    }
    else
    {
        return  p1.m_Age < p2.m_Age;
    }
}

void test()
{
    list<Person>L; 

    //data
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
            << " 身高： " << it->m_Height << endl;
    }

    cout << "---------------------------------" << endl;
    cout << "排序后:" << endl;
    L.sort(myCompareP); //排序
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
        cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
            << " 身高： " << it->m_Height << endl;
    }
}

int main()
{
    //list构造函数
    //test1();
    //赋值和交换
    //test2();
    //大小操作
    //test3();
    //插入和删除
    //test4();
    //数据存取
    //test5();
    //反转和排序
    //test6();
    //案例:按年龄升序,年龄相同按身高降序
    test();
    /*
    * 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序


    * 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
    */
    return 0;
}