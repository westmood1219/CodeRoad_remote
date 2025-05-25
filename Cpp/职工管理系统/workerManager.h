#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream> //�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
    WorkerManager();

    //show menu
    void Show_Menu();

    //exit system
    void ExitSystem();

    //��¼Ա������
    int m_EmpNum;

    //ְ������ָ��
    Worker** m_EmpArray;

    //���ְ��
    void Add_Emp();

    //�����ļ�
    void save();

    //�ж��ļ��ͷ�Ϊ��
    bool m_FileIsEmpty;

    //ͳ������
    int get_EmpNum();

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ��
    void Show_Emp();

    //����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
    int IsExist(int id);

    //ɾ��ְ��
    void Del_Emp();

    //�޸�ְ��
    void Mod_Emp();

    //����ְ��
    void Find_Emp();

    //����ְ��
    void Sort_Emp();

    //����ļ�
    void Clean_File();

    ~WorkerManager();

};