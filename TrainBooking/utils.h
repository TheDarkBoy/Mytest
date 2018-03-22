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
	//得到用户的车票选择
	void ticketChoice();
	void splitString(vector<string>& strs,
		                    string line, 
					        string split);
	//密码隐藏工具函数
	static void inputPassword(string &str, int size) {
		char c;
		int count = 0;
		char *password = new char[size]; // 动态申请空间
		while ((c = getch()) != '\r') {

			if (c == 8) { // 退格
				if (count == 0) {
					continue;
				}
				putchar('\b'); // 回退一格
				putchar(' '); // 输出一个空格将原来的*隐藏
				putchar('\b'); // 再回退一格等待输入
				count--;
			}
			if (count == size - 1) { // 最大长度为size-1
				continue;
			}
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {  // 密码只可包含数字和字母
				putchar('*');  // 接收到一个字符后, 打印一个*
				password[count] = c;
				count++;
			}
		}
		password[count] = '\0';
		str = password;
		delete[] password; // 释放空间
		cout << endl;
	}
private:
	Utils();
	int m_choice_;

};
}