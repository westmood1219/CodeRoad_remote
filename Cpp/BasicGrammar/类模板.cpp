#include<iostream>
#include<string>
using namespace std;
//#include "person.hpp"

////Ĭ�ϲ���
////template<class NameType, class AgeType = int>
////Person<string> p1("�����", 999);
//template<class NameType, class AgeType>
//class Person
//{
//public:
//    Person(NameType name, AgeType age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }
//
//    void showPerson()
//    {
//        cout << "name:" << this->m_Name << endl;
//        cout << "age:" << this->m_Age << endl;
//    }
//
//    NameType m_Name;
//    AgeType m_Age;
//};
//
//
//
//void test1()
//{
//    Person<string, int> p1("�����", 999);
//    //Person p1("�����", 999);û���Զ������Ƶ�
//    p1.showPerson();
//
//}

////��ģ���������������
//template<class NameType, class AgeType = int>
//class Person
//{
//public:
//	Person(NameType name, AgeType age)
//	{
//		this->mName = name;
//		this->mAge = age;
//	}
//	void showPerson()
//	{
//		cout << "name: " << this->mName << " age: " << this->mAge << endl;
//	}
//public:
//	NameType mName;
//	AgeType mAge;
//};
//
////1��ָ�����������
//void printPerson1(Person<string, int>& p)
//{
//	p.showPerson();
//}
//void test01()
//{
//	Person <string, int >p("�����", 100);
//	printPerson1(p);
//}
//
////2������ģ�廯
//template <class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//	p.showPerson();
//	cout << "T1������Ϊ�� " << typeid(T1).name() << endl;//��ӡ����ԭ��(����������)
//	cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
//}
//void test02()
//{
//	Person <string, int >p("��˽�", 90);
//	printPerson2(p);
//}
//
////3 ������ģ�廯
//template<class T>
//void printPerson3(T& p)
//{
//	Person<string, int>p("��ɮ", 30);
//	printPrint3(p);
//}
//
//int main()
//{
//
//    //test01();
//	//test02();
//	test03();
//
//    return 0;
//}

////��ģ����̳�
//template<class T>
//class Base
//{
//    T m;
//};
//
//class Son :public Base<int>//��֪��T�����;��޷������ڴ�,��������ָ����д����
//{
//
//};
//void test01()
//{
//    Son s1;
//}
//
////��������ָ��������T����,����ҲҪ��Ϊ��ģ��
//template<class T1,class T2>
//class Son2 :public Base<T2>
//{
//public:
//    Son2()
//    {
//        cout << "T1������Ϊ�� " << typeid(T1).name() << endl;//��ӡ����ԭ��(����������)
//        cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
//    }
//    T1 obj;
//};
//
//void test02()
//{
//
//    Son2 <int,char>S2;
//}
//
//int main()
//{
//    test02();
//
//    return 0;
//}

////��ģ���Ա��������ʵ��
//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name, T2 age);
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};
////����ʵ��
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)//��������<>��ʾ����������ģ��
//{
//    this->m_Name = name;
//    this->m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//    cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
//}
//
//void test1()
//{
//    Person<string, int> p1("��", 90);
//    p1.showPerson();
//}
//
//int main()
//{
//    test1();
//    return 0;
//}

///��ģ���Ա�������ļ���д�����������Լ������ʽ

//template<class T1,class T2>
//class Person
//{
//public:
//    Person(T1 name, T2 age);
//    void showPerson();
//
//    T1 m_Name;
//    T2 m_Age;
//};
//
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)
//{
//    this->m_Name = name;
//    this->m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//    cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
//}
//
//void test1()
//{
//    Person<string, int> p1("��", 90);
//    p1.showPerson();
//}
//
//int main()
//{
//    test1();
//
//    return 0;
//}

//2��ȫ�ֺ��������Ԫ  ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2> class Person;

//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1��ȫ�ֺ��������Ԫ   ����ʵ��
	friend void printPerson(Person<T1, T2>& p)
	{
		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
	}


	//ȫ�ֺ��������Ԫ  ����ʵ��
	friend void printPerson2<>(Person<T1, T2>& p);//��<>��ʾ����һ������ģ��

public:

	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}


private:
	T1 m_Name;
	T2 m_Age;

};

//1��ȫ�ֺ���������ʵ��
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}


//2��ȫ�ֺ���������ʵ��
void test02()
{
	Person <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main() {

	//test01();

	test02();

	system("pause");

	return 0;
}