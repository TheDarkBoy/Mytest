#pragma once
#include "stdafx.h"
#include "utils.h"
using namespace buyticket;

Utils::Utils()
{

}
Utils::~Utils()
{

}
Utils* Utils::getInstance()
{
	static Utils utils;
	return &utils;
}
void Utils::splitString(vector<string>& strs, string line, string split)
{
	int pos1 = 0;
	int pos2 = 0;
	pos2 = line.find(split);
	while(pos2 != string::npos)
	{
		strs.push_back(line.substr(pos1, pos2-pos1));
		pos1 = pos2 + split.size();
		pos2 = line.find(split,pos1);
	}
	if(pos2 != line.length())
	{
		strs.push_back(line.substr(pos1));
	}
}
void Utils::printMenu(vector<MenuItem>& items)
{
	//vector<MenuItem>::iterator-->��һ��MenuItem��ָ������
	//items.begin()-->�õ��ü����е�һ��Ԫ�ص�ָ��
	vector<MenuItem>::iterator p = items.begin();
	for (int i=0; i<items.size(); i++)
	{
		MenuItem temp = *p;
		cout << "-->" << (i+1) << "." << temp.getText() << endl;
		p++;
	}

}
int Utils::getChoice()
{
	return m_choice_;
}

void Utils::choice()
{
	cout << "��ѡ��"<<endl;
	cin >> m_choice_;
}
void Utils::ticketChoice()
{
	cout << "��������ѡ����Ҫ����ĳ�Ʊ:"<< endl;
	cin  >> m_choice_;
}
