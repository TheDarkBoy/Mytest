#pragma once
#include "stdafx.h"
#include "Train.h"
#include "DataUtils.h"
using namespace buyticket;
Train::Train(){}
Train::~Train(){}

string Train::get_id_()
{
	return id_;
}

string Train::get_train_number_()
{
	return train_number_;
}

string Train::get_start_station_()
{
	return start_station_;
}

string Train::get_terminal_station_()
{
	return terminal_station_;
}

string Train::get_start_time_()
{
	return start_time_;
}

string Train::get_arrival_time_()
{
	return arrival_time_;
}
int Train::get_surplus_seat_()
{
	return surplus_seat_;
}
void Train::set_id_(string t_id_)
{
	id_=t_id_;
}
void Train::set_train_number_(string t_train_number_)
{
	train_number_=t_train_number_;
}	
void Train::set_start_station_(string t_start_station_)
{
	start_station_=t_start_station_;
}
void Train::set_terminal_station_(string t_terminal_station_)
{
	terminal_station_=t_terminal_station_;
}
void Train::set_start_time_(string t_start_time_)
{
	start_time_=t_start_time_;
}
void Train::set_arrival_time_(string t_arrival_time_)
{
	arrival_time_=t_arrival_time_;
}
void Train::set_surplus_seat_(int t_surplus_seat_)
{
	surplus_seat_=t_surplus_seat_;
}
vector<Train> Train::checkTicket()
{
	DataUtils* dataUtils = DataUtils::getInstance();
	dataUtils->readAllTrain();
	vector<Train> allTrain = dataUtils->get_allTrain();
	vector<Train> myTrain ; 
	vector<Train>::iterator p = allTrain.begin();
	for(Train temp; p!=allTrain.end(); p++)
	{
		temp = *p;
		// 		cout << username << "," << password << endl;
		// 		cout << temp.getUsername() << "," << temp.getPassword() << endl;
		if(start_station_ == temp.get_start_station_() && terminal_station_ == temp.get_terminal_station_())
		{	
			Train train;
			train.set_id_(temp.get_id_());
			train.set_train_number_(temp.get_train_number_());
			train.set_start_station_(temp.get_start_station_());
			train.set_terminal_station_(temp.get_terminal_station_());
			train.set_start_time_(temp.get_start_time_());
			train.set_arrival_time_(temp.get_arrival_time_());
			train.set_surplus_seat_(temp.get_surplus_seat_());
			myTrain.push_back(train);
			
		}
	}
	    return myTrain;

}