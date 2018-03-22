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

//ʹ��֮ǰ������ҵ���߼�����һ�α�����ִ��readAllUsers
vector<User>& DataUtils::getAllUsers()
{
	return allUsers;
}
User& DataUtils::getUserById(string id)
{
	//����id�鵽���û���Ϣ�����µ�temp��
	
	return temp;//temp�д洢�ľ���Ҫ��ѯ�ĵ����û���Ϣ
}

//��ȡ�ļ���������һ��allUsers����
void DataUtils::readAllUsers()
{
	allUsers.clear();//���֮ǰ�洢������Ϣ
	//���ļ�
	ifstream infile("./data/users.txt",ios::in);
	string line;
	while(getline(infile,line)){
		User user;	
		//��һ�����ݵ��ַ����һ��user����
		getUser(user,line);
// 		cout << user.getId() << "|" << user.getUsername() << "|" 
// 			<< user.getPassword() << endl;
		allUsers.push_back(user);
	}
	//�ر��ļ�
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