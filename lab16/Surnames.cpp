#include "Surnames.h"

int Surnames::get_age() const
{
	return age;
}
int Surnames::get_number() const
{
	return number_stud;
}
int Surnames::get_mark() const
{
	return middle_mark;
}
int Surnames::get_dprog() const
{
	return prog_d;
}
bool Surnames::get_debt() const
{
	return debt;
}
string Surnames::get_name() const
{
	return name;
}

string Surnames::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(10) << star << setw(10) << cur;

	return temp.str();
}
void Surnames::enter(istream& data)
{
	data >> age >> number_stud >> middle_mark >> prog_d >> debt >> name >> star >> cur;
}

Surnames::Surnames(int a, int n, int m, string na, bool d, int pd, string st, string cu) : Student(a, n, m, na, d, pd), star(st), cur(cu) {}
Surnames::Surnames() : Student(), star("Petrov"), cur("Viktorovich") {}
Surnames::Surnames(const Surnames& other) : Student(other), star(other.star), cur(other.cur) {}
Surnames::~Surnames() {}

void* Surnames::operator new(size_t value)
{
	cout << "Вызов оператора new для класса Surnames" << endl;
	return ::operator new(value);
}
void* Surnames::operator new[](size_t value)
{
	cout << "Вызов оператора new[] для класса Surnames" << endl;
	return ::operator new[](value);
}
void Surnames::operator delete(void* pointer)
{
	cout << "Вызов оператора delete для класса Surnames" << endl;
	::operator delete(pointer);
}
void Surnames::operator delete[](void* pointer)
{
	cout << "Вызов оператора delete[] для класса Surnames" << endl;
	::operator delete(pointer);
}