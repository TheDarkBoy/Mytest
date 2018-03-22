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
	login::MenuItem item1("1","��½ϵͳ");
	login::MenuItem item2("2","�˳�ϵͳ");
	login::MenuItem item3("3","�û�ע��");
	guestMenu.push_back(item1);
	guestMenu.push_back(item2);
	guestMenu.push_back(item3);
}

	void initSecondMenu(vector<login::MenuItem>& SecondMenu)
{
	SecondMenu.push_back(login::MenuItem("11","��Ʊ"));
	SecondMenu.push_back(login::MenuItem("12","��ǩ"));
	SecondMenu.push_back(login::MenuItem("13","��Ʊ"));
	SecondMenu.push_back(login::MenuItem("14","��ѯ�ҵĹ�Ʊ��Ϣ"));
	SecondMenu.push_back(login::MenuItem("15","��ѯ�г���Ϣ"));
	SecondMenu.push_back(login::MenuItem("16","�˳�"));
}
//��Ʊ
void buyticketStep()
	{
		buyticket::Utils* utils_ = buyticket::Utils::getInstance();
		buyticket_->buyTicket();
		string i = buyticket_->choiceTicket(loginUser);

		while(i=="404")//����Ѿ����˴�Ʊ���¹���
		{
	    buyticket_->buyTicket();
	     i = buyticket_->choiceTicket(loginUser);
		}
		while(i == "405")//����������ѭ������ֱ��������ȷ
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
			cout << "����ɹ�" << endl;
			cout << "��ESC������һ��" << endl;
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
			cout << "�Ҳ���������˵ʲô" << endl;
		}
	}
//����ϵͳ
void enter1(int flag)
{	if(flag)
{
	cout << "��½�ɹ�" << endl;
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
	cout << "��ESC������һ��" << endl;
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
		cout << "��ESC������һ��" << endl;
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
		cout << "������Ҫ��Ʊ�ĳ�Ʊ���";
		string trainId;
		cin >> trainId;
		cout << "������Ҫ��Ʊ���û����֤";
		string userId;
		cin >> userId;
		dataUtils->refundTicket(trainId, userId);
		cout << "��ESC������һ��" << endl;
		if (_getch() == 27)
		{
			int t_flag = 0;
			enter1(t_flag);
		}
		break;
	}
	case 4:
		 find(loginUser);
		 cout << "��ESC������һ��" << endl;
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
		 cout << "��ESC������һ��" << endl;
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
		cout << "�������" << endl;
	}
	
}

//��¼ϵͳ�˵�
void loginSystem()
{
	cout<<"�������û���:"<<endl;
	cin >> loginSystem_username;
	cout<<"����������:"<<endl;
	Utils::inputPassword(loginSystem_passwrod, 16);
	loginUser.setUsername(loginSystem_username);
	loginUser.setPassword(loginSystem_passwrod);
    isSuccess = loginUser.login();
	if(isSuccess)
	{
		enter1(1);	
	}
	cout << "����������!" << endl;
	loginSystem();
}

void exitSystem()
{
	cout << "�˳�ϵͳ" << endl;
}

//��ѯ���ѹ���ĳ�Ʊ
void find(User user)
{
	dataUtils->readallUserTicketIformation();
	d_allUserTicketinformation = dataUtils->get_allUserTicketIformation();
	dataUtils->readAllTrain();
	vector<Train> alltrain=dataUtils->get_allTrain();
	vector<UserTicketIformation>::iterator p = d_allUserTicketinformation.begin();
	cout << "���Ѿ�������ĳ�Ʊ��" << endl;
	cout << "���" << "  " << "����" << "  " << "��ʼվ" << "  " << "�յ�վ" << "  " << "����ʱ��" << "  "
		<< "����ʱ��" << "  " <<  endl;
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
	cout << "��ESC���ص�¼" << endl;
	if (_getch() == 27)
	{
		loginSystem();
	}
	break;
	}
	}
	default:
		cout << "�������" << endl;
	}
	return 0;
}