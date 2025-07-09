/*
    * set不允许容器中有重复的元素
    * multiset允许容器中有重复的元素   
*/
#include <iostream>
#include<set>
using namespace std;
#include<string>

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造和赋值
void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	
	//拷贝构造
	set<int>s2(s1);
	printSet(s2);

	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

void test02()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1 is empty" << endl;
	}
	else
	{
		cout << "s1 is not empty" << endl;
		cout << "s1's size is:" << s1.size() << endl;
	}

	set<int>s2;
	s2.insert(20);
	s2.insert(30);
	s2.insert(30);
	s2.insert(40);
	s1.swap(s2);
	cout << "after swap" << endl;
	printSet(s1);

}

void test3()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	s1.erase(s1.begin());
	printSet(s1);

	s1.erase(s1.begin(), s1.end());
	printSet(s1);
	s1.insert(100);
	printSet(s1);

	s1.find(100);
	set<int>::iterator pos = s1.find(1);//返回s1.end();
	s1.count (1);//0
	s1.count(100);//1
}


void test4()
{
	set<int>s;
	pair<set<int>::iterator, bool> ret = s.insert(10); 
	if (ret.second)
	{
		cout << "insert sucess" << endl;
	}
	else
	{
		cout << "insert failed" << endl;
	}
	ret = s.insert(10);
	if (ret.second)
	{
		cout << "insert sucess" << endl;
	}
	else
	{
		cout << "insert failed" << endl;
	}

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void  test5()
{
	//pair	成对出现的数据,利用对组可以返回两个数据

	//构造
	pair<string, int>p("Tom", 20);
	cout << "name" << p.first << "age" << p.second << endl;

	pair<string, int>p1 = make_pair("jerry", 20);
	cout << "name" << p1.first << "age" << p1.second << endl;
}

class MyCompare
{
public:
	bool operator()(int v1,int v2)const//set要求比较器必须是 ​​常量成员函数​​（即不修改对象状态）
	{
		return v1 > v2;
	}
};

void test6()
{
	set<int>s1;

	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	printSet(s1);

	set<int, MyCompare>s2;

	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;

};

class comparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_Age > p2.m_Age;
	}
};

void test7()
{
	//自定义数据类型,都会指定排序规则
	set<Person, comparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person,comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->m_Name << " "<<it->m_Age;
		cout << endl;
	}
}

int main() {

	//test01();
	//test02();//大小和交换
	//test3();//delete,insert,find count
	//test4();//set和multiset的区别
	//test5();//pair对组创建
	//改变set容器排序规则 __ 仿函数
	//test6();
	//set存放自定义数据排序
	test7();
	system("pause");

	return 0;
}