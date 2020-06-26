/**
* @file Surnames.h
* Файл оголошення класу-спадкоемця.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** Підключення файлу Student.h */

class Surnames final : public Student /** Оголошення класу спадкоємця */
{
private:
	string star; /** Прізвище старости */

public:
	int get_age() const override; /** Оголошення перевантаженого гетера отримання віку студента */
	int get_prog_d() const override; /** Оголошення перевантаженого гетера отримання номера студента */
	int get_mark() const override; /** Оголошення перевантаженого гетера отримання середньої оцінки */
	int get_number()const override; /** Оголошення перевантаженого гетера отримання боргу з програмування */
	bool get_debt()const override; /** Оголошення перевантаженого гетера отримання віку студента */
	string get_name() const override; /** Оголошення перевантаженого гетера отримання імені студента */

	string getInfo() const override; /** Оголошення перевантаженого метода отримання інформації студента */
	void enter(istream&) override; /** Оголошення перевантаженого метода вводу інформації студента */

	Surnames(); /** Оголошення конструктора за замовчуванням */
	Surnames(int, int, int, string, bool, int, string); /** Оголошення конструктора з параметрами */
	Surnames(const Surnames&); /** Оголошення конструктора копіювання */
	~Surnames() override; /** Оголошення перевантаженого деструктора */

	Surnames& operator= (Surnames&); /** Оголошення оператора присвоювання */
	bool operator!=(const string) const override; /** Оголошення перевантаженого оператора нерівності */
	bool operator==(const int) const override; /** Оголошення перевантаженого оператора порівняння */
};