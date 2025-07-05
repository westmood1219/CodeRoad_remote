#include <iostream>
#include <string>
using namespace std;

////����ģ��
//void swapInt(int& a, int& b)//���㣿class��
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//template<typename T>//����ģ��
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//void test1()
//{
//    int a = 10;
//    int b = 20;
//    //swapInt(a, b);
//    //���ַ�ʽʹ��
//    //1.�Զ������Ƶ�
//    //mySwap(a, b);
//    //2.��ʾָ������
//    mySwap<int>(a, b);
//    cout << "a=" << a << endl;
//    cout << "b=" << b << endl;
//}
//
////notice
//// 
////1�Զ������Ƶ��������Ƶ���һ�µ���������T, �ſ���ʹ��
////void test2()
////{
////    int a = 10;
////    char b = 20;
////    mySwap(a, b);//T��һ�±���
////    cout << "a=" << a << endl;
////    cout << "b=" << b << endl;
////}
//
////2ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//template<class T>
//void func()
//{
//    cout << "func ����" << endl;
//}
//
//void test3()
//{
//    //func();�ᱨ��
//    func<int>();//Specify any one
//}
//
//int main()
//{
//    /*test1();
//    test3();*/
//
//    system("pause");
//
//    return 0;
//}


////ģ�尸��
////ʵ��ͨ�õĶ������������ĺ���
////Ҫ��Ӵ�С ,��ѡ������,��char����,int�������
//
////ѡ��������Ҫ����,�����дһ������ģ��
//template<class T>
//void mySwap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}
//
//template<class T>
//void mySort(T arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        int max = i;//ÿ��ѭ��ȷ�����ֵ�±�
//        for (int j = i + 1; j < len; j++)// �ҵ���ʵ���ֵ�±�
//        {
//            if (arr[max] < arr[j])
//            {
//                max = j;
//            }
//        }
//        mySwap(arr[max], arr[i]);
//    }
//}
//
////���Ե�ʱ��Ҫ��ӡ,���ṩ��ӡģ��
//template<class T>
//void myPrintArray(T arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void test1()
//{
//    //����char����
//    char charArr[] = "badcfe";
//    int num = sizeof(charArr) / sizeof(char);
//    mySort(charArr, num);
//    myPrintArray(charArr, num);
//}
//
//void test2()
//{
//    int intArr[] = { 2,4,5,3,7,89,100 };
//    int num = sizeof(intArr) / sizeof(int);
//    mySort(intArr, num);
//    myPrintArray(intArr, num);
//}
//
//int main()
//{
//    test1();
//    test2();
//    system("pause");
//
//    return 0;
//}


////��ͨ�����뺯��ģ����ù���
////1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//    // ע�� ������߱�����  ��ͨ�������еģ���ֻ������û��ʵ�֣����߲��ڵ�ǰ�ļ���ʵ�֣��ͻᱨ���Ҳ���
//
//void myPrint(int a, int b)
//{
//    cout << "original fun" << endl;
//}
//
//template <class T>
//void myPrint(T a, T b)
//{
//    cout << "template" << endl;
//}
////����ģ���������
//template <class T>
//void myPrint(T a, T b,T c)
//{
//    cout << "Reload template" << endl;
//}
//
//
//
//void test1()
//{
//    int a = 10;
//    int b = 20;
//    //myPrint(a, b);
//
//    //ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
//    myPrint<>(a, b);
//
//
//    myPrint<>(a, b,100);
//
//    //4�� �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��
//    char c1 = 'a';
//    char c2 = 'b';
//    myPrint(c1, c2); //���ú���ģ��
//
//}
//
//int main()
//{
//    test1();
//
//    return 0;
//}

//ģ��ľ�����
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
//e.g. :�ж���ȵ�ģ����֮ǰ���﷨�޷��ж϶����Ƿ����

//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//���廯����ʾ���廯��ԭ�ͺͶ���˼��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void test2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);

	//�Զ����������ͣ����������ͨ�ĺ���ģ��
	//���Դ������廯��Person�������͵�ģ�壬�������⴦���������
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}