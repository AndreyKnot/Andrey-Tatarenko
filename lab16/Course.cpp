#include "Course.h"
#include "Student.h"

int Course::get_age() const
{
	return age;
}
int Course::get_number() const
{
	return number_stud;
}
int Course::get_mark() const
{
	return middle_mark;
}
int Course::get_dprog() const
{
	return prog_d;
}
bool Course::get_debt() const
{
	return debt;
}
string Course::get_name() const
{
	return name;
}

string Course::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(4) << course;

	return temp.str();
}

void Course::enter(istream& data)
{
	data >> age >> number_stud >> middle_mark >> prog_d >> debt >> name >> course;
}

Course::Course(int a, int n, int m, string na, bool d, int pd, int c) : Student(a, n, m, na, d, pd), course(c) {}
Course::Course() : Student(), course(1) {}
Course::Course(const Course& other) : Student(other), course(other.course) {}
Course::~Course() {}

void* Course::operator new(size_t value)
{
	cout << "Вызов оператора new для класса Course" << endl;
	return ::operator new(value);
}

void* Course::operator new[](size_t value)
{
	cout << "Вызов оператора new[] для класса Course" << endl;
	return ::operator new[](value);
}

void Course::operator delete(void* pointer)
{
	cout << "Вызов оператора delete для класса Course" << endl;
	::operator delete(pointer);
}

void Course::operator delete[](void* pointer)
{
	cout << "Вызов оператора delete[] для класса Course" << endl;
	::operator delete(pointer);
}