//-----银行账户管理链表容器类-----
#pragma once
#ifndef HEADER_STUDENTLIST
#define HEADER_STUDENTLIST
#include <string>
#include "Student.h"

class Node {
public:
	Student& acnt;
	Node *next, *prev;
	Node(Student& a) :acnt(a), next(0), prev(0) {
	}
};

class StudentList {
public:
	StudentList() :first(0), size(0) {
	}
	Node* getFirst() {
		return first;
	}
	int getSize() {
		return size;
	}
	bool isEmpty()const {
		return !size;
	}
	void readStudentFromDat(string path);
	void saveStudentOnDat(string path);
	void add(Student& a);
	void remove(string acntNo);
	Student* find(string acntNo)const;
	void display()const;
	void display(Student stu);
private:
	//容量
	int size;
	//初始
	Node* first;
};

#endif
