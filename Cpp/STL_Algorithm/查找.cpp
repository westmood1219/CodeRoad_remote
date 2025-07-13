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
    //�����������Ƿ��� 5 ���Ԫ��
    vector<int>::iterator it = find(v.begin(), v.end(),5);
    if (it == v.end())
    {
        cout << "û���ҵ�!" << endl;
    }
    else
    {
        cout << "�ҵ�:" << *it << endl;
    }
}

class Person {
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    //����==Ϊʲô����?��Ϊfind�Ὣbegin()��val��==�Ƚ�,�Զ�����������==���ܱȽ�,���xutility1659��
    /*bool operator==(const Person& p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }*/
    //count��
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

    //��������
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
        cout << "û���ҵ�!" << endl;
    }
    else
    {
        cout << "�ҵ�����:" << it->m_Name << " ����: " << it->m_Age << endl;
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
        cout << "û���ҵ�!" << endl;
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
        cout << "û���ҵ�!" << endl;
    }
    else
    {
        cout << "�ҵ�����:" << pos->m_Name << " ����: " << pos->m_Age << endl;
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
        cout << "�Ҳ���!" << endl;
    }
    else {
        cout << "�ҵ������ظ�Ԫ��Ϊ:" << *pos << endl;
    }
}

void test5()
{
    vector<int>v;

    for (int i = 10; i > 0; i--)
    {
        v.push_back(i);
    }
    //���ֲ���
    bool ret = binary_search(v.begin(), v.end(), 9);
    if (ret)
    {
        cout << "�ҵ���" << endl;
    }
    else
    {
        cout << "δ�ҵ�" << endl;
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
    //����
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num1 = count_if(v.begin(), v.end(), Greater4());
    cout << "���ڵ�������"<<num1 << endl;
    //�Զ���
    vector<Person> v1;

    Person p1("����", 35);
    Person p2("����", 35);
    Person p3("�ŷ�", 35);
    Person p4("����", 30);
    Person p5("�ܲ�", 25);

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
    //test1();//find����������������
    //test2();//find�����Զ�������
    //test3();//find_if����/custom find_if����������ʹ���Ҹ������ṩ�ķº������Ըı䲻ͬ�Ĳ���
    //test4();//adjacent_find (���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õ�����)e.g.��������(�����������?)
    //test5();//binary_search �������������в���ָ��Ԫ���Ƿ����,����bool
    //test6();//count ͳ��Ԫ�ظ���
    test7();//count_if ������ͳ��

    system("pause");
    return 0;
}