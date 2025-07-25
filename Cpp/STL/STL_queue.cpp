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
	//创建队列
	queue<Person> q;

	//准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);

	//向队列中添加元素  入队操作
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//队列不提供迭代器，更不支持随机访问	
	while (!q.empty()) {
		//输出队头元素
		cout << "队头元素------ 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;

		cout << "队尾元素------ 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;

		cout << endl;
		//弹出队头元素
		q.pop();
	}

	cout << "队列大小为：" << q.size() << endl;

    return 0;
}