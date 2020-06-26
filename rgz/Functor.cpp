/**
* @file Functor.cpp
* Файл реалізації методів класу Functor
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Functor.h" /** Підключення файлу Functor.h */

bool Functor::operator()(const unique_ptr<Student>& first, const unique_ptr<Student>& second) const /** Реалізація перегруження оператору () */
{
	if (choise == 1) /** Якщо треба сортувати по назві */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_name() > second->get_name();
		else
			return first->get_name() < second->get_name();
	}
	else if (choise == 2) /** Якщо треба сортувати по номеру */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_number() > second->get_number();
		else
			return first->get_number() < second->get_number();
	}
	else if (choise == 3) /** Якщо треба сортувати по середньому балу */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_mark() > second->get_mark();
		else
			return first->get_mark() < second->get_mark();
	}
	else if (choise == 4) /** Якщо треба сортувати по боргу з програмування */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_prog_d() > second->get_prog_d();
		else
			return first->get_prog_d() < second->get_prog_d();
	}
	else if (choise == 5) /** Якщо треба сортувати по віку */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_age() > second->get_age();
		else
			return first->get_age() < second->get_age();
	}
	else if (choise == 6) /** Якщо треба сортувати по боргу */
	{
		if (direction == true) /** Вибір напряму сортування */
			return first->get_debt() > second->get_debt();
		else
			return first->get_debt() < second->get_debt();
	}
}

Functor::Functor(bool direction, int choise) :direction(direction), choise(choise) {} /** Реалізація конструктора з параметрами */
Functor::~Functor() {} /** Реалізація деструктора */