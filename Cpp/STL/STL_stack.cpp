#include <iostream>
using namespace std;
#include <stack>

void test1()
{
    //����ջ
    //�Ƚ����
    stack<int>s;

    //��ջ
    s.push(10);
    s.push(20);
    s.push(30);

    //ֻҪջ��Ϊ��,�鿴ջ��,��ִ�г�ջ����
    while (!s.empty())
    {
        cout << "ջ��Ԫ��Ϊ:" << s.top() << endl;

        //��ջ
        s.pop();
    }

    cout << "ջ�Ĵ�С:" << s.size() << endl;
}

int main()
{
    test1();

    system("pause");
    return 0;
}
