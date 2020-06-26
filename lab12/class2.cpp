#include "class2.h"

stringstream Course::get_str() const
{
	stringstream temp;

	temp << " " << age << " " << number_stud << " " << middle_mark << " "
		<< name << " " << debt << " " << prog_d << " " << course;

	return temp;
}

string Course::get_info() const
{
	stringstream temp;

	temp.setf(ios::left);
	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(4) << course;

	return temp.str();
}

Course::Course(int a, int n, int m, string na, bool d, int pd, int c) : Student(a, n, m, na, d, pd), course(c) {}
Course::Course() : Student(), course(0) {}
Course::Course(const Course& other) : Student(other), course(other.course) {}
Course::~Course() {}

bool Course::operator==(const int ns) const
{
	return this->number_stud == ns;
}