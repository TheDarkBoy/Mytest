#pragma once
#include "stdafx.h"
#include "menuitem.h"
#include "user.h"
namespace buyticket{

class BuyTicket
{
public:
	~BuyTicket(){}
	//买票的菜单插入
	void confirmBuy(vector<MenuItem>& confirm_buy);
	//买票功能
	void  buyTicket();
	//查询到匹配的票并返回用户选择的车次编号
	string choiceTicket(User user);

	static BuyTicket* getInstance();
	
private:
	BuyTicket(){}
};

}