#include <iostream>
using namespace std;
#include <stack>

void test1()
{
    //构造栈
    //先进后出
    stack<int>s;

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);

    //只要栈不为空,查看栈顶,并执行出栈操作
    while (!s.empty())
    {
        cout << "栈顶元素为:" << s.top() << endl;

        //出栈
        s.pop();
    }

    cout << "栈的大小:" << s.size() << endl;
}

int main()
{
    test1();

    system("pause");
    return 0;
}
