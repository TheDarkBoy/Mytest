#pragma once
#include "StdAfx.h"
#include <vector>
#include "Train.h"

class UserTicketIformation
{
private:
	string my_ticket_information_;
	string  me_;
	string bought_time_;
public:
	UserTicketIformation();
	~UserTicketIformation();
	string get_my_ticket_information_();
	string get_me_();
	string gte_bought_time_();
	void set_my_ticket_information_(string t_my_ticket_information_);
	void set_me_(string t_me_);
	void set_bought_time_(string t_bought_time_);
};