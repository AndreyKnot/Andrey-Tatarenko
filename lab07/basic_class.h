#pragma once

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h> 

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#include "audience.h"
#include "faculty.h"

#define El 3

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::ofstream;
using std::ifstream;
using std::regex;

typedef bool (comp)(const int&, const int&);

class Student
{
protected:

	int age;
	int number_stud;
	int middle_mark;
	string name;
	bool debt;
	int prog_d;
	Aud audience;
	Fac faculty;

public:

	virtual int get_number_stud() const;

	virtual int get_age() const;

	virtual int get_middle_mark() const;

	virtual string get_name() const;

	virtual bool get_debt() const;

	virtual int get_prog_d() const;

	virtual sint get_aud() const;

	virtual string get_fac() const;

	virtual void print() const = 0;
	virtual stringstream get_str() const = 0;
	virtual void write_in_file(ofstream&) = 0;

	Student();

	Student(int a, int n, int m, string na, bool d, int pd, sint ad, string fc);

	Student(const Student &other);

	~Student()
	{
		cout << "Вызвался деструктор!" << endl;
	}
};