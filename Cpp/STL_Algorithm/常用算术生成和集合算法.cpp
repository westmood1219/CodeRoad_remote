#include <iostream>
using namespace std;
#include <numeric>
#include <vector>
#include <algorithm>

void test1()
{
    vector<int>v;
	for (int i = 0; i <=100; i++)
	{
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total=" << total << endl;
}

class myPrint
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
	v.resize(10);
	//���
	fill(v.begin(), v.end(), 100);

	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

void test3()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	//ȡ���������С��ֵ��Ŀ���������ٿռ�,��������С�����������е�С����һ��
	vTarget.resize(min(v1.size(), v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd =
		set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

void test4()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	//ȡ���������ĺ͸�Ŀ���������ٿռ�
	vTarget.resize(v1.size() + v2.size());

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd =
		set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

void test5()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	//ȡ��������ϴ��ֵ��Ŀ���������ٿռ�
	vTarget.resize(max(v1.size(), v2.size()));

	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	cout << "v1��v2�ĲΪ�� " << endl;
	vector<int>::iterator itEnd =
		set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;


	cout << "v2��v1�ĲΪ�� " << endl;
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint());
	cout << endl;
}

int main()
{
	//���������㷨ͷ�ļ�numeric
	test1();//accmulate �����ڴӸ���ֵ��ʼ�ۼ�
	test2();//fill ���������ָ��ֵ
	//�����㷨ͷ�ļ�algorithm
	test3();//set_intersection �����������Ľ���(����������������) ����ֵ�ǽ��������һ��Ԫ�ص�λ��
	test4();//set_union ����������������,��Ŀ�꿪ʼ����,���ز������һ��Ԫ��λ�� 
	test5();//set_defference ��(e.g.v1��v2�Ĳ:v1��v2������Ĳ���) ����ͬ��,ע��Ŀ��������С�Ǵ�-С ,Ŀ��������С��v1,v2��da���Ǹ�

	return 0;
}