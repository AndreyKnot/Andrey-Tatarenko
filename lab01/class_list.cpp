#include "class_list.h"

void Arr::create_array()
{
	array_stud = new Student[count];
}

void Arr::fill_array()
{
	for (int i = 0; i < count; i++)
	{
		array_stud[i].set_number_stud(i + 1);
		array_stud[i].set_age(i + 17);
		array_stud[i].set_middle_mark();
	}

}

void Arr::print_array() const
{
	for(int i = 0; i < 50; i++)
	cout << "-";
	cout << endl;
	////////////////
	for (int i = 0; i < count; i++)
		cout << "Numder: " << array_stud[i].get_number_stud() << "\tAge: " << array_stud[i].get_age() << "\t\tMiddle mark: " << array_stud[i].get_middle_mark() << endl;
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_one()
{
	int input, i_arr = 0;
	cout << "Enter a number: ";
	cin >> input;

	for (int i = 0; i < El; i++)
		if (input == array_stud[i].get_number_stud())
		{
			count_minus();

			Student* array_stud_new = new Student[count];

			for (int i = 0; i < count + 1; i++)
			{
				if (input == array_stud[i].get_number_stud())
					continue;
				array_stud_new[i_arr++] = array_stud[i];
			}

			delete[] array_stud;

			array_stud = new Student[count];

			for (int i = 0; i < count; i++)
			{
				array_stud[i] = array_stud_new[i];
			}

			delete[] array_stud_new;

			print_array();
			
			return;
		}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "That student is not exist!" << endl;
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
}

void Arr::add()
{
	count_plus();

	Student* array_stud_new = new Student[count];
	
	int i = 0;

	for (i; i < count - 1; i++)
	{
		array_stud_new[i] = array_stud[i];
	}

	array_stud_new[count - 1].set_number_stud(i + 1);
	array_stud_new[count - 1].set_age(i + 17);
	array_stud_new[count - 1].set_middle_mark();

	delete[] array_stud;

	array_stud = new Student[count];

	for (i = 0; i < count; i++)
	{
		array_stud[i] = array_stud_new[i];
	}

	delete[] array_stud_new;

	print_array();
}

int Arr::count_plus()
{
	count = count + 1;

	return count;
}

int Arr::count_minus()
{
	count = count - 1;

	return count;
}

void Arr::select() const
{
	int input = 0;
	cout << "Enter a number: ";
	cin >> input;

	for (int i = 0; i < El; i++)
	{
		if (input == array_stud[i].get_number_stud())
		{
			print_one(array_stud[i]);
			return;
		}
	}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "That student is not exist!" << endl;
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
}

void Arr::print_one(Student stud) const
{
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	cout << "Numder: " << stud.get_number_stud() << "\tAge: " << stud.get_age() << "\t\tMiddle mark: " << stud.get_middle_mark() << endl;
	////////////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_array()
{
	delete[] array_stud;
}