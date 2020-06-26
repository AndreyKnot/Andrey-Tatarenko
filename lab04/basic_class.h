#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h> 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

#define El 3

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::ofstream;
using std::ifstream;
using std::regex;

class Student
{
private:

	int age;
	int number_stud;
	int middle_mark;
	string name;
	bool debt;
	int prog_d;

public:

	Student();

	Student(int a, int n, int m, string na, bool d, int pd);

	Student(const Student &other);

	int get_number_stud() const;

	int get_age() const;

	int get_middle_mark() const;

	string get_name() const;

	bool get_debt() const;

	int get_prog_d() const;

	~Student()
	{
		cout << "Вызвался деструктор!" << endl;
	}
};