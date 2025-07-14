#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include<vector>

void myPrint(int val)
{
	cout << val << " ";
}

void test1()
{
	//����
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	vector<int>vT;
	vT.resize(6);
	
	copy(++v.begin(), --v.end(), vT.begin());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	
	for_each(vT.begin(), vT.end(), myPrint);
	cout << endl;
}

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
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	replace(v.begin(), v.end(),1,2);
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}

};

void test3()
{
	vector<int>v1;

	for (int i = 25; i < 35; i++)
	{
		v1.push_back(i);
	}
	cout << "�滻ǰ��" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	replace_if(v1.begin(), v1.end(), ReplaceGreater30(), 1024);
	cout << "�滻��" << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	cout << endl;
}

void test4()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "����ǰ�� " << endl;
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;

	cout << "������ " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), MyPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), MyPrint());
	cout << endl;
}



int main()
{
	test1();//copy ������ָ����Χ�ڵ�Ԫ�ؿ�������һ����
	test2();//replace ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	test3();//replace_if  ������������������Ԫ�أ��滻��ָ��Ԫ��
	test4();// swap �������������ڵ�Ԫ��
	system("pause");
	return 0;
}