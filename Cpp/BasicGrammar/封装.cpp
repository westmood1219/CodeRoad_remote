#include <iostream>
#include <string>
using namespace std;


//class�������һ���࣬�������������
// ���е����Ժ���Ϊͳһ��Ϊ��Ա
// ����		��Ա���� ��Ա����
// ��Ϊ		��Ա���� ��Ա����
// ��װ����һ��
//��������ʱ�����Ժ���Ϊд��һ�𣬱�������
//�﷨��class ����{ ����Ȩ�ޣ� ���� / ��Ϊ }; 

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
//	//����Ϊ�����Ը�ֵ
//	void showStudent() {
//		cout << "name:" << m_name << " ID:" << m_id << endl;
//	}
//};
//
//int main() {
//	//ʵ��������
//	Student stu;
//	//���Ը�ֵ����
//	stu.setName("��������");
//	stu.setID(250);
//	stu.showStudent();
//
//	system("pause");
//
//	return 0;
//}

//����Ȩ��
//����Ȩ��  public     ���ڿ��Է���  ������Է���
//����Ȩ��  protected  ���ڿ��Է���  ���ⲻ���Է���
//˽��Ȩ��  private    ���ڿ��Է���  ���ⲻ���Է���

//class Person
//{
//	//����  ����Ȩ��
//public:
//	string m_Name;
//
//	//����  ����Ȩ��
//protected:
//	string m_Car;
//
//	//���п�����  ˽��Ȩ��
//private:
//	int m_Password;
//
//public:
//	void func()
//	{
//		m_Name = "����";
//		m_Car = "������";
//		m_Password = 123456;
//	}
//};
//
//int main() {
//
//	Person p;
//	p.m_Name = "����";
//	//p.m_Car = "����";  //����Ȩ��������ʲ���
//	//p.m_Password = 123; //˽��Ȩ��������ʲ���
//
//	system("pause");
//
//	return 0;
//}

//class C1
//{
//	int  m_A; //Ĭ����˽��Ȩ��
//};
//
//struct C2
//{
//	int m_A;  //Ĭ���ǹ���Ȩ��
//};
//
//int main() {
//
//	C1 c1;
//	c1.m_A = 10; //���󣬷���Ȩ����˽��
//
//	C2 c2;
//	c2.m_A = 10; //��ȷ������Ȩ���ǹ���
//
//	system("pause");
//
//	return 0;
//}

class Person {
public:

	//�������ÿɶ���д
	void setName(string name) {
		m_Name = name;
	}
	string getName()
	{
		return m_Name;
	}


	//��ȡ���� 
	int getAge() {
		return m_Age;
	}
	//��������
	void setAge(int age) {
		if (age < 0 || age > 150) {
			cout << "���������!" << endl;
			return;
		}
		m_Age = age;
	}

	//��������Ϊֻд
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name; //�ɶ���д  ����

	int m_Age; //ֻ��  ����

	string m_Lover; //ֻд  ����
};


int main() {

	Person p;
	//��������
	p.setName("����");
	cout << "������ " << p.getName() << endl;

	//��������
	p.setAge(50);
	cout << "���䣺 " << p.getAge() << endl;

	//��������
	p.setLover("hd");
	//cout << "���ˣ� " << p.m_Lover << endl;  //ֻд���ԣ������Զ�ȡ

	system("pause");

	return 0;
}