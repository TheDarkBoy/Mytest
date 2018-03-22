#pragma once
#include <string>

using namespace std;

class User
{
private:
	string id;
	string username;
	string password;
	int type;	
	
public:

	User(){}
	User(string t_id, string t_username, string t_password):
		id(t_id),username(t_username),password(t_password){};

		~User(){}
	bool login();
	//static User* getInstance();
	void setId(string t_id);
	void setUsername(string t_username);
	void setPassword(string password);
	string getId();
	string getUsername();
	string getPassword();
};