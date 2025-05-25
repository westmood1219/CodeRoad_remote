#include<iostream>
using namespace std;

//if for while switch break goto...这些,都和C一样,不一样下面会写

//int main() {
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//	c = a > b ? a : b;
//	cout << "c = " << c << endl;
//
//	//C++中三目运算符返回的是变量,可以继续赋值
//
//	(a > b ? a : b) = 100;
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//	system("pause");
//
//	return 0;
//}

//int main() {
//
//	//外层循环执行1次，内层循环执行1轮
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			cout << "*" << " ";
//		}
//		cout << endl;
//		//每次调用endl都会触发缓冲区刷新，确保输出立即可见,但频繁使用可能导致程序变慢
//	}
//
//	system("pause");
//
//	return 0;
//}

//continue
//作用：在==循环语句==中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
int main() {

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		cout << i << endl;
	}

	system("pause");

	return 0;
}//continue并没有使整个循环终止，而break会跳出循环

