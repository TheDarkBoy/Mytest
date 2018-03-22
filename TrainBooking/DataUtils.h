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
	//�õ����еĳ�����Ϣ
	void readAllTrain();
	//�������еĳ�����Ϣ
	void saveAllTrain(string choiceId);
	vector<Train>& get_allTrain();
	//�����û���Ʊ��Ϣ
	void saveBoughtTicketInformation(string userID, 
									 string trainID);
	//��ȡ�û���Ʊ��Ϣ
	void readallUserTicketIformation();
	//��Ʊ����
	void refundTicket(string trainId, string userId);
	//���������û���Ʊ��Ϣ
	void saveAllUserTicketIformation();
	//�õ����е��û���Ʊ��Ϣ
	vector<UserTicketIformation>& get_allUserTicketIformation();
	//�õ�һ��������Ϣ����ѯ�����г���Ϣʹ�ã�
	void getTrain_t(Train& train, string line);
};

}