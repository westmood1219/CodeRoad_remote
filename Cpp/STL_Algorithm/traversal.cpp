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
//��������
class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

//for_each�㷨�����÷�
void test01() {

    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //�����㷨
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

    vector<int>vTarget; //Ŀ������
    vTarget.resize(v.size());
    //transform������һ������* _UDest = _Func(*_UFirst);
    //�����resrve����ָ������û��ָ��size,size��Ϊ0,����һ���ͻ����һ��voidֵȻ��error
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}

int main()
{
    //test01();//for_each�Ա����������ÿ��ֵ���к������߷º�����һ�ε���
    test2();//transform �ѱ�������Ĳ�������������_func�� д���������������Ŀռ�,ע��Ŀ������Ҫ��ǰresize�ռ�
    system("pause");
    return 0;
}