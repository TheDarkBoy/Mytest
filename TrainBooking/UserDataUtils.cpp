#pragma once
#include "StdAfx.h"
#include "Userdatautils.h"
#include "Userutils.h"
#include <iostream>
using namespace login;

DataUtils::~DataUtils(){}
DataUtils* DataUtils::getInstance()
{
	static DataUtils instance;
	return &instance;
}

void getUser(User& user, string line)
{
	Utils* utils = Utils::getInstance();
	vector<string> datas;
	utils->splitString(datas,line," ");
	vector<string>::iterator p = datas.begin();
	string id = *p;
	p++;
	string username = *p;
	p++;
	string password = *p;
//	p++;
//	int type = atoi((*p).c_str());
	user.setId(id);
	user.setUsername(username);
	user.setPassword(password);
}

//使用之前，根据业务逻辑，第一次必须先执行readAllUsers
vector<User>& DataUtils::getAllUsers()
{
	return allUsers;
}
User& DataUtils::getUserById(string id)
{
	//根据id查到的用户信息，更新到temp中
	
	return temp;//temp中存储的就是要查询的单个用户信息
}

//读取文件重新生成一个allUsers对象
void DataUtils::readAllUsers()
{
	allUsers.clear();//清空之前存储过的信息
	//打开文件
	ifstream infile("./data/users.txt",ios::in);
	string line;
	while(getline(infile,line)){
		User user;	
		//将一行数据的字符变成一个user对象
		getUser(user,line);
// 		cout << user.getId() << "|" << user.getUsername() << "|" 
// 			<< user.getPassword() << endl;
		allUsers.push_back(user);
	}
	//关闭文件
	infile.close();
}

void DataUtils::printAllUsers()
{
	vector<User>::iterator p = allUsers.begin();
	for (User user; p!=allUsers.end(); p++)
	{
		user = *p;
		cout << user.getId() << "|" << user.getUsername() << "|" 
			<< user.getPassword() << endl;
	}
	
}