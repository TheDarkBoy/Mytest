#pragma once
#include "stdafx.h"
#include "menuitem.h"
#include "user.h"
namespace buyticket{

class BuyTicket
{
public:
	~BuyTicket(){}
	//��Ʊ�Ĳ˵�����
	void confirmBuy(vector<MenuItem>& confirm_buy);
	//��Ʊ����
	void  buyTicket();
	//��ѯ��ƥ���Ʊ�������û�ѡ��ĳ��α��
	string choiceTicket(User user);

	static BuyTicket* getInstance();
	
private:
	BuyTicket(){}
};

}