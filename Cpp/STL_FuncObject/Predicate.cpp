#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include <algorithm>
//�º��� :����ֵ������bool��������,��Ϊν��
//һԪν��
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
    //������������û�д���5������
    //GreaterFive() ������������
    vector<int>::iterator it =  find_if(v.begin(), v.end(), GreaterFive());
    //find_if ������GreaterFive���Ҳ����ص�һ�����������ĵ�������end()
    if (it == v.end())
    {
        cout << "δ�ҵ�" << endl;
    }
    else
    {
        cout << "�ҵ��˴���5��������:" << *it << endl;
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

    //Ĭ�ϴ�С����
    sort(v.begin(), v.end());
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "----------------------------" << endl;
    //ʹ�ú�������ı��㷨���ԣ�����Ӵ�С
    sort(v.begin(), v.end(), MyCompare());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    //һԪν��
    //test1();
    //��Ԫν��
    test2();


    system("pause");
    return 0;
}