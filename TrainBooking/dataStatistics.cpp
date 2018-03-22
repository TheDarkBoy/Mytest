#pragma once
#include "StdAfx.h"
#include "dataStatistics.h"
#include "DataUtils.h"
#include <iomanip>  //������λС��
using namespace buyticket;//???????
using namespace std;

dataStatistics::dataStatistics(){}
dataStatistics::~dataStatistics(){}
void dataStatistics::printData(){
	DataUtils* datautils = DataUtils::getInstance();
	allTrain.clear();//���֮ǰ�洢������Ϣ
	//���ļ�
	ifstream infile("./data/TrainInformation.txt",ios::in);
	string line;
	cout << "���" << "  " << "����" << "  " << "��ʼվ" << "  " << "�յ�վ" << "  " << "����ʱ��" << "  "
						<< "����ʱ��" << "   " << "ʣ��Ʊ��"<<"     "<<"������"<<"     "<< endl;
	cout <<"---------------------------------------------------------------------------" << endl ;
	while(getline(infile,line)){
		Train train;
		datautils->getTrain_t(train,line);//11111111111	
		//��һ�����ݵ��ַ����һ��train����
		cout << train.get_id_()<<"  " <<train.get_train_number_()<< "  " 
			<< train.get_start_station_()<< "   " <<train.get_terminal_station_()
			<< "   " << train.get_start_time_() << "     " <<train.get_arrival_time_()
			<< "       "<<train.get_surplus_seat_()<<"         "<<setprecision(2)<<(600-train.get_surplus_seat_())/6.0<<"%"<<endl;
		allTrain.push_back(train);
	}
	cout <<"---------------------------------------------------------------------------" << endl ;
	//�ر��ļ�
	infile.close();
}
