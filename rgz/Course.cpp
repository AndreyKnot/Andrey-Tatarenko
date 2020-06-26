/**
* @file Course.cpp
* Файл реалізації методів класу-спадкоємця
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Course.h" /** Підключення файлу Course.h */

int Course::get_age() const /** Реалізація геттера віку студента */
{
	return age; /** Повернення віку студента */
}

int Course::get_prog_d() const /** Реалізація геттера боргу з програмування */
{
	return prog_d; /** Повернення боргу з програмування */
}

int Course::get_mark() const /** Реалізація геттера середньої оцінки */
{
	return middle_mark; /** Повернення середньої оцінки */
}

int Course::get_number() const /** Реалізація геттера номера студента */
{
	return number_stud; /** Повернення номера студента */
}

bool Course::get_debt()const /** Реалізація геттера боргу студента */
{
	return debt; /** Повернення змінної боргу */
}

string Course::get_name()const /** Реалізація геттера імені студента */
{
	return name; /** Повернення імені студента */
}

string Course::getInfo() const /** Реалізація функції отримання інформації */
{
	stringstream temp; /** Оголошення змінної stringstream */
	temp.setf(ios::left);
	
	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(4) << course; /** Отримання рядка з даними */

	return temp.str(); /** Повернення рядка з інформацією */
}

void Course::enter(istream& data) /** Реалізація перевантаженого оператора вводу */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d >> course; /** Введення даних у об'єкт типу istream */
}

Course::Course(int a, int n, int m, string na, bool d, int pd, int c) : Student(a, n, m, na, d, pd), course(c) {} /** Реалізація конструктора з параметрами */
Course::Course() : Student(), course(1) {} /** Реалізація конструктора за замовчуванням */
Course::Course(const Course& other) : Student(other), course(other.course) {} /** Реалізація конструктора копіювання */
Course::~Course() {} /** Реалізація деструктора */

Course& Course::operator=(Course& temp) /** Реалізація перевантаження оператора присвоювання */
{
	if (this == &temp) /** Перевірка якщо змінні однакові */
		return *this;

	Student::operator=(temp); /** Присвоювання полів базового класу */
	int course = temp.course; /** Присвоювання полів класу-спадкоємця */

	return *this; /** Повернення покажчика */
}

bool Course::operator!=(const string type) const /** Реалізація перевантаження оператора нерівності */
{
	if (this->course != 1) /** Перевірка відбувається по типу зловмисного ПО */
		return true; /** Якщо програма не є трояном */
	else
		return false; /** Якщо програма є трояном */
}

bool Course::operator==(const int number_stud) const /** Реалізація перевантаження оператора порівняння */
{
	return this->number_stud == number_stud; /** Перевірка відбувається по номеру */
}