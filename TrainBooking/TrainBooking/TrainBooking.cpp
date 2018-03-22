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
	login::MenuItem item1("1","登陆系统");
	login::MenuItem item2("2","退出系统");
	guestMenu.push_back(item1);
	guestMenu.push_back(item2);
}

	void initSecondMenu(vector<login::MenuItem>& SecondMenu)
{
	SecondMenu.push_back(login::MenuItem("11","购票"));
	SecondMenu.push_back(login::MenuItem("12","改签"));
	SecondMenu.push_back(login::MenuItem("13","退票"));
	SecondMenu.push_back(login::MenuItem("14","查询"));
	SecondMenu.push_back(login::MenuItem("15","返回上一级菜单"));
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
		cout << "购买成功" << endl ;
		break;
	case 2 : 
		break;
	case 3 : 
		break;
	case 4 :
		break;
	default:		
		cout << "我不明白你在说什么" << endl;	
	}
}

void enter1()
{	
	cout << "登陆成功" << endl;
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
		cout << "正确" << endl;
		break;
	case 3:
	{
		dataUtils->readallUserTicketIformation();
		cout << "请输入要删除的车票编号";
		string trainId;
		cin >> trainId;
		cout << "请输入要删除的用户身份证";
		string userId;
		cin >> userId;
		dataUtils->refundTicket(trainId, userId);
		cout << "删除成功";
		break;
	}
	case 4:
		cout << "正确" << endl;
		break;
	case 5:
		cout << "正确" << endl;
		break;
	default:
		cout << "输入错误" << endl;
	}
	
}

void loginSystem()
{
	cout<<"请输入用户名:";
	string username;
	cin >> username;
	cout<<"请输入密码:";
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
		cout << "登陆失败" << endl;
	}
}

void exitSystem()
{
	cout << "退出系统" << endl;
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
		cout << "输入错误" << endl;
	}
	return 0;
}