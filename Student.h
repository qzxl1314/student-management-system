//-----基础学生类-----
#pragma once
#ifndef HEADER_STUDENT
#define HEADER_STUDENT
#include <string>
#include "Course.h"
#include "Person.h"
using namespace std;

class Student:public Person {
private:
	//id                                                      
	string StudentID;
	//系	
	string Department;
	//课程数
	int NumberOfCourse;
	//课程数组
	Course* Record;
public:
	Student(string name,Data birthday,string address,int age,string studentID,string department,int numberOfCourse,Course* record);
	//id的访问器
	void setStudentID(string studentID);
	string getStudentID();
	//系的访问器
	void setDepartment(string department);
	string getDepartment();
	//课程数的访问器
	void setNumberOfCourse(int numberOfCourse);
	int getNumberOfCourse();
	//课程数组的访问器
	void setRecord(Course* course);
	Course* getRecord();
	//输出学生信息
	void display();
	//输出数组信息
	void disrecord();
};
#endif 