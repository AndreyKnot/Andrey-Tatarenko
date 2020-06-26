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
	cout << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tКурс: " << course << endl;
}

stringstream Course::get_str() const
{
	stringstream temp;

	temp << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tКурс: " << course << endl;

	return temp;
}

void Course::write_in_file(ofstream& el)
{
	el << "Возраст: " << age << "\tНомер студента: " << number_stud << "\tСредний балл: " << middle_mark << "\tИмя: "
		<< name << "\tДолг: " << debt << "\tДолг с прог: " << prog_d << "\tНомер аудитории: " << audience.get_aud_numb()
		<< "\tФакультет: " << faculty.get_fname() << "\tКурс: " << course << endl;
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