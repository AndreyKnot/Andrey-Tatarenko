/**
* @file Course.h
* Файл оголошення класу спадкоємця
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** Підключення файлу Student.h */

class Course final : public Student /** Оголошення класу спадкоємця */
{
private:
	int course; /** Підключення файлу Student.h */

public:
	int get_age() const override; /** Оголошення перевантаженого гетера віку студента */
	int get_prog_d() const override; /** Оголошення перевантаженого гетера боргу з програмування */
	int get_mark() const override; /** Оголошення перевантаженого гетера середньої оцінки */
	int get_number()const override; /** Оголошення перевантаженого гетера номера студента */
	bool get_debt()const override; /** Оголошення перевантаженого гетера боргу студента */
	string get_name() const override; /** Оголошення перевантаженого гетера імені студента */

	string getInfo() const override; /** Оголошення перевантаженого метода отримання інформації студента */
	void enter(istream&) override; /** Оголошення перевантаженого метода введення інформації студента */

	Course(); /** Оголошення конструктора за замовчуванням */
	Course(int, int, int, string, bool, int, int); /** Оголошення конструктора з параметрами */
	Course(const Course&); /** Оголошення конструктора копіювання */
	~Course() override; /** Оголошення перевантаженного деструктора */

	Course& operator= (Course&); /** Оголошення перевантаженого оператора присвоювання */
	bool operator!=(const string) const override; /** Оголошення перевантаженого оператора нерівності */
	bool operator==(const int) const override; /** Оголошення перевантаженого оператора порівняння */
};