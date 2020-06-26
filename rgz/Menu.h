/**
* @file Menu.h
* Файл оголошення класу меню
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#pragma once
#include "list.h" /** Підключення файлу list.h */

class Menu
{
public:
	void menu() const; /** Оголошення методу роботи зі списком*/

	Menu(); /** Оголошення конструктора за замовчуванням */
	~Menu(); /** Оголошення деструктором */
};