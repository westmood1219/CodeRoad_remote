#include "speechManager.h"

//构造
SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();
}

//menu
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "请选择:";
}

void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//初始化属性
void SpeechManager::initSpeech()
{
	//容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker;

	//初始比赛轮数
	this->m_Index = 1;

	//将记录的容器也清空
	this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		//创建选手类前要先把选手类里的变量预制好

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		
		//再把管理类里和选手有关的容器填充进去
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speakerBattle();
	//3、显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speakerBattle();
	//3、显示最终结果
	this->showScore();
	//4、保存分数
	this->saveRecord();

	//重置比赛,获取记录
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "-------------------------------" << endl;
	cout << "抽签后演讲顺序如下" << endl;
	if (this->m_Index == 1)
	{
		//round one
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		//round two
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	system("pause");
	cout << endl;
}

//比赛
void SpeechManager::speakerBattle()
{
	cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;

	//准备临时容器,存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//统计人员个数(6人一组)

	vector<int>v_Src;
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//评委打分
		deque<double>score;
		for (int i = 0; i < 10; i++)
		{
			double singleScore = (600 + rand() % 401) / 10.f;
			score.push_back(singleScore);
			//cout << singleScore << " ";
		}
		//cout << endl;

		sort(score.begin(), score.end(),greater<double>());
		score.pop_front();//去掉最gao分
		score.pop_back();//去掉最低分
		int sum = accumulate(score.begin(), score.end(), 0.0f);
		double average = sum / (double)score.size();

		//每个人的平均分存到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = average; //this->m_Speaker[*it]是Speaker类,这个类.出来的第Index-1轮的分数是average,map容器通过中括号括起来键表示value了
		//打印平均分
		/*cout << "编号: " << *it <<"  "<<this->m_Speaker[*it].m_Name<<"第 "<<this->m_Index<<" 轮最终分数为 "<<average<<endl<<endl;*/

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(average, *it));//key是得分,value是选手编号

		//每六人中取前三名

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次: " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " " << this->m_Speaker[it->second].m_Name << " 本轮成绩: " << it->first << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count!=3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear();//小组容器清空
			cout << endl;
		}
	}
	
	cout << "------------第 " << this->m_Index << " 轮比赛完毕! ------------" << endl;
	system("pause");

}

//显示得分
void SpeechManager::showScore()
{
	cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;

	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名： " << m_Speaker[*it].m_Name << " 得分： " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//保存分数
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);// 用输出的方式打开文件  -- 写文件

	//将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录已保存" << endl;
}


//读取记录分数
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);//读文件
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;

	ifs.putback(ch);//将上面读取的单个字符 放回来

	string data;
	int index = 0;

	while (ifs >> data)
	{
		//cout << data << endl;//测试

		int pos = -1;//查到","位置的变量
		int start = 0;

		//存放六个string字符串

		vector<string>v;

		while (true)
		{
			pos = data.find(",", start);

			if (pos == -1)
			{
				//没有找到的情况
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);

			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;

	}

	ifs.close();
	this->fileIsEmpty = false;

	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "冠军编号: " << it->second[0] << " 分数: " << it->second[1] << endl;
	}*/
}

//显示往届记录
void SpeechManager::showRecord()
{
	system("cls");
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "         第  " << i + 1 << "  届  " << endl <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " " << endl<<
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " " << endl<<
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}

}

//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空 ?" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化属性
		this->initSpeech();

		//创建选手
		this->createSpeaker();

		//获取往届记录
		this->loadRecord();


		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构
SpeechManager::~SpeechManager()
{

}