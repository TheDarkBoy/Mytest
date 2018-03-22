// BuyTicket.cpp : Defines the entry point for the console application.
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
#include "UserTicketInformation.h"

using namespace std;
using namespace buyticket;

 Train buy_ticket_user;
 DataUtils* _datautils = DataUtils::getInstance();
 Utils* utils = Utils::getInstance();
 vector<UserTicketIformation> _allUserTicketinformation;


BuyTicket* BuyTicket::getInstance()

{
	static BuyTicket Instance;
	return &Instance;
}
void BuyTicket::confirmBuy(vector<MenuItem>& confirm_buy)
{
	MenuItem item1("1","确认购买");
 	MenuItem item2("2","取消购买");
	confirm_buy.push_back(item1);
 	confirm_buy.push_back(item2);


} 
//输入起始车站查询并打印
void  BuyTicket::buyTicket()
{
	cout << "请输入起始站" << endl ;
	string start_station;
	cin >> start_station;
	cout << "请输入终点站" << endl ;
	string terminal_station;
	cin >> terminal_station;
	buy_ticket_user.set_start_station_(start_station);
	buy_ticket_user.set_terminal_station_(terminal_station);
	//保存相同起始站的全部车票信息
	vector<Train> myTrain = buy_ticket_user.checkTicket();
	if(myTrain.size()!=0)
	{
		vector<Train>::iterator p = myTrain.begin();
		cout <<"编号"<<"  "<< "车次" << "  " << "起始站" << " " << "终点站" << " " << "发车时间" << " "
			 << "到达时间" << " " << "剩余票数" << endl;
		cout <<"-------------------------------------------------" << endl ;
		for(Train temp ; p!=myTrain.end();p++){
			temp = *p ;
		cout << temp.get_id_()<< "  " <<temp.get_train_number_() << " " << temp.get_start_station_()
			 << "   " << temp.get_terminal_station_() << "  " << temp.get_start_time_()
			 << "    " << temp.get_arrival_time_() << "   " << temp.get_surplus_seat_() <<  endl;
		}
		cout <<"--------------------------------------------------" << endl;
		}else {
		cout <<"查询不到此信息，请重新输入!" << endl;
	    buyTicket();
			}
}
//根据车票编号选择所需要的车票
string BuyTicket::choiceTicket(User user)
{	
	string False = "404";
	vector<Train> myTrain = buy_ticket_user.checkTicket();
	utils->ticketChoice();
	_datautils->readallUserTicketIformation();
	_allUserTicketinformation = _datautils->get_allUserTicketIformation();
	vector<UserTicketIformation>::iterator s = _allUserTicketinformation.begin();
	for (; s != _allUserTicketinformation.end();s++)
	{ 
		if (s->get_me_() == user.getId()&& atoi(s->get_my_ticket_information_().c_str()) == utils->getChoice())
		{
			cout << "你已经购买了此车票，请勿重复购买" << endl;
			cout << "请重新购买"<< endl ;
			return False;
		}
	}
	vector<Train>::iterator it = myTrain.begin();
	
	 False = "405" ; 
	if (s == _allUserTicketinformation.end())
	{
		do 
		{ 
        
		for( ; it!=myTrain.end();it++)
		{
			
				if (atoi(it->get_id_().c_str())==utils->getChoice())
				{	
					cout << "您选择的是：" << endl ;
					cout << it->get_id_()<< "  " <<it->get_train_number_() << " " << it->get_start_station_()
						 << "   " << it->get_terminal_station_() << "  " << it->get_start_time_()
			             << "    " << it->get_arrival_time_() << "   " << it->get_surplus_seat_() <<  endl;
					return it->get_id_();
				}		
		}
	
		cout << "错误编号，请重新输入!" << endl ;
		utils->ticketChoice();
		it = myTrain.begin();
		} while (atoi(it->get_id_().c_str()) != utils->getChoice());
		return False;
	}	
}

		





