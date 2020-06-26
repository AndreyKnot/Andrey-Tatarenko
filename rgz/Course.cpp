/**
* @file Course.cpp
* ���� ��������� ������ �����-���������
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Course.h" /** ϳ��������� ����� Course.h */

int Course::get_age() const /** ��������� ������� ��� �������� */
{
	return age; /** ���������� ��� �������� */
}

int Course::get_prog_d() const /** ��������� ������� ����� � ������������� */
{
	return prog_d; /** ���������� ����� � ������������� */
}

int Course::get_mark() const /** ��������� ������� �������� ������ */
{
	return middle_mark; /** ���������� �������� ������ */
}

int Course::get_number() const /** ��������� ������� ������ �������� */
{
	return number_stud; /** ���������� ������ �������� */
}

bool Course::get_debt()const /** ��������� ������� ����� �������� */
{
	return debt; /** ���������� ����� ����� */
}

string Course::get_name()const /** ��������� ������� ���� �������� */
{
	return name; /** ���������� ���� �������� */
}

string Course::getInfo() const /** ��������� ������� ��������� ���������� */
{
	stringstream temp; /** ���������� ����� stringstream */
	temp.setf(ios::left);
	
	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(4) << course; /** ��������� ����� � ������ */

	return temp.str(); /** ���������� ����� � ����������� */
}

void Course::enter(istream& data) /** ��������� ��������������� ��������� ����� */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d >> course; /** �������� ����� � ��'��� ���� istream */
}

Course::Course(int a, int n, int m, string na, bool d, int pd, int c) : Student(a, n, m, na, d, pd), course(c) {} /** ��������� ������������ � ����������� */
Course::Course() : Student(), course(1) {} /** ��������� ������������ �� ������������� */
Course::Course(const Course& other) : Student(other), course(other.course) {} /** ��������� ������������ ��������� */
Course::~Course() {} /** ��������� ����������� */

Course& Course::operator=(Course& temp) /** ��������� �������������� ��������� ������������ */
{
	if (this == &temp) /** �������� ���� ���� ������� */
		return *this;

	Student::operator=(temp); /** ������������ ���� �������� ����� */
	int course = temp.course; /** ������������ ���� �����-��������� */

	return *this; /** ���������� ��������� */
}

bool Course::operator!=(const string type) const /** ��������� �������������� ��������� �������� */
{
	if (this->course != 1) /** �������� ���������� �� ���� ����������� �� */
		return true; /** ���� �������� �� � ������� */
	else
		return false; /** ���� �������� � ������� */
}

bool Course::operator==(const int number_stud) const /** ��������� �������������� ��������� ��������� */
{
	return this->number_stud == number_stud; /** �������� ���������� �� ������ */
}