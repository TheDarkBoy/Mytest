#pragma once
#include "stdafx.h"
#include "menuitem.h"
namespace buyticket{

class BuyTicket
{
public:
	~BuyTicket(){}
	void confirmBuy(vector<MenuItem>& confirm_buy);
	void  buyTicket();
	string choiceTicket();
	static BuyTicket* getInstance();
private:
	BuyTicket(){}
};

}