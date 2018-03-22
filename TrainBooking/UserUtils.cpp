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
	cout << "  ��ӭʹ�û�������Ʊϵͳ" << endl;
	cout << "--------------------------------" << endl;
}

void Utils::printMenu(vector<login::MenuItem>& items)
{
	//vector<MenuItem>::iterator-->��һ��MenuItem��ָ������
	//items.begin()-->�õ��ü����е�һ��Ԫ�ص�ָ��
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
	cout << "��ѡ��";
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
	cout << "��ӭ" << user.getUsername() <<endl;
	cout << "-----------------------------------------" << endl;
}

