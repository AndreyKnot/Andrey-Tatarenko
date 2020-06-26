/**
* @file Student.h
* ϳ��������� ���������� ������� �� ���������� ����� Student.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h> /** ϳ��������� �������� crtdbg.h*/
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string> /** ϳ��������� �������� string*/
#include <iostream> /** ϳ��������� �������� iostream*/
#include <iomanip> /** ϳ��������� �������� iomanip*/
#include <locale> /** ϳ��������� �������� locale*/
#include <fstream> /** ϳ��������� �������� fstream*/
#include <sstream> /** ϳ��������� �������� sstream*/
#include <regex> /** ϳ��������� �������� regex*/
#include <memory> /** ϳ��������� �������� memory*/
#include <vector> /** ϳ��������� �������� vector*/
#include <exception> /** ϳ��������� �������� exception*/
#include <iterator> /** ϳ��������� �������� iterator*/

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

class Student { /** ���������� �������� �����*/
protected:
	int age; /** ³� ��������*/
	int number_stud; /** ����� ��������*/
	int middle_mark; /** ������� ���*/
	string name; /** ��'�*/
	bool debt; /** �� � � �������� ����*/
	int prog_d; /** ���� � �������������*/

public:
	virtual int get_age() const; /** ���������� ����������� ������ ��������� ���� ������ ��������*/
	virtual int get_prog_d() const; /** ���������� ����������� ������ ��������� ����� � �������������*/
	virtual int get_mark() const; /** ���������� ����������� ������ ��������� �������� ������*/
	virtual int get_number()const; /** ���������� ����������� ������ ��������� ������ ��������*/
	virtual bool get_debt()const; /** ���������� ����������� ������ ��������� ���� ������ ��������*/
	virtual string get_name() const; /** ���������� ����������� ������ ��������� ���� ��������*/

	virtual string getInfo() const; /** ���������� ��������� ������� ��������� ���������� ��������*/
	virtual void enter(istream&);

	Student(); /** ���������� ������������ �� �������������*/
	Student(int, int, int, string, bool, int); /** ���������� ������������ � �����������*/
	Student(const Student& other); /** ���������� ������������ ���������*/
	virtual ~Student(); /** ���������� ����������� �����������*/

	friend ofstream& operator<< (ofstream&, const Student&); /** ���������� ��������������� ��������� ������ � ����*/
	friend ostream& operator<< (ostream&, const Student&); /** ���������� ��������������� ��������� ������ � �������*/
	friend istream& operator>> (istream&, Student&); /** ���������� ��������������� ��������� �����*/
	virtual bool operator!=(const string) const; /** ���������� ����������� ��������������� ��������� ��������*/
	virtual bool operator==(const int) const; /** ���������� ����������� ��������������� ��������� ���������*/
	Student& operator= (Student&); /** ���������� ��������������� ��������� ������������*/
};