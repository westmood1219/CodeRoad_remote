#include <iostream>
using namespace std;
#include <map>
#include <string>

void printMap(map<int, int>& mp)
{
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "key = " << (*it).first << "val:" << (*it).second << endl;
    }
}

void test1()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));

    printMap(mp);
    map<int, int>mp1(mp);
    printMap(mp1);
    //��ֵ
    map<int, int>mp2 = mp1;
    printMap(mp2);
}

void test2()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));
    map<int, int>mp1(mp);

    cout << "size:" << mp.size() << endl;
    if (mp.empty())
    {
    cout << "is empty"<<endl;
    }
    else
    {
        cout << "not empty" << endl;
    }
    mp1.swap(mp);

    cout << "size:" << mp.size() << endl;
}

void test3()
{
    map<int, int>m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));//�Ƽ�
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;//������,��Ϊ����˻�ʹֵΪ��,��;:����key����value
    cout << m[4] << endl;
    cout << m[5] << endl;//0

    //delete
    m.erase(m.begin());
    m.erase(3);//��keyɾ��
    m.erase(30);//��Ч
    printMap(m);

    m.clear();//���

    
}

void test4()
{
    map<int, int>mp;
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));

    map<int, int>::iterator pos = mp.find(3);//�ҵ��˷��ص����� û�ҵ�����map.end()

    if (pos != mp.end())
    {
        cout << "�鵽��Ԫ��key = " << (*pos).first << "val" << (*pos).second << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    //ͳ��
    //map ����������ظ�key
    int num = mp.count(3);
    cout << num << endl;
}
class MyCompare
{
public:
    bool operator()(const int v1, const int v2)const
    {//��const����Ϊ�� ��ϣ������������ж��������и�ֵ�ġ�ԭ�桱���κ��޸ġ���������const��׺�������Ǳ��������������޸����Ա������
        //���Զ����������Ƚϲ���Ҫ&
        return v1 > v2;
    }
};
void test7()
{
    map<int, int,MyCompare>mp;//�º���ҲҪ���뵽�����б���
    //�����Զ������ͱ���Person,��Ҫ��Person��Ϊkey.��Ϊֻ����key������,ͬʱ����setҲҪ�����������
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));
    
    for (map<int, int,MyCompare>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << "key = " << (*it).first << "val:" << (*it).second << endl;
    }
}

int main()
{
    //test1();//����͸�ֵ
    //test2();//��С�ͽ���
    //test3();//�����ɾ��
    //test4();//���Һ�ͳ��
    test7();//map��������

    return 0;
}