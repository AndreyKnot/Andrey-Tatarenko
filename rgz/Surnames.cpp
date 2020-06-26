/**
* @file Surnames.cpp
* ���� ��������� ������ �����-���������
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Surnames.h" /** ϳ��������� ����� Surnames.h */

int Surnames::get_age() const /** ��������� ������� ���� ��� �������� */
{
	return age; /** ���������� ��� �������� */
}

int Surnames::get_prog_d() const /** ��������� ������� ����� � ������������� */
{
	return prog_d; /** ���������� ����� � ������������� */
}

int Surnames::get_mark() const /** ��������� ������� �������� ������ */
{
	return middle_mark; /** ���������� �������� ������ */
}

int Surnames::get_number() const /** ��������� ������� ������ �������� */
{
	return number_stud; /** ���������� ������ �������� */
}

bool Surnames::get_debt()const /** ��������� ������� ����� �������� */
{
	return debt; /** ���������� ����� �������� */
}

string Surnames::get_name()const /** ��������� ������� ���� �������� */
{
	return name; /** ���������� ���� �������� */
}

string Surnames::getInfo() const /** ��������� ������ ��������� ����� �������� */
{
	stringstream temp; /** ��������� ����� ���� stringstream */
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(10) << star; /** ����� ����� � ��'��� ���� stringstream */

	return temp.str(); /** ���������� ����� � ������ string */
}
void Surnames::enter(istream& data) /** ��������� ��������������� ��������� ����� */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d >> star; /** �������� ����� � ��'��� ���� istream */
}

Surnames::Surnames(int a, int n, int m, string na, bool d, int pd, string st) : Student(a, n, m, na, d, pd), star(st) {}
Surnames::Surnames() : Student(), star("Petrov") {}
Surnames::Surnames(const Surnames& other) : Student(other), star(other.star) {}
Surnames::~Surnames() {}

Surnames& Surnames::operator=(Surnames& temp) /** ��������� ��������������� ��������� ������������ */
{
	if (this == &temp) /** �������� ���� ���� ������� */
		return *this;

	Surnames::operator=(temp); /** ������������ ���� �������� ����� */
	string star = temp.star; /** ������������ ������� �������� */

	return *this;
}

bool Surnames::operator!=(const string type) const /** ��������� ��������������� ��������� �������� */
{
	return true; /** �������� ���������� �� ����� ����������� �� (�������� �������� �� ���� ���� ���������� ��) */
}

bool Surnames::operator==(const int number_stud) const /** ��������� ��������������� ��������� ��������� */
{
	return this->number_stud == number_stud; /** �������� ���������� �� ������� */
}