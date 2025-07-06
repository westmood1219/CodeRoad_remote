//������ѡ��:ѡ��ABCDE,10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ����

#include <iostream>
using namespace std;
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;
    int m_Score;
};

void createPerson(vector<Person>& v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name="player";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);
        v.push_back(p);

    }
}

void setScore(vector<Person>& v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        //����ί�ķ�������deque������
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        //����
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        (*it).m_Score = sum / d.size();
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    //1.��������ѡ��
    vector<Person>v;
    createPerson(v);
    

    //2.������ѡ�ִ��
    setScore(v);
    //3.��ʾ���÷�
    for (vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        cout << "name:" << (*it).m_Name << "score:" << (*it).m_Score << endl;
    }

    system("pause");
    return 0;
}