#pragma once
#include "StdAfx.h"
#include "DataUtils.h"
#include "Train.h"
#include "utils.h"
#include <ctime>
#include <fstream>
#include <iostream>

using namespace buyticket;
using namespace std;

DataUtils* DataUtils::getInstance()
{
	static DataUtils instance;
	return &instance;
}

vector<Train>& DataUtils::get_allTrain()
{
	return allTrain;
}

void getTrain(Train& train, string line)
{
	Utils* utils = Utils::getInstance();
	vector<string> datas;
	utils->splitString(datas,line," ");
	vector<string>::iterator p = datas.begin();
	string id = *p;
	p++;
	string train_number = *p;
	p++;
	string start_station = *p;
	p++;
	string terminal_station = *p;
	p++;
	string start_time = *p;
	p++;
	string arrival_time = *p;
	p++;
	int surplus_seat = atoi((*p).c_str());
	train.set_id_(id);
	train.set_train_number_(train_number);
	train.set_start_station_(start_station);
	train.set_terminal_station_(terminal_station);
	train.set_start_time_(start_time);
	train.set_arrival_time_(arrival_time);
	train.set_surplus_seat_(surplus_seat);
}
void DataUtils::readAllTrain()
{
	 allTrain.clear();//���֮ǰ�洢������Ϣ
	//���ļ�
	ifstream infile("./data/TrainInformation.txt",ios::in);
	string line;
	while(getline(infile,line)){
		Train train;	
		//��һ�����ݵ��ַ����һ��train����
		getTrain(train,line);
		allTrain.push_back(train);
	}
	//�ر��ļ�
	infile.close();
}
void DataUtils::saveAllTrain(string choiceId)
{	
	vector<Train>::iterator it = allTrain.begin();
	for(Train train; it != allTrain.end() ; it++)
	{
		train = *it ;
		if (train.get_id_()==choiceId)
		{
			train.set_surplus_seat_(train.get_surplus_seat_()-1);
			*it = train;
		}
	}
	ofstream outfile("./data/TrainInformation.txt");
	vector<Train>::iterator p = allTrain.begin();
	for(Train temp;p!=allTrain.end();p++)
	{
		temp = *p;
		outfile << temp.get_id_()<< " " <<temp.get_train_number_() << " " 
				<< temp.get_start_station_()<< " " << temp.get_terminal_station_() << " " 
				<< temp.get_start_time_()<< " " << temp.get_arrival_time_() << " " <<
				   temp.get_surplus_seat_() <<  endl;
	}
	outfile.close();
}
	
string getTime()
{
	time_t t;
	time(&t);
	struct tm*now = localtime(&t);
	string str = asctime(now);
	return str;
} 
	
void DataUtils::saveBoughtTicketInformation(string userID, string trainID)
{
	ofstream outfile("./data/UserTicketIformation.txt",ios::app);
	outfile  << userID << " " << trainID << " " <<getTime();
	outfile.close();
}



void get_UserTicketIformation(UserTicketIformation& userTicketIformation_, string line)
{
	Utils* utils = Utils::getInstance();
	vector<string> datas;
	utils->splitString(datas, line, " ");
	vector<string>::iterator p = datas.begin();
	string me_ = *p;
	p++;
	string my_ticket_information_ = *p;
	p++;
	string bought_time = *p;
	userTicketIformation_.set_my_ticket_information_(my_ticket_information_);
	userTicketIformation_.set_me_(me_);
	userTicketIformation_.set_bought_time_(bought_time);
}

void DataUtils::readallUserTicketIformation()
{

	allUserTicketIformation.clear();//���֮ǰ�洢������Ϣ
	//���ļ�
	ifstream infile("./data/UserTicketIformation.txt", ios::in);
	string line;
	while (getline(infile, line))
	{
		UserTicketIformation  t_userTicketIformation;
		//��һ�����ݵ��ַ����һ��train����
		get_UserTicketIformation(t_userTicketIformation, line);
		allUserTicketIformation.push_back(t_userTicketIformation);
	}
	//�ر��ļ�
	infile.close();
}

void DataUtils::saveAllUserTicketIformation()
{

	ofstream outfile("./data/UserTicketIformation.txt", ios::out);
	if (outfile.is_open()){
		vector<UserTicketIformation>::iterator p = allUserTicketIformation.begin();
		for (; p != allUserTicketIformation.end(); p++)
		{

		outfile << p->get_me_()
				<< " "
				<< p->get_my_ticket_information_()
				<< " "
				<< p->gte_bought_time_()
		        << endl;
		}
		outfile.close();
	}

}

void DataUtils::refundTicket(string trainId, string userId)
{


	vector<UserTicketIformation>::iterator it = allUserTicketIformation.begin();

	for (; it != allUserTicketIformation.end(); it++)
	{
		if (it->get_my_ticket_information_() == trainId && it->get_me_() == userId)
		{
			allUserTicketIformation.erase(it);
			saveAllUserTicketIformation();
			return;
		}
	}
	if (it==allUserTicketIformation.end())
	{
		cout << "ɾ��ʧ��" << endl;
	}

}