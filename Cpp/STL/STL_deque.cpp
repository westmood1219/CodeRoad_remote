//deque ˫����������
#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void printDeque(const deque<int>& d)
{//Ҫ���������ֵconst,������ҲҪconst
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//ע����const_iterator�и�_
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

    deque<int>d5;//��ֵ��vector����
    d5.assign(d1.begin(), d1.end());
    printDeque(d5);
    //��С������û��capacity,��Ϊ,deque�����������չ����Ҫ��������

}

void test2()
{
    //���˲���:��������front
    //deque<int> d;
    ////β��
    //d.push_back(10);
    //d.push_back(20);
    ////ͷ��
    //d.push_front(100);
    //d.push_front(200);

    //printDeque(d);

    ////βɾ
    //d.pop_back();
    ////ͷɾ
    //d.pop_front();
    //printDeque(d);

    //����
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

    d.insert(d.begin(), d2.begin(), d2.end());//ò�ƺ�vector��һ��
    printDeque(d);

    //ɾ��
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
    sort(d.begin(), d.end());//�����㷨���ǵ����� ��С����:����
    //����֧��������ʵĵ�����������,��������������ͷ�㷨ֱ�Ӷ�������
    //��vectorҲ������sort
    printDeque(d);
}

int main()
{
    //test1();//���츳ֵ��С
    //test2();//����ɾ��
    //test3();// ���ݴ�ȡ
    test4();//���� sort
    return 0;
}