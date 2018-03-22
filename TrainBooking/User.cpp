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
			cout << "密码错误!" << endl;
			return false;
		}
	}
	cout << "此用户不存在!" << endl;
	return false;
}

bool User::singup()
{
	cout << "请输入你的身份证号" << endl;
	string id;
	cin >> id;
	cout << "请输入你的姓名" << endl;
	string s_username;
	cin >> s_username;
	cout << "请输入你的密码" << endl;
	string s_password;
	buyticket::Utils::inputPassword(s_password, 16);
	ofstream outuser("./data/users.txt", ios::app);
	outuser << "\n"<<id << " " << s_username << " " << s_password ;
	outuser.close();
	cout << "注册成功" << endl;
	return true;
}