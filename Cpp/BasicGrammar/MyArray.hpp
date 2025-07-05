#pragma once
#include <iostream>
using namespace std;
#include <string>

template<class T>
class MyArray
{
public:

    //有参构造
    MyArray(int capacity)
    {
        //cout << "有参构造被调用" << endl;

        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    //拷贝构造(防止浅拷贝)
    MyArray(const MyArray& arr)
    {
        //cout << "拷贝构造 被调用" << endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //浅拷贝
        //this->pAddress = arr.pAddress
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];

        //将arr中的数据拷过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝
    //这里是为了链式拷贝,a=b=c,拷贝构造做不到
    MyArray& operator=(const MyArray& arr)
    {
        //cout << "重载运算符\"=\"被调用" << endl;
        //先判断原来堆区是否有数据,有的话先释放
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

    //尾插法
    void Push_Back(const T& val)
    {
        //先判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //尾删法
    void Pop_Back()
    {
        //逻辑伪删:让用户访问不到最后一个元素
        if (this->m_Size == 0)
        {
            return;
        }

        this->m_Size--;
    }

    //通过下标方式访问数组中的元素
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            //cout << "析构函数被调用" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }


private:
    //array T* 
    T *pAddress;  //指针指向堆区开辟的数组

    int m_Capacity; //数组容量

    int m_Size;     //数组大小

};
