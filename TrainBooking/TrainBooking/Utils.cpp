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
	//vector<MenuItem>::iterator-->是一个MenuItem的指针类型
	//items.begin()-->得到该集合中第一个元素的指针
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
	cout << "请选择："<<endl;
	cin >> m_choice_;
}
void Utils::ticketChoice()
{
	cout << "请输入编号选择您要购买的车票:"<< endl;
	cin  >> m_choice_;
}
