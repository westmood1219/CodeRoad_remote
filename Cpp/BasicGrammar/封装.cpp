#include <iostream>
#include <string>
using namespace std;


//class代表设计一个类，后面的是类名称
// 类中的属性和行为统一称为成员
// 属性		成员属性 成员变量
// 行为		成员函数 成员方法
// 封装意义一：
//在设计类的时候，属性和行为写在一起，表现事物
//语法：class 类名{ 访问权限： 属性 / 行为 }; 

//class Student{
//public:
//	string m_name;
//	int m_id;
//
//public:
//	void setName(string name) {
//		m_name = name;
//	}
//	void setID(int id) {
//		m_id = id;
//	}
//	//用行为给属性赋值
//	void showStudent() {
//		cout << "name:" << m_name << " ID:" << m_id << endl;
//	}
//};
//
//int main() {
//	//实例化对象
//	Student stu;
//	//属性赋值操作
//	stu.setName("德玛西亚");
//	stu.setID(250);
//	stu.showStudent();
//
//	system("pause");
//
//	return 0;
//}

//三种权限
//公共权限  public     类内可以访问  类外可以访问
//保护权限  protected  类内可以访问  类外不可以访问
//私有权限  private    类内可以访问  类外不可以访问

//class Person
//{
//	//姓名  公共权限
//public:
//	string m_Name;
//
//	//汽车  保护权限
//protected:
//	string m_Car;
//
//	//银行卡密码  私有权限
//private:
//	int m_Password;
//
//public:
//	void func()
//	{
//		m_Name = "张三";
//		m_Car = "拖拉机";
//		m_Password = 123456;
//	}
//};
//
//int main() {
//
//	Person p;
//	p.m_Name = "李四";
//	//p.m_Car = "奔驰";  //保护权限类外访问不到
//	//p.m_Password = 123; //私有权限类外访问不到
//
//	system("pause");
//
//	return 0;
//}

//class C1
//{
//	int  m_A; //默认是私有权限
//};
//
//struct C2
//{
//	int m_A;  //默认是公共权限
//};
//
//int main() {
//
//	C1 c1;
//	c1.m_A = 10; //错误，访问权限是私有
//
//	C2 c2;
//	c2.m_A = 10; //正确，访问权限是公共
//
//	system("pause");
//
//	return 0;
//}

class Person {
public:

	//姓名设置可读可写
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//获取年龄 
	int getAge() {
		return m_Age;
	}
	//设置年龄
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "你个老妖精!" << endl;
			return;
		}
		m_Age = age;
	}

	//情人设置为只写
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name; //可读可写  姓名

	int m_Age; //只读  年龄

	string m_Lover; //只写  情人
};


int main() {

	Person p;
	//姓名设置
	p.setName("张三");
	cout << "姓名： " << p.getName() << endl;

	//年龄设置
	p.setAge(50);
	cout << "年龄： " << p.getAge() << endl;

	//情人设置
	p.setLover("hd");
	//cout << "情人： " << p.m_Lover << endl;  //只写属性，不可以读取

	system("pause");

	return 0;
}