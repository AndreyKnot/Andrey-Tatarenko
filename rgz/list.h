/**
* @file list.h
* Файл оголошення класу-контролера.
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "Surnames.h" /** Підключення файлу Surnames.h */
#include "Course.h" /** Підключення файлу Course.h */
#include "Functor.h" /** Підключення файлу Functor.h */

class CList /** Оголошення класу-контролера */
{
private:
	vector <unique_ptr<Student>> StudentList; /** Контейнер для зберігання елементів */

public:
	void PrintList() const noexcept; /** Оголошення методу виводу списку у консоль */
	int Task() const; /** Оголошення методу виконання індивідуального завднання */
	int AddStudent(int); /** Оголошення методу додавання нового елемента у список */
	int DeleteStudent(int); /** Оголошення методу видалення програми зі списку */
	void Sort(Functor&) noexcept; /** Оголошення методу сортування даних */
	int SaveFile(string) const; /** Оголошення методу виведення даних у файл */
	int ReadFile(string); /** Оголошення методу виводу списку у консоль */
	int get_numb(int) const; /** Оголошення методу отримання індекса за номером */

	CList(); /** Оголошення конструктора за замовчуванням */
	~CList(); /** Оголошення деструктора */
};