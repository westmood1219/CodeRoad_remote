#include<iostream>
using namespace std;

//if for while switch break goto...��Щ,����Cһ��,��һ�������д

//int main() {
//	int a = 10;
//	int b = 20;
//	int c = 0;
//
//	c = a > b ? a : b;
//	cout << "c = " << c << endl;
//
//	//C++����Ŀ��������ص��Ǳ���,���Լ�����ֵ
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
//	//���ѭ��ִ��1�Σ��ڲ�ѭ��ִ��1��
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			cout << "*" << " ";
//		}
//		cout << endl;
//		//ÿ�ε���endl���ᴥ��������ˢ�£�ȷ����������ɼ�,��Ƶ��ʹ�ÿ��ܵ��³������
//	}
//
//	system("pause");
//
//	return 0;
//}

//continue
//���ã���==ѭ�����==�У���������ѭ����������δִ�е���䣬����ִ����һ��ѭ��
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
}//continue��û��ʹ����ѭ����ֹ����break������ѭ��

