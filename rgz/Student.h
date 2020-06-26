/**
* @file Student.h
* Підключення необхідних бібліотек та оголошення класу Student.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h> /** Підключення бібліотеки crtdbg.h*/
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)

#include <string> /** Підключення бібліотеки string*/
#include <iostream> /** Підключення бібліотеки iostream*/
#include <iomanip> /** Підключення бібліотеки iomanip*/
#include <locale> /** Підключення бібліотеки locale*/
#include <fstream> /** Підключення бібліотеки fstream*/
#include <sstream> /** Підключення бібліотеки sstream*/
#include <regex> /** Підключення бібліотеки regex*/
#include <memory> /** Підключення бібліотеки memory*/
#include <vector> /** Підключення бібліотеки vector*/
#include <exception> /** Підключення бібліотеки exception*/
#include <iterator> /** Підключення бібліотеки iterator*/

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

class Student { /** Оголошення базового класу*/
protected:
	int age; /** Вік студента*/
	int number_stud; /** Номер студента*/
	int middle_mark; /** Середній бал*/
	string name; /** Ім'я*/
	bool debt; /** Чи є у студента борг*/
	int prog_d; /** Борг з програмування*/

public:
	virtual int get_age() const; /** Оголошення віртуального гетера отримання часу роботи програми*/
	virtual int get_prog_d() const; /** Оголошення віртуального гетера отримання боргу з програмування*/
	virtual int get_mark() const; /** Оголошення віртуального гетера отримання середньої оцінки*/
	virtual int get_number()const; /** Оголошення віртуального гетера отримання номера студента*/
	virtual bool get_debt()const; /** Оголошення віртуального гетера отримання часу роботи програми*/
	virtual string get_name() const; /** Оголошення віртуального гетера отримання імені студента*/

	virtual string getInfo() const; /** Оголошення віртуальної функції отримання інформації студента*/
	virtual void enter(istream&);

	Student(); /** Оголошення конструктора по замовчуванням*/
	Student(int, int, int, string, bool, int); /** Оголошення конструктора з параметрами*/
	Student(const Student& other); /** Оголошення конструктора копіювання*/
	virtual ~Student(); /** Оголошення віртуального деструктора*/

	friend ofstream& operator<< (ofstream&, const Student&); /** Оголошення перевантаженого оператора виводу у файл*/
	friend ostream& operator<< (ostream&, const Student&); /** Оголошення перевантаженого оператора виводу у консоль*/
	friend istream& operator>> (istream&, Student&); /** Оголошення перевантаженого оператора вводу*/
	virtual bool operator!=(const string) const; /** Оголошення віртуального перевантаженого оператора нерівності*/
	virtual bool operator==(const int) const; /** Оголошення віртуального перевантаженого оператора порівняння*/
	Student& operator= (Student&); /** Оголошення перевантаженого оператора присвоювання*/
};