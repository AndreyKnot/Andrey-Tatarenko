/**
* @file Student.cpp
* ���� ��������� ������ �������� �����
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Student.h"

int Student::get_age() const /** ��������� ������� ���� ��� �������� */
{
	return age; /** ���������� ��� �������� */
}

int Student::get_prog_d() const /** ��������� ������� ����� � ������������� */
{
	return prog_d; /** ���������� ����� � ������������� */
}

int Student::get_mark() const /** ��������� ������� �������� ������ */
{
	return middle_mark; /** ���������� �������� ������ */
}

int Student::get_number() const /** ��������� ������� ������ �������� */
{
	return number_stud; /** ���������� ������ �������� */
}

bool Student::get_debt()const /** ��������� ������� ����� �������� */
{
	return debt; /** ���������� ����� �������� */
}

string Student::get_name()const /** ��������� ������� ���� �������� */
{
	return name; /** ���������� ���� �������� */
}

void Student::enter(istream& data) /** ��������� ��������������� ��������� ����� */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d; /** �������� ����� � ��'��� ���� istream */
}

string Student::getInfo() const /** ��������� ������ ��������� ����� �������� */
{
	stringstream temp; /** ��������� ����� ���� stringstream */
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d; /** ����� ����� � ��'��� ���� stringstream */

	return temp.str(); /** ���������� ����� � ������ string */
}


Student::Student(int a, int n, int m, string na, bool d, int pd) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd) {} /** ��������� ������������ � ����������� */
Student::Student() : age(17), number_stud(1), middle_mark(8), name("Bond"), debt(1), prog_d(15) {} /** ��������� ������������ �� ������������� */
Student::Student(const Student& other) : age(other.age), number_stud(other.number_stud), middle_mark(other.middle_mark), name(other.name), debt(other.debt), prog_d(other.prog_d) {} /** ��������� ������������ ��������� */
Student::~Student() {} /** ��������� ����������� */

ofstream& operator<< (ofstream& output, const Student& Student) /** ��������� ��������������� ��������� ������ ����� � ���� */
{
	output << Student.getInfo(); /** ������ ������ ��������� ���������� */
	return output; /** ���������� ���������� */
}

ostream& operator<< (ostream& output, const Student& Student) /** ��������� ��������������� ��������� ������ ����� � ������� */
{
	output << Student.getInfo(); /** ������ ������ ��������� ���������� */
	return output; /** ���������� ���������� */
}

istream& operator>> (istream& input, Student& Student) /** ��������� ��������������� ��������� ����� ����� � ������ */
{
	Student.enter(input); /** ������ ������ ����� ����� */
	return input; /** ���������� ���������� */
}

bool Student::operator!=(const string type) const /** ��������� ��������������� ��������� �������� */
{
	return true; /** �������� ���������� �� ����� ����������� �� (�������� �������� �� ���� ���� ���������� ��) */
}

bool Student::operator==(const int number_stud) const /** ��������� ��������������� ��������� ��������� */
{
	return this->number_stud == number_stud; /** �������� ���������� �� ������� */
}

Student& Student::operator= (Student& temp) /** ��������� ��������������� ��������� ������������ */
{
	if (this == &temp) /** �������� ���� ���� ������� */
		return *this;

	int age = temp.age; /** ������������ ���� ��� */
	int prog_d = temp.prog_d; /** ������������ ���� ����� � ������������� */
	int middle_mark = temp.middle_mark; /** ������������ ���� �������� ������ */
	int number_stud = temp.number_stud; /** ������������ ���� ������ �������� */
	bool debt = temp.debt; /** ������������ ���� ����� */
	string name = temp.name; /** ������������ ���� ���� �������� */

	return *this; /** ���������� �������� */
}