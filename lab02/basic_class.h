#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h> 

#include <iostream>
#define El 3

using std::cout;
using std::cin;
using std::endl;

class Student
{
private:

	int age;
	int number_stud;
	int middle_mark;
	const char *name;
	bool debt;
	int prog_d;

public:

	Student();

	Student(int a, int n, int m, const char* na, bool d, int pd);

	Student(const Student &other);

	int get_number_stud() const;

	int get_age() const;

	int get_middle_mark() const;

	const char* get_name();

	bool get_debt() const;

	int get_prog_d() const;

	~Student()
	{
		cout << "�������� ����������!" << endl;
	}
};