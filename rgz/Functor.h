/**
* @file Functor.h
* ���� ���������� �����, ���� ������ ������� ��������
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** ϳ��������� ����� Student.h */

class Functor /** ���������� ����� ��������*/
{
private:
	bool direction; /** ������ ����������*/
	int choise; /** ���� ���� ����������*/

public:
	bool operator()(const unique_ptr<Student>& first, const unique_ptr<Student>& second) const; /** ���������� ��������������� ��������� () */

	Functor(bool, int); /** ���������� ������������ �� �������������*/
	~Functor(); /** ���������� �����������*/
};