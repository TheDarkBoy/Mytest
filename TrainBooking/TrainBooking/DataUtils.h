#pragma once
#include "StdAfx.h"
#include "Train.h"
#include <vector>
#include <fstream>
#include "UserTicketInformation.h"

namespace buyticket{

class DataUtils
{
private:
	vector<Train> allTrain;
	Train temp;
	DataUtils(){}
	vector<UserTicketIformation> allUserTicketIformation;
public:
	~DataUtils(){}
	static DataUtils* getInstance();
	void readAllTrain();
	void saveAllTrain(string choiceId);
	vector<Train>& get_allTrain();
	void saveBoughtTicketInformation(string userID, 
									 string trainID);
	void readallUserTicketIformation();
	void refundTicket(string trainId, string userId);
	void saveAllUserTicketIformation();
};

}