#include <iostream>
using namespace std;

#include <queue>

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

void printQueue(queue<Person>& q)
{
    cout << q.front().m_Name << " " << q.front().m_Name << endl;
}

int main()
{
	//��������
	queue<Person> q;

	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳɮ", 800);

	//����������Ԫ��  ��Ӳ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//���в��ṩ������������֧���������	
	while (!q.empty()) {
		//�����ͷԪ��
		cout << "��ͷԪ��------ ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;

		cout << "��βԪ��------ ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;

		cout << endl;
		//������ͷԪ��
		q.pop();
	}

	cout << "���д�СΪ��" << q.size() << endl;

    return 0;
}