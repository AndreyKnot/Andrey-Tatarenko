#include "course.h"

int Course::get_course()
{
	return course;
}

void Course::set_course(int c)
{
	course = c;
}

void Course::print() const
{
	cout << "�������: " << age << "\t����� ��������: " << number_stud << "\t������� ����: " << middle_mark << "\t���: "
		<< name << "\t����: " << debt << "\t���� � ����: " << prog_d << "\t����� ���������: " << audience.get_aud_numb()
		<< "\t���������: " << faculty.get_fname() << "\t����: " << course << endl;
}

stringstream Course::get_str() const
{
	stringstream temp;

	temp << "�������: " << age << "\t����� ��������: " << number_stud << "\t������� ����: " << middle_mark << "\t���: "
		<< name << "\t����: " << debt << "\t���� � ����: " << prog_d << "\t����� ���������: " << audience.get_aud_numb()
		<< "\t���������: " << faculty.get_fname() << "\t����: " << course << endl;

	return temp;
}

void Course::write_in_file(ofstream& el)
{
	el << "�������: " << age << "\t����� ��������: " << number_stud << "\t������� ����: " << middle_mark << "\t���: "
		<< name << "\t����: " << debt << "\t���� � ����: " << prog_d << "\t����� ���������: " << audience.get_aud_numb()
		<< "\t���������: " << faculty.get_fname() << "\t����: " << course << endl;
}

Course::Course() : Student(0, 0, 0, "Name", 0, 0, 0, "Non"), course(0)
{

}

Course::Course(int a, int n, int m, string na, bool d, int pd, sint an, string fc, int c) : Student(a, n, m, na, d, pd, an, fc), course(c)
{

}

Course::Course(const Course& other) : Student(other), course(other.course)
{

}

Course::~Course()
{

}
////////////////////////////////////////////////////
Course& Course::operator=(Course& temp)
{
	if (this == &temp) return *this;

	Student::operator=(temp);
	int course = temp.course;

	return *this;
}

bool Course::operator==(const string name) const
{
	return this->name == name;
}

stringstream Course::getStr() const
{
	stringstream temp;

	temp << "�������: " << age << "\t����� ��������: " << number_stud << "\t������� ����: " << middle_mark << "\t���: "
		<< name << "\t����: " << debt << "\t���� � ����: " << prog_d << "\t����� ���������: " << audience.get_aud_numb()
		<< "\t���������: " << faculty.get_fname() << "\t����: " << course << endl;

	return temp;
}

string Course::getInfo() const
{
	stringstream temp;
	temp.setf(ios::left);

	temp << "�������: " << age << "\t����� ��������: " << number_stud << "\t������� ����: " << middle_mark << "\t���: "
		<< name << "\t����: " << debt << "\t���� � ����: " << prog_d << "\t����� ���������: " << audience.get_aud_numb()
		<< "\t���������: " << faculty.get_fname() << "\t����: " << course << endl;

	return temp.str();
}

void Course::input(istream& input)
{
	input >> age >> number_stud >> middle_mark >> name >> debt >> prog_d 
		>> audience >> faculty >> course;
}