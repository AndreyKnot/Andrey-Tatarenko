/**
* @file Course.h
* ���� ���������� ����� ���������
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** ϳ��������� ����� Student.h */

class Course final : public Student /** ���������� ����� ��������� */
{
private:
	int course; /** ϳ��������� ����� Student.h */

public:
	int get_age() const override; /** ���������� ��������������� ������ ��� �������� */
	int get_prog_d() const override; /** ���������� ��������������� ������ ����� � ������������� */
	int get_mark() const override; /** ���������� ��������������� ������ �������� ������ */
	int get_number()const override; /** ���������� ��������������� ������ ������ �������� */
	bool get_debt()const override; /** ���������� ��������������� ������ ����� �������� */
	string get_name() const override; /** ���������� ��������������� ������ ���� �������� */

	string getInfo() const override; /** ���������� ��������������� ������ ��������� ���������� �������� */
	void enter(istream&) override; /** ���������� ��������������� ������ �������� ���������� �������� */

	Course(); /** ���������� ������������ �� ������������� */
	Course(int, int, int, string, bool, int, int); /** ���������� ������������ � ����������� */
	Course(const Course&); /** ���������� ������������ ��������� */
	~Course() override; /** ���������� ���������������� ����������� */

	Course& operator= (Course&); /** ���������� ��������������� ��������� ������������ */
	bool operator!=(const string) const override; /** ���������� ��������������� ��������� �������� */
	bool operator==(const int) const override; /** ���������� ��������������� ��������� ��������� */
};