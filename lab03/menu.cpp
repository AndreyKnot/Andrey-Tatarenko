#include "menu.h"

void menu(Arr stud_array)
{
	int input = 0;

	cout << "1) �������� ������ � �����;" << endl << "2) ������� ������;" << endl << "3) ������� ������;" << endl << "4) ������� ��� �������;" << endl << "5) ����� ���������;" << endl << "6) ������ � ����;" << endl << "7) ������ � �����;" << endl <<  "8) �����;" << endl << "���� ��������: ";
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
		return;
	default:
		break;
	}

	menu(stud_array);
}