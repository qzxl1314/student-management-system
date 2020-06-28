#include "Student.h"
#include "Course.h"
#include <iostream>

using namespace std;
//学生类
Student::Student(string name,Data birthday,string address,int age,string studentID,string department,int numberOfCourse,Course* record):Person(name,birthday,address,age),StudentID(studentID),Department(department),NumberOfCourse(numberOfCourse),Record(record)
{
}	
//初始化函数
void Student::setStudentID(string studentID)
{
	StudentID = studentID;
}
string Student::getStudentID()
{
	return StudentID;
}
//id访问器实现
void Student::setDepartment(string department)
{
	Department = department;
}
string Student::getDepartment()
{
	return Department;
}
//系的访问器
void Student::setNumberOfCourse(int numberOfCourse)
{
	NumberOfCourse = numberOfCourse;
}
int Student::getNumberOfCourse()
{
	return NumberOfCourse;
}
//课程数的访问器
void Student::setRecord(Course* course)
{
	Record = course;
}
Course* Student::getRecord()
{
	return Record;
}
void Student::disrecord()
{
	
	for(int i=0;i<NumberOfCourse;i++)
	{
		Record[i].displayCourse();
	}
}
//课程数组的访问器
void Student::display()
{
	Student::displayperson();
	cout<<",学号:"<<Student::getStudentID()<<",专业:"<<Student::getDepartment()<<",课程数:"<<Student::getNumberOfCourse()<<endl;
	cout<<"课程情况:"<<endl;
	Student::disrecord();
}