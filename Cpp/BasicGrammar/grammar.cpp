//�������
#include <iostream>
using namespace std;

//�����Ķ���
#define Day 7//д�ں����ⲿ

int main()
{
    int a = 10;

    //����
    cout << "һ����Day = " << Day << "��" << endl;
    //const������д�ں����ڲ�
    const int month = 12;
    cout << "һ����month = " << month << "����" << endl;
    //sizeof
    cout << "longռ���ڴ�ռ�Ϊ:" << sizeof(long long) << endl;

    float f1 = 3.1415926f;//float��΢�е㲻һ��,����Ҫ��f��Ȼ�ᵱ��double����
    cout << "f1 = " << f1 << endl;//�����λ 3.14159

    //��ѧ������
    float f2 = 3e2;//3*10^2
    float f3 = 3e-2;//3*10^-2
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    system("pause");

    return 0;
}

//û˵�����Ǻ�Cһ��
/*
�������� ����ʹ�� ע��
��������:���� 
���ֹؼ���:sizeof 
*/