#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StudentList.h"
#include "Course.h"
#include "Data.h"
#include "Person.h"
#include "Student.h"
#include <fstream>
#include <string>
#define NULL 0
#include <sstream>
using namespace std;

void StudentList::add(Student& a)//添加模块
{
	Node* pN = new Node(a);
	if (first) {
		pN->next = first;
		first->prev = pN;
	}
	first = pN;
	size++;
}

void StudentList::remove(string acntNo)
{
	for (Node* p = first; p; p = p->next) {
		if ((p->acnt).getStudentID() == acntNo) {
			if (p == first)//当删除第一个时 first指向p->next
				first = p->next;
			if (p->prev) {
				p->prev->next = p->next;
			}
			if (p->next) {
				p->next->prev = p->prev;
			}
			delete p;
			size--;
			break;
		}
	}
}
Student* StudentList::find(string acntNo) const//查找模块
{
	for (Node* p = first; p; p = p->next) {
		if ((p->acnt).getStudentID()==acntNo) {
			return &(p->acnt);
		}
	}
	return NULL;
}
void StudentList::display() const
{
	system("cls"); 
	cout << "本系统共有 " << size << " 个学生，其具体信息如下"<<endl;
	int i = 1;
	for (Node* p = first; p; p = p->next) {
		cout << i++<<":";
		(p->acnt).display();
		cout<<endl;
	}
}
void StudentList::readStudentFromDat(string path)
{
	cout << "正在从文件中读入信息..." << endl<<endl;
	
	//姓名 
	string Name;
	//年 
	int Day;
	//月
	int Month;
	//日
	int Year;
	//生日
	Data Birthday;
	//地址
	string Address;
	//年龄
	int Age;
	//id 
	string StudentID;
	//系	
	string Department;
	//课程数
	int NumberOfCourse;
	//课程名
	string CourseName;
	//修课年级
	int AcademicYear;
	//成绩
	float Grade;
	string buffer;
	stringstream ss;
	ifstream inputFile(&path[0]);

	while (getline(inputFile, buffer))
	{
		//课程数组
		Course* Record=new Course[20];
		ss.clear();//清空缓存
		ss.str(buffer);//将字符串分割
		ss >> Name>>Year>>Month>>Day;
		Birthday.setData(Day,Month,Year);
		ss>>Address>>Age>>StudentID>>Department>>NumberOfCourse;
		for(int i=0;i<NumberOfCourse;i++)
		{

			ss>>CourseName>>AcademicYear>>Grade;
			Record[i].setCourseName(CourseName);
			Record[i].setAcademicYear(AcademicYear);
			Record[i].setGrade(Grade);
		}

		add(*(new Student(Name,Birthday,Address,Age,StudentID,Department,NumberOfCourse,Record)));
		
	}
	cout << "读入全部账户信息成功！" << endl << endl;

}
void StudentList::saveStudentOnDat(string path)
{
	cout << "正在将学生信息写入文件..." << endl << endl;
	//写出txt
	fstream f(&path[0], ios::out);
	if (f.bad())
	{
		cout << "打开文件出错" << endl;
		exit(0);
	}
	for (Node* p = first; p; p = p->next) {//写入文件
		Student* acnt_p = &p->acnt;
		f << acnt_p->getName() << " ";
		f << acnt_p->getBirthday().Year << " ";
		f << acnt_p->getBirthday().Month << " ";
		f << acnt_p->getBirthday().Day<< " ";
		f << acnt_p->getAddress()<< " ";
		f << acnt_p->getAge()<< " ";
		f << acnt_p->getStudentID()<< " ";
		f << acnt_p->getDepartment()<< " ";
		f << acnt_p->getNumberOfCourse()<< " ";
		Course * a=acnt_p->getRecord();
		for(int i=0;i<acnt_p->getNumberOfCourse();i++)
		{
			f << a[i].getCourseName()<< " ";
			f << a[i].getAcademicYear()<< " ";
			f << a[i].getGrade()<< " ";
		}
		f<<endl;
	}
	f.close();
	cout << "写入成功！" << endl << endl;
}
void StudentList::display(Student stu)
{
	stu.display();
}
