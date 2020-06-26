#include "class_list.h"

void Arr::create_array()
{
	int c = get_count();

	array_stud = new Student[c];
}

void Arr::fill_array()
{
	int c = get_count();

	for (int i = 0; i < c; i++)
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
	else if (i == 3)
	{
		d = rand() % 2;
		Student st2(i + 17, i + 1, i + 10 / 2, "Vladimir", d, prog_d_rand(d));
		return st2;
	}

	d = rand() % 2;
	Student st(i + 17, i + 1, i + 10 / 2, "Edgar", d, prog_d_rand(d));
	return st;
}

void Arr::print_array(int c) const
{
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	for (int i = 0; i < c; i++)
	{
		cout << "�����: " << array_stud[i].get_number_stud() << "\t�������: " << array_stud[i].get_age() << "\t\t������� ����: " << array_stud[i].get_middle_mark() << "\t\t���: " << array_stud[i].get_name() << endl;
	}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_one()
{
	int input, i_arr = 0;
	cout << "������� �����: ";
	cin >> input;

	for (int i = 0; i < El; i++)
		if (input == array_stud[i].get_number_stud())
		{
			count_minus();
			int c = get_count();

			Student* array_stud_new = new Student[c];

			for (int i = 0; i < c + 1; i++)
			{
				if (input == array_stud[i].get_number_stud())
					continue;
				array_stud_new[i_arr++] = array_stud[i];
			}

			delete[] array_stud;

			array_stud = new Student[c];

			for (int i = 0; i < c; i++)
			{
				array_stud[i] = array_stud_new[i];
			}

			delete[] array_stud_new;

			print_array(c);
			
			return;
		}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "����� �������� �� ����������!" << endl;
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
}

void Arr::add()
{
	count_plus();
	int c = get_count();

	Student* array_stud_new = new Student[c];
	
	int i = 0;

	for (i; i < c - 1; i++)
	{
		array_stud_new[i] = array_stud[i];
	}

	array_stud_new[c - 1] = Construct(i);

	delete[] array_stud;

	array_stud = new Student[c];

	for (i = 0; i < c; i++)
	{
		array_stud[i] = array_stud_new[i];
	}

	delete[] array_stud_new;

	print_array(c);
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

string Arr::select() const
{
	int input = 0;
	cout << "������� �����: ";
	cin >> input;
	int c = get_count();

	for (int i = 0; i < c; i++)
	{
		if (input == array_stud[i].get_number_stud())
		{
			string info;
			stringstream ss;
			ss << "�����: " << array_stud[i].get_number_stud() << "\t�������: " << array_stud[i].get_age() << "\t\t������� ����: " << array_stud[i].get_middle_mark() << "\t\t���: " << array_stud[i].get_name() << endl;
			info = ss.str();

			return info;
		}
	}
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "����� �������� �� ����������!" << endl;
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
	cout << "�����: " << stud.get_number_stud() << "\t�������: " << stud.get_age() << "\t\t������� ����: " << stud.get_middle_mark() << "\t\t���: " << stud.get_name() << endl;
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
			cout << "�����: " << array_stud[i].get_number_stud() << "\t�������: " << array_stud[i].get_age() << "\t\t������� ����: " << array_stud[i].get_middle_mark() << "\t\t���: " << array_stud[i].get_name() << "\t\t����: ����" << "\t\t���� �� ����������������: " << array_stud[i].get_prog_d() << "%" << endl;
		}
	////////////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}

void Arr::in_f()
{
	ofstream file;
	file.open("of.txt", ofstream::app);

	if (!file.is_open())
	{
		cout << "���� �� ������!" << endl;
		return;
	}

	string info;
	stringstream ss;
	int c = get_count();

	for (int i = 0; i < c; i++)
	{
		ss << "�����: " << array_stud[i].get_number_stud() << "\t�������: " << array_stud[i].get_age() << "\t\t������� ����: " << array_stud[i].get_middle_mark() << "\t\t���: " << array_stud[i].get_name() << endl;
	}
	
	for (int i = 0; i < 80; i++)
		ss << "-";
	ss << endl;

	info = ss.str();
	file << info;

	file.close();

	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "���� ������� �������!" << endl;
	////////////////
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////

}

void Arr::from_f(int size)
{
	ifstream file;
	file.open("if.txt");

	if (!file.is_open())
	{
		cout << "���� �� ������!" << endl;
		return;
	}

	delete[] array_stud;
	array_stud = new Student[size];

	for (int i = 0; i < size; i++)
	{
		int age;
		int number;
		int middle_mark;
		string name;
		bool debt;
		int prog_d;

		file >> age;
		file >> number;
		file >> middle_mark;
		file >> name;
		file >> debt;
		file >> prog_d;

		Student file_el(age, number, middle_mark, name, debt, prog_d);
		array_stud[i] = file_el;
	}

	file.close();

	cout << "������ � ����� �������!" << endl << endl;

	set_count(size);

	print_array(size);

}

int Arr::get_count() const
{
	return count;

}

int Arr::str_in_file(string fileName) const
{
	int size = 0;
	int c = get_count();
	string line;
	ifstream file(fileName);
	if (!file.is_open() || c == 0)
	{
		cout << "There is no such file" << endl << endl;
		return 0;
	}

	while (getline(file, line))
	{
		size++;
	}
	file.close();

	return size;
}

void Arr::set_count(int c)
{
	count = c;

}