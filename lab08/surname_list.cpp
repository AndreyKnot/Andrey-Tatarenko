#include "surname_list.h"

void Arr_Sur::create_array()
{
	int c = get_count();

	array_sur = new Surname[c];
}

void Arr_Sur::fill_array()
{
	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		array_sur[i] = Construct(i);
	}

}

Surname Arr_Sur::Construct(int i)
{
	bool d = 0;

	if (i == 0)
	{
		d = rand() % 2;
		Surname st0(i + 17, i + 1, i + 10 / 2, "Dani", d, prog_d_rand(d), 15, "KIT", "Pavlov", "Jordon");
		return st0;
	}
	else if (i == 1)
	{
		d = rand() % 2;
		Surname st1(i + 17, i + 1, i + 10 / 2, "Peter", d, prog_d_rand(d), 15, "KIT", "Pavlov", "Jordon");
		return st1;
	}
	else if (i == 2)
	{
		d = rand() % 2;
		Surname st2(i + 17, i + 1, i + 10 / 2, "Donald Tramp", d, prog_d_rand(d), 36, "PIT", "Hashin", "Ivanov");
		return st2;
	}
	else if (i == 3)
	{
		d = rand() % 2;
		Surname st2(i + 17, i + 1, i + 10 / 2, "Vladimir", d, prog_d_rand(d), 87, "PIT", "Vityaz", "Ivanov");
		return st2;
	}

	d = rand() % 2;
	Surname st(i + 17, i + 1, i + 10 / 2, "Edgar", d, prog_d_rand(d), 17, "PIT", "Dropov", "Ivanov");
	return st;
}

void Arr_Sur::print_array(int c) const
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	for (size_t i = 0; i < c; i++)
	{
		cout << "Номер: " << array_sur[i].get_number_stud() << "\tВозраст: " << array_sur[i].get_age() << "\tСредний балл: " << array_sur[i].get_middle_mark() << "\tИмя: " << array_sur[i].get_name() << "\tАудитория: " << array_sur[i].get_aud() << "\tФакультет: " << array_sur[i].get_fac() << "\tФамилия старосты: " << array_sur[i].get_sur_star() << "\tФамилия куратора: " << array_sur[i].get_sur_cur() << endl;
	}
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr_Sur::delete_one()
{
	int input, i_arr = 0;
	cout << "Введите номер: ";
	cin >> input;

	for (size_t i = 0; i < El; i++)
		if (input == array_sur[i].get_number_stud())
		{
			count_minus();
			int c = get_count();

			Surname* array_sur_new = new Surname[c];

			for (size_t i = 0; i < c + 1; i++)
			{
				if (input == array_sur[i].get_number_stud())
					continue;
				array_sur_new[i_arr++] = array_sur[i];
			}

			delete[] array_sur;

			array_sur = new Surname[c];

			for (size_t i = 0; i < c; i++)
			{
				array_sur[i] = array_sur_new[i];
			}

			delete[] array_sur_new;

			print_array(c);

			return;
		}
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "Этого студента не существует!" << endl;
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
}

void Arr_Sur::add()
{
	count_plus();
	int c = get_count();

	Surname* array_sur_new = new Surname[c];

	size_t i = 0;

	for (i; i < c - 1; i++)
	{
		array_sur_new[i] = array_sur[i];
	}

	array_sur_new[c - 1] = Construct(i);

	delete[] array_sur;

	array_sur = new Surname[c];

	for (i = 0; i < c; i++)
	{
		array_sur[i] = array_sur_new[i];
	}

	delete[] array_sur_new;

	print_array(c);
}

int Arr_Sur::count_plus()
{
	count = count + 1;

	return count;
}

int Arr_Sur::count_minus()
{
	count = count - 1;

	return count;
}

string Arr_Sur::select() const
{
	int input = 0;
	cout << "Введите номер: ";
	cin >> input;
	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		if (input == array_sur[i].get_number_stud())
		{
			string info;
			stringstream ss;
			ss << "Номер: " << array_sur[i].get_number_stud() << "\tВозраст: " << array_sur[i].get_age() << "\t\tСредний балл: " << array_sur[i].get_middle_mark() << "\t\tИмя: " << array_sur[i].get_name() << "\tАудитория: " << array_sur[i].get_aud() << "\tФакультет: " << array_sur[i].get_fac() << "\tФамилия старосты: " << array_sur[i].get_sur_star() << "\tФамилия куратора: " << array_sur[i].get_sur_cur() << endl;
			info = ss.str();

			return info;
		}
	}
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "Этого студента не существует!" << endl;
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
}

void Arr_Sur::print_one(Surname stud) const
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	cout << "Номер: " << stud.get_number_stud() << "\tВозраст: " << stud.get_age() << "\t\tСредний балл: " << stud.get_middle_mark() << "\t\tИмя: " << stud.get_name() << "\t\tАудитория: " << stud.get_aud() << "\t\tФакультет: " << stud.get_fac() << "\tФамилия старосты: " << stud.get_sur_star() << "\tФамилия куратора: " << stud.get_sur_cur() << endl;
	////////////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr_Sur::delete_array()
{
	delete[] array_sur;
}

int Arr_Sur::prog_d_rand(bool d)
{
	int pd = 0;

	if (d == 1)
		pd = rand() % 50;

	return pd;
}

void Arr_Sur::find_debt()
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	for (size_t i = 0; i < count; i++)
		if (array_sur[i].get_debt() == 1)
		{
			cout << "Номер: " << array_sur[i].get_number_stud() << "\tВозраст: " << array_sur[i].get_age() << "\t\tСредний балл: " << array_sur[i].get_middle_mark() << "\t\tИмя: " << array_sur[i].get_name() << "\t\tДолг: Есть" << "\t\tДолг по программированию: " << array_sur[i].get_prog_d() << "%" << endl;
		}
	////////////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}

void Arr_Sur::in_f()
{
	ofstream file;
	file.open("of2.txt", ofstream::app);

	if (!file.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}

	string info;
	stringstream ss;
	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		ss << "Номер: " << array_sur[i].get_number_stud() << "\tВозраст: " << array_sur[i].get_age() << "\tСредний балл: " << array_sur[i].get_middle_mark() << "\tИмя: " << array_sur[i].get_name() << "\tАудитория: " << array_sur[i].get_aud() << "\tФакультет: " << array_sur[i].get_fac() << "\tФамилия старосты: " << array_sur[i].get_sur_star() << "\tФамилия куратора: " << array_sur[i].get_sur_cur() << endl;
	}

	for (size_t i = 0; i < 80; i++)
		ss << "-";
	ss << endl;

	info = ss.str();
	file << info;

	file.close();

	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	cout << "Файл записан успешно!" << endl;
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////

}

void Arr_Sur::from_f(int size)
{
	string s;
	regex varEn("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [\\d]* [A-Z]* [A-Z]+[\\w,.;:-]* [A-Z]+[\\w,.;:-]*)");

	ifstream file;
	file.open("if2.txt");

	if (!file.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}

	delete[] array_sur;
	array_sur = new Surname[size];

	for (size_t i = 0; i < size; i++)
	{
		getline(file, s);
		if (regex_match(s, varEn))
		{
			std::istringstream iss(s);
			int age;
			int number;
			int middle_mark;
			string name;
			bool debt;
			int prog_d;
			sint audience;
			string faculty;
			string sur_star;
			string sur_cur;

			iss >> age;
			iss >> number;
			iss >> middle_mark;
			iss >> name;
			iss >> debt;
			iss >> prog_d;
			iss >> audience;
			iss >> faculty;
			iss >> sur_star;
			iss >> sur_cur;

			Surname file_el(age, number, middle_mark, name, debt, prog_d, audience, faculty, sur_star, sur_cur);
			array_sur[i] = file_el;
		}
	}

	file.close();

	cout << "Чтение с файла успешно!" << endl << endl;

	set_count(size);

	print_array(size);

}

int Arr_Sur::get_count() const
{
	return count;

}

int Arr_Sur::str_in_file(string fileName) const
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

void Arr_Sur::set_count(int c)
{
	count = c;

}

void Arr_Sur::regex_task()
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	regex regular("(^[A-ZÀ-ß]+[\\wÀ-ßà-ÿ,.;:-]* [\\wÀ-ßà-ÿ,.;:-]+)");
	int listSize = get_count();

	for (size_t i = 0; i < listSize; i++)
	{
		if (regex_match(array_sur[i].get_name(), regular))
			print_one(array_sur[i]);

	}

	cout << endl;
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

bool Arr_Sur::sort_forward(const int& a, const int& b)
{
	return a > b;
}

bool Arr_Sur::sort_back(const int& a, const int& b)
{
	return a < b;
}

void Arr_Sur::sort(comp condition)
{
	Surname temp;
	int size = get_count();
	bool pr;

	do {
		pr = 0;
		for (size_t i = 0; i < size - 1; i++)
		{
			if (condition(array_sur[i].get_number_stud(), array_sur[i + 1].get_number_stud()))
			{
				temp = array_sur[i];
				array_sur[i] = array_sur[i + 1];
				array_sur[i + 1] = temp;
				pr = 1;
			}
		}
	} while (pr == 1);

	print_array(size);
}