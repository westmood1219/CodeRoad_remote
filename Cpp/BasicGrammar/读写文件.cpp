#include <iostream>
using namespace std;
#include <fstream>
#include <string>

//write
void test1()
{
    ofstream ofs;

    ofs.open("test1.txt",ios::out);

    ofs << "name:tom" << endl;
    ofs << "gender:man" << endl;
    ofs << "old:18" << endl;

    ofs.close();
}

//read
void test2()
{
    ifstream ifs;

    ifs.open("test1.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "open file failed!" << endl;
        return;
    }
    //read method1
    /*char buf[1024] = { 0 };
    while (ifs >> buf)
    {
        cout << buf << endl;
    }*/

    //method2
    /*char buf[1024] = { 0 };
    while (ifs.getline(buf,sizeof(buf)))
    {
        cout << buf << endl;
    }*/

    //method3

    string buf;

    /*while (getline(ifs, buf))
    {
        cout << buf << endl;

    }*/

    //4
    char c;
    while (((c = ifs.get()) != EOF))
    {
        cout << c;
    }

    ifs.close();
}

class person
{
public:
    char m_name[64];
    int m_age;
};

void test3()
{
    ofstream ofs("person.txt", ios::out | ios::binary);

    //ofs.open("person.txt", ios::out | ios::binary);

    person p = { "tom", 19 };
    ofs.write((const char *)&p , sizeof(person));

    ofs.close();
}

void test4()
{
    ifstream ifs;

    ifs.open("person.txt", ios::in | ios::binary);

    if (!ifs.is_open())
    {
        cout << "open failed " << endl;
        return;
    }

    person p;

    ifs.read((char*)&p, sizeof(person));

    cout << "name:" << p.m_name << "old:" << p.m_age << endl;
    ifs.close();


}

int main()
{
    test4();
    system("pause");
    return 0;
}