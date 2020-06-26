#include "basic_class.h"

Student::Student() : age(0), number_stud(0), middle_mark(0), name("Name"), debt(0), prog_d(0)
{
	cout << "������ ���������� �����������!" << endl;
}

Student::Student(int a, int n, int m, const char* na, bool d, int pd) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd)
{
	cout << "������ ����������� � �����������!" << endl;
}

Student::Student(const Student &other) : age(other.age), number_stud(other.number_stud), middle_mark(other.middle_mark), name(other.name), debt(other.debt), prog_d(other.prog_d)
{
	cout << "������ ����������� �����������!" << endl;
}

int Student::get_number_stud() const
{
	return number_stud;
}


int Student::get_age() const
{
	return age;
}

int Student::get_middle_mark() const
{
	return middle_mark;
}


const char* Student::get_name()
{
	return name;
}

bool Student::get_debt() const
{
	return debt;
}

int Student::get_prog_d() const
{
	return prog_d;
}