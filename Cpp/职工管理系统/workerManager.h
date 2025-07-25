#pragma once//防止头文件重复包含
#include <iostream> //包含输入输出流头文件
using namespace std;//使用标准命名空间
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

    //记录员工人数
    int m_EmpNum;

    //职工数组指针
    Worker** m_EmpArray;

    //添加职工
    void Add_Emp();

    //保存文件
    void save();

    //判断文件释放为空
    bool m_FileIsEmpty;

    //统计人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void Show_Emp();

    //按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);

    //删除职工
    void Del_Emp();

    //修改职工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();

    //清空文件
    void Clean_File();

    ~WorkerManager();

};