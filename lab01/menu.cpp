#include "menu.h"

void menu(Arr stud_array)
{
	int input = 0;

	cout << "1) Add object at the end;" << endl << "2) Delete object;" << endl << "3) Select;" << endl << "4) Show all objects;" << endl << "5) Exit;" << endl << "Your choice: ";
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
		stud_array.select();
		break;
	case 4:
		stud_array.print_array();
		break;
	case 5:
		return;
	default:
		break;
	}

	menu(stud_array);
}