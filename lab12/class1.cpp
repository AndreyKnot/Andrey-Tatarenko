#include "class1.h"

string Student::get_info() const
{
	stringstream temp;

	temp.setf(std::ios::left);
	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d;

	return temp.str();
}

int Student::get_numb() const
{
	return number_stud;
}

stringstream Student::get_str() const
{
	stringstream temp;
	temp << " " << age << " " << number_stud << " " << middle_mark << " "
		<< name << " " << debt << " " << prog_d;

	return temp;
}

ostream& operator<< (ostream& output, const Student& other)
{
	output << other.get_info();
	return output;
}

bool Student::operator==(const int ns) const
{
	return this->number_stud == ns;
}

Student::Student(int a, int n, int m, string na, bool d, int pd) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd)
{
	//cout << "\nВызвался конструктор с параметрами";
}
Student::Student() : age(0), number_stud(0), middle_mark(0), name("Name"), debt(0), prog_d(0)
{
	//cout << "\nВызвался конструктор по умолчанию.";
}
Student::Student(const Student& other) : age(other.age), number_stud(other.number_stud), middle_mark(other.middle_mark), name(other.name), debt(other.debt), prog_d(other.prog_d)
{
	//cout << "\nВызвался конструктор копирования.";
}
Student::~Student()
{
	//cout << "\nВызвался деструктор";
}