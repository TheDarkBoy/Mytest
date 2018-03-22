#pragma once
#include "StdAfx.h"
#include "Change.h"
#include "UserTicketInformation.h"
#include "utils.h"
#include "DataUtils.h"
#include "BuyTicket.h"

using namespace buyticket;
DataUtils* datautils = DataUtils::getInstance();
vector<UserTicketIformation> allUserTicketinformation;
BuyTicket* _buyticket = BuyTicket::getInstance();
void Change::changeTicket(User& user)
{	
	datautils->readallUserTicketIformation();
	allUserTicketinformation=datautils->get_allUserTicketIformation();
	datautils->readAllTrain();
	vector<Train> alltrain=datautils->get_allTrain();
	vector<UserTicketIformation>::iterator p = allUserTicketinformation.begin();
	cout << "���Ѿ�������ĳ�Ʊ��" << endl;
	cout << "���" << "  " << "����" << "  " << "��ʼվ" << "  " << "�յ�վ" << "  " << "����ʱ��" << "  "
						<< "����ʱ��" << "  " <<  endl;
	cout << "-------------------------------------------------" << endl;
	for (; p != allUserTicketinformation.end(); p++)
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
	
	cout << "����������Ҫ��ǩ�ĳ�Ʊ���" << endl;
	string trainID;
	cin >> trainID;
	cout << "�������������֤" << endl;
	string userId;
	cin >> userId;
	datautils->refundTicket(trainID,userId);


	
}
