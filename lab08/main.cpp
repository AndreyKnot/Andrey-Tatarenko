/**
 * @mainpage
 * <b> Лабораторна робота № 8. <br/> ПЕРЕВАНТАЖЕННЯ ОПЕРАТОРІВ </b>
 * <br/><b><i>Мета роботи:</i></b>:  отримати знання про базові регулярні вирази та досвід роботи із застосування їх на практиці. <br/>
 * <b><i>Індивідуальне завдання 19:</i></b>
 * 	Поширити попередню лабораторну роботу. <br/>
 * <br/>
 * <br/> <b> Arr p; class Student; class Arr; </b> Класи, методи, функції, конструктори, потоки </b>
 * @author Tatarenko A.
 * @date 29-may-2020
 * @version 1.0
 */

#include "menu.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Arr stud_array;

	auto input = 0;

	cout << "Введите 1 чтобы создать массив, 2 чтобы выйти: ";
	cin >> input;

	if (input == 1)
	{
		stud_array.create_array();
		//cout << "Список созданый с помощью конструктора:" << endl;
		//stud_array.print_array(stud_array.get_count());

		cout << "Рандомное заполнение списка:" << endl;
		stud_array.fill_array();
		stud_array.print_array(stud_array.get_count());

		menu(stud_array);
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