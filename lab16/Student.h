#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include <sstream>
#include <regex>
#include <memory>
#include <vector>
#include <exception>
#include <iterator>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::boolalpha;
using std::setiosflags;
using std::ios;
using std::ifstream;
using std::istream;
using std::ostream;
using std::ofstream;
using std::stringstream;
using std::istringstream;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::regex_replace;
using std::cmatch;
using std::unique_ptr;
using std::vector;
using std::exception;
using std::iterator;

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
	virtual int get_age() const;
	virtual int get_number() const;
	virtual int get_mark() const;
	virtual int get_dprog()const;
	virtual bool get_debt()const;
	virtual string get_name() const;

	virtual string getInfo() const;
	virtual void enter(istream&);

	Student();
	Student(int, int, int, string, bool, int);
	Student(const Student& other);
	virtual ~Student();

	friend ofstream& operator<< (ofstream&, const Student&);
	friend ostream& operator<< (ostream&, const Student&);

	void* operator new(size_t);
	void* operator new[](size_t);
	void operator delete(void*);
	void operator delete[](void*);
};
