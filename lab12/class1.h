#pragma once
#include "Header.h"

class Student 
{
protected:
	int age;
	int number_stud;
	int middle_mark;
	string name;
	bool debt;
	int prog_d;

public:
	virtual string get_info() const;
	virtual stringstream get_str() const;
	int get_numb() const;

	Student();
	Student(int, int, int, string, bool, int);
	Student(const Student&);
	virtual ~Student();

	friend ostream& operator<< (ostream&, const Student&);
	virtual bool operator==(const int) const;
};