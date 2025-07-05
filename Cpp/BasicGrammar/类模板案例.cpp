#include <iostream>
#include <string>
using namespace std;
#include "MyArray.hpp"

void printIntArray(MyArray<int>&arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray <int>arr1(4);
    /*MyArray <int>arr2(arr1);
    MyArray <int>arr4(34);
    MyArray <int>arr3(34);
    arr4 = arr3 = arr1;*/

    for (int i = 0; i < 4; i++)
    {
        //利用尾插法像数组中插入数据
        arr1.Push_Back(i);
    }
    cout << "arr1 :"  << endl;
    printIntArray(arr1);
    cout << "arr1's capacity:" << arr1.getCapacity() << endl;
    cout << "arr1's size:" << arr1.getSize() << endl;

    MyArray <int>arr2(arr1);
    cout << "arr2 :" << endl;
    printIntArray(arr2);
    //尾删
    arr2.Pop_Back();
    cout << "arr2's capacity:" << arr2.getCapacity() << endl;
    cout << "arr2's size:" << arr2.getSize() << endl;


}

//test Custom data types
class Person
{
public:
    Person() {};
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void printPerson(MyArray<Person>& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "name:" << arr[i].m_Name << "age:" << arr[i].m_Age << endl;
    }
}

void test2()
{
    MyArray<Person> arr(10);
    Person p1("sun", 82);
    Person p2("han", 23);
    Person p3("zhe", 23);
    Person p4("dui", 23);
    Person p5("ma?", 23);

    //将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);

    //print
    printPerson(arr);
    cout << "arr's capacity:" << arr.getCapacity() << endl;
    cout << "arr's size:" << arr.getSize() << endl;
}

int main()
{
    //test01();
    test2();

    return 0;
}