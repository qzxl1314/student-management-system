//------------------主程序----------------
#include <iostream>
#include<fstream>
#include "StudentList.h"
#include "Course.h"
#include "Data.h"
#include "Person.h"
#include "Student.h"
#include<windows.h>
#include<conio.h>
#include <string>
#include <stdio.h>
using namespace std;
StudentList a;
void welcome();
void add();
void wait_user()//等待用户 
{
	cout << "按任意键继续";
	_getch(); 
	system("cls");
	welcome();
}
void add()//添加学生
{
	system("cls");
	//学号
	string StudentID;
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
	//系	
	string Department;
	//课程数
	int NumberOfCourse;
	//课程数组
	Course Record[20];
	//课程名
	string CourseName;
	//修课年级
	int AcademicYear;
	//成绩
	int Grade;
	cout << "请输入学生的学号:"; cin >> StudentID;
	if (a.find(StudentID))
		cout << "该学号已存在！不能重复添加！";
	else
	{
		cout << "请输入学生的姓名:"; cin >> Name;
		cout << "请输入学生的生日，空格隔开按年月日的顺序:"; cin >> Year>>Month>>Day;
		Birthday.setData(Day,Month,Year);
		cout << "请输入学生的地址:"; cin >> Address;
		cout << "请输入学生的年龄:"; cin >> Age;
		cout << "请输入学生的系:"; cin >> Department;
		cout << "请输入学生的课程数:"; cin >> NumberOfCourse;
		for(int i=0;i<NumberOfCourse;i++)
		{
			cout << "请输入学生的第"<<i+1<<"门课程课程名，修课年级，成绩:";
			cin >>CourseName>>AcademicYear>>Grade;
			Record[i].setCourseName(CourseName);
			Record[i].setAcademicYear(AcademicYear);
			Record[i].setGrade(Grade);
		}
		a.add(*(new Student(Name,Birthday,Address,Age,StudentID,Department,NumberOfCourse,Record)));
	}
	wait_user();
}

void welcome()//初始界面
{
	cout << "欢迎来到学生信息管理系统" << endl << endl;
	cout << "1、从文件中读取学生信息" << endl << endl;
	cout << "2、显示当前所有学生信息" << endl << endl;
	cout << "3、新增学生" << endl << endl;
	cout << "4、通过学号查找学生" << endl << endl;
	cout << "5、将所有账户信息保存到文件" << endl << endl;
	cout << "6、退出" << endl << endl;
	cout << "请选择1-6：";
	int n;
	cin >> n;
	switch (n)
	{
	case 1:
		a.readStudentFromDat("student_data.txt");
		wait_user();
		break;
	case 2:
		a.display();
		wait_user();
		break;
	case 3:
		add();
		wait_user();
		break;
	case 4:
	{
		string id;
		cout << "请输入学号："; cin >> id;
		Student* p = a.find(id);
		if (!p)
			cout << "该账户不存在！" << endl;
		else
			p->display();
		wait_user();
		break;
	}
	case 5:
		a.saveStudentOnDat("student_data.txt");
		wait_user();
		break;
	case 6:
		exit(0);
		break;
	default:
		cout << "输入错误请重新输入\n";
		wait_user();
		break;
	}
}
int main()
{
	welcome();
}
