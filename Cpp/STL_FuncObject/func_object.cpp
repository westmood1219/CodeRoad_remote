#include<iostream>
using namespace std;
#include<string>

//��������(�º���)
/*
* ����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
* �������󳬳���ͨ�����ĸ����������������Լ���״̬
* �������������Ϊ��������
*/

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint
{
public:

    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count;
};

void doPrint(MyPrint& mp, string test)
{
    mp(test);
}

int main()
{
    //1
    MyAdd myAdd;
    cout << myAdd(10, 10) << endl;
    //2
    MyPrint myPring;
    myPring("Jheloo wrodl");
    myPring("Jheloo wrodl");
    myPring("Jheloo wrodl");
    cout << "myPring���ô���Ϊ:" << myPring.count << endl;
    //3
    MyPrint myPrint;
    doPrint(myPrint, "lsafc");
    system("pause");
    return 0;
}