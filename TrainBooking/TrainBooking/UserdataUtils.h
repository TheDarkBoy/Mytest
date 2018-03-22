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

	//获取所有用户集合的对象（查询全部）
	vector<User>& getAllUsers();
	//查询单独某个用户的信息
	User& getUserById(string id);
	//读取文件重新生成一个allUsers对象
	void readAllUsers();
	//将所有用户信息写入文件（覆盖）

	void printAllUsers();

};

}