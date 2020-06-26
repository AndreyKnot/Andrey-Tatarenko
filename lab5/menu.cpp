#include "menu.h"

void menu(Arr stud_array)
{
	int input = 0;

	cout << "1) Добавить объект в конец;" << endl << "2) Удалить объект;" << endl << "3) Выбрать объект;" << endl << "4) Вывести все объекты;" << endl << "5) Поиск должников;" << endl << "6) Запись в файл;" << endl << "7) Читать с файла;" << endl << "8) REGEX TASK;" << endl << "9) Сортировать;" << endl << "10) Выйти;" << endl << "Ваше действие: ";
	cin >> input;

	switch (input)
	{
	case 1:
		stud_array.add();
		break;
	case 2:
		stud_array.delete_one();
		break;
	case 3:
		cout << stud_array.select();
		break;
	case 4:
		stud_array.print_array(stud_array.get_count());
		break;
	case 5:
		stud_array.find_debt();
		break;
	case 6:
		stud_array.in_f();
		break;
	case 7:
		stud_array.from_f(stud_array.str_in_file("if.txt"));
		break;
	case 8:
		stud_array.regex_task();
		break;
	case 9:
		cout << "Выберете тип сортировки:" << endl << "Сортировка по возрастанию;" << endl << "Сортировка по убыванию;" << endl << endl;
		int c;
		cin >> c;

		if (c == 1)
			stud_array.sort(stud_array.sort_forward);
		else if (c == 2)
			stud_array.sort(stud_array.sort_back);
		else
		{
			cout << "НЕВЕРНОЕ ДЕЙСТВИЕ!" << endl;
			////////////////
			for (size_t i = 0; i < 50; i++)
				cout << "-";
			cout << endl;
		}
		break;
	case 10:
		return;
	default:
		break;
	}

	menu(stud_array);
}