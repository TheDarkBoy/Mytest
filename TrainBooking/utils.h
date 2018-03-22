#pragma once
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <conio.h>
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
	//�õ��û��ĳ�Ʊѡ��
	void ticketChoice();
	void splitString(vector<string>& strs,
		                    string line, 
					        string split);
	//�������ع��ߺ���
	static void inputPassword(string &str, int size) {
		char c;
		int count = 0;
		char *password = new char[size]; // ��̬����ռ�
		while ((c = getch()) != '\r') {

			if (c == 8) { // �˸�
				if (count == 0) {
					continue;
				}
				putchar('\b'); // ����һ��
				putchar(' '); // ���һ���ո�ԭ����*����
				putchar('\b'); // �ٻ���һ��ȴ�����
				count--;
			}
			if (count == size - 1) { // ��󳤶�Ϊsize-1
				continue;
			}
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // ����ֻ�ɰ������ֺ���ĸ
				putchar('*');  // ���յ�һ���ַ���, ��ӡһ��*
				password[count] = c;
				count++;
			}
		}
		password[count] = '\0';
		str = password;
		delete[] password; // �ͷſռ�
		cout << endl;
	}
private:
	Utils();
	int m_choice_;

};
}