#pragma once
#include "StdAfx.h"
#include "MenuItem.h"
using namespace buyticket;

MenuItem::MenuItem(){}
MenuItem::~MenuItem(){}

string MenuItem::getId()
{
	return id;
}

string MenuItem::getText()
{
	return text;
}

vector<MenuItem>& MenuItem::getChildItems()
{
	return childItems;
}