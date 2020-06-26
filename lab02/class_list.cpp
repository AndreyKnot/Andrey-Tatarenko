#include "class_list.h"

void Arr::create_array()
{
	array_stud = new Student[count];
}

void Arr::fill_array()
{
	for (int i = 0; i < count; i++)
	{
		array_stud[i] = Construct(i);
	}

}

Student Arr::Construct(int i)
{
	bool d = 0;

	if (i == 0)
	{
		d = rand() % 2;
		Student st0(i + 17, i + 1, i + 10 / 2, "Dani", d, prog_d_rand(d));
		return st0;
	}
	else if (i == 1)
	{
		d = rand() % 2;
		Student st1(i + 17, i + 1, i + 10 / 2, "Peter", d, prog_d_rand(d));
		return st1;
	}
	else if (i == 2)
	{
		d = rand() % 2;
		Student st2(i + 17, i + 1, i + 10 / 2, "Donald", d, prog_d_rand(d));
		return st2;
	}

	d = rand() % 2;
	Student st(i + 17, i + 1, i + 10 / 2, "Edgar", d, prog_d_rand(d));
	return st;
}

void Arr::print_array() const
{
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	for (int i = 0; i < count; i++)
	{
		cout << "Номер: " << array_stud[i].get_number_stud() << "\tВозраст: " << array_stud[i].get_age() << "\t\tСредний балл: " << array_stud[i].get_middle_mark() << "\t\tИмя: " << array_stud[i].get_name() << endl;
	}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_one()
{
	int input, i_arr = 0;
	cout << "Введите номер: ";
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
	cout << "Этого студента не существует!" << endl;
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

	array_stud_new[count - 1] = Construct(i);

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
	cout << "Введите номер: ";
	cin >> input;

	for (int i = 0; i < count; i++)
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
	cout << "Этого студента не существует!" << endl;
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
	cout << "Номер: " << stud.get_number_stud() << "\tВозраст: " << stud.get_age() << "\t\tСредний балл: " << stud.get_middle_mark() << "\t\tИмя: " << stud.get_name() << endl;
	////////////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_array()
{
	delete[] array_stud;
}

int Arr::prog_d_rand(bool d)
{
	int pd = 0;

	if (d == 1)
		pd = rand() % 50;

	return pd;
}

void Arr::find_debt()
{
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	for(int i = 0; i < count; i++)
		if (array_stud[i].get_debt() == 1)
		{
			cout << "Номер: " << array_stud[i].get_number_stud() << "\tВозраст: " << array_stud[i].get_age() << "\t\tСредний балл: " << array_stud[i].get_middle_mark() << "\t\tИмя: " << array_stud[i].get_name() << "\t\tДолг: Есть" << "\t\tДолг по программированию: " << array_stud[i].get_prog_d() << "%" << endl;
		}
	////////////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}