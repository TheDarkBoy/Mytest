#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Userdatautils.h"
#include <iostream>
#include <fstream>
#include "utils.h"

using namespace std;
using namespace login;


void User::setId(string t_id)
{
	id = t_id;
}
void User::setUsername(string t_username)
{
	username = t_username;
}
void User::setPassword(string t_password)
{
	password = t_password;
}

string User::getId()
{
	return id;
}
string User::getUsername()
{
	return username;
}
string User::getPassword()
{
	return password;
}
bool User::login()
{
	DataUtils* dataUtils = DataUtils::getInstance();
	dataUtils->readAllUsers();
	vector<User> allUsers = dataUtils->getAllUsers();
	vector<User>::iterator p = allUsers.begin();
	for(User temp; p!=allUsers.end(); p++)
	{
		temp = *p;
		if (username == temp.getUsername() && password == temp.getPassword())
		{
			id = temp.getId();
			return true;
		}
		else if (username == temp.getUsername())
		{
			cout << "�������!" << endl;
			return false;
		}
	}
	cout << "���û�������!" << endl;
	return false;
}

bool User::singup()
{
	cout << "������������֤��" << endl;
	string id;
	cin >> id;
	cout << "�������������" << endl;
	string s_username;
	cin >> s_username;
	cout << "�������������" << endl;
	string s_password;
	buyticket::Utils::inputPassword(s_password, 16);
	ofstream outuser("./data/users.txt", ios::app);
	outuser << "\n"<<id << " " << s_username << " " << s_password ;
	outuser.close();
	cout << "ע��ɹ�" << endl;
	return true;
}