#include <iostream>
using namespace std;

//ѧ���ṹ�嶨��
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
};

//��ʦ�ṹ�嶨��
struct teacher
{
	//��Ա�б�
	int id; //ְ�����
	string name;  //��ʦ����
	int age;   //��ʦ����
	struct student stu; //�ӽṹ�� ѧ��
};


//int main() {
//
//	struct teacher t1;
//	t1.id = 10000;
//	t1.name = "����";
//	t1.age = 40;
//
//	t1.stu.name = "����";
//	t1.stu.age = 18;
//	t1.stu.score = 100;
//
//	cout << "��ʦ ְ����ţ� " << t1.id << " ������ " << t1.name << " ���䣺 " << t1.age << endl;
//
//	cout << "����ѧԱ ������ " << t1.stu.name << " ���䣺" << t1.stu.age << " ���Է����� " << t1.stu.score << endl;
//
//	system("pause");
//
//	return 0;
//}//**�ܽ᣺** �ڽṹ���п��Զ�����һ���ṹ����Ϊ��Ա���������ʵ������

//ֵ����
void printStudent(student stu)
{
	stu.age = 28;
	cout << "�Ӻ����� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;
}

//��ַ����
void printStudent2(student* stu)
{
	stu->age = 28;
	cout << "�Ӻ����� ������" << stu->name << " ���䣺 " << stu->age << " ������" << stu->score << endl;
}

int main() {

	student stu = { "����",18,100 };
	//ֵ����
	printStudent(stu);
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;

	cout << endl;

	//��ַ����
	printStudent2(&stu);
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;

	system("pause");

	return 0;
}
