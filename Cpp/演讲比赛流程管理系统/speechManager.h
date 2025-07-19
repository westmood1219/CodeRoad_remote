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

//设计管理类函数
class SpeechManager
{
public:
    //构造
    SpeechManager();
    // 初始化属性
    void initSpeech();
    //菜单
    void show_Menu();
    //创建选手
    void createSpeaker();
    //开始比赛
    void startSpeech();
    //抽签功能
    void speechDraw();
    //比赛
    void speakerBattle();
    //显示得分
    void showScore();
    //退出系统
    void exitSystem();

    //保存分数
    void saveRecord();

    //读取记录分数
    void loadRecord();

    //文件为空的标志
    bool fileIsEmpty;

    //往届记录
    map<int, vector<string>> m_Record;

    //显示往届得分
    void showRecord();

    void clearRecord();

    //析构
    ~SpeechManager();

    //成员属性
    //保存第一轮比赛选手编号容器
    vector<int>v1;
    //round two
    vector<int>v2;
    //final
    vector<int>vVictory;

    //存放编号及对应具体选手容器
    map<int, Speaker>m_Speaker;

    //比赛轮数
    int m_Index;
};