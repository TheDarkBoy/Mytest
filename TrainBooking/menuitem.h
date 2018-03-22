#pragma once
#include <vector>
#include <string>

using namespace std;

namespace buyticket{
class MenuItem
{
private:
	string id;
	string text;
	vector<MenuItem> childItems;
public:
	MenuItem();
	MenuItem(string t_id ,string t_text):id(t_id),text(t_text){};
	virtual ~MenuItem();
	string getId();
	string getText();
	//vector<MenuItem>& ：函数返回的是一个vector<MenuItem>类型数据的引用
	vector<MenuItem>& getChildItems();
};
}