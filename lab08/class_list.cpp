#include "class_list.h"

void Arr::create_array()
{
	int c = get_count();

	array_stud = new Student*[c];
}

void Arr::fill_array()
{
	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		*(array_stud + i) = Construct(i);
	}

}

Student* Arr::Construct(int i)
{
	bool d = 0;

	if (i == 0)
	{
		d = rand() % 2;
		Student *st0 = new Surname(i + 17, i + 1, i + 10 / 2, "Dani", d, prog_d_rand(d), 15, "KIT", "Jhordon", "Pavlov");
		return st0;
	}
	else if (i == 1)
	{
		d = rand() % 2;
		Student *st1 = new Course(i + 17, i + 1, i + 10 / 2, "Peter", d, prog_d_rand(d), 15, "KIT", 1);
		return st1;
	}
	else if (i == 2)
	{
		d = rand() % 2;
		Student *st2 = new Course(i + 17, i + 1, i + 10 / 2, "Donald Tramp", d, prog_d_rand(d), 36, "PIT", 2);
		return st2;
	}
	else if (i == 3)
	{
		d = rand() % 2;
		Student *st2 = new Course(i + 17, i + 1, i + 10 / 2, "Vladimir", d, prog_d_rand(d), 36, "PIT", 3);
		return st2;
	}

	d = rand() % 2;
	Student *st = new Course(i + 17, i + 1, i + 10 / 2, "Edgar", d, prog_d_rand(d), 17, "GM", 3);
	return st;
}

void Arr::print_array(int c) const
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	for (size_t i = 0; i < c; i++)
	{
		array_stud[i]->print();
	}
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_one()
{
	int c = get_count();
	int input, i_arr = 0;
	cout << "Введите номер: ";
	cin >> input;

	for (size_t i = 0; i < c; i++)
		if (input == array_stud[i]->get_number_stud())
		{
			count_minus();
			int c = get_count();

			Student** array_stud_new = new Student *[c];
			Student** s_arr = array_stud;

			for (size_t i = 0; i < input; i++)
				*(array_stud_new + i) = *(s_arr + i);

			for (size_t i = input, j = input + 1; j < c+1; i++, j++)
				*(array_stud_new + i) = *(s_arr + j);

			delete* (array_stud + input);
			array_stud = array_stud_new;
			delete s_arr;

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

void Arr::add()
{
	count_plus();
	int c = get_count();

	Student** array_stud_new = new Student*[c];
	Student** s_arr = array_stud;

	size_t i = 0;

	for (i; i < c - 1; i++)
	{
		*(array_stud_new + i) = *(s_arr + i);
	}

	array_stud_new[c - 1] = Construct(i);

	array_stud = array_stud_new;

	delete s_arr;

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
	cout << "Введите номер: ";
	cin >> input;
	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		if (input == array_stud[i]->get_number_stud())
		{
			string info;
			stringstream ss;
			ss << "Номер: " << array_stud[i]->get_number_stud() << "\tВозраст: " << array_stud[i]->get_age() << "\t\tСредний балл: " << array_stud[i]->get_middle_mark() << "\t\tИмя: " << array_stud[i]->get_name() << endl;
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

void Arr::print_one(Student *stud) const
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	cout << "Номер: " << stud->get_number_stud() << "\tВозраст: " << stud->get_age() << "\t\tСредний балл: " << stud->get_middle_mark() << "\t\tИмя: " << stud->get_name() << "\t\tАудитория: " << stud->get_aud() << "\t\tФакультет: " << stud->get_fac() << endl;
	////////////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void Arr::delete_array()
{
	int c = get_count();
	for (int i = 0; i < c; i++)
		delete *(array_stud + i);

	delete array_stud;
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
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////////////
	for(size_t i = 0; i < count; i++)
		if (array_stud[i]->get_debt() == 1)
		{
			cout << "Номер: " << array_stud[i]->get_number_stud() << "\tВозраст: " << array_stud[i]->get_age() << "\t\tСредний балл: " << array_stud[i]->get_middle_mark() << "\t\tИмя: " << array_stud[i]->get_name() << "\t\tДолг: Есть" << "\t\tДолг по программированию: " << array_stud[i]->get_prog_d() << "%" << endl;
		}
	////////////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}

void Arr::in_f()
{
	ofstream file;
	file.open("of.txt", ofstream::app);

	if (!file.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}

	int c = get_count();

	for (size_t i = 0; i < c; i++)
	{
		array_stud[i]->write_in_file(file);
	}

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

void Arr::from_f(int size)
{
	string s;
	regex varEn("([\\d]* [\\d]* [\\d]* [A-Z]+[\\w,.;:-]* [0|1] [\\d]* [\\d]* [A-Z]* [\\d]*)");

	ifstream file;
	file.open("if.txt");

	if (!file.is_open())
	{
		cout << "Файл не открыт!" << endl;
		return;
	}

	delete[] array_stud;
	array_stud = new Student*[size];

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
			int course;

			iss >> age;
			iss >> number;
			iss >> middle_mark;
			iss >> name;
			iss >> debt;
			iss >> prog_d;
			iss >> audience;
			iss >> faculty;
			iss >> course;

			array_stud[i] = new Course(age, number, middle_mark, name, debt, prog_d, audience, faculty, course);
		}
	}

	file.close();

	cout << "Чтение с файла успешно!" << endl << endl;

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

void Arr::regex_task()
{
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
	////////////////
	regex regular("(^[A-ZÀ-ß]+[\\wÀ-ßà-ÿ,.;:-]* [\\wÀ-ßà-ÿ,.;:-]+)");
	int listSize = get_count();

	for (size_t i = 0; i < listSize; i++)
	{
		if (regex_match(array_stud[i]->get_name(), regular))
			print_one(array_stud[i]);

	}

	cout << endl;
	////////////////
	for (size_t i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

bool Arr::sort_forward(const int& a, const int& b)
{ 
	return a > b; 
}

bool Arr::sort_back(const int& a, const int& b)
{
	return a < b; 
}

void Arr::sort(comp condition)
{
	Student *temp;
	int size = get_count();
	bool pr;

		do {
			pr = 0;
			for (size_t i = 0; i < size - 1; i++)
			{
				if (condition(array_stud[i]->get_number_stud(), array_stud[i + 1]->get_number_stud()))
				{
					temp = array_stud[i];
					array_stud[i] = array_stud[i + 1];
					array_stud[i + 1] = temp;
					pr = 1;
				}
			}
		} while (pr == 1);

	print_array(size);
}
//////////////////////////////////////////////
Student* Arr::operator[] (int i)
{
	int c = get_count();

	if (c > i)
		return array_stud[i];
}