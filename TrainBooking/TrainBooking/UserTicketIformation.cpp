#pragma once
#include "StdAfx.h"
#include "UserTicketInformation.h"

UserTicketIformation::UserTicketIformation(){}
UserTicketIformation::~UserTicketIformation(){}

string UserTicketIformation::get_my_ticket_information_()
{
	return my_ticket_information_;

}
string UserTicketIformation::get_me_()
{
	return me_;
}
string UserTicketIformation::gte_bought_time_()
{
	return bought_time_;
}


void UserTicketIformation::set_me_(string t_me_)
{
	me_ = t_me_;
}
void UserTicketIformation::set_my_ticket_information_(string t_my_ticket_information_)
{
	my_ticket_information_ = t_my_ticket_information_;
}
void UserTicketIformation::set_bought_time_(string t_bought_time_)
{
	bought_time_ = t_bought_time_;
}
