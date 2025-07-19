#include "speechManager.h"

int main()
{
    srand((unsigned int)time(NULL));
    //创建管理类对象
    SpeechManager sm;
    ////测试选手的创建
    //for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    //{
    //    cout << "选手编号:" << it->first << " 选手姓名" << it->second.m_Name << " score:" << it->second.m_Score[0] << endl;
    //}
    int choice = 0;//存储用户输入
    
    while (true)
    {
        sm.show_Menu();
        cin >> choice;
        switch (choice)
        {
        case 1://开始比赛
            sm.startSpeech();
            break;
        case 2://查看往届比赛记录
            sm.showRecord();
            break;
        case 3://清空比赛记录
            sm.clearRecord();
            break;
        case 0://退出
            sm.exitSystem();
            break;
        default:
            cout << "输入有误,输入选项数字" << endl;
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}