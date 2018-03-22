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
	//得到所有的车次信息
	void readAllTrain();
	//保存所有的车次信息
	void saveAllTrain(string choiceId);
	vector<Train>& get_allTrain();
	//保存用户买票信息
	void saveBoughtTicketInformation(string userID, 
									 string trainID);
	//读取用户买票信息
	void readallUserTicketIformation();
	//退票功能
	void refundTicket(string trainId, string userId);
	//保存所有用户买票信息
	void saveAllUserTicketIformation();
	//得到所有的用户买票信息
	vector<UserTicketIformation>& get_allUserTicketIformation();
	//得到一个车次信息（查询所有列车信息使用）
	void getTrain_t(Train& train, string line);
};

}