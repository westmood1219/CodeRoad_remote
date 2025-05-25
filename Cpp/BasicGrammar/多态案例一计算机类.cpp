#include <iostream>
using namespace std;
#include <string>

//普通实现
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//如果要提供新的运算，需要修改源码
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//普通实现测试
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

class abcalc
{
public:

	virtual int getret()
	{
		return 0;
	}

	int m_num1;
	int m_num2;
};

class addcalc :public abcalc
{
public:

	int getret()
	{
		return m_num1 + m_num2;
	}
};

class subcalc :public abcalc
{
public:

	int getret()
	{
		return m_num1 - m_num2;
	}
};

class mulcalc :public abcalc
{
public:

	int getret()
	{
		return m_num1 * m_num2;
	}
};

void test02()
{
	abcalc* abc = new addcalc;
	abc->m_num1 = 10;
	abc->m_num2 = 10;
	cout << abc -> m_num1 << " + " << abc -> m_num2 << " = " << abc -> getret() << endl;

	delete abc;
}

int main()
{
    test02();

    system("pause");

    return 0;

}