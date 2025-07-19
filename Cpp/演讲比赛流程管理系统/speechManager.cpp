#include "speechManager.h"

//����
SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

	//���������¼
	this->loadRecord();
}

//menu
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
	cout << "��ѡ��:";
}

void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void SpeechManager::initSpeech()
{
	//�������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker;

	//��ʼ��������
	this->m_Index = 1;

	//����¼������Ҳ���
	this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		//����ѡ����ǰҪ�Ȱ�ѡ������ı���Ԥ�ƺ�

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		
		//�ٰѹ��������ѡ���йص���������ȥ
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1����ǩ
	this->speechDraw();
	//2������
	this->speakerBattle();
	//3����ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	this->speechDraw();
	//2������
	this->speakerBattle();
	//3����ʾ���ս��
	this->showScore();
	//4���������
	this->saveRecord();

	//���ñ���,��ȡ��¼
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeaker();

	//���������¼
	this->loadRecord();

	cout << "����������" << endl;
	system("pause");
	system("cls");
}

//��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->m_Index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------------" << endl;
	cout << "��ǩ���ݽ�˳������" << endl;
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

//����
void SpeechManager::speakerBattle()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;

	//׼����ʱ����,���С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0;//ͳ����Ա����(6��һ��)

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
		//��ί���
		deque<double>score;
		for (int i = 0; i < 10; i++)
		{
			double singleScore = (600 + rand() % 401) / 10.f;
			score.push_back(singleScore);
			//cout << singleScore << " ";
		}
		//cout << endl;

		sort(score.begin(), score.end(),greater<double>());
		score.pop_front();//ȥ����gao��
		score.pop_back();//ȥ����ͷ�
		int sum = accumulate(score.begin(), score.end(), 0.0f);
		double average = sum / (double)score.size();

		//ÿ���˵�ƽ���ִ浽map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = average; //this->m_Speaker[*it]��Speaker��,�����.�����ĵ�Index-1�ֵķ�����average,map����ͨ������������������ʾvalue��
		//��ӡƽ����
		/*cout << "���: " << *it <<"  "<<this->m_Speaker[*it].m_Name<<"�� "<<this->m_Index<<" �����շ���Ϊ "<<average<<endl<<endl;*/

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(average, *it));//key�ǵ÷�,value��ѡ�ֱ��

		//ÿ������ȡǰ����

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������: " << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " " << this->m_Speaker[it->second].m_Name << " ���ֳɼ�: " << it->first << endl;
			}

			//ȡ��ǰ����
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

			groupScore.clear();//С���������
			cout << endl;
		}
	}
	
	cout << "------------�� " << this->m_Index << " �ֱ������! ------------" << endl;
	system("pause");

}

//��ʾ�÷�
void SpeechManager::showScore()
{
	cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_Speaker[*it].m_Name << " �÷֣� " << m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//�������
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);// ������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "��¼�ѱ���" << endl;
}


//��ȡ��¼����
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);//���ļ�
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch);//�������ȡ�ĵ����ַ� �Ż���

	string data;
	int index = 0;

	while (ifs >> data)
	{
		//cout << data << endl;//����

		int pos = -1;//�鵽","λ�õı���
		int start = 0;

		//�������string�ַ���

		vector<string>v;

		while (true)
		{
			pos = data.find(",", start);

			if (pos == -1)
			{
				//û���ҵ������
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
		cout << it->first << "�ھ����: " << it->second[0] << " ����: " << it->second[1] << endl;
	}*/
}

//��ʾ�����¼
void SpeechManager::showRecord()
{
	system("cls");
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߲�����" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "         ��  " << i + 1 << "  ��  " << endl <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " " << endl<<
			"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " " << endl<<
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}

}

//��ռ�¼
void SpeechManager::clearRecord()
{
	cout << "ȷ����� ?" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//��ʼ������
		this->initSpeech();

		//����ѡ��
		this->createSpeaker();

		//��ȡ�����¼
		this->loadRecord();


		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//����
SpeechManager::~SpeechManager()
{

}