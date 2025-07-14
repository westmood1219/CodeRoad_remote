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

	//sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), myPrint);
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
	srand((unsigned int)time(NULL));
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;

	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
}

void test3()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	vector<int>vTarget;
	vTarget.resize(21);
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;
}

void test4()
{
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i + 1);
	}
	reverse(v2.begin(), v2.end());
	for_each(v2.begin(), v2.end(), myPrint);
}



int main()
{
    test1();//sort 
	test2();//random_shuffle �������˳��
	test3();//merge �������������ϲ���һ������,�ǵ�resize
	test4();// reverse ������Ԫ�ط�ת
    system("pause");
    return 0;
}