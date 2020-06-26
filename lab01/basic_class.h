#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h> 

#include <iostream>
#define El 5

using std::cout;
using std::cin;
using std::endl;

class Student
{
private:

	int age;
	int number_stud;
	int middle_mark;

public:

	void set_number_stud(int);
	int get_number_stud() const;

	void set_age(int);
	int get_age() const;

	void set_middle_mark();
	int get_middle_mark() const;

};