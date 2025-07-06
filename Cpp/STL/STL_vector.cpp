#include <vector>

#include <iostream>
using namespace std;

void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << endl;
}

//vector容器的构造
void test1()
{
    vector<int>v1;//默认无参构造

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //通过区间方式进行构造(左闭右开)
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //n个elem方式构造
    vector<int>v3(10, 100);
    printVector(v3);

    //拷贝构造(常用)
    vector<int>v4(v3);
    printVector(v4);
}

void test2()
{
    vector<int>v1;
    for (int i = 10; i < 20; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //=
    vector<int>v2 = v1;
    printVector(v2);
    //assign(左闭右开)
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);
    vector<int>v4;
    v4.assign(2, 30);
    printVector(v4);
}

void test3()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量 = " << v1.capacity() << endl;
        cout << "v1的大小 = " << v1.size() << endl;
    }

    //resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10);
    printVector(v1);
    cout << "resize后v1的容量 = " << v1.capacity() << endl;
    //resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);

}

void test4()
{
    vector<int>v1;
    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(10);
    v1.push_back(30);
    printVector(v1);
    v1.pop_back();
    printVector(v1);
    v1.insert(v1.begin(), 100);
    printVector(v1);
    v1.insert(v1.begin(), 3, 99);
    printVector(v1);
    v1.erase(v1.begin()+1);
    printVector(v1);
    v1.erase(v1.begin()+2, v1.end()-1);
    printVector(v1);
    v1.clear();
    printVector(v1);

}

void test5()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << "v1的第一个元素为： " << v1.front() << endl;
    cout << "v1的最后一个元素为： " << v1.back() << endl;

    
}

void test6()
{
    //vector<int>v1;
    //for (int i = 0; i < 10; i++)
    //{
    //    v1.push_back(i);
    //}
    //printVector(v1);

    //vector<int>v2;
    //for (int i = 10; i > 0; i--)
    //{
    //    v2.push_back(i);
    //}
    //printVector(v2);

    ////互换容器
    //cout << "互换后" << endl;
    //v1.swap(v2);
    //printVector(v1);
    //printVector(v2);

    //实际用途:巧用swqp收缩空间
    vector<int>v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v's capacity" << v.capacity() << endl;
    cout << "v's size" << v.size() << endl;
    v.resize(3);
    cout << "after resize to 3:v's capacity" << v.capacity() << endl;

    vector<int>(v).swap(v);//这里拷贝构造了一个匿名对象,并在swap后被编译器回收
    cout << "v's capacity" << v.capacity() << endl;
    cout << "v's size" << v.size() << endl;

}

void test7()
{
    vector<int> v;
    v.reserve(10000);

    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);

        if (p != &v[0]) {
            p = &v[0];//每次动态扩展空间,都会开辟新空间放置v,故v[0]的地址会改变一次
            num++;
        }
    }
    cout << "num:" << num << endl;
}

int main()
{
    //test1();//构造操作 push_back 
    //test2();//赋值 = assign
    //test3();//容量和大小 size resize capacity empty
    //test4();//插入和删除 pop_back insert eraser clear
    //test5();//数据存取
    //test6();//互换容器 swap
    test7();//预留空间 reserve(int a)
    return 0;
}