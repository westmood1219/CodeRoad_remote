#include "speechManager.h"

int main()
{
    srand((unsigned int)time(NULL));
    //�������������
    SpeechManager sm;
    ////����ѡ�ֵĴ���
    //for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
    //{
    //    cout << "ѡ�ֱ��:" << it->first << " ѡ������" << it->second.m_Name << " score:" << it->second.m_Score[0] << endl;
    //}
    int choice = 0;//�洢�û�����
    
    while (true)
    {
        sm.show_Menu();
        cin >> choice;
        switch (choice)
        {
        case 1://��ʼ����
            sm.startSpeech();
            break;
        case 2://�鿴���������¼
            sm.showRecord();
            break;
        case 3://��ձ�����¼
            sm.clearRecord();
            break;
        case 0://�˳�
            sm.exitSystem();
            break;
        default:
            cout << "��������,����ѡ������" << endl;
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}