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

    //���乹��
    list<int>L2(L1.begin(), L1.end());
    printList(L2);

    list<int>L3(L2);
    printList(L3);

    list<int>L4(3, 90);
    printList(L4);
}

void test2()
{
    //��ֵ
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
    cout << "����ǰ�� " << endl;
    printList(L1);
    printList(L4);

    cout << endl;

    L1.swap(L4);

    cout << "������ " << endl;
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
    //β��
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    //ͷ��
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);
    //βɾ
    L.pop_back();
    printList(L);

    //ͷɾ
    L.pop_front();
    printList(L);
    //����
    list<int>::iterator it = L.begin();
    L.insert(++it, 1000);
    printList(L);

    //ɾ��
    it = L.begin();
    L.erase(++it);
    printList(L);
    //�Ƴ�
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);
    L.remove(10000);
    printList(L);
    //���
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


    //cout << L1.at(0) << endl;//���� ��֧��at��������
    //cout << L1[0] << endl; //����  ��֧��[]��ʽ��������
    cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;
    cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;
    //list ����������,�������������Կռ�洢����,������Ҳ��֧��������� 
    //list�����ĵ�������˫�����������֧���������
    list<int>::iterator it = L1.begin();
    //it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
    //++������,+û��

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

    //��ת������Ԫ��
    L.reverse();
    printList(L);

    //����
    //���в�֧��������ʵ�����������,�������ñ�׼�㷨
    //��֧��������ʵ�����������,�ڲ����ṩ��ӦһЩ�㷨
    L.sort(); //Ĭ�ϵ�������� ��С����
    printList(L);

    L.sort(compare); //ָ�����򣬴Ӵ�С
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
    Person p1("����", 35, 175);
    Person p2("�ܲ�", 45, 180);
    Person p3("��Ȩ", 40, 170);
    Person p4("����", 25, 190);
    Person p5("�ŷ�", 35, 160);
    Person p6("����", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
            << " ��ߣ� " << it->m_Height << endl;
    }

    cout << "---------------------------------" << endl;
    cout << "�����:" << endl;
    L.sort(myCompareP); //����
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
        cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
            << " ��ߣ� " << it->m_Height << endl;
    }
}

int main()
{
    //list���캯��
    //test1();
    //��ֵ�ͽ���
    //test2();
    //��С����
    //test3();
    //�����ɾ��
    //test4();
    //���ݴ�ȡ
    //test5();
    //��ת������
    //test6();
    //����:����������,������ͬ����߽���
    test();
    /*
    * �����Զ����������ͣ�����Ҫָ��������򣬷����������֪����ν�������


    * �߼�����ֻ��������������ٽ���һ���߼������ƶ�����������
    */
    return 0;
}