#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include "menuitem.h"

using namespace std;

namespace buyticket
{
class Utils
{
public:
	~Utils();
	static Utils* getInstance();

	void printMenu(vector<MenuItem>& items);
	int getChoice();
	void choice();
	void ticketChoice();
	void splitString(vector<string>& strs,
		                    string line, 
					        string split);
private:
	Utils();
	int m_choice_;

};


}