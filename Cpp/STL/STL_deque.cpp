//deque 双端数组容器
#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d)
{//要让容器里的值const,迭代器也要const
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//注意是const_iterator有个_
    {
        //*it = 10; 
        cout << *it << ' ';
    }
    cout << endl;
}

void test1()
{
    deque<int>d1;
    for (int i = 10; i > 0; i--)
    {
        d1.push_front(i);
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(), d1.end());
    printDeque(d2);
    deque<int>d3(20, 13);
    printDeque(d3);
    deque<int>d4(d3);
    printDeque(d4);

    deque<int>d5;//赋值与vector类似
    d5.assign(d1.begin(), d1.end());
    printDeque(d5);
    //大小操作里没有capacity,因为,deque本身可无限扩展不需要容量概念

}

void test2()
{
    //两端操作:多了两个front
    //deque<int> d;
    ////尾插
    //d.push_back(10);
    //d.push_back(20);
    ////头插
    //d.push_front(100);
    //d.push_front(200);

    //printDeque(d);

    ////尾删
    //d.pop_back();
    ////头删
    //d.pop_front();
    //printDeque(d);

    //插入
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin(), 2, 10000);
    printDeque(d);

    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d.insert(d.begin(), d2.begin(), d2.end());//貌似和vector不一样
    printDeque(d);

    //删除
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    printDeque(d);

    d.erase(d.begin());
    printDeque(d);

    d.erase(d.begin(), d.end());
    d.clear();
    printDeque(d);
}

void test3()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "front:" << d.front() << endl;

    cout << "back:" << d.back() << endl;
}

void test4()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    printDeque(d);
    sort(d.begin(), d.end());//这是算法不是迭代器 从小到大:升序
    //对于支持随机访问的迭代器的容器,都可以利用送人头算法直接对其排序
    //如vector也可以用sort
    printDeque(d);
}

int main()
{
    //test1();//构造赋值大小
    //test2();//插入删除
    //test3();// 数据存取
    test4();//排序 sort
    return 0;
}