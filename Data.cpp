#include "Data.h"
#include <iostream>
using namespace std;
//账号基类
Data::Data(int day,int month,int year):Day(day),Month(month),Year(year)
{
}	
//初始化日期	
void Data::display()const
{
	cout << Year <<"/"<<Month <<"/"<<Day;
}


//获得日期
void Data::setData(int day,int month,int year)
{
	Day = day;
	Month = month;
	Year = year;
}


