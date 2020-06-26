/**
* @file Student.cpp
* Файл реалізації методів базового класу
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Student.h"

int Student::get_age() const /** Реалізація геттера часу віку студента */
{
	return age; /** Повернення віку студента */
}

int Student::get_prog_d() const /** Реалізація геттера боргу з програмування */
{
	return prog_d; /** Повернення боргу з програмування */
}

int Student::get_mark() const /** Реалізація геттера середньої оцінки */
{
	return middle_mark; /** Повернення середньої оцінки */
}

int Student::get_number() const /** Реалізація геттера номеру студента */
{
	return number_stud; /** Повернення номера студента */
}

bool Student::get_debt()const /** Реалізація геттера боргу студента */
{
	return debt; /** Повернення боргу студента */
}

string Student::get_name()const /** Реалізація геттера імені студента */
{
	return name; /** Повернення імені студента */
}

void Student::enter(istream& data) /** Реалізація перевантаженого оператора вводу */
{
	data >> age >> number_stud >> middle_mark >> name >> debt >> prog_d; /** Введення даних у об'єкт типу istream */
}

string Student::getInfo() const /** Реалізація методу отримання даних програми */
{
	stringstream temp; /** Створення змінної типу stringstream */
	temp.setf(ios::left);

	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d; /** Запис даних у об'єкт типу stringstream */

	return temp.str(); /** Повернення даних у форматі string */
}


Student::Student(int a, int n, int m, string na, bool d, int pd) : age(a), number_stud(n), middle_mark(m), name(na), debt(d), prog_d(pd) {} /** Реалізація конструктора з параметрами */
Student::Student() : age(17), number_stud(1), middle_mark(8), name("Bond"), debt(1), prog_d(15) {} /** Реалізація конструктора за замовчуванням */
Student::Student(const Student& other) : age(other.age), number_stud(other.number_stud), middle_mark(other.middle_mark), name(other.name), debt(other.debt), prog_d(other.prog_d) {} /** Реалізація конструктора копіювання */
Student::~Student() {} /** Реалізація деструктора */

ofstream& operator<< (ofstream& output, const Student& Student) /** Реалізація перевантаженого оператора запису даних у файл */
{
	output << Student.getInfo(); /** Виклик фкнції отримання інформації */
	return output; /** Повернення інформації */
}

ostream& operator<< (ostream& output, const Student& Student) /** Реалізація перевантаженого оператора виводу даних у консоль */
{
	output << Student.getInfo(); /** Виклик фкнції отримання інформації */
	return output; /** Повернення інформації */
}

istream& operator>> (istream& input, Student& Student) /** Реалізація перевантаженого оператора вводу даних з консолі */
{
	Student.enter(input); /** Виклик метода вводу даних */
	return input; /** Повернення інформації */
}

bool Student::operator!=(const string type) const /** Реалізація перевантаженого оператора нерівності */
{
	return true; /** Перевірка відбувається за типом зловмисного ПО (звичайна програма не може бути зловмисним ПО) */
}

bool Student::operator==(const int number_stud) const /** Реалізація перевантаженого оператора порівняння */
{
	return this->number_stud == number_stud; /** Перевірка відбувається за номером */
}

Student& Student::operator= (Student& temp) /** Реалізація перевантаженого оператора присвоювання */
{
	if (this == &temp) /** Перевірка якщо змінні однакові */
		return *this;

	int age = temp.age; /** Присвоювання поля віку */
	int prog_d = temp.prog_d; /** Присвоювання поля боргу з програмування */
	int middle_mark = temp.middle_mark; /** Присвоювання поля середньої оцінки */
	int number_stud = temp.number_stud; /** Присвоювання поля номера студента */
	bool debt = temp.debt; /** Присвоювання поля боргу */
	string name = temp.name; /** Присвоювання поля імені студента */

	return *this; /** Повернення програми */
}