#include "Course.h"
#include <iostream>
using namespace std;
//课程类
Course::Course(string coursename,int academicyear,float grade):CourseName(coursename),AcademicYear(academicyear),Grade(grade)
{
}	
//初始化	
//课程名的访问器
void Course::setCourseName(string coursecname)
{
	CourseName=coursecname;
}
string Course::getCourseName()
{
	return CourseName;
}
//修课年级的访问器
void Course::setAcademicYear(int academicyear)
{
	AcademicYear=academicyear;
}
int Course::getAcademicYear()
{
	return AcademicYear;
}
//成绩的访问器
void Course::setGrade(int grade)
{
	Grade=grade;
}
int Course::getGrade()
{
	return Grade;
}
//输出课程信息
void Course::displayCourse()
{
	cout<<"课程名:"<<getCourseName()<<",修课年级:"<<getAcademicYear()<<",成绩:"<<getGrade()<<endl;
}

