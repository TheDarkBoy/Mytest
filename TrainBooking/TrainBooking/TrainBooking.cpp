// TrainBooking.cpp : Defines the entry point for the console application.
//

#pragma once
#include "Stdafx.h"
#include <iostream>
#include <string>
#include "menuitem.h"
#include "utils.h"
#include "Train.h"
#include "user.h"
#include "DataUtils.h"
#include "BuyTicket.h"
#include "Userutils.h"
#include "Userdatautils.h"
#include "UsermenuItem.h"
#include <vector>

using namespace std;
using namespace buyticket;

	vector<MenuItem> confirm_buy;
	BuyTicket* buyticket_ = BuyTicket::getInstance();
	DataUtils* dataUtils = DataUtils::getInstance();
	
	vector<login::MenuItem> guestMenu;
    vector<login::MenuItem> SecondMenu;
	User loginUser;
	login::Utils* userutils_ = login::Utils::getInstance();
	void initGuestMenu(vector<login::MenuItem>& guestMenu)
{
	login::MenuItem item1("1","��½ϵͳ");
	login::MenuItem item2("2","�˳�ϵͳ");
	guestMenu.push_back(item1);
	guestMenu.push_back(item2);
}

	void initSecondMenu(vector<login::MenuItem>& SecondMenu)
{
	SecondMenu.push_back(login::MenuItem("11","��Ʊ"));
	SecondMenu.push_back(login::MenuItem("12","��ǩ"));
	SecondMenu.push_back(login::MenuItem("13","��Ʊ"));
	SecondMenu.push_back(login::MenuItem("14","��ѯ"));
	SecondMenu.push_back(login::MenuItem("15","������һ���˵�"));
}
void buyticketStep()
{	
	buyticket::Utils* utils_ = buyticket::Utils::getInstance();
	buyticket_->buyTicket();
	string i = buyticket_->choiceTicket();
	buyticket_->confirmBuy(confirm_buy);
	utils_->printMenu(confirm_buy);
	utils_->choice();
	switch (utils_->getChoice())
	{
	case 1 : dataUtils->saveAllTrain(i);
		dataUtils->saveBoughtTicketInformation(loginUser.getId(),i);
		cout << "����ɹ�" << endl ;
		break;
	case 2 : 
		break;
	case 3 : 
		break;
	case 4 :
		break;
	default:		
		cout << "�Ҳ���������˵ʲô" << endl;	
	}
}

void enter1()
{	
	cout << "��½�ɹ�" << endl;
	userutils_->printWellcom(loginUser);
	initSecondMenu(SecondMenu);
	userutils_->printMenu(SecondMenu);
	userutils_->choice();
	
	switch (userutils_->getChoice())
	{
	case 1:
		buyticketStep();
		break;
	case 2:
		cout << "��ȷ" << endl;
		break;
	case 3:
	{
		dataUtils->readallUserTicketIformation();
		cout << "������Ҫɾ���ĳ�Ʊ���";
		string trainId;
		cin >> trainId;
		cout << "������Ҫɾ�����û����֤";
		string userId;
		cin >> userId;
		dataUtils->refundTicket(trainId, userId);
		cout << "ɾ���ɹ�";
		break;
	}
	case 4:
		cout << "��ȷ" << endl;
		break;
	case 5:
		cout << "��ȷ" << endl;
		break;
	default:
		cout << "�������" << endl;
	}
	
}

void loginSystem()
{
	cout<<"�������û���:";
	string username;
	cin >> username;
	cout<<"����������:";
	string passwrod;
	cin >> passwrod;
	loginUser.setUsername(username);
	loginUser.setPassword(passwrod);
	bool isSuccess = loginUser.login();
	if(isSuccess)
	{
		enter1();	
	}
	else
	{
		cout << "��½ʧ��" << endl;
	}
}

void exitSystem()
{
	cout << "�˳�ϵͳ" << endl;
}


int main(int argc, char* argv[])
{
	
	userutils_->printWellcom();
		initGuestMenu(guestMenu);
	userutils_->printMenu(guestMenu);
	userutils_->choice();
	switch (userutils_->getChoice())
	{
	case 1:
		loginSystem();
		break;
	case 2:
	    exitSystem();
		break;
	default:
		cout << "�������" << endl;
	}
	return 0;
}