#include<iostream>
using namespace std;
#include<string>
#include <vector>
#include <algorithm>
#include <functional>

//�º���������һ���þͿ���

void test1()//�����º���
{
    //negate һԪ�º��� ȡ���º���
    negate<int>n;
    cout << n(50) << endl;
    //plus ��Ԫ�º��� �ӷ�
    plus<int>p;
    cout << p(14, 11) << endl;
}

class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test2()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//�Լ�ʵ�ַº���
	//sort(v.begin(), v.end(), MyCompare());
	//STL�ڽ��º���  ���ڷº���
	sort(v.begin(), v.end(), greater<int>());//�����ž�����������

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//�߼��º���
void test3()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//�߼���  ��v�������˵�v2�У���ִ���߼�������
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//�㷨transform���ڰ���
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
    
    //test1();
    //test2();
	test3();

    system("pause");
    return 0;
}