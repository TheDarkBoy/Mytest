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

using namespace std;
using namespace buyticket;

 Train buy_ticket_user;
 
 Utils* utils = Utils::getInstance();
 

 //User* loginuser_ = User::getInstance();
 //User loginuser_;


BuyTicket* BuyTicket::getInstance()

{
	static BuyTicket Instance;
	return &Instance;
}
void BuyTicket::confirmBuy(vector<MenuItem>& confirm_buy)
{
	MenuItem item1("1","ȷ�Ϲ���");
 	MenuItem item2("2","ȡ������");
// 	MenuItem item3("3","�������˵�");
// 	MenuItem item4("4","�˳�ϵͳ");
	confirm_buy.push_back(item1);
 	confirm_buy.push_back(item2);
// 	confirm_buy.push_back(item3);
// 	confirm_buy.push_back(item4);
// 	
} 
//������ʼ��վ��ѯ����ӡ
void  BuyTicket::buyTicket()
{
	cout << "��������ʼվ" << endl ;
	string start_station;
	cin >> start_station;
	cout << "�������յ�վ" << endl ;
	string terminal_station;
	cin >> terminal_station;
	buy_ticket_user.set_start_station_(start_station);
	buy_ticket_user.set_terminal_station_(terminal_station);
	//������ͬ��ʼվ��ȫ����Ʊ��Ϣ
	vector<Train> myTrain = buy_ticket_user.checkTicket();
	if(myTrain.size()!=0)
	{
		vector<Train>::iterator p = myTrain.begin();
		cout <<"���"<<"  "<< "����" << "  " << "��ʼվ" << " " << "�յ�վ" << " " << "����ʱ��" << " "
			 << "����ʱ��" << " " << "ʣ��Ʊ��" << endl;
		cout <<"-------------------------------------------------" << endl ;
		for(Train temp ; p!=myTrain.end();p++){
			temp = *p ;
		cout << temp.get_id_()<< "  " <<temp.get_train_number_() << " " << temp.get_start_station_()
			 << "   " << temp.get_terminal_station_() << "  " << temp.get_start_time_()
			 << "    " << temp.get_arrival_time_() << "   " << temp.get_surplus_seat_() <<  endl;
		}
		cout <<"--------------------------------------------------" << endl;
		}else {
		cout <<"��ѯ��������Ϣ������������!" << endl;
	    buyTicket();
			}
}
//���ݳ�Ʊ���ѡ������Ҫ�ĳ�Ʊ
string BuyTicket::choiceTicket()
{		
	    vector<Train> myTrain = buy_ticket_user.checkTicket();
		Utils* utils = Utils::getInstance();
		utils->ticketChoice();
		vector<Train>::iterator it = myTrain.begin();
		for(Train temp ; it!=myTrain.end();it++)
		{
				temp = *it ;
				if (atoi(temp.get_id_().c_str())==utils->getChoice())
				{	
					cout << "��ѡ����ǣ�" << endl ;
					cout << temp.get_id_()<< "  " <<temp.get_train_number_() << " " << temp.get_start_station_()
						 << "   " << temp.get_terminal_station_() << "  " << temp.get_start_time_()
			             << "    " << temp.get_arrival_time_() << "   " << temp.get_surplus_seat_() <<  endl;
					return temp.get_id_();
				}
				
				
		}
		cout << "�����ţ�����������!" <<endl ;
		choiceTicket();
}
		





