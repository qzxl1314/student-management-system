//-----基础学生类-----
#pragma once
#ifndef HEADER_PERSON
#define HEADER_PERSON
#include <string>
#include "Data.h"
using namespace std;

class Person {
private:
	//姓名 
	string Name;
	//生日
	Data Birthday;
	//地址
	string Address;
	//年龄
	int Age;
public:
	Person(){};
	Person(string name,Data birthday,string address,int age);
	//姓名的访问器
	void setName(string name);
	string getName();
	//生日的访问器
	void setBirthday(Data birthday);
	Data getBirthday();
	//地址的访问器
	void setAddress(string address);
	string getAddress();
	//年龄的访问器
	void setAge(int age);
	int getAge();
	//输出个人信息
	void displayperson();
};
#endif 