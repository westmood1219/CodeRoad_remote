#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T>
class MyArray
{
public:

    //�вι���
    MyArray(int capacity)
    {
        //cout << "�вι��챻����" << endl;

        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //��������(��ֹǳ����)
    MyArray(const MyArray& arr)
    {
        //cout << "�������� ������" << endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //ǳ����
        //this->pAddress = arr.pAddress
        //���
        this->pAddress = new T[arr.m_Capacity];

        //��arr�е����ݿ�����
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= ��ֹǳ����
    //������Ϊ����ʽ����,a=b=c,��������������
    MyArray& operator=(const MyArray& arr)
    {
        //cout << "���������\"=\"������" << endl;
        //���ж�ԭ�������Ƿ�������,�еĻ����ͷ�
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //���
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //β�巨
    void Push_Back(const T& val)
    {
        //���ж������Ƿ���ڴ�С
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //βɾ��
    void Pop_Back()
    {
        //�߼�αɾ:���û����ʲ������һ��Ԫ��
        if (this->m_Size == 0)
        {
            return;
        }

        this->m_Size--;
    }

    //ͨ���±귽ʽ���������е�Ԫ��
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    //������������
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //���������С
    int getSize()
    {
        return this->m_Size;
    }

    //����
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            //cout << "��������������" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }


private:
    //array T* 
    T *pAddress;  //ָ��ָ��������ٵ�����

    int m_Capacity; //��������

    int m_Size;     //�����С

};
