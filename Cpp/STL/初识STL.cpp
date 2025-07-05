#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>    //标准算法头文件

////vector存放内置数据类型
//void myPrint(int val)
//{
//    cout << "val" << endl;
//}
//
//void test1()
//{
//    //create a vector container, array
//    vector<int> v;
//
//    //insert data into container
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);
//
//    //通过迭代器访问容器中的数据
//    vector<int>::iterator itBegin = v.begin();
//    vector<int>::iterator itEnd = v.end();
//
//    //遍历方式1
//    while (itBegin != itEnd)
//    {
//        cout << *itBegin << endl;
//        itBegin++;
//    }
//
//    //2
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << endl;
//    }
//
//    //3
//    for_each(v.begin(),v.end(),myPrint);
//}
//
//int main()
//{
//    test1();
//    system("pause");
//    return 0;
//}


////vector存放自定义数据类型
//class Person {
//public:
//	Person(string name, int age) {
//		m_Name = name;
//		m_Age = age;
//	}
//public:
//	string m_Name;
//	int m_Age;
//};
//
//void test1()
//{
//	vector<Person>v;
//
//	Person p1("adf", 10);
//	Person p2("adf", 30);
//	Person p3("adf", 40);
//	Person p5("adf", 50);
//
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p5);
//
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "name:" << (*it).m_Name << "  age:" << (*it).m_Age << endl;
//
//	}
//}
//
////存放自定义数据类型 指针
//void test2()
//{
//	vector<Person*>v;
//
//	Person p1("adf", 10);
//	Person p2("adf", 30);
//	Person p3("adf", 40);
//	Person p5("adf", 50);
//
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p5);
//
//	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "name:" << (*it)->m_Name << "  age:" << (*it)->m_Age << endl;
//
//	}
//}
//
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}



//容器中嵌套容器



void test1()
{
    vector <vector<int>>v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;

    for (int i = 0; i < 4; i++)
    {

        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        //(*it) -----容器 vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout <<  *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test1();

    return 0;
}