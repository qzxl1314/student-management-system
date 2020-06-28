#include "Person.h"
#include "Data.h"
#include <string>
#include <iostream>

using namespace std;
//学生基类
Person::Person(string name,Data birthday,string address,int age):Name(name),Birthday(birthday),Address(address),Age(age)
{
}	
//初始化函数
void Person::setName(string name)
{
	Name = name;
}
string Person::getName()
{
	return Name;
}
//姓名访问器实现
void Person::setBirthday(Data birthday)
{
	Birthday = birthday;
}
Data Person::getBirthday()
{
	return Birthday;
}
//生日访问器实现
void Person::setAddress(string address)
{
	Address = address;
}
string Person::getAddress()
{
	return Address;
}
//地址访问器实现
void Person::setAge(int age)
{
	Age = age;
}
int Person::getAge()
{
	return Age;
}
//年龄访问器实现
void Person::displayperson()
{
	Data b=Person::getBirthday();
	cout<<"姓名:"<<Person::getName()<<",生日:";
	b.display();
	cout<<",地址:"<<Person::getAddress()<<",年龄:"<<Person::getAge();
}