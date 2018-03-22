#pragma once
#include "UserMenuItem.h"
#include "user.h"
#include <vector>

namespace login{

class Utils
{
private:
	int mChoice;
	Utils(){};
public:
	virtual ~Utils();
	static Utils* getInstance();
	void printWellcom();
	void printMenu(vector<MenuItem>& items);
	int getChoice();
	void choice();
	void splitString(vector<string>& strs, string line, string split);
	void printWellcom(User& user);
	
	
};

}