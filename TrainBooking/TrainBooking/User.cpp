#pragma once
#include "StdAfx.h"
#include "user.h"
#include "Userdatautils.h"
#include <iostream>

using namespace std;
using namespace login;

// User* User::getInstance()
// {
// 	static User Instance;
// 	return &Instance;
// }

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
		// 		cout << username << "," << password << endl;
		// 		cout << temp.getUsername() << "," << temp.getPassword() << endl;
		if(username == temp.getUsername() && password == temp.getPassword())
		{
			id = temp.getId();
			return true;
		}
	}
	return false;
}