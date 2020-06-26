/**
* @file list.h
* ���� ���������� �����-����������.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Surnames.h" /** ϳ��������� ����� Surnames.h */
#include "Course.h" /** ϳ��������� ����� Course.h */
#include "Functor.h" /** ϳ��������� ����� Functor.h */

class CList /** ���������� �����-���������� */
{
private:
	vector <unique_ptr<Student>> StudentList; /** ��������� ��� ��������� �������� */

public:
	void PrintList() const noexcept; /** ���������� ������ ������ ������ � ������� */
	int Task() const; /** ���������� ������ ��������� �������������� ��������� */
	int AddStudent(int); /** ���������� ������ ��������� ������ �������� � ������ */
	int DeleteStudent(int); /** ���������� ������ ��������� �������� � ������ */
	void Sort(Functor&) noexcept; /** ���������� ������ ���������� ����� */
	int SaveFile(string) const; /** ���������� ������ ��������� ����� � ���� */
	int ReadFile(string); /** ���������� ������ ������ ������ � ������� */
	int get_numb(int) const; /** ���������� ������ ��������� ������� �� ������� */

	CList(); /** ���������� ������������ �� ������������� */
	~CList(); /** ���������� ����������� */
};