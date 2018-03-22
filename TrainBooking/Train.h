//BuyTicket
//Author:HeKaiChuan
//This is all train information
#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class Train
{
private:
	string id_;
	string train_number_;
	string start_station_;
	string terminal_station_;
	string start_time_;
	string arrival_time_;
	int    surplus_seat_;
public:
	Train();
	~Train();
	string get_id_();
	string get_train_number_();
	string get_start_station_();
	string get_terminal_station_();
	string get_start_time_();
	string get_arrival_time_();
	int    get_surplus_seat_();
	void   set_id_(string t_id_);
	void   set_train_number_(string t_train_number_);
	void   set_start_station_(string t_start_station_);
	void   set_terminal_station_(string t_terminal_station_);
	void   set_start_time_(string t_start_time_);
	void   set_arrival_time_(string t_arrival_time_);
	void   set_surplus_seat_(int t_surplus_seat_);
	vector<Train> checkTicket();
};
