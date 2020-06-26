/**
 * @mainpage
 * <b> Лабораторна робота № 2. <br/> ПЕРЕВАНТАЖЕННЯ МЕТОДІВ </b>
 * <br/><b><i>Мета роботи:</i></b>: отримати базові знання про класи, конструктори та деструктори. Дослідити механізм створення та видалення об’єктів. <br/>
 * <b><i>Індивідуальне завдання 19:</i></b>
 * 	Поширити попередню лабораторну роботу. <br/>
 * <br/>
 * <br/> <b> Arr p; class Student; class Arr; </b> Класи, методи, функції, конструктори </b>
 * @author Tatarenko A.
 * @date 18-mar-2020
 * @version 1.0
 */

#include "menu.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Arr stud_array;

	int input = 0;

	cout << "Введите 1 чтобы создать массив, 2 чтобы выйти: ";
	cin >> input;

	if (input == 1)
	{
		stud_array.create_array();
		cout << "Список созданый с помощью конструктора:" << endl;
		stud_array.print_array();

		cout << "Рандомное заполнение списка:" << endl;
		stud_array.fill_array();
		stud_array.print_array();

		menu(stud_array);

		stud_array.delete_array();

	}

	/////////////////////////////////////////////////////////
	int l = _CrtDumpMemoryLeaks(); // Контроль витоку пам'яті
	if (l == 0)
		cout << "Утечки памяти не обнаруженно!" << endl;
	else
		cout << "Обнаружена утечка памяти!" << endl;

	system("PAUSE");
	return 0;
}