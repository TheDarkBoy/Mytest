// TrainBooking.cpp : Defines the entry point for the console application.
//

#pragma once
#include "Stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <conio.h>
#include "menuitem.h"
#include "utils.h"
#include "Train.h"
#include "user.h"
#include "DataUtils.h"
#include "BuyTicket.h"
#include "Userutils.h"
#include "Userdatautils.h"
#include "UsermenuItem.h"
#include "Change.h"
#include "dataStatistics.h"
void enter1(int flag);
void find(User user);
using namespace std;
using namespace buyticket;

	vector<MenuItem> confirm_buy;
	BuyTicket* buyticket_ = BuyTicket::getInstance();
	DataUtils* dataUtils = DataUtils::getInstance();
	
	vector<login::MenuItem> guestMenu;
    vector<login::MenuItem> SecondMenu;
	User loginUser;
	login::Utils* userutils_ = login::Utils::getInstance();

	vector<UserTicketIformation> d_allUserTicketinformation;
	Change change_;

	string loginSystem_username;
	string loginSystem_passwrod;
	bool isSuccess;

	
	void initGuestMenu(vector<login::MenuItem>& guestMenu)
{
	login::MenuItem item1("1","登陆系统");
	login::MenuItem item2("2","退出系统");
	login::MenuItem item3("3","用户注册");
	guestMenu.push_back(item1);
	guestMenu.push_back(item2);
	guestMenu.push_back(item3);
}

	void initSecondMenu(vector<login::MenuItem>& SecondMenu)
{
	SecondMenu.push_back(login::MenuItem("11","购票"));
	SecondMenu.push_back(login::MenuItem("12","改签"));
	SecondMenu.push_back(login::MenuItem("13","退票"));
	SecondMenu.push_back(login::MenuItem("14","查询我的购票信息"));
	SecondMenu.push_back(login::MenuItem("15","查询列车信息"));
	SecondMenu.push_back(login::MenuItem("16","退出"));
}
//买票
void buyticketStep()
	{
		buyticket::Utils* utils_ = buyticket::Utils::getInstance();
		buyticket_->buyTicket();
		string i = buyticket_->choiceTicket(loginUser);

		while(i=="404")//如果已经买了此票重新购买
		{
	    buyticket_->buyTicket();
	     i = buyticket_->choiceTicket(loginUser);
		}
		while(i == "405")//如果输入错误，循环输入直到输入正确
		{
			buyticket_->buyTicket();
		i = buyticket_->choiceTicket(loginUser);
         }
		buyticket_->confirmBuy(confirm_buy);
		utils_->printMenu(confirm_buy);
		utils_->choice();
		switch (utils_->getChoice())
		{
		case 1: dataUtils->saveAllTrain(i);
			dataUtils->saveBoughtTicketInformation(loginUser.getId(), i);
			cout << "购买成功" << endl;
			cout << "按ESC返回上一级" << endl;
			if (_getch() == 27)
			{
				int t_flag = 0;
				enter1(t_flag);
			}
			break;
		case 2: buyticket_->buyTicket();
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "我不明白你在说什么" << endl;
		}
	}
//进入系统
void enter1(int flag)
{	if(flag)
{
	cout << "登陆成功" << endl;
	userutils_->printWellcom(loginUser);
	initSecondMenu(SecondMenu);
}
	userutils_->printMenu(SecondMenu);
	userutils_->choice();
	
	switch (userutils_->getChoice())
	{
	case 1:
	{
		buyticketStep();
	cout << "按ESC返回上一级" << endl;
	if (_getch() == 27)
	{
		int t_flag = 0;
		enter1(t_flag);
	}
	break;
	}
	case 2:
	{
		change_.changeTicket(loginUser);
		buyticketStep();
		cout << "按ESC返回上一级" << endl;
		if (_getch() == 27)
		{
			int t_flag = 0;
			enter1(t_flag);
		}
		break;
	}
	case 3:
	{
		dataUtils->readallUserTicketIformation();
		cout << "请输入要退票的车票编号";
		string trainId;
		cin >> trainId;
		cout << "请输入要退票的用户身份证";
		string userId;
		cin >> userId;
		dataUtils->refundTicket(trainId, userId);
		cout << "按ESC返回上一级" << endl;
		if (_getch() == 27)
		{
			int t_flag = 0;
			enter1(t_flag);
		}
		break;
	}
	case 4:
		 find(loginUser);
		 cout << "按ESC返回上一级" << endl;
		 if (_getch() == 27)
		 {
			 int t_flag = 0;
			 enter1(t_flag);
		 }
		break;
	case 5:
		{
		     dataStatistics d;
 	         d.printData();
		 cout << "按ESC返回上一级" << endl;
		 if (_getch() == 27)
			{
				int t_flag = 0;
				enter1(t_flag);
			}
		break;
		}
	case 6 :
		exit(0);

	default:
		cout << "输入错误" << endl;
	}
	
}

//登录系统菜单
void loginSystem()
{
	cout<<"请输入用户名:"<<endl;
	cin >> loginSystem_username;
	cout<<"请输入密码:"<<endl;
	Utils::inputPassword(loginSystem_passwrod, 16);
	loginUser.setUsername(loginSystem_username);
	loginUser.setPassword(loginSystem_passwrod);
    isSuccess = loginUser.login();
	if(isSuccess)
	{
		enter1(1);	
	}
	cout << "请重新输入!" << endl;
	loginSystem();
}

void exitSystem()
{
	cout << "退出系统" << endl;
}

//查询我已购买的车票
void find(User user)
{
	dataUtils->readallUserTicketIformation();
	d_allUserTicketinformation = dataUtils->get_allUserTicketIformation();
	dataUtils->readAllTrain();
	vector<Train> alltrain=dataUtils->get_allTrain();
	vector<UserTicketIformation>::iterator p = d_allUserTicketinformation.begin();
	cout << "你已经购买过的车票有" << endl;
	cout << "编号" << "  " << "车次" << "  " << "起始站" << "  " << "终点站" << "  " << "发车时间" << "  "
		<< "到达时间" << "  " <<  endl;
	cout << "-------------------------------------------------" << endl;
	for (; p != d_allUserTicketinformation.end(); p++)
	{
		if (p->get_me_() == user.getId())
		{
			vector<Train>::iterator it = alltrain.begin();
			for (; it != alltrain.end(); it++)
			{
				if (it->get_id_() == p->get_my_ticket_information_())
				{
					cout << it->get_id_() << "  " << it->get_train_number_() << "  " << it->get_start_station_()
						<< "   " << it->get_terminal_station_() << "  " << it->get_start_time_() << "    "
						<< it->get_arrival_time_()<< "  " << endl;
				}
			}
		}
	}
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
	case 3:
	{	
		if (loginUser.singup())
		{
	cout << "按ESC返回登录" << endl;
	if (_getch() == 27)
	{
		loginSystem();
	}
	break;
	}
	}
	default:
		cout << "输入错误" << endl;
	}
	return 0;
}