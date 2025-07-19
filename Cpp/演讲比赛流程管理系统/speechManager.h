#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <string>
#include <algorithm>
#include <deque>
#include <numeric>
#include <functional>
#include <fstream>
#include <ctime>

//��ƹ����ຯ��
class SpeechManager
{
public:
    //����
    SpeechManager();
    // ��ʼ������
    void initSpeech();
    //�˵�
    void show_Menu();
    //����ѡ��
    void createSpeaker();
    //��ʼ����
    void startSpeech();
    //��ǩ����
    void speechDraw();
    //����
    void speakerBattle();
    //��ʾ�÷�
    void showScore();
    //�˳�ϵͳ
    void exitSystem();

    //�������
    void saveRecord();

    //��ȡ��¼����
    void loadRecord();

    //�ļ�Ϊ�յı�־
    bool fileIsEmpty;

    //�����¼
    map<int, vector<string>> m_Record;

    //��ʾ����÷�
    void showRecord();

    void clearRecord();

    //����
    ~SpeechManager();

    //��Ա����
    //�����һ�ֱ���ѡ�ֱ������
    vector<int>v1;
    //round two
    vector<int>v2;
    //final
    vector<int>vVictory;

    //��ű�ż���Ӧ����ѡ������
    map<int, Speaker>m_Speaker;

    //��������
    int m_Index;
};