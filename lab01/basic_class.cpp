#include "basic_class.h"

int Student::get_number_stud() const
{
	return number_stud;
}

void Student::set_number_stud(int n)
{
	number_stud = n;
}

int Student::get_age() const
{
	return age;
}

void Student::set_age(int a)
{
	age = a;
}

int Student::get_middle_mark() const
{
	return middle_mark;
}

void Student::set_middle_mark()
{
	middle_mark = rand() % 10;
}