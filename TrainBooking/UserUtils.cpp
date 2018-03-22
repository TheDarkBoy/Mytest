#pragma once
#include "stdAfx.h"
#include <iostream>
#include "Userutils.h"
#include "Usermenuitem.h"
#include "BuyTicket.h"
#include "user.h"
#include "UserdataUtils.h"


using namespace std;
using namespace login;

login::DataUtils* dataUtils = login::DataUtils::getInstance();
//buyticket::BuyTicket* buyticket_ = buyticket::BuyTicket::getInstance();


Utils::~Utils()
{

}

Utils* Utils::getInstance()
{
	static Utils instance;
	return &instance;
}

void Utils::printWellcom()
{
	cout << "--------------------------------" << endl;
	cout << "  欢迎使用火车自助订票系统" << endl;
	cout << "--------------------------------" << endl;
}

void Utils::printMenu(vector<login::MenuItem>& items)
{
	//vector<MenuItem>::iterator-->是一个MenuItem的指针类型
	//items.begin()-->得到该集合中第一个元素的指针
	vector<login::MenuItem>::iterator p = items.begin();
	for (int i=0; i<items.size(); i++)
	{
		login::MenuItem temp = *p;
		cout << "-->" << (i+1) << "." << temp.getText() << endl;
		p++;
	}

}


int Utils::getChoice()
{
	return mChoice;
}

void Utils::choice()
{
	cout << "请选择：";
	cin >> mChoice;
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
void Utils::printWellcom(User& user)
{
	cout << "-----------------------------------------" << endl;
	cout << "欢迎" << user.getUsername() <<endl;
	cout << "-----------------------------------------" << endl;
}

