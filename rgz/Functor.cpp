/**
* @file Functor.cpp
* ���� ��������� ������ ����� Functor
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Functor.h" /** ϳ��������� ����� Functor.h */

bool Functor::operator()(const unique_ptr<Student>& first, const unique_ptr<Student>& second) const /** ��������� ������������ ��������� () */
{
	if (choise == 1) /** ���� ����� ��������� �� ���� */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_name() > second->get_name();
		else
			return first->get_name() < second->get_name();
	}
	else if (choise == 2) /** ���� ����� ��������� �� ������ */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_number() > second->get_number();
		else
			return first->get_number() < second->get_number();
	}
	else if (choise == 3) /** ���� ����� ��������� �� ���������� ���� */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_mark() > second->get_mark();
		else
			return first->get_mark() < second->get_mark();
	}
	else if (choise == 4) /** ���� ����� ��������� �� ����� � ������������� */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_prog_d() > second->get_prog_d();
		else
			return first->get_prog_d() < second->get_prog_d();
	}
	else if (choise == 5) /** ���� ����� ��������� �� ��� */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_age() > second->get_age();
		else
			return first->get_age() < second->get_age();
	}
	else if (choise == 6) /** ���� ����� ��������� �� ����� */
	{
		if (direction == true) /** ���� ������� ���������� */
			return first->get_debt() > second->get_debt();
		else
			return first->get_debt() < second->get_debt();
	}
}

Functor::Functor(bool direction, int choise) :direction(direction), choise(choise) {} /** ��������� ������������ � ����������� */
Functor::~Functor() {} /** ��������� ����������� */