#pragma once
#include "StdAfx.h"
#include "dataStatistics.h"
#include "DataUtils.h"
#include <iomanip>  //保留两位小数
using namespace buyticket;//???????
using namespace std;

dataStatistics::dataStatistics(){}
dataStatistics::~dataStatistics(){}
void dataStatistics::printData(){
	DataUtils* datautils = DataUtils::getInstance();
	allTrain.clear();//清空之前存储过的信息
	//打开文件
	ifstream infile("./data/TrainInformation.txt",ios::in);
	string line;
	cout << "编号" << "  " << "车次" << "  " << "起始站" << "  " << "终点站" << "  " << "发车时间" << "  "
						<< "到达时间" << "   " << "剩余票数"<<"     "<<"入座率"<<"     "<< endl;
	cout <<"---------------------------------------------------------------------------" << endl ;
	while(getline(infile,line)){
		Train train;
		datautils->getTrain_t(train,line);//11111111111	
		//将一行数据的字符变成一个train对象
		cout << train.get_id_()<<"  " <<train.get_train_number_()<< "  " 
			<< train.get_start_station_()<< "   " <<train.get_terminal_station_()
			<< "   " << train.get_start_time_() << "     " <<train.get_arrival_time_()
			<< "       "<<train.get_surplus_seat_()<<"         "<<setprecision(2)<<(600-train.get_surplus_seat_())/6.0<<"%"<<endl;
		allTrain.push_back(train);
	}
	cout <<"---------------------------------------------------------------------------" << endl ;
	//关闭文件
	infile.close();
}
