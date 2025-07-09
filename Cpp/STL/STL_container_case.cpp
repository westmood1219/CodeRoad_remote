//员工分组
#include<iostream>
using namespace std;
#include<string>
#include <map>
#include<vector>
#include<ctime>
#define cehua 0
#define meishu 1
#define yanfa 2

class Empee
{
public:
    string m_Name;
    int m_Money;
};

void createEmpee(vector<Empee>& v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Empee empee;
        empee.m_Name = "员工";
        empee.m_Name += nameSeed[i];

        empee.m_Money = rand() % 5001 + 5000;
        //插入
        v.push_back(empee);
    }
}

void setGroup(vector<Empee>& v, multimap<int, Empee>& m)
{
    for (vector<Empee>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机部门编号
        int dept = rand() % 3; // 0 1 2 

        //将员工插入到分组中
        //key部门编号，value具体员工
        m.insert(make_pair(dept, *it));
    }
}

void showEmpeeByGroup(multimap<int, Empee>& m)
{
    cout << "策划部门" << endl;
    multimap<int, Empee>::iterator pos = m.find(cehua);

    int count = m.count(cehua);
    for (int index = 0; pos != m.end() && index<count; pos++,index++)
    {
        cout << pos->second.m_Name << " salary: " << pos->second.m_Money << endl;
    }
    cout << "----------------------" << endl;

    cout << "美术部门" << endl;
    pos = m.find(meishu);

    count = m.count(meishu);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " salary: " << pos->second.m_Money << endl;
    }
    cout << "----------------------" << endl;
    cout << "研发部门" << endl;
    pos = m.find(yanfa);

    count = m.count(yanfa);
    for (int index = 0; pos != m.end() && index < count; pos++, index++)
    {
        cout << pos->second.m_Name << " salary: " << pos->second.m_Money << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Empee>v;
    createEmpee(v);

    multimap<int,Empee>mWorker;
    setGroup(v,mWorker);
    showEmpeeByGroup(mWorker);

    system("pause");
    return 0;
}