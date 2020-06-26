/**
* @file Surnames.h
* ���� ���������� �����-����������.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** ϳ��������� ����� Student.h */

class Surnames final : public Student /** ���������� ����� ��������� */
{
private:
	string star; /** ������� �������� */

public:
	int get_age() const override; /** ���������� ��������������� ������ ��������� ��� �������� */
	int get_prog_d() const override; /** ���������� ��������������� ������ ��������� ������ �������� */
	int get_mark() const override; /** ���������� ��������������� ������ ��������� �������� ������ */
	int get_number()const override; /** ���������� ��������������� ������ ��������� ����� � ������������� */
	bool get_debt()const override; /** ���������� ��������������� ������ ��������� ��� �������� */
	string get_name() const override; /** ���������� ��������������� ������ ��������� ���� �������� */

	string getInfo() const override; /** ���������� ��������������� ������ ��������� ���������� �������� */
	void enter(istream&) override; /** ���������� ��������������� ������ ����� ���������� �������� */

	Surnames(); /** ���������� ������������ �� ������������� */
	Surnames(int, int, int, string, bool, int, string); /** ���������� ������������ � ����������� */
	Surnames(const Surnames&); /** ���������� ������������ ��������� */
	~Surnames() override; /** ���������� ��������������� ����������� */

	Surnames& operator= (Surnames&); /** ���������� ��������� ������������ */
	bool operator!=(const string) const override; /** ���������� ��������������� ��������� �������� */
	bool operator==(const int) const override; /** ���������� ��������������� ��������� ��������� */
};