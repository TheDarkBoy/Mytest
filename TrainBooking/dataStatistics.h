#pragma once
#include "StdAfx.h"
#include "Train.h"
#include "DataUtils.h"
#include "utils.h"
#include <ctime>
#include <fstream>
#include <iostream>
class dataStatistics
{
public:
	dataStatistics();
	~dataStatistics();
	//��ӡ�����г�����Ϣ
	void printData();
private:
	vector<Train> allTrain;
};