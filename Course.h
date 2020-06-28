//-----课程类-----
#pragma once
#ifndef HEADER_COURSE
#define HEADER_COURSE
#include <string>
using namespace std;

class Course {
private:
	//课程名
	string CourseName;
	//修课年级
	int AcademicYear;
	//成绩
	int Grade;
public:
	Course() {};	
	Course(string coursename,int academicyear,float grade);
	//课程名的访问器
	void setCourseName(string coursecname);
	string getCourseName();
	//修课年级的访问器
	void setAcademicYear(int academicyear);
	int getAcademicYear();
	//成绩的访问器
	void setGrade(int grade);
	int getGrade();
	//输出课程情况
	void displayCourse();
};
#endif 