#include "Student.h"

int Student::get_age() const
{
	return age;
}
int Student::get_number() const
{
	return number_stud;
}
int Student::get_mark() const
{
	return middle_mark;
}
int Student::get_dprog() const
{
	return prog_d;
}
bool Student::get_debt() const
{
	return debt;
}
string Student::get_name() const
{
	return name;
}

void Student::enter(istream& data)
{
	data >> age >> number_stud >> middle_mark >> prog_d >> debt >> name;
}

string Student::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d;

	return temp.str();
}

Student::Student(int a, int n, int m, string na, bool d, int pd) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd)
{
	//cout << "\nВызвался конструктор с параметрами";
}

Student::Student() : age(17), number_stud(1), middle_mark(8), name("Bond"), debt(1), prog_d(15)
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

ofstream& operator<< (ofstream& output, const Student& program)
{
	output << program.getInfo();
	return output;
}

ostream& operator<< (ostream& output, const Student& program)
{
	output << program.getInfo();
	return output;
}

void* Student::operator new(size_t value)
{
	cout << "Вызов оператора new для класса Student" << endl;
	return ::operator new(value);
}

void* Student::operator new[](size_t value)
{
	cout << "Вызов оператора new[] для класса Student" << endl;
	return ::operator new[](value);
}

void Student::operator delete(void* pointer)
{
	cout << "Вызов оператора delete для класса Student" << endl;
	::operator delete(pointer);
}

void Student::operator delete[](void* pointer)
{
	cout << "Вызов оператора delete[] для класса Student" << endl;
	::operator delete(pointer);
}