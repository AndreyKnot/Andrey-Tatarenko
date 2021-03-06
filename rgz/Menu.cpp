/**
* @file Menu.cpp
* ���� ��������� ������ ����� Menu
* @author Tatarenko Andrey
* @date 2020.06.16
* @version 1.0
*/

#include "Menu.h" /** ϳ��������� ����� Menu.h*/

void Menu::menu() const /** ������ ������ ���������� ����*/
{
	/** ���������� ������ ��� ������ ��������*/
	int choise, choise2;
	int size = -1, value;
	bool stop = true;
	string filename; /** ����� ����� */
	CList list; /** ������ �������� */

	while (stop != 0) /** ����, ���� ������ ���� ���������� �� ������ �����*/
	{
		cout << endl;
		cout << "1) ������� ������ �� �����" << endl;
		cout << "2) �������� ��������" << endl;
		cout << "3) ���������� ��������" << endl;
		cout << "4) �������������� �������" << endl;
		cout << "5) ������ � �������" << endl;
		cout << "6) ����������" << endl;
		cout << "7) ���������� ������" << endl;
		cout << "==========================" << endl;
		cout << "��� �����: ";
		cin >> choise; /** �������� ���� ������ 䳿*/
		cout << endl;

		switch (choise)
		{
		case 1:

			list.PrintList(); /** ������ ������ ��������� ������ � ������� */

			break;

		case 2:
			cout << "������� ����� ��������, ������� ������ �������: ";
			cin >> choise; /** �������� ���� ������ 䳿*/
			cout << endl;

			try
			{
				list.DeleteStudent(choise); /** ������ ������ ��������� �������� */
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 3:
			cout << "�������� ���������, ������� ������ ��������:" << endl;
			cout << "1. ������� ������ Student" << endl;
			cout << "2. ������� ������ Course" << endl;
			cout << "3. ������� ������ Surnames" << endl;
			cout << "=================================" << endl;
			cout << "��� �����: ";
			cin >> value; /** �������� ���� ������ 䳿*/

			try
			{
				list.AddStudent(value); /** ������ ������ ��������� �������� */
			}
			catch (const std::exception & ex)
			{
				cout << ex.what() << endl;
			}
			cout << "��������� ���������." << endl;

			break;
		case 4:
			cout << "�������������� �������:\n������, ��� �� ��������� ����� �����������, � ����� ������� ����������� �� ����������������" << endl;

			try
			{
				list.Task(); /** ������ ������ ��������� �������������� �������� */
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}

			break;

		case 5:
			cout << "��� ������?" << endl;
			cout << "1) ������ � ����" << endl;
			cout << "2) ������ �����" << endl;
			cout << "3) ��������� �����" << endl;
			cout << "==================" << endl;
			cout << "��� �����: ";
			cin >> choise2; /** �������� ���� ������ 䳿*/
			cout << endl;

			if (choise2 == 1)
			{
				string::size_type n;
				cout << "������� �������� ����� ��� ������: ";
				cin >> filename; /** �������� ����� ����� */
				cout << endl;

				n = filename.find(".txt");
				if (n > 187) filename += string(".txt");

				try
				{
					list.SaveFile(filename); /** ������ ������ ������ ������ � ���� */
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				cout << "������ ���������. " << endl;
			}
			else if (choise2 == 2)
			{
				string::size_type n;
				cout << "������� �������� ����� ��� ������: ";
				cin >> filename; /** �������� ����� �����*/
				cout << endl;

				n = filename.find(".txt");
				if (n > 187) filename += string(".txt");

				try
				{
					list.ReadFile(filename); /** ������ ������ ������� ����� � ����� */
				}
				catch (const std::exception & ex)
				{
					cout << ex.what() << endl;
				}

				cout << "������ ����� ���������." << endl;

			}
			else if (choise2 == 3)
				cout << "����������� �����. " << endl;
			else
				cout << "�������� �������. ��������� �������." << endl;

			break;

		case 6:
			cout << "����������� ��: " << endl;
			cout << "1) �����������" << endl;
			cout << "2) ��������" << endl;
			cout << "3) ��������� �����" << endl;
			cout << "==================" << endl;
			cout << "��� �����: ";
			cin >> choise2; /** �������� ���� ������� ����������*/
			cout << endl;

			if (choise2 == 1 || choise2 == 2)
			{
				cout << "�� ������ ���� �����������: " << endl;
				cout << "1) ��������" << endl;
				cout << "2) ������" << endl;
				cout << "3) ���������� ����� ����" << endl;
				cout << "4) ������ ���������" << endl;
				cout << "5) ����� ���������� ����" << endl;
				cout << "6) ���������� �� ��������� �������� ��� ���" << endl;
				cout << "=============================" << endl;
				cout << "��� �����: ";
				cin >> value;
				cout << endl;

				if (value > 0 && value <= 6)
				{
					Functor funct(choise2 - 1, value); /** ���������� ����� ����� Functor */
					list.Sort(funct); /** ������ ������ ���������� */

					cout << "������ ������������. " << endl;
				}
				else
					cout << "�������� ������." << endl;
			}
			else if (choise2 == 3)
				cout << "����������� �����." << endl;
			else
				cout << "������. �������� �������." << endl;

			break;
		case 7:
			cout << "���������� ������." << endl;
			stop = false;
			break;

		default:
			cout << "�������� ������. ��������� �������." << endl;
			break;

		}

	}

	return; /** ���������� ������ ������ */
}

Menu::Menu() {} /** ��������� ������������ �� ������������� */
Menu::~Menu() {} /** ��������� ����������� */