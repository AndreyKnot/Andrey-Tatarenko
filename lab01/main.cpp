/**
 * @mainpage
 * <b> Лабораторна робота № 1. <br/> Класи </b>
 * <br/><b><i>Мета роботи:</i></b>: отримати базові знання про класи. Дослідити механізм інкапсуляції. <br/>
 * <b><i>Індивідуальне завдання 19:</i></b>
 * 	Для предметної галузі розробити два класи. <br/>
 * <br/>
 * <br/> <b> Arr stud_array; class Student; class Arr; </b> Класи, методи, функції </b>
 * @author Tatarenko A.
 * @date 4-mar-2020
 * @version 1.0
 */

#include "menu.h"

int main()
{
	Arr stud_array;

	int input = 0;

	cout << "Enter 1 to create array, 2 to exit: ";
	cin >> input;

	if (input == 1)
	{
		stud_array.create_array();
		stud_array.fill_array();
		stud_array.print_array();

		menu(stud_array);

		stud_array.delete_array();
	}

	/////////////////////////////////////////////////////////
	int l = _CrtDumpMemoryLeaks(); // Контроль витоку пам'яті
	if (l == 0)
		cout << "No memory leaks!" << endl;
	else
		cout << "Memory leaks!" << endl;

	system("PAUSE");
	return 0;
}