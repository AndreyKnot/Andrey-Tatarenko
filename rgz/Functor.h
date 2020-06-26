/**
* @file Functor.h
* Файл оголошення класу, який виконує функції функтора
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Student.h" /** Підключення файлу Student.h */

class Functor /** Оголошення класу функтора*/
{
private:
	bool direction; /** Напрям сортування*/
	int choise; /** Вибір поля сортування*/

public:
	bool operator()(const unique_ptr<Student>& first, const unique_ptr<Student>& second) const; /** Оголошення перевантаженого оператора () */

	Functor(bool, int); /** Оголошення конструктора по замовчуванням*/
	~Functor(); /** Оголошення деструктора*/
};