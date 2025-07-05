#include<iostream>
#include<string>
using namespace std;
//#include "person.hpp"

////默认参数
////template<class NameType, class AgeType = int>
////Person<string> p1("孙悟空", 999);
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
//    Person<string, int> p1("孙悟空", 999);
//    //Person p1("孙悟空", 999);没有自动类型推导
//    p1.showPerson();
//
//}

////类模板对象做函数参数
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
////1、指定传入的类型
//void printPerson1(Person<string, int>& p)
//{
//	p.showPerson();
//}
//void test01()
//{
//	Person <string, int >p("孙悟空", 100);
//	printPerson1(p);
//}
//
////2、参数模板化
//template <class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//	p.showPerson();
//	cout << "T1的类型为： " << typeid(T1).name() << endl;//打印类型原名(包括作用域)
//	cout << "T2的类型为： " << typeid(T2).name() << endl;
//}
//void test02()
//{
//	Person <string, int >p("猪八戒", 90);
//	printPerson2(p);
//}
//
////3 整个类模板化
//template<class T>
//void printPerson3(T& p)
//{
//	Person<string, int>p("唐僧", 30);
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

////类模板与继承
//template<class T>
//class Base
//{
//    T m;
//};
//
//class Son :public Base<int>//不知道T的类型就无法分配内存,但是这样指定就写死了
//{
//
//};
//void test01()
//{
//    Son s1;
//}
//
////如果想灵活指定父类中T类型,子类也要变为类模板
//template<class T1,class T2>
//class Son2 :public Base<T2>
//{
//public:
//    Son2()
//    {
//        cout << "T1的类型为： " << typeid(T1).name() << endl;//打印类型原名(包括作用域)
//        cout << "T2的类型为： " << typeid(T2).name() << endl;
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

////类模板成员函数类外实现
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
////类外实现
//template<class T1,class T2>
//Person<T1,T2>::Person(T1 name, T2 age)//作用域后加<>表示作用域是类模板
//{
//    this->m_Name = name;
//    this->m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
//}
//
//void test1()
//{
//    Person<string, int> p1("我", 90);
//    p1.showPerson();
//}
//
//int main()
//{
//    test1();
//    return 0;
//}

///类模板成员函数分文件编写产生的问题以及解决方式

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
//    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
//}
//
//void test1()
//{
//    Person<string, int> p1("我", 90);
//    p1.showPerson();
//}
//
//int main()
//{
//    test1();
//
//    return 0;
//}

//2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2> class Person;

//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 

template<class T1, class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1、全局函数配合友元   类内实现
	friend void printPerson(Person<T1, T2>& p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}


	//全局函数配合友元  类外实现
	friend void printPerson2<>(Person<T1, T2>& p);//加<>表示这是一个函数模板

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

//1、全局函数在类内实现
void test01()
{
	Person <string, int >p("Tom", 20);
	printPerson(p);
}


//2、全局函数在类外实现
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