//有五名选手:选手ABCDE,10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

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
        //将评委的分数放入deque容器中
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        //排序
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

    //1.创建五名选手
    vector<Person>v;
    createPerson(v);
    

    //2.给五名选手打分
    setScore(v);
    //3.显示最后得分
    for (vector<Person>::iterator it = v.begin();it!=v.end();it++)
    {
        cout << "name:" << (*it).m_Name << "score:" << (*it).m_Score << endl;
    }

    system("pause");
    return 0;
}