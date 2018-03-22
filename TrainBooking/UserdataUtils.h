#pragma once
#include "user.h"
#include <vector>
#include <fstream>

namespace login{

class DataUtils
{
private:
	vector<User> allUsers;
	User temp;	
	DataUtils(){};
public:
	virtual ~DataUtils();
	static DataUtils* getInstance();

	//��ȡ�����û����ϵĶ��󣨲�ѯȫ����
	vector<User>& getAllUsers();
	//��ѯ����ĳ���û�����Ϣ
	User& getUserById(string id);
	//��ȡ�ļ���������һ��allUsers����
	void readAllUsers();
	//�������û���Ϣд���ļ������ǣ�

	void printAllUsers();

};

}