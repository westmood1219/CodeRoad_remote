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

//vector�����Ĺ���
void test1()
{
    vector<int>v1;//Ĭ���޲ι���

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //ͨ�����䷽ʽ���й���(����ҿ�)
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //n��elem��ʽ����
    vector<int>v3(10, 100);
    printVector(v3);

    //��������(����)
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
    //assign(����ҿ�)
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
        cout << "v1Ϊ��" << endl;
    }
    else
    {
        cout << "v1��Ϊ��" << endl;
        cout << "v1������ = " << v1.capacity() << endl;
        cout << "v1�Ĵ�С = " << v1.size() << endl;
    }

    //resize ����ָ����С ����ָ���ĸ���Ĭ����0�����λ�ã������������ذ汾�滻Ĭ�����
    v1.resize(15, 10);
    printVector(v1);
    cout << "resize��v1������ = " << v1.capacity() << endl;
    //resize ����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
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

    cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
    cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;

    
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

    ////��������
    //cout << "������" << endl;
    //v1.swap(v2);
    //printVector(v1);
    //printVector(v2);

    //ʵ����;:����swqp�����ռ�
    vector<int>v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v's capacity" << v.capacity() << endl;
    cout << "v's size" << v.size() << endl;
    v.resize(3);
    cout << "after resize to 3:v's capacity" << v.capacity() << endl;

    vector<int>(v).swap(v);//������������һ����������,����swap�󱻱���������
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
            p = &v[0];//ÿ�ζ�̬��չ�ռ�,���Ὺ���¿ռ����v,��v[0]�ĵ�ַ��ı�һ��
            num++;
        }
    }
    cout << "num:" << num << endl;
}

int main()
{
    //test1();//������� push_back 
    //test2();//��ֵ = assign
    //test3();//�����ʹ�С size resize capacity empty
    //test4();//�����ɾ�� pop_back insert eraser clear
    //test5();//���ݴ�ȡ
    //test6();//�������� swap
    test7();//Ԥ���ռ� reserve(int a)
    return 0;
}