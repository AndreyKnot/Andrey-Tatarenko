#include "basic_class.h"

Student::Student() : age(0), number_stud(0), middle_mark(0), name("Name"), debt(0), prog_d(0), audience(0), faculty("Non")
{
	cout << "Вызван стандартый конструктор!" << endl;
}

Student::Student(int a, int n, int m, string na, bool d, int pd, sint an, string fc) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd), audience(an), faculty(fc)
{
	cout << "Вызван конструктор с параметрами!" << endl;
}

Student::Student(const Student &other) : age(other.age), number_stud(other.number_stud), middle_mark(other.middle_mark), name(other.name), debt(other.debt), prog_d(other.prog_d), audience(other.audience), faculty(other.faculty)
{
	cout << "Вызван конструктор копирования!" << endl;
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


string Student::get_name() const
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

sint Student::get_aud()
{
	return audience.get_aud_numb();
}

string Student::get_fac()
{
	return faculty.get_fname();
}