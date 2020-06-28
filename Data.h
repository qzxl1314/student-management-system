//-----日期类-----
#pragma once
#ifndef HEADER_DATA
#define HEADER_DATA
#include <string>
using namespace std;

class Data {
public:
	//年 
	int Day;
	//月
	int Month;
	//日
	int Year;
	Data() {};
	Data(int day,int month,int year);
	//日期的访问器
	void setData(int day,int month,int year);

	virtual void display()const;
};
#endif 