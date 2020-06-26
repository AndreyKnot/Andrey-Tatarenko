#include "class2.h"

stringstream Course::get_str() const
{
	stringstream temp;

	temp << " " << age << " " << number_stud << " " << middle_mark << " "
		<< name << " " << debt << " " << prog_d << " " << course;

	return temp;
}

string Course::get_info() const
{
	stringstream temp;

	temp.setf(ios::left);
	temp << setw(10) << age << setw(8) << number_stud << setw(16) << middle_mark << setw(9)
		<< name << setw(7) << debt << setw(14) << prog_d << setw(4) << course;

	return temp.str();
}

int Course::countElement(int value, string data)
{
	try
	{
		if (value == 1)
		{
			if (this->name == data)
				return 1;
			else
				return 0;
		}
		else if (value == 2)
		{
			int number = stoi(data);
			if (this->age == number)
				return 1;
			else
				return 0;
		}
		else if (value == 3)
		{
			int number = stoi(data);
			if (this->middle_mark == number)
				return 1;
			else
				return 0;
		}
		else if (value == 4)
		{
			int number = stoi(data);
			if (this->prog_d == number)
				return 1;
			else
				return 0;
		}
		else if (value == 5)
		{
			int number = stoi(data);
			if (this->number_stud == number)
				return 1;
			else
				return 0;
		}
		else if (value == 6)
		{
			int number = 0;
			if (data == "true" || data == "true" || data == "1")
				number = 1;
			else
				number = 0;

			if (this->debt == number)
				return 1;
			else
				return 0;
		}
		else if (value == 7)
		{
			int number = stoi(data);
			if (this->course == number)
				return 1;
			else
				return 0;
		}
	}
	catch (const std::exception & ex)
	{
		cout << ex.what() << endl;
		return 0;
	}

	return 0;
}

bool Course::elementOutput(int value, string data)
{
	try
	{
		if (value == 1)
		{
			if (this->name == data)
				cout << *this << endl;
			return true;
		}
		else if (value == 2)
		{
			int number = stoi(data);
			if (this->age == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 3)
		{
			int number = stoi(data);
			if (this->middle_mark == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 4)
		{
			int number = stoi(data);
			if (this->prog_d == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 5)
		{
			int number = stoi(data);
			if (this->number_stud == number)
				cout << *this << endl;
			return true;
		}
		else if (value == 6)
		{
			int number = 0;
			if (data == "true" || data == "true" || data == "1")
				number = 1;
			else
				number = 0;

			if (this->debt == number)
				return 1;
			else
				return 0;
		}
		else if (value == 7)
		{
			int number = stoi(data);
			if (this->course == number)
				cout << *this << endl;
			return true;
		}
	}
	catch (const std::exception & ex)
	{
		cout << ex.what() << endl;
		return 0;
	}

	return 0;
}

Course::Course(int a, int n, int m, string na, bool d, int pd, int c) : Student(a, n, m, na, d, pd), course(c) {}
Course::Course() : Student(), course(1) {}
Course::Course(const Course& other) : Student(other), course(other.course) {}
Course::~Course() {}

bool Course::operator==(const int ns) const
{
	return this->number_stud == ns;
}