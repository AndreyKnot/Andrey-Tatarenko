/**
* @file Surnames.cpp
* Файл реалізації методів класу-спадкоємця
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Surnames.h" /** Підключення файлу Surnames.h */

int Surnames::get_age() const /** Реалізація геттера часу віку студента */
{
	return age; /** Повернення віку студента */
}

int Surnames::get_prog_d() const /** Реалізація геттера боргу з програмування */
{
	return prog_d; /** Повернення боргу з програмування */
}

int Surnames::get_mark() const /** Реалізація геттера середньої оцінки */
{
	return middle_mark; /** Повернення середньої оцінки */
}

int Surnames::get_number() const /** Реалізація геттера номеру студента */
{
	return number_stud; /** Повернення номера студента */
}

bool Surnames::get_debt()const /** Реалізація геттера боргу студента */
{
	return debt; /** Повернення боргу студента */
}

string Surnames::get_name()const /** Реалізація геттера імені студента */
{
	return name; /** Повернення імені студента */
}

string Surnames::getInfo() const /** Реалізація методу отримання даних програми */
{
	stringstream temp; /** Створення змінної типу stringstream */
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(10) << star; /** Запис даних у об'єкт типу stringstream */

	return temp.str(); /** Повернення даних у форматі string */
}
void Surnames::enter(istream& data) /** Реалізація перевантаженого оператора вводу */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d >> star; /** Введення даних у об'єкт типу istream */
}

Surnames::Surnames(int a, int n, int m, string na, bool d, int pd, string st) : Student(a, n, m, na, d, pd), star(st) {}
Surnames::Surnames() : Student(), star("Petrov") {}
Surnames::Surnames(const Surnames& other) : Student(other), star(other.star) {}
Surnames::~Surnames() {}

Surnames& Surnames::operator=(Surnames& temp) /** Реалізація перевантаженого оператора присвоювання */
{
	if (this == &temp) /** Перевірка якщо змінні однакові */
		return *this;

	Surnames::operator=(temp); /** Присвоювання полів базового класу */
	string star = temp.star; /** Присвоювання прізвища старости */

	return *this;
}

bool Surnames::operator!=(const string type) const /** Реалізація перевантаженого оператора нерівності */
{
	return true; /** Перевірка відбувається за типом зловмисного ПО (звичайна програма не може бути зловмисним ПО) */
}

bool Surnames::operator==(const int number_stud) const /** Реалізація перевантаженого оператора порівняння */
{
	return this->number_stud == number_stud; /** Перевірка відбувається за номером */
}